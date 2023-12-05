# Surcharge et spécialisation

Sans utiliser ni l’instruction if, ni l’opérateur ternaire ?:, complétez le code ci-dessous en
définissant les fonctions afficher, opposer et operator<< , qui prennent des `array<T,n>` 
en paramètre, ainsi que leurs spécialisation et surcharges éventuelles, pour que l’exécution 
du programme suivant affiche

~~~
-42 4294967254 false true 3.14
[ vide ]
[ 1, 2, 3, 4 ]
[ -1, -2, -3, -4 ]
[ vide ]
[ vrai, faux, faux, vrai, vrai ]
[ faux, vrai, vrai, faux, faux ]
[ vide ]
[ 1.61, 2.72, 3.14 ]
[ -1.61, -2.72, -3.14 ]
~~~

~~~cpp
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const char* BOOL_EN_FRANCAIS [] = { "faux", "vrai" };

// A COMPLETER ICI

int main() {

    cout << opposer(42) << " "
         << opposer(42u) << " "
         << boolalpha << opposer(true) << " "
         << opposer(false) << " "
         << opposer(-3.14) << endl;

    array<int,0> a0;                                      cout << a0 << endl;

    array<int, 4> a4 { 1, 2, 3,  4 };                     cout << a4 << endl;
    transformer(a4, opposer<int>);                        cout << a4 << endl;

    array<bool,0> b0;                                     cout << b0 << endl;

    array<bool, 5> b5 { true, false, false, true, true }; cout << b5 << endl;
    transformer(b5, opposer<bool>);                       cout << b5 << endl;

    array<double,0> c0;                                   cout << c0 << endl;

    array<double, 3> c3 { 1.61, 2.72, 3.14 };             cout << c3 << endl;
    transformer(c3, opposer<double>);                     cout << c3 << endl;
}
~~~


<details>
<summary>Solution transformer</summary>

La fonction prend un `array<T,n>` et une fonction en paramètre, ce qui requiert 3 
arguments génériques. `array<T,N>& a` doit être passé par référence car il est modifié. 
La boucle `for(T& t : a)` doit prendre une référence à `t` pour pouvoir le modifier

~~~cpp
template<typename T, size_t N, typename Fn>
void transformer(array<T,N>& a, Fn f) {
   for(T& t : a)
      t = f(t);
}
~~~

-----------------------------------------------------

</details>

<details>
<summary>Solution opposer</summary>

La solution la plus simple consiste a écrire une fonction générique qui utilise 
l'opérateur unaire `-`, et à la spécialiser pour le type `bool` qui utilise 
l'opérateur `not`. 

~~~cpp
template<typename T>
T opposer(T a) {
   return -a;
}

template<> bool opposer<bool>(bool a) {
   return not a;
}
~~~

En utilisant la déduction d'argument, la spécialisation pourrait aussi s'écrire 

~~~cpp
template<> bool opposer<>(bool a);
~~~

ou

~~~cpp
template<> bool opposer(bool a);
~~~

-----------------------------------------------------

</details>


<details>
<summary>Solution operator affichage </summary>

On écrit une version générique qui affiche des `array<T,n>` 
et on la **surcharge** pour les 2 cas particulier `array<bool,n>`
et `array<T,0>`. Comme cela crée une ambiguité pour l'appel 
avec `array<bool,0>`, on ajoute une surcharge supplémentaire
pour ce cas particulier avec une fonction non générique.

~~~cpp
template<typename T, size_t N>
ostream& operator<<(ostream& os, array<T,N> const& a) {
   os << "[ ";
   for(T const& e : a)
      os << e << ", ";
   os << "\b\b ]";
   return os;
}

template<size_t N>
ostream& operator<<(ostream& os, array<bool,N> const& a) {
   os << "[ ";
   for(bool e : a)
      os << BOOL_EN_FRANCAIS[e] << ", ";
   os << "\b\b ]";
   return os;
}

template<typename T>
ostream& operator<<(ostream& os, array<T,0> const& a) {
   os << "[ vide ]";
   return os;
}

ostream& operator<<(ostream& os, array<bool,0> const& a) {  // lève l'ambiguité
   return operator<< <bool>(os,a);
}
~~~

-----------------------------------------------------

</details>