#include "Buffer.h"

RingBuffer::RingBuffer(unsigned int size) : size(size), data(new int[size]{}) {}

RingBuffer::RingBuffer(unsigned int size, int init_value)
    : size(size), data(new int[size]) {
  cout << "RingBuffer(unsigned int size, int init_value) constructor." << endl;
  for (int i = 0; i < this->size; i++) {
    this->data[i] = init_value;
  }
}

RingBuffer::RingBuffer(unsigned int size, const int* init_data)
    : size(size), data(new int[size]) {
  cout << "RingBuffer(unsigned int size, const int* init_data) constructor."
       << endl;
  for (int i = 0; i < this->size; i++) {
    this->data[i] = init_data[i];
  }
}

RingBuffer::~RingBuffer() { delete this->data; }

RingBuffer::RingBuffer(const RingBuffer& obj)
    : size(obj.size), data(new int[obj.size]{}) {
  cout << "RingBuffer(const RingBuffer& obj) copy constructor." << endl;
  for (int i = 0; i < this->size; i++) {
    this->data[i] = obj.data[i];
  }
}

RingBuffer& RingBuffer::operator=(RingBuffer obj) {
  cout << "RingBuffer::operator=(RingBuffer obj) assignment operator." << endl;
  swap(obj);
  return *this;
}

void RingBuffer::swap(RingBuffer& obj) {
  using std::swap;
  swap(this->size, obj.size);
  swap(this->data, obj.data);
}

void RingBuffer::push(int val) { this->data[pos++ % size] = val; }

void RingBuffer::print(const char* name) {
  cout << "----------------------------------------------" << endl;
  cout << name << " Data:" << endl;
  for (int i = 0; i < this->size; i++) {
    cout << "Buffer[" << i << "] = " << this->data[i] << endl;
  }
  cout << "----------------------------------------------" << endl;
}
