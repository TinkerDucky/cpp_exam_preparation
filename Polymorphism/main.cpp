#include <vector>

#include <algorithm>

#include "Item.h"
#include "Pokemon.h"
#include "Glumanda.h"
#include "Supertrank.h"
#include "Trank.h"
#include "Schiggy.h"
#include "Bisasam.h"

using std::vector;
using std::for_each;

int main(int argc, char* argv[]) {
  Pokemon* active_pokemon = nullptr;
  vector<Pokemon*> pokemon;

  Supertrank supertrank;
  Trank trank;

  pokemon.push_back(new Glumanda(string("Glumanda"), supertrank));
  pokemon.push_back(new Schiggy(string("Schiggy"), trank));
  pokemon.push_back(new Bisasam(string("Bisasam"), trank));

  auto attack = [](Pokemon* p) -> void {
    p->speak();
	p->attack();
    p->useItem();
  };

  for_each(pokemon.begin(), pokemon.end(), attack);

}