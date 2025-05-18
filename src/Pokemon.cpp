#include "Pokemon.hpp"
#include <algorithm>

Pokemon::Pokemon(const std::string& nom,
                 int pv,
                 const std::vector<Type*>& types,
                 const std::vector<Attack*>& attaques)
  : nom_(nom), pv_(pv), types_(types), attaques_(attaques)
{}

// Ancienne version : attaque sans Attack*
void Pokemon::attaquer(Pokemon& cible) {
    // appelle la première attaque
    attaquer(cible, attaques_.front());
}

// Nouvelle version : injection de l’Attack*
void Pokemon::attaquer(Pokemon& cible, Attack* atk) {
    double mult = 1.0;
    for (Type* t : cible.types_) {
        mult *= atk->getType()->multiplicateurContre(t);
    }
    int deg = static_cast<int>(atk->getPuissance() * mult);
    std::cout << nom_ << " utilise " << atk->getNom()
              << " et inflige " << deg << " dégâts sur "
              << cible.getNom() << ".\n";
    cible.recevoirDegats(deg);
}

void Pokemon::recevoirDegats(int montant) {
    pv_ = std::max(0, pv_ - montant);
    std::cout << nom_ << " a maintenant " << pv_ << " PV.\n";
}

bool Pokemon::estKO() const {
    return pv_ <= 0;
}

const std::string& Pokemon::getNom() const { return nom_; }
int Pokemon::getPV() const { return pv_; }

size_t Pokemon::getNbAttaques() const {
    return attaques_.size();
}

Attack* Pokemon::getAttaque(size_t idx) const {
    return attaques_.at(idx);
}

