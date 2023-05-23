#pragma once
#ifndef CTIKZ_HPP

#include <string>
#include <sstream>
#include <cmath>
#include <vector>

struct FunctionStyle{
    std::string color = "black";
    std::string mark = "none";
    bool only_marks = 0;
    int samples = 200;

    void write(std::stringstream& writing){
         writing << "\\addplot [" << std::endl;
        writing << "mark=" << mark << "," << std::endl;
        if(only_marks){
            writing << "only marks," << std::endl;
        }
        writing << "samples=" << samples << "," << std::endl;
        writing << "color=" << color << "]" << std::endl;
    }
};

struct FigureStyle{
    std::string color = "black";
    std::string patterned = "solid"; // default
    std::string arrow = "";
    std::string thickness = "";
    std::string fill = "none";

    void write(std::stringstream& writing){
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

class CTikz{
public:
    CTikz();
    void create_tikz_file(std::string filename);
    void start_axis(std::string axis_lines="box", bool grade=0, double scale=1, double ymin=-10, double xmin=-10);
    void end_axis();
    void drawFunc(std::vector<std::pair<long double, long double> > points, FunctionStyle style=FunctionStyle());
    void drawFunc(std::string func, FunctionStyle style=FunctionStyle());

    void start_picture();
    void end_picture();
    void drawCircle(double x1, double y1, double r, FigureStyle style=FigureStyle());
    void drawRectangle(double x1, double y1, double x2, double y2, FigureStyle style=FigureStyle());
    void drawGrid(double x1, double y1, double x2, double y2, double step=1, FigureStyle style=FigureStyle());
    void drawLines(std::vector<std::pair<double, double> > points, FigureStyle style=FigureStyle());

    void add_parse();

private:
    int block_status = 0; // 1 - axis, 2 - only tikz picture
    std::stringstream writing;
};

#endif //CTIKZ_HPP