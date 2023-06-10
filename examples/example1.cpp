#include <ctikz/ctikz.hpp>
#include <string>
#include <iostream>

//using namespace std;

int main(){
    CTikz my_tex;
    AxisStyle axis_style; // Задаем стиль системы координат
    axis_style.axis_lines = "left"; // Оси по левой стороне блока
    axis_style.title = "Пример 1"; // Подпись над графиком
    axis_style.grid = 1; // Вспомогательная сетка
    axis_style.grid_style = "dashed"; // Стиль сетки
    axis_style.ymax = "100"; // Максимальное значение по оси OY
    axis_style.ymin = "0"; // Минимальное значение по оси OY
    my_tex.start_axis(axis_style); // Создаем систему координат с стилем
    FunctionStyle function_style;
    function_style.color = "red"; // Цвет функции - красный
    function_style.samples = 400; // Кол-во точек - 400
    my_tex.drawFunc("x^4", function_style); // Функция x^4 со стилем выше
    function_style.color = "blue"; // Меняем цвет функции на синий
    my_tex.drawFunc("e^x", function_style); // Функция e^x
    my_tex.end_axis(); // Заканчиваем систему координат
    my_tex.create_tikz_file("example1"); // Создаем файл

//   CTikz test;
//   test.start_axis();
//   freopen("data.txt", "r", stdin);
//   double x, y;
//   // int color;
//   vector<pair<double, double> > asd;
//   while(cin >> x >> y){
//      asd.push_back(mp(x, y));
//   // }
//   // vector<string> ar {"red", "blue", "green"};
//   // style.only_marks = 1;
//   // style.mark = "**";
//   // style.mark_size = "1pt";
//   // vector<pair<double, double> > points;
//   // for(int i = 0; i < 3; ++i){
//   //   style.color = ar[i];
//   //   for(int j = 0; j < asd.size(); ++j){
//   //     if(asd[j].second == i){
//   //       points.push_back(asd[j].first);
//   //     }
//   //   }
//   //   test.drawFunc(points, style);
//   //   points.clear();
//  }
//   FunctionStyle style;
//   test.drawFunc(asd);
//   test.end_axis();
//   test.create_tikz_file("result");

  std::cout << 1;

}