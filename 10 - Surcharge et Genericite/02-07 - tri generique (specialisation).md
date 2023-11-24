# Tri générique (spécialisation)

Reprise de l'exercice [02-04 - tri generique.md](../10%20-%20Surcharge%20et%20Genericite/02-04%20-%20tri%20generique.md)

Soient les vectors déclarés

~~~cpp
vector<int> v1 {6, 2, 9, 7, 1, 3};

const vector<int>    vInt {6, 2, 9, 7, 1, 3};
const vector<string> vStr {"chien"s, "chat"s, "souris"s, "poisson"s};
~~~

Tout en étant capable de trier le *vector\<int\>* **non constant**, écrire les fonctions permettant d'afficher les deux **vecteurs constants** de manière triée.

⚠️ Les vecteurs occupent potentiellement beaucoup de mémoire.

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
3. Nous pouvons créer un **vecteur de pointeurs** sur les éléments du vecteur constant à trier.<br>Ce seront les pointeurs qui seront réorganisés pour voir les valeurs pointées de manière triée.<br>
**NB** : Malheureusement, il n'est pas possible de créer un tableau de références.


	Vecteur constant de valeurs
	
	|  0  |  1  |  2  |  3  |  4  |  5  |
	|:---:|:---:|:---:|:---:|:---:|:---:|
	|  6  |   2 |  9  |  7  |  1  |  3  |
	| 0x00| 0x04| 0x08| 0x0B| 0x0F| 0x14|
	
	Vecteur de pointeurs
	
	|  0  |  1  |  2  |  3  |  4  |  5  |
	|:---:|:---:|:---:|:---:|:---:|:---:|
	| 0x0F| 0x04| 0x14| 0x00| 0x0B| 0x08|

</details>

<details>
<summary>Solution</summary>

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


