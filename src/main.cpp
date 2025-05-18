#include <iostream>
#include "Pokemon.hpp"
#include "Attack.hpp"
#include "Type.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "Combat.hpp"

int main() {
    // 1) Création des types et attaques « à la main »
    Type feu("Feu"), eau("Eau");
    Attack flamm("Flammèche", 12, &feu);
    Attack hydro("Hydrocanon", 15, &eau);

    // 2) Création des Pokémon
    Pokemon p1("Salamèche", 50, std::vector<Type*>{&feu},   std::vector<Attack*>{&flamm});
    Pokemon p2("Carapuce",   50, std::vector<Type*>{&eau},   std::vector<Attack*>{&hydro});

    // 3) Création du joueur
    Joueur joueur("Toi", { &p1, &p2 });

    // 4) Création des leaders de gym en dur
    LeaderGym l1("Pierre le Roche", { &p2 }, 1, "Badge Roche");
    LeaderGym l2("Marina l’Eau",    { &p1 }, 2, "Badge Cascade");
    LeaderGym l3("Flora la Plante", { &p1 }, 3, "Badge Verdure");
    LeaderGym l4("Volt l’Éclair",   { &p2 }, 4, "Badge Foudre");
    std::vector<LeaderGym*> gymLeaders = { &l1, &l2, &l3, &l4 };

    // 5) Prototype : affronter un gymnase
    std::cout << "=== Choisis un gymnase ===\n";
    for (auto* lg : gymLeaders) {
        std::cout << " Gym " << lg->getGymId()
                  << ") " << lg->getNom()
                  << " (" << lg->getBadgeName() << ")\n";
    }
    std::cout << "Ton choix> " << std::flush;
    int gid;
    std::cin >> gid;

    // Trouver le gym choisi (sinon on prend le premier)
    LeaderGym* choisi = gymLeaders.front();
    for (auto* lg : gymLeaders) {
        if (lg->getGymId() == gid) {
            choisi = lg;
            break;
        }
    }

    // 6) Enchaîner les combats contre les 4 leaders
    for (auto* lg : gymLeaders) {
        Combat c(&joueur, lg);
        c.demarrer();
        // si plus de Pokémon dispo → défaite
        if (!joueur.aPokemonDisponible()) {
            std::cout << "Tu as perdu contre " << lg->getNom() << "...\n";
            return 0;
        }
    }

    // 7) Si tu as vaincu tous les leaders → tu gagnes le badge
    joueur.gagnerBadge();
    std::cout << "Bravo, tu gagnes le " 
              << choisi->getBadgeName() << " !\n";

    return 0;
}

