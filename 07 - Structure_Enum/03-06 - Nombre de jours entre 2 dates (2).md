# Nombre de jours entre 2 dates (2)

Reprenez votre code de l'exercice [01-06](./01-06%20-%20Nombre%20de%20jours%20entre%202%20dates.md) 
et modifiez le pour que les mois utilisent une `enum class` plutôt que le type `uint8_t`.

~~~cpp
struct Date {
   uint8_t jour;
   Mois mois;
   int16_t annee;
};
~~~

<details>
<summary>Solutions</summary>

~~~cpp
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdint>

using namespace std;

enum class Mois : uint8_t {
   JANVIER = 1, FEVRIER, MARS, AVRIL,
   MAI, JUIN, JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

Mois& increment(Mois& m) {
   return m = Mois(int(m) % 12+1);
}

struct Date {
   uint8_t jour;
   Mois mois;
   int16_t annee;
};

bool est_bissextile(const Date& d) {
   return d.annee % 400 == 0 or
          (d.annee % 4 == 0 and d.annee % 100);
}

int duree_annee(Date const& d) {
   return est_bissextile(d) ? 366 : 365;
}

int duree_mois(Date const& d) {
   switch(d.mois) {
      case Mois::FEVRIER:
         return est_bissextile(d) ? 29 : 28;
      case Mois::AVRIL: [[fallthrough]];
      case Mois::JUIN: [[fallthrough]];
      case Mois::SEPTEMBRE: [[fallthrough]];
      case Mois::NOVEMBRE:
         return 30;
      default :
         return 31;
   }
}

int date_to_int(Date const& d) {
   int r = d.jour;
   for(Mois m = Mois::JANVIER; m < d.mois; increment(m))
      r += duree_mois(Date{1,m,d.annee});
   for(int16_t a = 1; a < d.annee; ++a)
      r += duree_annee(Date{1,Mois::JANVIER,a});
   return r;
}

int jours_entre(Date const& d1, Date const& d2) {
   return date_to_int(d2) - date_to_int(d1);
}

string to_string(const Date& d) {
   stringstream out;
   out << setfill('0') << right
       << setw(2) << +d.jour << '/'
       << setw(2) << int(d.mois) << '/'
       << setw(4) << d.annee;
   return out.str();
}

int main() {
   Date d1{31, Mois::JANVIER, 1973};
   Date d2{7, Mois::NOVEMBRE, 2023};
   cout << jours_entre(d1, d2) << " jours entre "
        << to_string(d1) << " et "
        << to_string(d2) << endl;
}
~~~
</details>

