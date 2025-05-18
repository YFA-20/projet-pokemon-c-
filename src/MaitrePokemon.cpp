#include "MaitrePokemon.hpp"

MaitrePokemon::MaitrePokemon(const std::string& nom,
                             const std::vector<Pokemon*>& equipe)
  : Dresseur(nom, equipe)
{}

Action MaitrePokemon::choisirAction() {
    // Machine ultra-simple : 1ere attaque
    Pokemon* actif = getActif();
    return Action::makeAttaque(actif->getAttaque(0));
}

