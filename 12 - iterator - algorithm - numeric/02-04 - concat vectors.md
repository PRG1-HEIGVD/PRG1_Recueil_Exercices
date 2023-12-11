# Concaténation de deux vecteurs

Sans utiliser `<algorithm>`, écrire une fonction générique *concat_tab* qui prend en paramètres 4 itérateurs identifiant 2 deux plages de données de type `<T>` et qui retourne un `vector<T>` avec l'ensemble de ces données.

Aucun ordre particulier n'est demandé.

Exemple d'exécution

~~~
vector   : [11, 12, 13]
array    : [21, 22, 23, 24, 25]
resultat : [11, 12, 13, 21, 22, 23, 24, 25]
~~~

<details>
<summary>Solution 1 - avec boucle</summary>

~~~cpp
#include <iostream>
#include <array>
#include <vector>
#include <span>

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

template<typename T, typename Iterator1, typename Iterator2>
vector<T> concat_tab(Iterator1 first1, Iterator1 last1,
                     Iterator2 first2, Iterator2 last2) {

   vector<T> v( distance(first1, last1) +
                distance(first2, last2)  );

   typename vector<T>::iterator it = v.begin();

   while(first1 != last1)
      *it++ = *first1++;

   while(first2 != last2)
      *it++ = *first2++;

   return v;
}

int main() {
   
   vector v {11, 12, 13};
   array  a {21, 22, 23, 24, 25};

   cout << "vector   : " << span<int>(v) << endl;
   cout << "array    : " << span<int>(a) << endl;

   vector r = concat_tab<int>(v.begin(), v.end(),
                              a.begin(), a.end());

   cout << "resultat : " << span<int>(r) << endl;
}
~~~

</details>

<details>
<summary>Solution 2 - sans boucle</summary>

~~~cpp
#include <iostream>
#include <array>
#include <vector>
#include <span>

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

template<typename T, typename Iterator1, typename Iterator2>
vector<T> concat_tab(Iterator1 first1, Iterator1 last1,
                     Iterator2 first2, Iterator2 last2) {
   vector<T> v;
   v.reserve(distance(first1, last1) +
             distance(first2, last2));
   v.insert(v.end(), first1, last1);
   v.insert(v.end(), first2, last2);
   return v;
}

int main() {

   vector v {11, 12, 13};
   array  a {21, 22, 23, 24, 25};

   cout << "vector   : " << span<int>(v) << endl;
   cout << "array    : " << span<int>(a) << endl;

   vector r = concat_tab<int>(v.begin(), v.end(),
                              a.begin(), a.end());

   cout << "resultat : " << span<int>(r) << endl;
}
~~~

</details>
