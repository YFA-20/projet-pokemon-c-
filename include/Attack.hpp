#pragma once
#include <string>

// simple forward‐decl pour éviter les includes croisés
class Type;

class Attack {
public:
  // constructeur : nom, puissance brute, pointeur vers un Type
  Attack(const std::string& nom, int puissance, Type* type);

  // getters
  const std::string& getNom() const;
  int                getPuissance() const;
  Type*              getType() const;

private:
  std::string nom_;
  int         puissance_;
  Type*       type_;
};

