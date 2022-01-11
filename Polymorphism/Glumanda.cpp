#include "Glumanda.h"

Glumanda::Glumanda(string name, Item& item) : Pokemon(name, item) {}

void Glumanda::attack() { cout << "Glumanda setzt Glut ein." << endl; }

void Glumanda::speak() { cout << "Glumanda Glumanda!" << endl; }
