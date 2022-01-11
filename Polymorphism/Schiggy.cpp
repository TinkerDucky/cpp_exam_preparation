#include "Schiggy.h"

Schiggy::Schiggy(string name, Item& item) : Pokemon(name, item) {}

void Schiggy::attack() { cout << "Schiggy setzt Blubber ein" << endl; }

void Schiggy::speak() { cout << "Schiggy Schiggy" << endl; }
