#include <ctikz/ctikz.hpp>
#include <string>
#include <iostream>
#include <vector>

//using namespace std;

int main(){ // Пример с отрисовкой фигур
    CTikz my_tex;
    my_tex.start_picture();
    FigureStyle figure;
    figure.color = "white"; // цвет контура - белый
    figure.fill = "blue!40!white"; // Заливка фигура 40% синий, 60% белый
    figure.patterned = "dashdotted"; // тип линии контура
    my_tex.drawCircle(1, 1, 5, figure);  // Окружность радиусом 5 с центром (1, 1)
    figure.color = "black"; 
    figure.fill = "green!60"; // зеленый 60% от прозрачности
    figure.patterned = "solid"; // стандартная линия
    my_tex.drawRectangle(0, 0, 3, 3, figure); // Прямоугольник с вершинами (0, 0) - (3, 3)
    my_tex.create_tikz_file("example3");
}
