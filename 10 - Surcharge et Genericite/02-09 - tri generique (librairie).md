# Tri générique (compilation séparée)

Reprise de l'exercice [02-04 - tri generique.md](../10%20-%20Surcharge%20et%20Genericite/02-04%20-%20tri%20generique.md)

Soient les tabeaux déclarés

~~~cpp
vector v      {6, 2, 8, 7, 1, 3};
array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
double t[ ] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
~~~

Trier ces tableaux en utilisant le tri par *sélection*.<br>
Les tableaux seront affichés avant et après le tri par le programme principal.

**Les sous-programmes utiles au tri seront placés dans un fichier séparé "Tri.h"**.

~~~
[6, 2, 8, 7, 1, 3]
[1, 2, 3, 6, 7, 8]

[chien, chat, souris, poisson]
[chat, chien, poisson, souris]

[6.1, 2.2, 8.3, 7.4, 1.5, 3.6]
[1.5, 2.2, 3.6, 6.1, 7.4, 8.3]
~~~

<details>
<summary>Solution - main</summary>

~~~cpp
#include <iostream>
#include <vector>
#include <array>
#include <span>
#include "Tri.h"

using namespace std;

template<typename T, size_t N>
void afficher(span<T, N> s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}

int main() {
   vector v      {6, 2, 8, 7, 1, 3};
   afficher(span(v)); tri(span(v)); afficher(span(v));

   array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
   afficher(span(a)); tri(span(a)); afficher(span(a));

   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   afficher(span(t)); tri(span(t)); afficher(span(t));
}
~~~

</details>


<details>
<summary>Solution - Tri.h</summary>

~~~cpp
#ifndef TRI_H
#define TRI_H

#include <span>     // std::span , std::size_t 
#include <utility>  // std::swap

template <typename T, size_t N>
size_t indice_min(std::span<T, N> s) {
   size_t i_min = 0;
   for (size_t i = 1; i < s.size(); ++i)
      if (s[i] < s[i_min])
         i_min = i;
   return i_min;
}

template<typename T, size_t N>
void tri(std::span<T, N> v) {
   using std::swap;
   for(size_t i = 0; i < v.size()-1; ++i) {
      size_t i_min = i + indice_min(v.subspan(i));
      swap(v[i], v[i_min]);
   }
}
#endif
~~~

</details>
