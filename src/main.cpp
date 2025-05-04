#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Joueur.hpp"
#include "Dresseur.hpp"
#include "Combat.hpp"
#include <vector>

int main() {
  // 1) types + faiblesses/résistances
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
  Joueur joueur("Toi", {&p1});
  Dresseur ia("Bob",   {&p2});

  // 5) combat interactif
  Combat c(&joueur, &ia);
  c.demarrer();

  return 0;
}

