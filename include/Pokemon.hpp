#pragma once
#include <string>

class Pokemon {
public:
  Pokemon(const std::string& nom, int pv);
  void attaquer(Pokemon* cible);
  void recevoirDegats(int montant);
  bool estKO() const;

private:
  std::string nom_;
  int pv_;
};

