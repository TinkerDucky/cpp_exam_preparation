#pragma once

#include "Item.h"

class Trank : public Item {
 public:
  Trank(unsigned int uses = 5);

  virtual void useItem() override;
  virtual Item* clone() override;
};
