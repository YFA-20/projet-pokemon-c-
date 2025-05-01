#pragma once
#include <string>
#include <vector>

class Type {
public:
  Type(const std::string& nom);
  void addFaiblesse(Type* t);
  void addResistance(Type* t);
  double multiplicateurContre(Type* cible) const;
  const std::string& getNom() const;

private:
  std::string nom_;
  std::vector<Type*> faiblesses_;
  std::vector<Type*> resistances_;
};

