#pragma once
#include <string>
class Attack;
class Pokemon;

/// Type d’action possible
enum class ActionType { ATTAQUE, CHANGEMENT };

/// Contient soit une attaque, soit un nouveau Pokémon
class Action {
public:
  ActionType    type;
  Attack*       attaqueChoisie;   // valide si type==ATTAQUE
  Pokemon*      nouveauPokemon;    // valide si type==CHANGEMENT

  /// Crée une Action ATTAQUE
  static Action makeAttaque(Attack* a) {
    return Action{ ActionType::ATTAQUE, a, nullptr };
  }

  /// Crée une Action CHANGEMENT
  static Action makeChangement(Pokemon* p) {
    return Action{ ActionType::CHANGEMENT, nullptr, p };
  }

  bool estAttaque()   const { return type == ActionType::ATTAQUE; }
  bool estChangement()const { return type == ActionType::CHANGEMENT; }

private:
  // constructeur privé : on force l’usage des fabriques statiques
  Action(ActionType t, Attack* a, Pokemon* p)
    : type(t), attaqueChoisie(a), nouveauPokemon(p) {}
};

