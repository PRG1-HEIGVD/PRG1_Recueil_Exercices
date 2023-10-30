#ifndef DATE_H
#define DATE_H

#include <cstdint>

using Jour  = uint8_t;
using Mois  = uint8_t;
using Annee = uint16_t;

struct Date {
   Jour  jour;
   Mois  mois;
   Annee annee;
};

Date  set(Jour j, Mois m, Annee a);
Jour  getJour (const Date& d);
Mois  getMois (const Date& d);
Annee getAnnee(const Date& d);

void afficher (const Date& d);

#endif //DATE_H
