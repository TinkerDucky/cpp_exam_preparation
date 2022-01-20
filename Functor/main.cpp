#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#include "Canvas.h"

using std::cout;
using std::endl;
using std::list;
using std::replace_if;

int main(int argc, char* argv[]) {
  list<Canvas> canvas_list;
  list<Canvas>::iterator it;

  Canvas ref_canvas(5, 5);

  auto ref_lambda = [ref_canvas](const Canvas& canvas) -> bool {
    return ref_canvas.getHeight() * ref_canvas.getWidth() <
           canvas.getHeight() * canvas.getWidth();
  };

  canvas_list.push_back(Canvas(8, 8, 0xffff0000));
  canvas_list.push_back(Canvas(3, 3, 0xff00ff00));
  canvas_list.push_back(Canvas(7, 7, 0xff0000ff));
  canvas_list.push_back(Canvas(2, 2, 0xffff00ff));
  canvas_list.push_back(Canvas(11, 11, 0xff00ffff));

  it = canvas_list.begin();

  for_each(canvas_list.begin(), canvas_list.end(),
           [](Canvas& c) { c.print(); });

  replace_if(canvas_list.begin(), canvas_list.end(), ref_lambda, ref_canvas);

  for_each(canvas_list.begin(), canvas_list.end(),
           [](Canvas& c) { c.print(); });
}