# Nombre de jours entre 2 dates (exercice long)

Soit la structure suivante permettant de représenter une date 

~~~cpp
struct Date {
   uint8_t jour;
   uint8_t mois;
   int16_t annee;
};
~~~

Ecrire les fonctions `jours_entre` et `to_string` de sorte que le programme suivant

~~~cpp 
int main() {
   Date d1{31, 1, 1973};
   Date d2{7, 11, 2023};
   cout << jours_entre(d1, d2) << " jours entre "
        << to_string(d1) << " et "
        << to_string(d2) << endl;
}
~~~

compile et affiche 

~~~
18542 jours entre 31/1/1973 et 7/11/2023
~~~

Conseils : une approche possible consiste à écrire une fonction de conversion `date_to_int` qui fait
correspondre à chaque date un entier de sorte que le 1er janvier de l'an 1 corresponde à l'entier 1, et 2 dates 
consécutives correspondent à 2 entiers consécutifs. Cette fonction a besoin de connaitre le nombre de jours d'un mois
et le nombre de jours d'une année. 

Note : on ignore pour cet exercices les subtilités du passage du calendrier julien au calendrier grégorien et encore 
moins des calendriers pré-juliens. Pour simplifier le problème, ne considérez que les dates de l'ère commune, i.e. avec `.annee > 0`.

<details>
<summary>Solutions</summary>

~~~cpp
#include <iostream>
#include <string>
#include <cstdint>
#include <cassert>

using namespace std;

struct Date {
   uint8_t jour;
   uint8_t mois;
   int16_t annee;
};

bool est_bissextile(const Date& d) {
   return d.annee % 400 == 0 or
          (d.annee % 4 == 0 and d.annee % 100);
}

int duree_mois(const Date& d) {
   switch(d.mois) {
      case 2 :
         return est_bissextile(d) ? 29 : 28;
      case 4 : case 6 : case 9 : case 11:
         return 30;
      default:
         return 31;
   }
}

int duree_annee(const Date& d) {
   return est_bissextile(d) ? 366 : 365;
}

long long date_to_ll(const Date& d) {
   assert(d.annee > 0);
   long long r = 0;
   for(int16_t i = 1; i < d.annee; ++i)
      r += duree_annee({1,1,i});
   for(uint8_t i = 1; i < d.mois; ++i)
      r += duree_mois({1,i,d.annee});
   r += d.jour;
   return r;
}

long long jours_entre(Date const& d1, Date const& d2) {
   return date_to_ll(d2)- date_to_ll(d1);
}

string to_string(Date const& d) {
   return to_string(d.jour) + '/' + to_string(d.mois) + '/' + to_string(d.annee);
}

int main() {
   Date d1{31, 1, 1973};
   Date d2{7, 11, 2023};
   cout << jours_entre(d1, d2) << " jours entre "
        << to_string(d1) << " et "
        << to_string(d2) << endl;
}
~~~
</details>

