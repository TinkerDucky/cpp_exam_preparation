#include "Buffer.h"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  RingBuffer buf_0 = RingBuffer(5);
  RingBuffer buf_1 = buf_0;
  buf_0.print("Buffer 0");
  buf_1.print("Buffer 1");
  buf_0.push(1);
  buf_0.push(2);
  buf_0.push(3);
  buf_0.push(4);
  buf_0.push(5);
  buf_0.push(6);
  buf_0.push(7);
  buf_0.print("Buffer 0");
  buf_1.print("Buffer 1");
  buf_1 = buf_0;
  buf_0.print("Buffer 0");
  buf_1.print("Buffer 1");
  buf_1.push(100);
  buf_1.push(101);
  buf_1.push(102);
  buf_0.print("Buffer 0");
  buf_1.print("Buffer 1");

  RingBuffer(std::move(buf_1)).print("Buffer Moved");
}