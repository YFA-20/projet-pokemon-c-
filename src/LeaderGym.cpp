#include "LeaderGym.hpp"
#include "Pokemon.hpp"

LeaderGym::LeaderGym(const std::string& nom,
                     const std::vector<Pokemon*>& equipe,
                     int gymId,
                     const std::string& badgeName)
  : Dresseur(nom, equipe),
    gymId_(gymId),
    badgeName_(badgeName)
{}

Action LeaderGym::choisirAction() {
    // IA très simple : toujours première attaque
    Pokemon* actif = getActif();
    return Action::makeAttaque(actif->getAttaque(0));
}

