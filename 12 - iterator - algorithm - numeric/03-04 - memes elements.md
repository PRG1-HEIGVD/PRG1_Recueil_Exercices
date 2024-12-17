# Mêmes éléments

Ecrire une fonction `meme_elements` qui reçoit deux tableaux en paramètre de type `<T>` et retourne `true` si les deux tableaux contiennent les même éléments et `false` dans le cas contraire.

- l'ordre n'a pas d'importance
- les valeurs à double sont possibles

Les deux tableaux ci-dessous ont les même éléments

~~~cpp
array  a {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <span>

using namespace std;

//---------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, span<T> s) {
   os << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) os << ", ";
      os << s[i];
   }
   return os << "]";
}

//---------------------------------------------------------
template <typename T>
bool tab_contient_val(const T& e, span<T> tab) {
   return find(tab.begin(), tab.end(), e) != tab.end();
}

//---------------------------------------------------------
template <typename T>
bool meme_elements(span<T> tab1, span<T> tab2) {

   for (const T& e : tab1)
      if (not tab_contient_val<T>(e, tab2))
         return false;

   for (const T& e : tab2)
      if (not tab_contient_val<T>(e, tab1))
         return false;

   return true;
}

//---------------------------------------------------------
int main() {

   array  a {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

   cout << span<int>(a) << endl;
   cout << span<int>(v) << endl;

   cout << meme_elements<int>(span<int>(a), span<int>(v));
}
~~~

</details>

🤔... et si nous voulions écrire

~~~cpp
if (span<int>(a) == span<int>(v)) { ... }
~~~

<details>
<summary>Solution</summary>

~~~cpp
template <typename T>
bool operator== (span<T> tab1, span<T> tab2) {
   for (const T& e : tab1)
      if (not tab_contient_val<T>(e, tab2))
         return false;

   for (const T& e : tab2)
      if (not tab_contient_val<T>(e, tab1))
         return false;

   return true;
}
~~~

</details>
