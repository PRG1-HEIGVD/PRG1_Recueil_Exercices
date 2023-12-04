# Iterator et capacity

Ce code produit le résultat indiqué.

~~~cpp
#include <iostream>
#include <vector>

using namespace std;

template<typename Iterator>
void display(Iterator first, Iterator last) {
   cout << "[";
   for (Iterator it = first; it != last; ++it) {
      if (it != first) cout << ", ";
      cout << *it;
   }
   cout << "]\n";
}

int main() {
   vector v  {1, 2, 3, 4};
   display(v.begin(), v.end());

   vector<int>::iterator begin = v.begin();
   vector<int>::iterator end   = v.end();

   v.push_back(5);
   display(v.begin(), v.end());

   display(begin, end);

}
~~~

Que se passe-t-il ?<br>
Ecrire le code nécessaire pour démontrer le problème.

~~~
[1, 2, 3, 4]
[1, 2, 3, 4, 5]
[-595935184, 3613, 2043, 0]
~~~

<details>
<summary>Solution</summary>

Le vecteur ayant grandi (passé de 4 à 5 éléments), la **capacité a été ajustée** et l' **emplacement mémoire de la partie `data` du vecteur a changé**.

Les deux itérateurs déclarés `begin` et `end` existent toujours mais n'ont pas été mis à jour !!

Pour s'en convraincre

~~~cpp
#include <iostream>
#include <vector>

using namespace std;

template<typename Iterator>
void display(Iterator first, Iterator last) {
   cout << "[";
   for (Iterator it = first; it != last; ++it) {
      if (it != first) cout << ", ";
      cout << *it;
   }
   cout << "]\n";
}

template <typename T>
void display_details(const vector<T>& v) {
   cout << "taille   : " << v.size()      << endl;
   cout << "capacity : " << v.capacity()  << endl;
   cout << "data     : " << v.data()      << endl;
   cout << endl;
}

template <typename Iterator>
void display_details(Iterator it) {
   cout << "adresse  : " << &(*it) << endl;
}

int main() {
   vector v  {1, 2, 3, 4};
   display(v.begin(), v.end());

   vector<int>::iterator begin = v.begin();
   vector<int>::iterator end   = v.end();

   cout << endl;
   cout << "AVANT insertion" << endl;
   display_details(v);
   v.push_back(5);

   cout << "APRES insertion" << endl;
   display_details(v);

   cout << "itérations" << endl;
   display(v.begin(), v.end());
   display(begin, end);

   cout << endl;
   display_details(begin);
   display_details(v.begin());

}
~~~

qui produit

~~~
[1, 2, 3, 4]

AVANT insertion
taille   : 4
capacity : 4
data     : 0x600001618030

APRES insertion
taille   : 5
capacity : 8
data     : 0x60000141d240

itérations
[1, 2, 3, 4, 5]
[609648688, 10632, 2043, 0]

adresse  : 0x600001618030
adresse  : 0x60000141d240
~~~


</details>