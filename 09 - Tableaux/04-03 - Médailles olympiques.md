# Médailles olympiques

Soit le tableau suivant, donnant le nombre de médailles d'or, d'argent et de bronze obtenues par pays en patinage aux Jeux olympiques d'hiver.

| Pays       | Or     | Argent | Bronze |
|------------|:------:|:------:|:------:|
| Allemagne  |   0    |   0    |   2    |
| Canada     |   1    |   0    |   1    |
| Chine      |   1    |   2    |   0    |
| Corée      |   1    |   0    |   0    |
| Etats-Unis |   2    |   1    |   1    |
| Japon      |   0    |   1    |   1    |
| Russie     |   0    |   1    |   0    |

Ecrire un programme C++ mettant à disposition :

- une fonction retournant le nombre total de médailles obtenues par un pays donné
- une fonction retournant le nombre total de médailles d'un type donné obtenues par l'ensemble des pays (par ex le nombre total de médailles d'or obtenues par l'ensemble des pays)
- … et bien sûr une fonction *main* permettant de tester les 2 fonctions précédentes.

**NB** Le tableau des médailles ci-dessus est à implémenter sous la forme d'un array bidimensionnel (2D).<br>Utilisez intensément les alias de type pour clarifier votre code.   

<details>
<summary>Solution</summary>

~~~cpp
#include <array>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const array PAYS {"Allemagne", "Canada", "Chine", "Coree",
                  "Etats-Unis", "Japon", "Russie"};
const int W_PAYS_MAX {10}; // plus long nom de pays

const array METAUX {"Or", "Argent", "Bronze"};
const int W_METAL_MAX {6}; // plus long nom de metal

using Nombre_de_medailles = unsigned short;
using Pays = size_t;
using Metal = size_t;

using Medailles_du_pays = array<Nombre_de_medailles, METAUX.size()>;
using Tableau_des_medailles = array<Medailles_du_pays, PAYS.size()>;

Nombre_de_medailles total_medailles_pays(
        const Tableau_des_medailles& medailles,
        Pays pays);

Nombre_de_medailles total_medailles_metal(
        const Tableau_des_medailles& medailles,
        Metal metal);

inline auto pluriel(unsigned n) { return n >= 2 ? "s" : ""; }

int main() {

   const Tableau_des_medailles tableau_des_medailles
           { Medailles_du_pays{0, 0, 2},
             Medailles_du_pays{1, 0, 1},
             Medailles_du_pays{1, 2, 0},
             Medailles_du_pays{1, 0, 0},
             Medailles_du_pays{2, 1, 1},
             Medailles_du_pays{0, 1, 1},
             Medailles_du_pays{0, 1, 0} };

   // Nombre total de médailles obtenues par chacun des pays

   for (Pays pays{0}; pays < PAYS.size(); ++pays) {
      const string& nom_du_pays { PAYS.at(pays) };
      Nombre_de_medailles nb_medailles { total_medailles_pays(tableau_des_medailles, pays) };

      cout << setw(W_PAYS_MAX) << left << nom_du_pays << " : "
           << nb_medailles << " medaille" << pluriel(nb_medailles)
           << endl;
   }
   cout << endl;

   // Nombre total de médailles d'or, d'argent et de bronze obtenues
   // par l'ensemble des pays

   for (Metal metal{0}; metal < METAUX.size(); ++metal) {
      const string& nom_du_metal { METAUX.at(metal) };
      Nombre_de_medailles nb_medailles { total_medailles_metal(tableau_des_medailles, metal)};

      cout << setw(W_METAL_MAX) << left << nom_du_metal << " : "
           << nb_medailles << " medaille" << pluriel(nb_medailles)
           << endl;
   }
}

Nombre_de_medailles total_medailles_pays(
        const Tableau_des_medailles & tableau_des_medailles,
        Pays pays)
{
   Nombre_de_medailles cnt{0};
   const Medailles_du_pays& medailles_du_pays = tableau_des_medailles.at(pays);
   for (Nombre_de_medailles nb : medailles_du_pays) {
      cnt += nb;
   }
   return cnt;
}

Nombre_de_medailles total_medailles_metal(
        const Tableau_des_medailles & tableau_des_medailles,
        Metal metal)
{
   Nombre_de_medailles cnt{0};
   for (Pays pays{0}; pays < PAYS.size(); ++pays) {
      cnt += tableau_des_medailles.at(pays).at(metal);
   }
   return cnt;
}
~~~
</details>

