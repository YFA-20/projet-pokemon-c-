#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include <vector>

int main() {
    // 1) Déclaration des types
    Type feu("Feu");
    Type eau("Eau"); 
    Type plante("Plante");

    // 2) Configuration des faiblesses / résistances
    feu.addFaiblesse(&eau);
    feu.addResistance(&plante);
    eau.addFaiblesse(&plante);
    eau.addResistance(&feu);

    // 3) Création des attaques
    Attack flamm("Flammèche", 12, &feu);
    Attack hydro("Hydrocanon", 15, &eau);

    // 4) Création des Pokémon avec types et attaques
    Pokemon p1("Salamèche", 50, {&feu}, {&flamm});
    Pokemon p2("Carapuce",  50, {&eau}, {&hydro});

    // 5) Test d’attaque
    p1.attaquer(p2);
    return 0;
}

