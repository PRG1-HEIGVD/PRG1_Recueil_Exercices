# Vecteur d'itérateurs

Soit le vecteur constant déclaré.

~~~cpp
const vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};
~~~

Ecrire une fonction `vect_iter_val` qui reçoit un `vector<T>` **constant** et une valeur `<T>` et retourne un vecteur contenant des itérateurs sur chacune des valeurs correspondantes.

Dans l'exemple ci-dessous, la valeur `2` était recherchée.

~~~cpp
vecteur d'entiers     : [1, 2, 3, 2, 4, 2, 2, 6, 2]
vecteur d'iterateurs  : [2, 2, 2, 2, 2]
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
template <typename T, typename Iterator>
vector<Iterator> vect_iter_val(const vector<T>& v, const T& e) {

   vector<Iterator> result;
   auto it = v.cbegin();
   // ou
   typename vector<T>::const_iterator it = v.cbegin();

   while( (it = find(it, v.cend(), e)) != v.cend()) {
      result.push_back(it);
      ++it;
   }

   return result;
}

//---------------------------------------------------------
// pour éviter des problèmes de surcharge avec l'opérateur de flux
template <typename Iterateur>
void afficher_vect_iter (const vector<Iterateur>& v) {
   cout << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i) cout << ", ";
      cout << *v[i];
   }
   cout << "]";
}

//---------------------------------------------------------
int main() {

   vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};

   using it_int = vector<int>::const_iterator;

   cout << "vecteur d'entiers     : " << span(v) << endl;
   vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
   cout << "vecteur d'iterateurs  : ";
   afficher_vect_iter(vect_int_ref);
}
~~~

</details>