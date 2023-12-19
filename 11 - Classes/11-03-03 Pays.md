# Pays
1. Implémenter une classe Pays permettant de stocker le nom, le nombre d'habitants (en millions d'habitants) ainsi que la superficie (en $`km^2`$) d'un pays.

2. A l'aide de la classe Pays, écrire un programme C++ qui, à partir d'un ensemble de pays donnés (codé "en dur"), affiche :
- le pays ayant la plus grande superficie
- le pays le plus peuplé
- le pays ayant __la densité de population__ la plus élevée

Pour les pays suivants (nom, population, superficie), 
~~~text
Suisse, 8.121830, 41290
France, 66.663766, 547030
Italie, 61.855120, 301230
Allemagne, 80.854408, 357021
~~~

votre programme affichera le résultat ci-après :

~~~text
Pays ayant la plus grande superficie               : France
Pays ayant le plus d'habitants                     : Allemagne
Pays ayant la densite de population la plus grande : Allemagne
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------
class Pays {
public:
   // Constructeur
   Pays(const string& nom, double population, int superficie);
   
   // getters
   string get_nom()        const { return nom; }
   double get_population() const { return population; }
   int    get_superficie() const { return superficie; }
   
   // setters
   void set_population(double population);
   void set_superficie(int superficie);
   // pas de setter pour le nom, qui ne change a priori pas
   
   // Autres
   double calcule_densite_population() const;
   
private:
   string nom;          // nom du pays
   double population;   // en mio d'habitants
   int superficie;      // en km2
};
// ---------------------------------------------------------------------------

int main() {
   vector<Pays> v_pays{
           Pays("Suisse", 8.121830, 41290),
           Pays("France", 66.663766, 547030),
           Pays("Italie", 61.855120, 301230),
           Pays("Allemagne", 80.854408, 357021)
   };

   size_t idx_max_superficie = 0; 
   size_t idx_max_population = 0;
   size_t idx_max_densite = 0;

   for (size_t i = 0; i < v_pays.size(); ++i){
      if (v_pays[i].get_superficie() > v_pays[idx_max_superficie].get_superficie()) {
         idx_max_superficie = i;
      }
      if (v_pays[i].get_population() > v_pays[idx_max_population].get_population()) {
         idx_max_population = i;
      }
      if (v_pays[i].calcule_densite_population() > v_pays[idx_max_densite].calcule_densite_population()) {
         idx_max_densite = i;
      }
   }
   cout << "Pays ayant la plus grande superficie               : "
        << v_pays[idx_max_superficie].get_nom()
        << endl
        << "Pays ayant le plus d'habitants                     : "
        << v_pays[idx_max_population].get_nom()
        << endl
        << "Pays ayant la densite de population la plus grande : "
        << v_pays[idx_max_densite].get_nom()
        << endl;
}

// ---------------------------------------------------------------------------

Pays::Pays(const string& nom, double population, int superficie)
        : nom(nom), population(population), superficie(superficie) {
}

void Pays::set_population(double population) {
   this->population = population;
}

void Pays::set_superficie(int superficie) {
   this->superficie = superficie;
}

double Pays::calcule_densite_population() const {
   return population * 1E6 / superficie;
}
// ---------------------------------------------------------------------------
~~~
</details>
