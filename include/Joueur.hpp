#pragma once

#include <string>
#include <vector>
#include "Dresseur.hpp"
#include "Action.hpp"

class Pokemon;  // forward

/// Un joueur humain : choix interactif + statistiques + historique de vaincus
class Joueur : public Dresseur {
public:
    Joueur(const std::string& nom,
           const std::vector<Pokemon*>& equipe);
    ~Joueur() override;

    /// Menu de choix d’action (options 1 à 7)
    Action choisirAction() override;

    // ─── Statistiques ────────────────────────────────────────────────
    int getNbBadges()    const { return nbBadges_; }
    int getNbVictoires() const { return nbVictoires_; }
    int getNbDefaites()  const { return nbDefaites_; }

    void gagnerBadge()         { ++nbBadges_; }
    void enregistrerVictoire() { ++nbVictoires_; }
    void encaisserDefaite()    { ++nbDefaites_; }

    // ─── Historique d’entraîneurs vaincus ────────────────────────────
    void addDefeatedTrainer(Dresseur* defeated) {
        defeatedTrainers_.push_back(defeated);
    }
    const std::vector<Dresseur*>& getDefeatedTrainers() const {
        return defeatedTrainers_;
    }

    // ─── Affichages hors-combat ──────────────────────────────────────
    void afficherMesPokemons() const;
    void afficherPvEquipe()     const;
    void afficherStatistiques() const;
    void interagirKOvaincus()   const;

private:
    int nbBadges_     = 0;
    int nbVictoires_  = 0;
    int nbDefaites_   = 0;

    std::vector<Dresseur*> defeatedTrainers_;
};

