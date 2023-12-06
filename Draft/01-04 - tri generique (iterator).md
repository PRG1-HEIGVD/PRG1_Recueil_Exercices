# Tri générique (itérateur)

## ne compile pas encore ... à termine(GMB)

Reprise de l'exercice [02-07 - tri generique (surcharge).md](../10%20-%20Surcharge%20et%20Genericite/02-07%20-%20tri%20generique%20(surcharge).md)

Soient les vectors déclarés

~~~cpp
vector<int> v1{6, 2, 9, 7, 1, 3};

const vector<int>    vInt {6, 2, 9, 7, 1, 3};
const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
~~~

Utiliser cette fois un array d'térateur

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

using namespace std;

template <typename T> void afficher_element(T const& t) { cout << t; }
template <typename T> void afficher_element(const T* t) { cout << *t; }

template <typename T>
void afficher_span(span<T> v) {
   cout << "[";
//   for (auto it = v.begin(); it != v.end(); ++it) {
//      if (it != v.begin()) cout << ", ";
//      afficher_element(it);
//   }
   for (size_t i=0; i<v.size(); ++i) {
      if (i) cout << ", ";
      afficher_element(v[i]);
   }
}

template <typename T> bool comparer(const T& a, const T& b) { return  a <  b; }
template <typename T> bool comparer(const T *a, const T *b) { return *a < *b; }

template <typename T>
size_t indice_min(span<T> v) {
   size_t iMin = 0;
   for (size_t i=1; i<v.size(); ++i)
      if (comparer(v[i],v[iMin]))
         iMin = i;
   return iMin;
}

template <typename T>
void tri_par_selection(span<T> v) {
   for (size_t i = 0; i < v.size()-1 ; ++i) {
      size_t imin = i + indice_min(v.subspan(i));
      swap(v[i], v[imin]);
   }
}

template <typename Iterator, typename T>
vector<Iterator> vecteur_de_iterateurs(span<T> v) {
   vector<Iterator> vIter;
   vIter.reserve(v.size());

   for (Iterator it = v.begin(); it != v.end(); ++it)
      vIter.push_back(it);
//
//   for (const T& e : v) {
//      vPtr.push_back(&e);
//   }
   return vIter;
}

int main() {
   vector<int> v1{6, 2, 9, 7, 1, 3};
   span s1(v1);
   afficher_span(s1);
   cout << endl;
   tri_par_selection(s1);
   afficher_span(s1);
   cout << endl << endl;

   const vector<int> vInt{6, 2, 9, 7, 1, 3};
   auto vIterInt = vecteur_de_iterateurs<vector<int>::const_iterator>(span(vInt));
   span sPtrInt(vIterInt);
   afficher_span(sPtrInt);
   cout << endl;
   tri_par_selection(sPtrInt);
   afficher_span(sPtrInt);
   cout << endl << endl;

   const vector<string> vStr{"chien"s, "chat"s, "souris"s, "poisson"s};
   auto vIterStr = vecteur_de_iterateurs<vector<string>::const_iterator>(span(vStr));
   span sPtrStr(vPtrStr);
   afficher_span(sPtrStr);
   cout << endl;
   tri_par_selection(sPtrStr);
   afficher_span(sPtrStr);
   cout << endl << endl;
}
~~~
</details>


