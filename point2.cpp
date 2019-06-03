#include "point2.h"

#include <iostream>
using namespace std;

Point::Point(float x2, float y2) {
  x = x2; y = y2;
}
Point::~Point() {
  cout << "das war's" << endl;
}
void Point::scale(float f) {
  x = f * x; y = f * y;
}
