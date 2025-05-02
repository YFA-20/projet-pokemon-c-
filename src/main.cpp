#include "Pokemon.hpp"

int main() {
  Pokemon pikachu("Pikachu",    100, 15);
  Pokemon salameche("Salamèche", 100, 12);

  pikachu.attaquer(salameche);
  return 0;
}

