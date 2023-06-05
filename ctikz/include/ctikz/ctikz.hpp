#pragma once
#ifndef CTIKZ_HPP

#include <string>
#include <sstream>
#include <cmath>
#include <vector>

/**
* @brief Структура, которая задает стиль функций.
*/
struct FunctionStyle{
    std::string color = "black"; /**< цвет линии и точек */
    std::string mark = "none"; /**< обозначение отметок графика функции (по умолчанию толстые точки) */
    std::string mark_size = ""; /**< толщина отметок */
    bool only_marks = 0; /**< отображение только ометок */
    int samples = 200; /**< шаг значений, повышающий качество графика */

    void write(std::stringstream& writing){ /**< записывает параметры стиля в поток */
         writing << "\\addplot [" << std::endl;
        writing << "mark=" << mark << "," << std::endl;
        if(only_marks){
            writing << "only marks," << std::endl;
        }
        if(!mark_size.empty()){
            writing << "mark size=" << mark_size << "," << std::endl;
        }
        writing << "samples=" << samples << "," << std::endl;
        writing << "color=" << color << "]" << std::endl;
    }
};

/**
 * @brief Структура, которая задает стиль фигур.
 */
struct FigureStyle{
    std::string color = "black"; /**< цвет контура фигуры */
    std::string patterned = "solid"; /**< толщина линии, также можно указать числом, например 4pt (смотреть документацию) */
    std::string arrow = ""; /**< стрелка (для отрезков) */
    std::string thickness = ""; /**< стиль линии */
    std::string fill = "none"; /**< заливка (цвет) */
    void write(std::stringstream& writing){ /**< записывает параметры стиля в поток */
        writing << "\\draw[";
        writing << "color=" << color << ", ";
        writing << "fill=" << fill << ", ";
        if (!thickness.empty()){
            writing << thickness << ", ";
        }
        if(!arrow.empty()){
            writing << arrow << ", ";
        }
        writing << patterned << "] ";
    }

};

/**
 * @brief Структура, которая задает стиль Axis-блока (Системы координат).
 */
struct AxisStyle{
    std::string title = ""; /**< заголовок над Axis-блоком */
    std::string xlabel = ""; /**< подпись горизонтальной оси (абсцисс) */
    std::string ylabel = ""; /**< подпись вертикальной оси (ординат) */
    std::string ymin = ""; /**< минимальное значение y */
    std::string xmin = ""; /**< минимальное значение x */
    std::string xmax = ""; /**< максимальное значение x */
    std::string ymax = ""; /**< максимальное значение y */

    std::string axis_lines = "box"; /**< расположение осей относительно Axis-блока (Например left, right и др.) */
    bool grid = 0; /**< вспомогательная сетка */
    std::string grid_style = ""; /**< стиль вспомогательной сетки  */
    double scale = 1; /**< масштаб */
    bool enlarge_limits = 1; /**< расположение точек на краях Axis-блока */

    void write(std::stringstream& writing){ /**< записывает параметры стиля в поток */
        if (!title.empty()){
            writing << "title=" << title << "," << std::endl;
        }
        if (!xlabel.empty()){
            writing << "xlabel=" << xlabel << "," << std::endl;
        }
        if (!ylabel.empty()){
            writing << "ylabel=" << ylabel << "," << std::endl;
        }       
        if(!xmin.empty()){
            writing << "xmin=" << xmin << "," << std::endl;
        }
        if(!ymin.empty()){
            writing << "ymin=" << ymin << "," << std::endl;
        }
        if(!xmax.empty()){
            writing << "xmax=" << xmax << "," << std::endl;
        }
        if(!ymax.empty()){
            writing << "ymax=" << ymax << "," << std::endl;
        }
        writing << "axis lines=" << axis_lines << "," << std::endl;
        if(grid){
            writing << "grid," << std::endl;
            if(!grid_style.empty()){
                writing << "grid style=" << grid_style << "," << std::endl;
            }
        }
        writing << "scale=" << scale << "," << std::endl;
        writing << "enlargelimits=" << std::boolalpha << enlarge_limits << "]" << std::endl;
    }
};

/**
 * @brief C++ library to work with LaTeX
 */
class CTikz{ 
public:
    CTikz() noexcept;
    void create_tikz_file(std::string filename);
    void start_axis(AxisStyle style=AxisStyle()); // enlargelimits
    void end_axis();
    void drawFunc(std::vector<std::pair<double, double> > points, FunctionStyle style=FunctionStyle());
    void drawFunc(std::string func, FunctionStyle style=FunctionStyle());

    void start_picture();
    void end_picture();
    void drawCircle(double x1, double y1, double r, FigureStyle style=FigureStyle());
    void drawRectangle(double x1, double y1, double x2, double y2, FigureStyle style=FigureStyle());
    void drawGrid(double x1, double y1, double x2, double y2, double step=1, FigureStyle style=FigureStyle());
    void drawLines(std::vector<std::pair<double, double> > points, FigureStyle style=FigureStyle());

    void add_parse();

private:
    int block_status = 0; /**< возможные значения: 0 - none, 1 - axis, 2 - only tikz picture */
    std::stringstream writing;
};

#endif //CTIKZ_HPP