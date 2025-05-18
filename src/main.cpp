#include <iostream>
#include <vector>
#include "Pokemon.hpp"
#include "Attack.hpp"
#include "Type.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"
#include "Combat.hpp"

int main() {
    // ─── 1) Types & Attaques ──────────────────────────────────────────
    Type feu("Feu"), eau("Eau");
    Attack flamm("Flammèche", 12, &feu);
    Attack hydro("Hydrocanon", 15, &eau);

    // ─── 2) Pokémon ───────────────────────────────────────────────────
    Pokemon p1("Salamèche", 50, std::vector<Type*>{&feu}, std::vector<Attack*>{&flamm});
    Pokemon p2("Carapuce",   50, std::vector<Type*>{&eau}, std::vector<Attack*>{&hydro});

    // ─── 3) Joueur ────────────────────────────────────────────────────
    Joueur joueur("Toi", { &p1, &p2 });

    // ─── 4) Gymnases (4 leaders) ──────────────────────────────────────
    LeaderGym l1("Pierre le Roche", { &p2 }, 1, "Badge Roche");
    LeaderGym l2("Marina l’Eau",    { &p1 }, 2, "Badge Cascade");
    LeaderGym l3("Flora la Plante", { &p1 }, 3, "Badge Verdure");
    LeaderGym l4("Volt l’Éclair",   { &p2 }, 4, "Badge Foudre");
    std::vector<LeaderGym*> gymLeaders = { &l1, &l2, &l3, &l4 };

    // Choix du gymnase
    std::cout << "=== Choisis un gymnase ===\n";
    for (auto* lg : gymLeaders) {
        std::cout << " Gym " << lg->getGymId()
                  << ") " << lg->getNom()
                  << " (" << lg->getBadgeName() << ")\n";
    }
    std::cout << "Ton choix> " << std::flush;
    int gid;
    std::cin >> gid;

    // On récupère le leader choisi (par défaut le premier)
    LeaderGym* choisi = gymLeaders.front();
    for (auto* lg : gymLeaders) {
        if (lg->getGymId() == gid) {
            choisi = lg;
            break;
        }
    }

    // ─── 5) Enchaînement des combats de gymnase ───────────────────────
    std::cout << "\nDébut du combat entre " << joueur.getNom()
              << " et " << choisi->getNom() << " !\n";
    for (auto* lg : gymLeaders) {
        Combat c(&joueur, lg);
        c.demarrer();
        if (!joueur.aPokemonDisponible()) {
            std::cout << "Tu as perdu contre " << lg->getNom() << "...\n";
            return 0;
        }
    }

    // ─── 6) Récompense Gymnase ────────────────────────────────────────
    joueur.gagnerBadge();
    std::cout << "Bravo, tu gagnes le badge "
              << choisi->getBadgeName() << " !\n";

    // ─── 7) Affronter un Maître Pokémon ──────────────────────────────
    std::cout << "\n=== Affronter un Maître Pokémon ? (o/n) ===\n"
              << "Choix> " << std::flush;
    char rep;
    std::cin >> rep;
    if (rep == 'o' || rep == 'O') {
        // Pour l’exemple, on affronte un Maître avec les mêmes Pokémon
        MaitrePokemon maitre("Maître Suprême", { &p1, &p2 });
        Combat c2(&joueur, &maitre);
        c2.demarrer();
        if (!joueur.aPokemonDisponible()) {
            std::cout << "Tu as perdu contre " << maitre.getNom() << "...\n";
            return 0;
        }
        std::cout << "Félicitations, tu as vaincu le Maître Pokémon !\n";
    }

    std::cout << "\nFin de la simulation. Merci d'avoir joué !\n";
    return 0;
}

