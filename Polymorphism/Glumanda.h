#pragma once

#include "Pokemon.h"

class Glumanda : public Pokemon {
 public:
  Glumanda() = delete;
  Glumanda(string name, Item& item);
  ~Glumanda() = default;
  Glumanda(Pokemon& p) = delete;
  Glumanda(Pokemon&& p) noexcept = delete;

  void attack();
  void speak();
};