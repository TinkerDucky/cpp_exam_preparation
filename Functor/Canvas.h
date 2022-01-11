#pragma once

#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using std::map;
using std::string;
using std::swap;
using std::cout;
using std::endl;

class Canvas {
 private:
  unsigned int** pixels;
  map<string, unsigned int> properties;
  
  void swap(Canvas& c);

  public:
  Canvas(unsigned int width, unsigned int height, unsigned int init_color = 0xffffff00);
  ~Canvas();

  Canvas(const Canvas& obj);
  Canvas(Canvas&& obj) noexcept;

  Canvas& operator=(const Canvas obj);
  //Canvas operator=(Canvas&& obj) noexcept;
  bool operator()(const Canvas&);

  void setPixelColor(unsigned int x, unsigned int y, unsigned int color);
  unsigned int getPixelColor(unsigned int x, unsigned int y);
  void invert();

  void print();
};
