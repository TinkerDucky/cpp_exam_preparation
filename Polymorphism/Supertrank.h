#pragma once

#include "Item.h"

class Supertrank : public Item {
 public:
  Supertrank(unsigned int uses = 3);

  virtual void useItem() override;
  virtual Item* clone() override;
};
