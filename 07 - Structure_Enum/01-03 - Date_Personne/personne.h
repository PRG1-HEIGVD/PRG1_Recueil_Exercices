#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "date.h"

struct Personne {
   std::string nom;
   std::string adresse;
   Date        anniversaire;
};

Personne set(const std::string& nom,
             const std::string& adresse,
             const Date&        date);

std::string getNom         (const Personne& p);
std::string getAdresse     (const Personne& p);
Date        getAnniversaire(const Personne& p);

void afficher (const Personne& p);


#endif //PERSONNE_H
