# Statistique

Soient les déclarations.

~~~cpp
using Data    = double;
using Ligne   = vector<Data>;
using Matrice = vector<Ligne>;

const Matrice notes {{4.0, 5.0, 6.0},  // Jean
                     {4.1, 5.1, 4.8},  // Marie
                     {3.5, 4.1     },  // Joshua
                     {4.5, 4.5, 4.6}}; // Ali
~~~

Ecrire le code générique nécessaire afin de créer un vecteur contenant la somme des notes de chacun ou la moyenne de chacun.

~~~
somme   : [15.0, 14.0, 7.6, 13.6]
moyenne : [5.0, 4.7, 3.8, 4.5]
~~~

**Important**

- ne pas utiliser la librairie \<algorithm\> dans cet exercice.
- Utiliser la généricité autant que possible afin de maximiser la réutilisation des fonctions créées.

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <vector>
#include <span>
#include <iomanip>

using namespace std;

template <typename T, size_t N>
void afficher(span<T, N> s) {
   cout << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]";
}

template <typename T, size_t N>
T somme(span<T, N> v) {
   auto result = T{};
   for (const T& t : v)
      result += t;
   return result;
}

template <typename T, size_t N>
T moyenne(span<T, N> v) {
   if (v.empty())
      return T{};
   return somme(v) / v.size();
}

template <typename T, typename Fct>
vector<T> vectStats(const vector<vector<T>>& v, Fct fct) {
   vector<T> stats;
   stats.reserve(v.size());
   for (auto& ligne : v)
      stats.push_back(fct(ligne));
   return stats;
}

using Data    = double;
using Ligne   = vector<Data>;
using Matrice = vector<Ligne>;

int main() {

   const Matrice notes {{4.0, 5.0, 6.0},  // Jean
                        {4.1, 5.1, 4.8},  // Marie
                        {3.5, 4.1     },  // Joshua
                        {4.5, 4.5, 4.6}}; // Ali

   cout << fixed << setprecision(1);

   cout << "somme   : ";
   vector sommes = vectStats(notes, somme<const Data, std::dynamic_extent>);
   afficher(span(sommes));
   cout << endl;

   cout << "moyenne : ";
   vector moyennes = vectStats(notes, moyenne<const Data, std::dynamic_extent>);
   afficher(span(moyennes));
   cout << endl;
}
~~~

-----------------------------------------------------

</details>