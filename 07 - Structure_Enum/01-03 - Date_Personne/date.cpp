#include <iostream>
#include "date.h"

//-------------------------------------
Date  set(Jour j, Mois m, Annee a) {
   return Date {j, m, a};
}

//-------------------------------------
Jour  getJour (const Date& d) {
   return d.jour;
}

//-------------------------------------
Mois  getMois (const Date& d) {
   return d.mois;
}

//-------------------------------------
Annee getAnnee(const Date& d) {
   return d.annee;
}

//-------------------------------------
void afficher(const Date& d) {
   std::cout << (int)d.jour << '.'
             << (int)d.mois << '.'
             << d.annee;
}
