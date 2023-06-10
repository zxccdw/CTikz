#include <ctikz/ctikz.hpp>
#include <string>
#include <iostream>
#include <vector>

//using namespace std;

int main(){ // Пример с отрисовкой матрицы
    CTikz my_tex;
    std::vector<std::vector<double> > ar;
    std::vector<double> temp;
    int cnt = 0;
    for(int i = 0; i < 10; ++i){
        temp.clear();
        for(int j = 0; j < 5; ++j){
            temp.push_back(cnt);
            cnt += 1;
        }
        ar.push_back(temp);
    }
    my_tex.draw_table(ar);
    my_tex.create_tikz_file("matrix_test");
}