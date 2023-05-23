#include <ctikz/ctikz.hpp>

#define mp make_pair

using namespace std;


int main(){
  CTikz test;
  test.start_axis();
  test.drawFunc("x + 1");
  vector<pair<long double, long double> > asd;
  for(double i = 0.0; i <= 3.0; i += 0.1){
    asd.push_back(mp(i, exp(i)));
  }
  test.drawFunc(asd);
  test.end_axis();
  test.add_parse();
  test.start_picture();
  test.drawCircle(1, 1, 5);
  test.drawGrid(0, 0, 4, 4);
  //test.add_rectangle(1, 1, 6, 6);
  vector <pair<double, double> > points;
  points.push_back(make_pair(0, 1));
  points.push_back(make_pair(10, 1));
  points.push_back(make_pair(0, 4));
  points.push_back(make_pair(1, 1));
  test.drawLines(points);
  FunctionStyle style;
  style.only_marks = 1;
  style.color = "red";
  test.create_tikz_file("drawing");
}