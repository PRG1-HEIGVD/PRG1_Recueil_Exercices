# Médailles olympiques

Soit le tableau suivant, donnant le nombre de médailles d'or, d'argent et de bronze obtenues par pays en patinage aux Jeux olympiques d'hiver de 2010 à Vancouver (Canada).

| Pays      | Or | Argent | Bronze |
|-----------|----|--------|--------|
| Allemagne |  0 |     0  |     1  |
| Canada    |  1 |     0  |     1  |
| Chine     |  1 |     1  |     0  |
| Corée     |  1 |     0  |     0  |
| Etats-Unis|  1 |     1  |     0  |
| Japon     |  0 |     1  |     1  |
| Russie    |  0 |     1  |     1  |

Ecrire un programme C++ mettant à disposition :

- une fonction retournant le nombre total de médailles obtenues par un pays donné
- une fonction retournant le nombre total de médailles d'un type donné obtenues par l'ensemble des pays (par ex le nombre total de médailles d'or obtenues par l'ensemble des pays)
- … et bien sûr une fonction main permettant de tester les 2 fonctions précédentes.

**NB** Le tableau des médailles ci-dessus est à implémenter sous la forme d'un array bidimensionnel (2D)   

<details>
<summary>Solution</summary>

~~~cpp
#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

using ushort = unsigned short;

enum class Pays {CANADA, CHINE, ALLEMAGNE, COREE, JAPON, RUSSIE, ETATS_UNIS};
const ushort NB_PAYS = 7;
const string PAYS[] = {"Canada", "Chine", "Allemagne", "Coree",
                       "Japon", "Russie", "Etats-Unis"};

enum class TypeMedaille {OR, ARGENT, BRONZE};
const ushort NB_TYPES_MEDAILLE = 3;
const string TYPE_MEDAILLE[] = {"Or", "Argent", "Bronze"};

using Medailles_Obtenues = array<ushort, NB_TYPES_MEDAILLE>;
using Medailles = array<Medailles_Obtenues, NB_PAYS>;

// nombre total de médailles obtenues par un pays donné
unsigned nbTotalMedailles(const Medailles& medailles,
                          const Pays& pays);

// nombre total de médailles d'un type donné obtenues par l'ensemble des pays
unsigned nbTotalMedailles(const Medailles& medailles,
                          const TypeMedaille& typeMedaille);

int main() {

   const Medailles MEDAILLES = { Medailles_Obtenues{1, 0, 1},
                                 Medailles_Obtenues{1, 1, 0},
                                 Medailles_Obtenues{0, 0, 1},
                                 Medailles_Obtenues{1, 0, 0},
                                 Medailles_Obtenues{0, 1, 1},
                                 Medailles_Obtenues{0, 1, 1},
                                 Medailles_Obtenues{1, 1, 0} };

   // Nombre total de médailles obtenues par chacun des pays
   // NB Le setw(10) ci-dessous est fixé "en dur".
   //    Aurait pu (dû) se calculer en déterminant le nom du pays le plus long.
   for (Pays p = Pays::CANADA; p <= Pays::ETATS_UNIS; p = (Pays) ((int) p + 1)) {
      unsigned nbMedailles = nbTotalMedailles(MEDAILLES, p);
      cout << setw(10) << left << PAYS[(int) p] << " : "
           << nbMedailles << " medaille" << (nbMedailles >= 2 ? "s" : "")
           << endl;
   }
   cout << endl;
   // Nombre total de médailles d'or, d'argent et de bronze obtenues
   // par l'ensemble des pays
   // NB Le setw(6) ci-dessous est fixé "en dur".
   //    Aurait pu (dû) se calculer en déterminant le nom du type de médaille
   //    le plus long.
   for (TypeMedaille tm = TypeMedaille::OR; tm <= TypeMedaille::BRONZE;
        tm = (TypeMedaille) ((int) tm + 1)) {
      unsigned nbMedailles = nbTotalMedailles(MEDAILLES, tm);
      cout << setw(6) << left << TYPE_MEDAILLE[(int) tm] << " : "
           << nbMedailles << " medaille" << (nbMedailles >= 2 ? "s" : "")
           << endl;
   }

   return EXIT_SUCCESS;
}

unsigned nbTotalMedailles(const Medailles& medailles,
                          const Pays& pays) {
   unsigned nbTotalMedailles = 0;
   for (ushort j = 0; j < NB_TYPES_MEDAILLE; ++j) {
      nbTotalMedailles += medailles[(ushort) pays][j];
   }
   return nbTotalMedailles;
}

unsigned nbTotalMedailles(const Medailles& medailles,
                          const TypeMedaille& typeMedaille) {
   unsigned nbTotalMedailles = 0;
   for (ushort i = 0; i < NB_PAYS; ++i) {
      nbTotalMedailles += medailles[i][(ushort) typeMedaille];
   }
   return nbTotalMedailles;
}
~~~
</details>

