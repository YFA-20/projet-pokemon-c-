#include "Pokemon.hpp"

int main() {
    // Création de deux Pokémon avec dégâts fixes
    Pokemon pikachu("Pikachu", 100, 15);
    Pokemon salameche("Salamèche", 100, 12);

    // TODO (à implémenter) :
    // 1. Définir et associer des Type à chaque Pokémon
    // 2. Créer des Attack dynamiques (nom, puissance, type)
    // 3. Modifier Pokemon::attaquer pour utiliser Attack et Type
    // 4. Gérer les multiplicateurs de dégâts selon faiblesses/résistances

    // Test basique d'attaque (version minimaliste)
    pikachu.attaquer(salameche);
    return 0;
}

