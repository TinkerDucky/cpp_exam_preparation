#pragma once

#include "Pokemon.h"

class Schiggy : public Pokemon {
 public:
  Schiggy() = delete;
  Schiggy(string name, Item& item);
  ~Schiggy() = default;
  Schiggy(Pokemon& p) = delete;
  Schiggy(Pokemon&& p) noexcept = delete;

  void attack();
  void speak();
};