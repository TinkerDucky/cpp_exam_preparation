#pragma once

#include <iostream>
#include <string>

#include "Item.h"

using std::cout;
using std::endl;
using std::string;

class Pokemon {
 private:
  string name;
  Item* item;

 public:
  Pokemon() = delete;
  Pokemon(string name, Item& item);
  ~Pokemon();
  Pokemon(Pokemon& p);
  Pokemon(Pokemon&& p) noexcept;

  Item& getItem() { return *(this->item); }
  void useItem() { this->item->useItem(); }
  void attack();
  void speak();
};
