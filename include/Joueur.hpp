#pragma once

#include <string>
#include <vector>

#include "Dresseur.hpp"
#include "Action.hpp"   // pour le type Action
#include "Pokemon.hpp"  // pour std::vector<Pokemon*>

/// Un joueur humain : possède des stats (badges, victoires, défaites)
class Joueur : public Dresseur {
public:
    /// Nom du joueur + son équipe initiale
    Joueur(const std::string& nom,
           const std::vector<Pokemon*>& equipe);

    /// Menu interactif personnalisé pour un humain
    Action choisirAction() override;

    // ─── Statistiques du joueur ─────────────────────────────────────
    int getNbBadges()    const { return nbBadges_; }
    int getNbVictoires() const { return nbVictoires_; }
    int getNbDefaites()  const { return nbDefaites_; }

    /// Incrémenter badge / victoire / défaite (appelé depuis Combat)
    void gagnerBadge()         { ++nbBadges_; }
    void enregistrerVictoire() { ++nbVictoires_; }
    void encaisserDefaite()    { ++nbDefaites_; }

private:
    int nbBadges_    = 0;
    int nbVictoires_ = 0;
    int nbDefaites_  = 0;
};

