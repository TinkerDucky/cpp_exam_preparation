#include "Supertrank.h"

Supertrank::Supertrank(unsigned int uses) : Item(string("Supertrank"), uses) {
  cout << "Created Item -> " << this->name << endl;
}

Item* Supertrank::clone() { return new Supertrank(*this); }

void Supertrank::useItem() {
  cout << this->name << " used, " << this->uses << " remaining." << endl;
}
