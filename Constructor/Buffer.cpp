#include "Buffer.h"

RingBuffer::RingBuffer(unsigned int size) : size(size), data(new int[size]{}) {
  cout << "RingBuffer(unsigned int size) constructor." << endl;
}

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

RingBuffer::~RingBuffer() {
    cout << "~RingBuffer destructor." << endl;
    delete this->data; 
}

RingBuffer::RingBuffer(const RingBuffer& obj)
    : size(obj.size), data(new int[obj.size]{}), pos(obj.pos) {
  cout << "RingBuffer(const RingBuffer& obj) copy constructor." << endl;
  for (int i = 0; i < this->size; i++) {
    this->data[i] = obj.data[i];
  }
}

RingBuffer::RingBuffer(RingBuffer&& obj) noexcept : size(obj.size), data(obj.data), pos(obj.pos) {
  cout << "RingBuffer(RingBuffer&& obj) noexcept move constructor." << endl;
  obj.data = nullptr;
  obj.size = 0;
  obj.pos = 0;
}

// Without copy and swap
RingBuffer& RingBuffer::operator=(const RingBuffer& obj) {
    cout << "RingBuffer::operator=(RingBuffer& obj) assignment operator." << endl;
    this->size = obj.size;
    this->pos = obj.pos;
    delete this->data;
    this->data = new int[obj.size];
    for (int i = 0; i < obj.size; i++) {
        this->data[i] = obj.data[i];
    }
    return *this;
}

 // With copy and swap
//RingBuffer& RingBuffer::operator=(RingBuffer obj) {
//  cout << "RingBuffer::operator=(RingBuffer obj) assignment operator." << endl;
//  swap(obj);
//  return *this;
//}

//// Move assignment without copy and swap
RingBuffer& RingBuffer::operator=(RingBuffer&& obj) noexcept {
    cout << "RingBuffer& RingBuffer::operator=(RingBuffer&& obj) noexcept move assignment operator." << endl;
    this->data = obj.data;
    this->size = obj.size;
    this->pos = obj.pos;

    obj.data = nullptr;
    obj.size = 0;
    obj.pos = 0;

    return *this;
}

void RingBuffer::swap(RingBuffer& obj) {
  using std::swap;
  swap(this->size, obj.size);
  swap(this->data, obj.data);
  swap(this->pos, obj.pos);
}

void RingBuffer::push(int val) { this->data[this->pos++ % this->size] = val; }

void RingBuffer::print(const char* name) {
  cout << "----------------------------------------------" << endl;
  cout << name << " Data:" << endl;
  for (int i = 0; i < this->size; i++) {
    cout << "Buffer[" << i << "] = " << this->data[i] << endl;
  }
  cout << "----------------------------------------------" << endl;
}
