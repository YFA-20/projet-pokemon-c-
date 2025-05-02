#pragma once
#include <string>
#include <vector>

class Type {
public:
  explicit Type(const std::string& nom);

  const std::string& getNom() const;
  void addFaiblesse(Type* t);
  void addResistance(Type* t);
  double multiplicateurContre(Type* cible) const;

private:
  std::string        nom_;
  std::vector<Type*> faiblesses_;
  std::vector<Type*> resistances_;
};

