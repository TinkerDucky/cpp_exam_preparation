#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Item {
 protected:
  unsigned int uses;
  string name;

 public:
  Item() = delete;
  Item(string name, unsigned int uses);
  ~Item() = default;
  Item(const Item& i) = default;
  Item(Item&& i) noexcept = default;
  Item& operator=(Item& i) = default;

  string getName();
  virtual void useItem() = 0;
  virtual Item* clone() = 0;
};
