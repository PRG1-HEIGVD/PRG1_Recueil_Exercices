#include <iostream>
#include "personne.h"

//-------------------------------------
Personne set(const std::string& nom,
             const std::string& adresse,
             const Date&        date) {
   return {nom, adresse, date};
}

//-------------------------------------
std::string getNom(const Personne& p) {
   return p.nom;
}

//-------------------------------------
std::string getAdresse(const Personne& p) {
   return p.adresse;
}

//-------------------------------------
Date getAnniversaire(const Personne& p) {
   return p.anniversaire;
}

//-------------------------------------
void afficher (const Personne& p) {
   std::cout << "Nom          : " << p.nom      << std::endl
             << "Adresse      : " << p.adresse  << std::endl
             << "Anniversaire : ";
   afficher(p.anniversaire);
}
