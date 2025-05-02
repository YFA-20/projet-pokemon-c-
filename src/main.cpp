#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Dresseur.hpp"
#include <vector>

int main() {
  // 1) types
  Type feu("Feu"), eau("Eau");
  feu.addFaiblesse(&eau);
  eau.addResistance(&feu);

  // 2) attaques
  Attack flamm("Flammèche", 12, &feu);
  Attack hydro("Hydrocanon", 15, &eau);

  // 3) pokémons
  Pokemon p1("Salamèche", 50, {&feu}, {&flamm});
  Pokemon p2("Carapuce",  50, {&eau}, {&hydro});

  // 4) dresseurs
  Dresseur d1("Alice", {&p1});
  Dresseur d2("Bob",   {&p2});

  // 5) action choisie
  Action a1 = d1.choisirAction();
  if (a1.estAttaque())
    p1.attaquer(p2);
  else
    d1.changerPokemon(0);

  return 0;
}
