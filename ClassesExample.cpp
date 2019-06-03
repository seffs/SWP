#include <iostream>
using namespace std;

class Point {
  float x, y;
public:
  Point(){}
  Point (float x2, float y2) {
    x = x2; y = y2;
  }
  ~Point() {
    cout << x << " " << y << endl;
    cout << "das war's" << endl;
  }
  void scale(float f){
    x = x * f ; y = y * f;
  }
};

int main() {
  Point p = Point(1.0,2.0);
  p.scale(3.0);
}
