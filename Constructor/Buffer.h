#pragma once

#include <iostream>

using std::cout;
using std::endl;

class RingBuffer {
 private:
  int* data;
  unsigned int size;
  unsigned int pos = 0;

 public:
  RingBuffer(unsigned int size = 10);
  RingBuffer(unsigned int size, int init_value);
  RingBuffer(unsigned int size, const int* init_data);
  ~RingBuffer();
  RingBuffer(const RingBuffer& obj);
  RingBuffer(RingBuffer&& obj) noexcept;

  // Without copy and swap
  RingBuffer& operator=(const RingBuffer& obj);

  // With copy and swap
  //RingBuffer& operator=(RingBuffer obj);
  // 
  // Without move assignment withoout copy and swap
  RingBuffer& operator=(RingBuffer&& obj) noexcept;

  void push(int val);

  void swap(RingBuffer& obj);

  void print(const char* name);
};
