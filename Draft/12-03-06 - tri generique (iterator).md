# Tri générique par itérateur

Reprise de l'exercice [02-07 - tri generique (surcharge).md](../10%20-%20Surcharge%20et%20Genericite/02-07%20-%20tri%20generique%20(surcharge).md)

Soient les vectors déclarés

~~~cpp
vector vInt {6, 2, 9, 7, 1, 3};
vector vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
~~~

Implémenter un tri générique par sélection utilisant des itérateurs.

Par défaut, le tri se fait en ordonnant les valeurs par ordre croissant.<br>
Par parmètre générique, il doit être possible de trier de manière décroissante.

~~~
[6, 2, 9, 7, 1, 3]
[1, 2, 3, 6, 7, 9]

[6, 2, 9, 7, 1, 3]
[1, 2, 3, 6, 7, 9]

[chien, chat, souris, poisson]
[chat, chien, poisson, souris]
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <numeric>
#include <functional>

using namespace std;

template <typename T>
ostream& operator<< (ostream& os, span<T> s) {
   os << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) os << ", ";
      os << s[i];
   }
   return os << "]";
}

template <typename Iterator, typename Comp>
void tri_selection(Iterator first, Iterator last,
                   Comp comp = less<typename Iterator::value_type>()) {
   for (Iterator it = first; it != last; ++it)
      swap(*it, *min_element(it, last, comp));
}

int main() {

   vector vInt {6, 2, 9, 7, 1, 3};
   cout << span(vInt) << endl;
//   tri_selection<vector<int>::iterator, less<int> >(vInt.begin(), vInt.end());
   tri_selection(vInt.begin(), vInt.end());
   cout << span(vInt) << endl;

   vector vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
   cout << span(vStr) << endl;
   tri_selection<vector<string>::iterator, less<string> >(vStr.begin(), vStr.end());
   cout << span(vStr) << endl;
}
~~~
</details>


