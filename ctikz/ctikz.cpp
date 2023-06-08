#include <ctikz/ctikz.hpp>
#include <fstream>

/**
* @brief Генерирует tikz файл
* @param filename название генерируемого файла
* @throw "File not created" файл не был создан (запустите от имени администратора или проверьте название файла)
*/
void CTikz::create_tikz_file(std::string filename){
    if (block_status == 1){
        end_axis();
    }
    if (block_status == 2){
        end_picture();
    }
    block_status = 0;
    writing << "\\end{document}";
    filename += ".tex";
    std::ofstream file;
    file.open(filename);
    if (file.bad()){
        throw "File not created";
    }
    file << writing.str();
    return;
}


/**
 * @brief Construct a new CTikz::CTikz object
 * Добавляет преамбулу в документ.
 */
CTikz::CTikz() noexcept{
    writing.clear();
    writing << "\\documentclass[a4paper, 10pt]{article}" << std::endl;
    writing << "\\usepackage[margin=0.25in]{geometry}" << std::endl;
    writing << "\\usepackage{tikz, pgfplots}" << std::endl;
    writing << "\\pgfplotsset{compat=1.9}" << std::endl;
    writing << "\\begin{document}" << std::endl;

}
/**
* @brief Конец блока с системой координат.
* @throw "Axis not started" В случае, если система координат не была начата.
*/
void CTikz::end_axis(){
    if (block_status == 1){
        writing << "\\end{axis}" << std::endl;
        writing << "\\end{tikzpicture}" << std::endl;
    }
    else {
        throw "Axis not started";
    }
    block_status = 0;
}


/**
* @brief Блок, отвечающий за начало системы координат.
* @param style Стиль системы координат (структура AxisStyle).
* @throw "Block not ended" Если какой-то из блоков не был закончен.
*/
void CTikz::start_axis(AxisStyle style){
    if(block_status != 0){
        throw "Block not ended";
    }
    block_status = 1;
    writing << "\\begin{tikzpicture}" << std::endl;
    writing << "\\begin{axis}[" << std::endl;
    style.write(writing);

}

/**
* @brief Добавляет функцию, которая будет нанесена на график по точкам.
* @param points Вектор пар точек (x, y).
* @param style Стиль функции (структура FunctionStyle).
* @throw "Axis not started" В случае, когда система координат не была начата.
*/
void CTikz::drawFunc(std::vector<std::pair<double, double>> points, FunctionStyle style){
    if (block_status == 1){
        style.write(writing);
        writing << "coordinates{" << std::endl;
        for(auto & i: points){
            writing << "(" << i.first << "," << i.second << ")";
        }
        writing << std::endl << "};" << std::endl;
    }
    else{
        throw "Axis not started";
    }
}

/**
* @brief Добавляет функцию, которая будет нанесена на график по заданному уравнению
* @param func Уравнение функции, например x + 5
* @param style Стиль функции (структура FunctionStyle)
* @throw "Axis not started" В случае, когда система координат не была начата.
*/
void CTikz::drawFunc(std::string func, FunctionStyle style){
    if(block_status != 1){
        throw "Axis not started";
    }
    style.write(writing);
    if (func.empty()){
        throw "Func is empty";
    }
    // check func !!!!!
    writing << "{" << func << "};" << std::endl;

}

/**
* @brief Начинает tikzpicture-блок, отвечающий за отрисовку фигур (без осей координат).
* @throw "Block not ended" Если какой-то из блоков не был закончен.
*/
void CTikz::start_picture(){
    if(block_status != 0){
        throw "Block not ended";
    }
    writing << "\\begin{tikzpicture}" << std::endl;
    block_status = 2;
}

/**
* @brief Блок заканчивающий tikzpicture-блок.
* @throw "Block not ended" Если какой-то из блоков не был закончен.
*/
void CTikz::end_picture(){
    if(block_status == 2){
        writing << "\\end{tikzpicture}" << std::endl;
        block_status = 0;
    }
    else{
        throw "Picture not started";
    }
}

/**
* @brief Рисует окружность
* @param x координата центра окр-ти по горизонтальной оси (абсцисс)
* @param y координата центра окр-ти по вертикальной оси (ординат)
* @param r радиус окружности
* @param style стиль фигуры (структура FigureStyle)
* @throw "Picture not found" если tikzpicture-блок не был начат.
*/
void CTikz::drawCircle(double x, double y, double r, FigureStyle style){
    if(block_status != 2){
        throw "Picture not found";
    }
    style.write(writing);
    writing << "(" << x << "," << y << ")" << " circle (" << r << ");" << std::endl;
}

/**
* @brief Рисует прямоугольник по двум противоположным вершинам
* @param x1 координата левой нижней вершины по горизонтальной оси (абсцисс)
* @param y1 координата левой нижней вершины вертикальной оси (ординат)
* @param x2 координата правой верхней вершины по горизонтальной оси (абсцисс)
* @param y2 координата правой верхней вершины вертикальной оси (ординат)
* @param style стиль фигуры (структура FigureStyle)
* @throw "Picture not found" если tikzpicture-блок не был начат.
*/
void CTikz::drawRectangle(double x1, double y1, double x2, double y2, FigureStyle style){
    if(block_status != 2){
        throw "Picture not found";
    }
    style.write(writing);
    writing << "(" << x1 << "," << y1 << ") rectangle (" << x2 << "," << y2 << ");" << std::endl;
}

/**
* @brief Рисует вспомогательную сетку
* @param x1 координата левой нижней вершины по горизонтальной оси (абсцисс)
* @param y1 координата левой нижней вершины вертикальной оси (ординат)
* @param x2 координата правой верхней вершины по горизонтальной оси (абсцисс)
* @param y2 координата правой верхней вершины вертикальной оси (ординат)
* @param step шаг сетки
* @param style стиль фигуры (структура FigureStyle)
* @throw "Picture not found" если tikzpicture-блок не был начат.
*/
void CTikz::drawGrid(double x1, double y1, double x2, double y2, double step, FigureStyle style){
    if(block_status != 2){
        throw "Picture not found";
    }
    style.write(writing);
    writing << "(" << x1 << "," << y1 << ") grid " << "(" << x2 << "," << y2 << ");" << std::endl;
}

/**
* @brief Рисует ломанные линии, заданные по коориднатам
* @param point вектор точек формата (x, y)
* @param style стиль фигуры (структура FigureStyle)
* @throw "Picture not found" если tikzpicture-блок не был начат.
*/
void CTikz::drawLines(std::vector<std::pair<double, double>> point, FigureStyle style){
    if(block_status != 2){
        throw "Picture not found";
    }
    style.write(writing);
    for(int i = 0; i < point.size() - 1; ++i){
        writing << "(" << point[i].first << "," << point[i].second << ") -- ";
    }
    writing << "(" << point[point.size() - 1].first << "," << point[point.size() - 1].second << ");" << std::endl;
    return;
}

/**
* @brief добавляет отступ между блоками, в нашем случае блоки будут располагаться друг под другом
* @throw "Block not ended" если один из блоков не был закончен.
*/
void CTikz::add_parse(){
    if(block_status != 0){
        throw "Blocks not ended";
    }
    writing << std::endl;
}