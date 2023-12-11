# Fusion alternée

Sans utiliser `<algorithm>`, écrire une fonction générique *merge* qui prend en paramètres 4 itérateurs identifiant 2 deux plages de données de type `<T>` et qui retourne un `vector<T>` avec l'ensemble de ces données fusionnées de manière alternée.

Exemple d'exécution

~~~
vector   : [11, 12, 13]
array    : [21, 22, 23, 24, 25]
resultat : [11, 21, 12, 22, 13, 23, 24, 25]
~~~

<details>
<summary>Solution 1</summary>

~~~cpp
#include <iostream>
#include <array>
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
template<typename T, typename Iterator1, typename Iterator2>
vector<T> merge(Iterator1 first1, Iterator1 last1,
                Iterator2 first2, Iterator2 last2) {

   vector<T> v(distance(first1, last1) + distance(first2, last2));

   typename vector<T>::iterator it = v.begin();
   
   while (first1 != last1 and first2 != last2) {
      *it++ = *first1++;
      *it++ = *first2++;
   }

   if (first1 == last1)
      while (first2 != last2)
         *it++ = *first2++;
   else
      while (first1 != last1)
         *it++ = *first1++;

   return v;
}

//---------------------------------------------------------
int main() {

   vector v {11, 12, 13};
   array  a {21, 22, 23, 24, 25};

   cout << "vector   : " << span<int>(v) << endl;
   cout << "array    : " << span<int>(a) << endl;

   vector r = merge<int>(v.begin(), v.end(),
                         a.begin(), a.end());

   cout << "resultat : " << span<int>(r) << endl;
}
~~~

</details>

<details>
<summary>Solution 2</summary>

En utilisant `vector<T>::insert` mais alors la taille doit être ajustée à `2 * min(taille1, taille2)`.<br>
Pour éviter un changement de capacité, la réservation est faite en une seule fois et la taille réduite.

~~~cpp
#include <iostream>
#include <array>
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
template<typename T, typename Iterator1, typename Iterator2>
vector<T> merge(Iterator1 first1, Iterator1 last1,
                Iterator2 first2, Iterator2 last2) {

   auto taille1 = distance(first1, last1);
   auto taille2 = distance(first2, last2);

   vector<T> v(taille1 + taille2);
   v.resize(taille1 < taille2 ? taille1 : taille2);

   typename vector<T>::iterator it = v.begin();
   while (first1 != last1 and first2 != last2) {
      *it++ = *first1++;
      *it++ = *first2++;
   }

   v.insert(it, first1, last1);
   v.insert(it, first2, last2);

   return v;
}

//---------------------------------------------------------
int main() {

   vector v {11, 12, 13};
   array  a {21, 22, 23, 24, 25};

   cout << "vector   : " << span<int>(v) << endl;
   cout << "array    : " << span<int>(a) << endl;

   vector r = merge<int>(v.begin(), v.end(),
                         a.begin(), a.end());

   cout << "resultat : " << span<int>(r) << endl;
}
~~~

</details>
