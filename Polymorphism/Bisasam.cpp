#include "Bisasam.h"

Bisasam::Bisasam(string name, Item& item) : Pokemon(name, item) {}

void Bisasam::attack() { cout << "Bisasam setzt Rasierblatt ein" << endl; }

void Bisasam::speak() { cout << "Bisasam Bisasam!" << endl; }
