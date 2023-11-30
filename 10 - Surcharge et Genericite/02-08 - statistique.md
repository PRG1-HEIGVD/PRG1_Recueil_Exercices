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

template <typename T>
void afficher(span<const T> s) {
   cout << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]";
}

template <typename T>
T somme(span<const T> v) {
   T result = T();
   for (const T& t : v)
      result += t;
   return result;
}

template <typename T>
T moyenne(span<const T> v) {
   if (v.empty())
      return T();
   return somme<T>(v) / v.size();
}

template <typename T, typename Fct>
vector<T> vectStats(const vector<vector<T>>& v, Fct fct) {
   vector<T> stats;
   stats.reserve(v.size());
   for (const vector<T>& ligne : v)
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
   afficher<Data>(vectStats<Data>(notes, somme<Data>));
   cout << endl;

   cout << "moyenne : ";
   afficher<Data>(vectStats<Data>(notes, moyenne<Data>));

   cout << endl;
   return EXIT_SUCCESS;
}
~~~

-----------------------------------------------------

</details>