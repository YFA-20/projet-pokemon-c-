#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Joueur.hpp"
#include "Dresseur.hpp"
#include "Combat.hpp"
#include <vector>

int main() {
    // 1) Types et faiblesses / résistances
    Type feu("Feu"), eau("Eau"), plante("Plante");
    feu.addFaiblesse(&eau);
    feu.addResistance(&plante);
    eau.addFaiblesse(&plante);
    eau.addResistance(&feu);
    plante.addFaiblesse(&feu);
    plante.addResistance(&eau);

    // 2) Attaques liées aux types
    Attack flamm("Flammèche",    12, &feu);
    Attack lanceFlamme("Lance-Flamme", 15, &feu);
    Attack fouetLiane("Fouet Lianes", 10, &plante);
    Attack gigaSangsue("Giga-Sangsue", 14, &plante);

    // 3) Pokémons du joueur
    Pokemon p1("Salamèche",  60, {&feu},    {&flamm, &lanceFlamme});
    Pokemon p2("Bulbizarre", 55, {&plante}, {&fouetLiane, &gigaSangsue});

    // 4) Pokémon de l'IA
    Pokemon ia1("Carapuce",  50, {&eau},    {&fouetLiane}); 

    // 5) Création des dresseurs
    Joueur   joueur("Toi", { &p1, &p2 });        // DEUX pokémon !
    Dresseur ia("Bob",   { &ia1 });

    // 6) Lancement du combat interactif
    Combat c(&joueur, &ia);
    c.demarrer();

    return 0;
}

