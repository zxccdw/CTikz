#include <ctikz/ctikz.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

#define mp make_pair

using namespace std;


int main(){
  CTikz test;
  test.start_axis();
  freopen("data.txt", "r", stdin);
  double x, y;
  // int color;
  vector<pair<double, double> > asd;
  while(cin >> x >> y){
     asd.push_back(mp(x, y));
  // }
  // vector<string> ar {"red", "blue", "green"};
  // style.only_marks = 1;
  // style.mark = "**";
  // style.mark_size = "1pt";
  // vector<pair<double, double> > points;
  // for(int i = 0; i < 3; ++i){
  //   style.color = ar[i];
  //   for(int j = 0; j < asd.size(); ++j){
  //     if(asd[j].second == i){
  //       points.push_back(asd[j].first);
  //     }
  //   }
  //   test.drawFunc(points, style);
  //   points.clear();
 }
  FunctionStyle style;
  test.drawFunc(asd);
  test.end_axis();
  test.create_tikz_file("result");


  cout << 1;

}