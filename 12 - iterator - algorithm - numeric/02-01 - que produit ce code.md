# Que produit ce code

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
   display(v.cbegin(), v.cend());

   vector<int>::const_iterator begin = v.cbegin();
   vector<int>::const_iterator end   = v.cend();

   v.push_back(5);
   
   display(v.cbegin(), v.cend());
   display(begin, end);
}
~~~

<details>
<summary>Solution</summary>

Le vecteur ayant grandi (passé de 4 à 5 éléments), la **capacité a été ajustée** et l' **emplacement mémoire de la partie `data` du vecteur a changé**.

⚠️ Les deux itérateurs déclarés `begin` et `end` existent toujours mais n'ont pas été mis à jour !!

~~~
[1, 2, 3, 4]
[1, 2, 3, 4, 5]
[-595935184, 3613, 2043, 0] // indéterminé
~~~

**Ecrire le code nécessaire pour démontrer le problème.**

<details>
<summary>Solution</summary>


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

int main() {
   vector v  {1, 2, 3, 4};
   display(v.cbegin(), v.cend());

   vector<int>::const_iterator begin = v.cbegin();
   vector<int>::const_iterator end   = v.cend();

   cout << endl;
   cout << "AVANT insertion" << endl;
   display_details(v);
   v.push_back(5);

   cout << "APRES insertion" << endl;
   display_details(v);

   cout << "itérations" << endl;
   display(v.cbegin(), v.cend());
   display(begin, end);

   cout << endl;
   cout << "v.begin(): " << &(*v.cbegin()) << endl;
   cout << "begin    : " << &(*begin)      << endl;
}
~~~

qui produit

~~~
[1, 2, 3, 4]

AVANT insertion
taille   : 4
capacity : 4
data     : 0x600003994030

APRES insertion
taille   : 5
capacity : 8
data     : 0x600003b911e0

itérations
[1, 2, 3, 4, 5]
[-499695568, 2366, 2043, 0]

v.begin(): 0x600003b911e0
begin    : 0x600003994030
~~~

</details>
</details>
