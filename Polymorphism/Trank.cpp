#include "Trank.h"

Trank::Trank(unsigned int uses) : Item(string("Trank"), uses) {
  cout << "Created Item -> " << this->name << endl;
}

void Trank::useItem() {
  cout << this->name << " used, " << this->uses << " remaining." << endl;
}

Item* Trank::clone() { return new Trank(*this); }
