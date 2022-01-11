#include "Item.h"

Item::Item(string name, unsigned int uses) : name(name), uses(uses) {
  cout << "Item(string name, unsigned int uses) -> " << name << ", " << uses
       << " uses." << endl;
}

string Item::getName() { return this->name; }
