# Tri générique

Soient les tableaux déclarés

~~~cpp
vector v      {6, 2, 8, 7, 1, 3};
array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
double t[ ] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
~~~

Trier ces tableaux en utilisant le tri par *sélection*.<br>
Les tableaux seront affichés avant et après le tri par le programme principal.

~~~
[6, 2, 8, 7, 1, 3]
[1, 2, 3, 6, 7, 8]

[chien, chat, souris, poisson]
[chat, chien, poisson, souris]

[6.1, 2.2, 8.3, 7.4, 1.5, 3.6]
[1.5, 2.2, 3.6, 6.1, 7.4, 8.3]
~~~

<details>
<summary>Solution</summary>

Intéressons nous d'abord à fonction d'affichage. La solution la plus simple
consiste à utiliser le tableau comme type générique. `Tableau` pourra 
alors être déduit comme `vector<int>` ou `array<string, 4>` par exemple.

~~~cpp
template <typename Tableau>
void afficher(const Tableau& s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}
~~~

Il faut noter que cela pose un problème lors de l'appel avec un tableau natif
en C, ces tableaux ne disposant pas de la méthode `.size()`. Dans ce cas,
il faut convertir explicitement le tableau natif en `span` lors de l'appel. 
Ce n'est pas rédhibitoire, convertir les tableaux natifs en `span` ou mieux
s'en passer complètement étant plutôt une bonne pratique en C++ moderne. 

~~~cpp
int main() {
   vector v      {6, 2, 8, 7, 1, 3};
   afficher(v);

   array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
   afficher(a);

   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   // afficher(t); ne compile pas car t.size(), utilisé par afficher(...), n'existe pas.
   afficher(span(t));
}
~~~

Une alternative possible consiste à spécifier que notre fonction n'affiche
que des "tableaux", i.e. des `std::span` en C++. Le type générique T est 
alors celui des éléments du tableau. La fonction `afficher` devient 

~~~cpp
template<typename T>
void afficher(span<T> s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}
~~~

Cependant, cela pose problème à l'appel. Par exemple, l'appel `afficher(v);` 
avec `v` un `vector<int>` ne fonctionne plus. En effet, cet appel devrait 
à la fois 

- convertir le `vector` en `span` 
- déduire que `T = int`

mais la déduction d'argument générique ne fonctionne qu'avec des types exacts, 
pas en combinaison avec des conversions. Il faudra donc écrire soit 
`afficher<int>(v)` qui déduit explicitement le type `T`, soit 
`afficher(span(v))` qui convertit explitement de `vector` à `span`

Pire, pour les `array` et les tableaux natifs, seule la version déduisant `T` fonctionne, i.e. 

- `afficher<string>(a);`
- `afficher<double>(t);`

Par contre, `afficher(span(a))` et `afficher(span(t))` ne compilent pas, parce
que l'on ne passe pas le bon type de `span`. 

- `span(a)` est de type `std::span<string, 4>` l'`array a` ayant 4 éléments
- `span(t)` est de type `std::span<double, 6>` le tableau `t` ayant 6 éléments
- le paramètre `span<T>` est de type `std::span<T, std::dynamic_extent>` avec la taille par défaut qui vaut `std::dynamic_extent`, i.e. `size_t(-1)`.  

Une manière plus propre d'écrire cette fonction serait plutôt la suivante

~~~cpp
template<typename T, size_t N>
void afficher(span<T, N> s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}
~~~

La taille `N` du `span<T,N>` peut alors être déduite lors de l'appel, ce
qui permet de faire l'appel simplement avec conversion explicite vers `span`

~~~cpp
int main() {
   vector v      {6, 2, 8, 7, 1, 3};
   afficher(span(v));  // T = int, N = std::dynamic_extent 

   array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
   afficher(span(a));  // T = std::string, N = 4

   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   afficher(span(t));  // T = double, N = 6
}
~~~

Notons enfin que l'on pourrait être tempté d'expliciter que la fonction afficher
ne vas pas modifier le contenu du `span` ainsi : 

~~~cpp
template<typename T, size_t N> void afficher(span<const T, N> s);
~~~

mais c'est une mauvaise idée : cela force à utiliser explicitement des 
`span<const ...>` lors des appels pour que T soit déductible. 

~~~cpp 
vector v      {6, 2, 8, 7, 1, 3};
afficher(span(v)); // ne compile pas : cannot deduce a type 
                   // for 'T' that would make 'const T' equal 'int'
afficher(span<const int>(v));  // compile 
~~~

