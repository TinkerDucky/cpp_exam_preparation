#include "Pokemon.h"

Pokemon::Pokemon(string name, Item& item) : name(name), item(item.clone()) {}

Pokemon::~Pokemon() { delete this->item; }

Pokemon::Pokemon(Pokemon& p) {
  cout << "Pokemon(Pokemon& p) -> " << this->name << ", "
       << this->item->getName() << endl;
}

Pokemon::Pokemon(Pokemon&& p) noexcept : item(p.item->clone()), name(p.name) {
  if (this->item == nullptr) return;

  p.item = nullptr;
}

void Pokemon::attack() { cout << this->name << " setzt Tackle ein." << endl; }

void Pokemon::speak() { cout << "Das Pokemon sagt etwas." << endl; }
