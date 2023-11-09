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

   Date uneDate = {30, 10, 2023};
   cout << "une date     : "; afficher_date(uneDate);
   cout << endl << endl;

   Personne anna = {"Anna", "Yverdon", uneDate};
   afficher_personne(anna);

   cout << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>Solutions</summary>

<details>
<summary>date.h</summary>

~~~cpp
//----------------------------------------------
// A NOTER
// - pas de using namespace std
// - pas de #using <iostream>
//----------------------------------------------

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

void afficher_date(const Date& d);

#endif //DATE_H
~~~
</details>

<details>
<summary>date.cpp</summary>

~~~cpp
//----------------------------------------------
// A NOTER
// - using namespace std possible
// - #include <iostream> ici et non dans le .h
// - cast (int)d.jour et (int)d.mois sinon un car est affiché
//----------------------------------------------

#include <iostream>
#include "date.h"

void afficher_date(const Date& d) {
   std::cout << (int)d.jour << '.'
             << (int)d.mois << '.'
             << d.annee;
}
~~~

</details>

<details>
<summary>personne.h</summary>

~~~cpp
//----------------------------------------------
// A NOTER
// - pas de using namespace std
// - pas de #using <iostream>
// - #include <string> nécessaire (paramètre)
// - #include "date.h" nécessaire (paramètre)
//----------------------------------------------

#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include "date.h"

struct Personne {
   std::string nom;
   std::string adresse;
   Date        anniversaire;
};

void afficher_personne(const Personne& p);


#endif //PERSONNE_H
~~~

</details>

<details>
<summary>personne.cpp</summary>

~~~cpp
//----------------------------------------------
// A NOTER
// - using namespace std possible
// - #using <iostream> nécessaire
// - pas de #include <string>, déjà dans le .h
//----------------------------------------------

#include <iostream>
#include "personne.h"

void afficher_personne(const Personne& p) {
   std::cout << "Nom          : " << p.nom      << std::endl
             << "Adresse      : " << p.adresse  << std::endl
             << "Anniversaire : ";
   afficher_date(p.anniversaire);
}
~~~

</details>