Notons que la raison pour laquelle - dans le cas non-générique - on aurait 
préféré `void afficher(span<const int> s);` à `void afficher(span<int> s);`, 
est que cela permet de l'appeler indifféremment avec des paramètres
variables (i.e. `vector<int>`) ou constants (i.e. `const vector<int>`) 
plutôt que de la restreindre à des arguments variables. La même logique 
nous pousse dans le cas générique à préférer `void afficher(span<T, N> s);`
à `void afficher(span<const T, N> s);`, le second ne permettant la déduction
de `T` que pour des spans de constantes. 
`

Ayant donc opté pour passer nos tableaux sous forme de `span<T, N>`, on obtient
la solution suivante pour le problème complet. 

~~~cpp
#include <iostream>
#include <vector>
#include <array>
#include <span>

using namespace std;

template <typename T, size_t N>
size_t indice_min(span<T, N> s) {
   size_t i_min = 0;
   for (size_t i = 1; i < s.size(); ++i)
      if (s[i] < s[i_min])
         i_min = i;
   return i_min;
}

template<typename T, size_t N>
void tri(span<T, N> v) {
   for(size_t i = 0; i < v.size()-1; ++i) {
      size_t i_min = i + indice_min(v.subspan(i));
      swap(v[i], v[i_min]);
   }
}

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
   afficher(span(a)); tri(span(a)); afficher(span(v));
   
   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   afficher(span(t)); tri(span(t)); afficher(span(t));
}
~~~

Notons que l'on peut légitimement préférer une solution ou le tableau est
le type générique. La seule limitation que cela entraine est que le paramètre
de la fonction `tri` étant une référence, on doit lui passer une *lvalue*, et 
donc on ne peut faire l'appel `tri(span(t))`, qu'il faut remplacer par `span s(t); tri(s);`, 
mais comme noté précédemment, ne pas utiliser les tableaux natifs ou les encapsuler
de suite dans des `span` est une bonne pratique de toute manière.

~~~cpp
#include <cstdlib>
#include <iostream>
#include <span>
#include <array>
#include <vector>

using namespace std;

template<typename Tableau>
size_t indice_min(const Tableau& v ) {
   size_t i_min = 0;
   for (size_t i = 1; i < v.size(); ++i)
      if (v[i] < v[i_min])
         i_min = i;
   return i_min;
}

template<typename Tableau>
void tri(Tableau& v) {
   std::span s(v);  // pour pouvoir utiliser subspan
   for(size_t i = 0; i < v.size() - 1; ++i) {
      size_t i_min = i + indice_min(s.subspan(i));
      swap(v[i], v[i_min]);
   }
}

template <typename Tableau>
void afficher(const Tableau& s) {
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}

int main() {
   vector v      {6, 2, 8, 7, 1, 3};
   afficher(v); tri(v); afficher(v);

   array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
   afficher(a); tri(a); afficher(a);

   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   span s(t);
   afficher(s); tri(s); afficher(s);
}
~~~

La seule difficulté pour ce genre de code est si l'on a besoin de connaitre le type `T`
des éléments du tableau. Pour tous les conteneurs de la STL, on peut l'obtenir en ajoutant 
par exemple une ligne 

~~~cpp
using T = typename Tableau::value_type;
~~~

Pour être tout à fait complet, mais on va alors bien au delà de ce qui vous est demandé en PRG1, 
la solution la plus propre et moderne (C++20 minimum) serait sans doute 

~~~cpp
#include <cstdlib>
#include <iostream>
#include <span>
#include <array>
#include <vector>
#include <concepts>

template<typename T>
concept Container = requires(const T& c, size_t i) {
   { c.size() } -> std::convertible_to<size_t>;       
   { c[i] } -> std::common_reference_with<typename T::value_type&>; 
};

template<typename T>
concept ComparableContainer =
Container<T> and requires(const T& c, size_t i, size_t j) {
   { c[i] < c[j] } -> std::convertible_to<bool>;   
};

template<typename T>
concept PrintableContainer =
Container<T> and requires(const T& c, size_t i, std::ostream& os) {
   { os << c[i] };                                 
};

template<ComparableContainer Tableau>
size_t indice_min(const Tableau& v ) {
   size_t i_min = 0;
   for (size_t i = 1; i < v.size(); ++i)
      if (v[i] < v[i_min])
         i_min = i;
   return i_min;
}

template<ComparableContainer Tableau>
void tri(Tableau& v) {
   using std::swap;
   std::span s(v);  // pour pouvoir utiliser subspan
   for(size_t i = 0; i < v.size() - 1; ++i) {
      size_t i_min = i + indice_min(s.subspan(i));
      swap(v[i], v[i_min]);
   }
}

template <PrintableContainer Tableau>
void afficher(const Tableau& s) {
   using std::cout, std::endl;
   cout << "[";
   for (size_t i = 0; i < s.size(); ++i) {
      if (i) cout << ", ";
      cout << s[i];
   }
   cout << "]" << endl;
}

int main() {
   std::vector v {6, 2, 8, 7, 1, 3};
   afficher(v); tri(v); afficher(v);

   using namespace std::literals;
   std::array a {"chien"s, "chat"s, "souris"s, "poisson"s};
   afficher(a); tri(a); afficher(a);

   double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
   std::span s(t);
   afficher(s); tri(s); afficher(s);
}
~~~

</details>


