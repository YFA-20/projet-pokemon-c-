#pragma once
#include <string>
#include "Type.hpp"

class Attack {
public:
  Attack(const std::string& nom, int puissance, Type* type);
  int getPuissance() const;
  Type* getType() const;
  const std::string& getNom() const;

private:
  std::string nom_;
  int puissance_;
  Type* type_;
};

