# Tri générique (surcharge)

Reprise de l'exercice [02-04 - tri generique.md](../10%20-%20Surcharge%20et%20Genericite/02-04%20-%20tri%20generique.md)

Soient les vectors déclarés

~~~cpp
vector<int> v1 {6, 2, 9, 7, 1, 3};
const vector<int>    vInt {6, 2, 9, 7, 1, 3};
const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
~~~

Tout en étant capable de trier un **tableau non constant**, par exemple un *vector\<int\>*, écrire les fonctions permettant d'afficher les deux **vecteurs constants** de manière triée.

⚠️ Les éléments stockés dans les vecteurs occupent potentiellement beaucoup de mémoire.

~~~
[6, 2, 9, 7, 1, 3]
[1, 2, 3, 6, 7, 9]

[6, 2, 9, 7, 1, 3]
[1, 2, 3, 6, 7, 9]

[chien, chat, souris, poisson]
[chat, chien, poisson, souris]
~~~

## Indices

1. Un vecteur constant ne peut pas être modifié.<br>
2. Copier un vecteur n'est pas une option du point de vue de l'utilisation de la mémoire.<br>
3. Nous pouvons créer un **vecteur de pointeurs** sur les éléments du vecteur constant à trier. Ce seront les pointeurs qui seront réorganisés pour voir les valeurs pointées de manière triée.

**NB** : Il n'est pas possible de créer un tableau de références, elles seraient d'ailleurs toujours associées au même élément. Un tableau d'itérateurs serait possible et même mieux, mais pas encore vu.

Vecteur constant de valeurs

|Indice|  0  |  1  |  2  |  3  |  4  |  5  |
|:----:|:---:|:---:|:---:|:---:|:---:|:---:|
| val  |  6  |   2 |  9  |  7  |  1  |  3  |
| adr  | 0x00| 0x04| 0x08| 0x0B| 0x0F| 0x14|

Vecteur de pointeurs

|Indice|  0  |  1  |  2  |  3  |  4  |  5  |
|:----:|:---:|:---:|:---:|:---:|:---:|:---:|
| val  | 0x0F| 0x04| 0x14| 0x00| 0x0B| 0x08|


<details>
<summary>Solution 1</summary>

En surchargeant pour T* les fonctions `afficher` et `indice_min`.
Notons que comme expliqué dans la solution de l'[exercice 02-04](02-04%20-%20tri%20generique.md), 
on passe les tableaux sous forme de `span<T, N>`. 

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <span>

using namespace std;

template<typename T, size_t N>
void afficher(span<T, N> v) {
   cout << "[";
   for (size_t i = 0; i < v.size(); ++i) {
      if (i) cout << ", ";
      cout << v[i];
   }
   cout << "]";
}

template<typename T, size_t N>
void afficher(span<T*, N> v) {
   cout << "[";
   for (size_t i = 0; i < v.size(); ++i) {
      if (i) cout << ", ";
      cout << *(v[i]);
   }
   cout << "]";
}

template<typename T, size_t N>
size_t indice_min(span<T, N> v) {
   size_t iMin = 0;
   for (size_t i = 1; i < v.size(); ++i)
      if (v[i] < v[iMin])
         iMin = i;
   return iMin;
}

template<typename T, size_t N>
size_t indice_min(span<T*, N> v) {
   size_t iMin = 0;
   for (size_t i = 1; i < v.size(); ++i)
      if (*v[i] < *v[iMin])
         iMin = i;
   return iMin;
}

template<typename T, size_t N>
void tri_par_selection(span<T, N> v) {
   for (size_t i = 0; i < v.size() - 1; ++i) {
      size_t imin = i + indice_min(v.subspan(i));
      swap(v[i], v[imin]);
   }
}

template<typename T, size_t N>
vector<const T*> make_pointers_to_span_data(span<T, N> v) {
   vector<const T*> w;
   w.reserve(v.size());
   for (const T& e: v) {
      w.push_back(&e);
   }
   return w;
}

int main() {
   vector<int> v1{6, 2, 9, 7, 1, 3};
   span s1(v1);
   afficher(s1); cout << endl;
   tri_par_selection(s1);
   afficher(s1); cout << endl << endl;

   const vector<int> v2{6, 2, 9, 7, 1, 3};
   vector vp2 = make_pointers_to_span_data(span(v2));
   span s2(vp2);
   afficher(s2); cout << endl;
   tri_par_selection(s2);
   afficher(s2); cout << endl << endl;

   const vector<string> v3{"chien"s, "chat"s, "souris"s, "poisson"s};
   vector vp3 = make_pointers_to_span_data(span(v3));
   span s3(vp3);
   afficher(s3); cout << endl;
   tri_par_selection(s3);
   afficher(s3); cout << endl << endl;
}
~~~
</details>

<details>
<summary>Solution 2 (meilleure)</summary>

On peut éviter de dupliquer le code des fonctions `afficher` et `indice_min` en se rendant 
compte qu'elles ne diffèrent l'une et l'autre que part la manière dont elles interprètent 
la valeur d'un élément selon qu'il est `T` ou `T*`. Dès lors, écrivons et surchargeons 
une fonction valeur qui sera appelée par ces 2 fonctions. 

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <span>

using namespace std;

template <typename T>
const T& valeur(T const& t) {
   return t;
}

template <typename T>
const T& valeur(T* t) {
   return *t;
}

template<typename T, size_t N>
void afficher(span<T, N> v) {
   cout << "[";
   for (size_t i = 0; i < v.size(); ++i) {
      if (i) cout << ", ";
      cout << valeur(v[i]);
   }
   cout << "]";
}

template<typename T, size_t N>
size_t indice_min(span<T, N> v) {
   size_t iMin = 0;
   for (size_t i = 1; i < v.size(); ++i)
      if (valeur(v[i]) < valeur(v[iMin]))
         iMin = i;
   return iMin;
}

//---------------------------------------------
template<typename T, size_t N>
void tri_par_selection(span<T, N> v) {
   for (size_t i = 0; i < v.size() - 1; ++i) {
      size_t imin = i + indice_min(v.subspan(i));
      swap(v[i], v[imin]);
   }
}

//---------------------------------------------
template<typename T, size_t N>
vector<const T*> make_pointers_to_span_data(span<T, N> v) {
   vector<const T*> w;
   w.reserve(v.size());
   for (const T& e: v) {
      w.push_back(&e);
   }
   return w;
}

//---------------------------------------------
int main() {
   vector<int> v1{6, 2, 9, 7, 1, 3};
   span s1(v1);
   afficher(s1); cout << endl;
   tri_par_selection(s1);
   afficher(s1); cout << endl << endl;

   const vector<int> v2{6, 2, 9, 7, 1, 3};
   vector vp2 = make_pointers_to_span_data(span(v2));
   span s2(vp2);
   afficher(s2); cout << endl;
   tri_par_selection(s2);
   afficher(s2); cout << endl << endl;

   const vector<string> v3{"chien"s, "chat"s, "souris"s, "poisson"s};
   vector vp3 = make_pointers_to_span_data(span(v3));
   span s3(vp3);
   afficher(s3); cout << endl;
   tri_par_selection(s3);
   afficher(s3); cout << endl << endl;
}
~~~
</details>


