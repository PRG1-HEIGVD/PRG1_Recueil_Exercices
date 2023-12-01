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

<details>
<summary>💡Indice</summary>

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

</details>

<details>
<summary>Solution 1</summary>

En surchargeant pour T* les fonctions `afficher`, `indice_min` et `tri_par_selection` 

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <span>

using namespace std;

//---------------------------------------------
template <typename T>
void afficher(span<const T> v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i) cout << ", ";
      cout << v[i];
   }
   cout << "]";
}

template <typename T>
void afficher(const vector<T*>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i) cout << ", ";
      cout << *(v[i]);
   }
   cout << "]";
}

//---------------------------------------------
template <typename T>
size_t indice_min(span<const T> v) {
   size_t iMin = 0;
   for (size_t i=1; i<v.size(); ++i)
      if (v[i] < v[iMin])
         iMin = i;
   return iMin;
}

template <typename T>
size_t indice_min(span<T*> v) {
   size_t iMin = 0;
   for (size_t i=1; i<v.size(); ++i)
      if (*v[i] < *v[iMin])
         iMin = i;
   return iMin;
}

//---------------------------------------------
template <typename T>
void tri_par_selection(span<T> v) {
   for (size_t i = 0; i < v.size()-1 ; ++i) {
    size_t imin = i + indice_min<T>(v.subspan(i));
      swap(v[i], v[imin]);
   }
}

template <typename T>
void tri_par_selection(span<T*> v) {
   for (size_t i = 0; i < v.size()-1 ; ++i) {
      size_t imin = i + indice_min<T>(v.subspan(i));
      swap(v[i], v[imin]);
   }
}

//---------------------------------------------
template <typename T>
vector<const T*> tab_to_vectPtr(span<const T> v) {
   vector<const T*> vPtr;
   vPtr.reserve(v.size());
   for (const T& e : v) {
      vPtr.push_back(&e);
   }
   return vPtr;
}

//---------------------------------------------
int main() {
   vector<int> v1 {6, 2, 9, 7, 1, 3};

   const vector<int>    vInt {6, 2, 9, 7, 1, 3};
   const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};

   afficher<const int>(v1);   cout << endl;
   tri_par_selection<int>(v1);
   afficher<const int>(v1);   cout << endl;
   cout << endl;

   vector<const int*> vPtrInt = tab_to_vectPtr<const int>(vInt);
   afficher(vPtrInt);   cout << endl;
   tri_par_selection<const int>(vPtrInt);
   afficher(vPtrInt);   cout << endl;
   cout << endl;

   vector<const string*> vPtrStr = tab_to_vectPtr<const string>(vStr);
   afficher(vPtrStr);   cout << endl;
   tri_par_selection<const string>(vPtrStr);
   afficher(vPtrStr);   cout << endl;
   cout << endl;
}
~~~

</details>

<details>
<summary>Solution 2</summary>

Avec une seule version des fonctions `afficher`, `indice_min` et `tri_par_selection`, 
mais qui appellent des fonctions `afficher_element` et `comparer` surchargées. 

Dans cette version, on évite aussi de devoir spécifier l'argument générique lors des 
appels à `afficher`, `indice_min` et `tri_par_selection` en leur passant explicitement
des `std::span` plutôt que des `std::vector`, ce qui permet à la déduction d'arguments 
génériques de fonctionner. 

Enfin, on n'utilise toujours `span<T>` comme type de paramètre plutôt que `span<const T>`
qui est inutilement complexe. `span<T>` est appelable par `span<const int>` avec 
déduction de `T = const int`. Il n'est pas nécessaire et plus simple de ne pas écrire le 
`const` dans ce cas. 

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <span>

using namespace std;

template <typename T> void afficher_element(T const& t) { cout << t; }
template <typename T> void afficher_element(const T *t) { cout << *t; }

template <typename T>
void afficher_span(span<T> v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i) cout << ", ";
      afficher_element(v[i]);
   }
   cout << "]";
}

template <typename T> bool comparer(const T& a, const T& b) { return a < b; }
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

template <typename T>
vector<const T*> vecteur_de_const_pointeurs(span<T> v) {
   vector<const T*> vPtr;
   vPtr.reserve(v.size());
   for (const T& e : v) {
      vPtr.push_back(&e);
   }
   return vPtr;
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
   auto vPtrInt = vecteur_de_const_pointeurs(span(vInt));
   span sPtrInt(vPtrInt);
   afficher_span(sPtrInt);
   cout << endl;
   tri_par_selection(sPtrInt);
   afficher_span(sPtrInt);
   cout << endl << endl;

   const vector<string> vStr{"chien"s, "chat"s, "souris"s, "poisson"s};
   auto vPtrStr = vecteur_de_const_pointeurs(span(vStr));
   span sPtrStr(vPtrStr);
   afficher_span(sPtrStr);
   cout << endl;
   tri_par_selection(sPtrStr);
   afficher_span(sPtrStr);
   cout << endl << endl;
}
~~~
</details>


