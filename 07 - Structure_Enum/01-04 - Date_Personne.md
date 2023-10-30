# struct - Date et Personne
Soit le programme principal mis à disposition.

Ecrire les librairies *Date* et *Personne* de sorte à ce que le programme produise le résultat ci-après.

~~~
une date     : 30.10.2023

Nom          : Anna
Adresse      : Yverdon
Anniversaire : 30.10.2023
~~~

~~~cpp
#include <iostream>
#include <cstdlib>

#include "date.h"
#include "personne.h"

using namespace std;
int main() {

   Date uneDate = set(30, 10, 2023);
   cout << "une date     : "; afficher(uneDate);
   cout << endl << endl;

   Personne anna = set("Anna", "Yverdon", uneDate);
   afficher(anna);

   cout << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>Solutions</summary>

<details>
<summary>date.h</summary>

~~~cpp
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
}
~~~
</details>

<details>
<summary>date.cpp</summary>

~~~cpp
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
~~~

</details>

<details>
<summary>personne.h</summary>

~~~cpp
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
~~~

</details>

<details>
<summary>personne.cpp</summary>

~~~cpp
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
~~~

</details>
