# Tri générique (itérateur)

## ne compile pas encore ... à termine

Reprise de l'exercice [02-07 - tri generique (surcharge).md](../10%20-%20Surcharge%20et%20Genericite/02-07%20-%20tri%20generique%20(surcharge).md)

Soient les vectors déclarés

~~~cpp
vector<int> v1{6, 2, 9, 7, 1, 3};

const vector<int>    vInt {6, 2, 9, 7, 1, 3};
const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
~~~

Utiliser cette fois un array d'itérateur et la généricité.

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

template <typename T>
void afficher_element(const T& t) { cout << t; }

template <typename T>
void afficher_element(typename span<T>::iterator it) { cout << *it; }

template <typename T>
bool operator< (const T& a, const T& b) { return  a <  b; }

template <typename T>
bool operator< (const T *a, const T *b) { return *a < *b; }

template <typename T>
void afficher_span (span<T> s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      afficher_element(s[i]);
   }
   cout << "]";
}

template <typename T>
size_t indice_min(span<T> v) {
   size_t iMin = 0;
   for (size_t i=1; i<v.size(); ++i)
      if (v[i] < v[iMin])
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

   return vIter;
}

int main() {

   vector<int> v1{6, 2, 9, 7, 1, 3};
   span s1(v1);
   afficher_span(s1); cout << endl;
   tri_par_selection(s1);
   afficher_span(s1); cout << endl;

   const vector<int> v_int{6, 2, 9, 7, 1, 3};
   auto v_iter_int = vecteur_de_iterateurs<vector<int>::const_iterator>(span(v_int));
   span s_iter_int(v_iter_int);
   afficher_span(s_iter_int);
   cout << endl;
   tri_par_selection(s_iter_int);
   afficher_span(s_iter_int);
   cout << endl;

//   const vector<string> v_string{"chien"s, "chat"s, "souris"s, "poisson"s};
//   auto v_iter_string = vecteur_de_iterateurs<vector<string>::const_iterator>(span(v_string));
//   span s_iter_string(v_iter_string);
//   afficher_span(s_iter_string);
//   cout << endl;
//   tri_par_selection(s_iter_string);
//   afficher_span(s_iter_string);
//   cout << endl << endl;
}
~~~
</details>


