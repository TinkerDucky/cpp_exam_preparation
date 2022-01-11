#pragma once

#include "Pokemon.h"

class Bisasam : public Pokemon {
 public:
  Bisasam() = delete;
  Bisasam(string name, Item& item);
  ~Bisasam() = default;
  Bisasam(Pokemon& p) = delete;
  Bisasam(Pokemon&& p) noexcept = delete;

  void attack();
  void speak();
};
