#pragma once

#include <string>
#include <vector>
#include "Dresseur.hpp"
#include "Action.hpp"

/// Un joueur humain : choix interactif + statistiques + historiques de dresseurs vaincus
class Joueur : public Dresseur {
public:
    Joueur(const std::string& nom,
           const std::vector<Pokemon*>& equipe);

    /// Menu de choix d’action (options 1 à 7)
    Action choisirAction() override;

    // ─── Statistiques ────────────────────────────────────────────────
    int getNbBadges()    const { return nbBadges_; }
    int getNbVictoires() const { return nbVictoires_; }
    int getNbDefaites()  const { return nbDefaites_; }

    void gagnerBadge()        { ++nbBadges_; }
    void enregistrerVictoire(){ ++nbVictoires_; }
    void encaisserDefaite()   { ++nbDefaites_; }

    // ─── Historique d’entraîneurs vaincus ────────────────────────────
    /// Ajoute un dresseur à la liste des vaincus (appelé depuis Combat)
    void addDefeatedTrainer(Dresseur* defeated) {
        defeatedTrainers_.push_back(defeated);
    }

    /// Accès en lecture à la liste des entraîneurs vaincus
    const std::vector<Dresseur*>& getDefeatedTrainers() const {
        return defeatedTrainers_;
    }

private:
    int nbBadges_     = 0;
    int nbVictoires_  = 0;
    int nbDefaites_   = 0;

    std::vector<Dresseur*> defeatedTrainers_;
};

