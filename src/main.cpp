#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Dresseur.hpp"
#include "Combat.hpp"
#include <vector>

int main() {
  // Types
  Type feu("Feu"), eau("Eau");
  feu.addFaiblesse(&eau);
  eau.addResistance(&feu);

  // Attaques
  Attack flamm("Flammèche", 12, &feu);
  Attack hydro("Hydrocanon", 15, &eau);

  // Pokémons
  Pokemon p1("Salamèche", 50, {&feu}, {&flamm});
  Pokemon p2("Carapuce",  50, {&eau}, {&hydro});

  // Dresseurs
  Dresseur d1("Alice", {&p1});
  Dresseur d2("Bob",   {&p2});

  // Combat
  Combat c(&d1, &d2);
  c.demarrer();

  return 0;
}

