#ifndef __POINT__
#define __POINT__

class Point {
  float x, y;
 public:
  Point(float x2, float y2);
  ~Point();
  void scale(float f);
};

#endif // __POINT__
