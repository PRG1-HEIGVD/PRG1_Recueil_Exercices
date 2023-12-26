# Nombre de valeurs dans un intervalle

Ecrire le code permettant de compter le nombre de valeurs comprises dans un intervalle donné [min, max] contenues dans un tableau de type `<T>`.

NB : l'intervalle n'est pas connu à la compilation

~~~
vecteur    : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
intervalle : [3, 6]
résultat   : 4
~~~

<details>
<summary>Solution 1 - foncteur</summary>

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
struct entre {
   const T& min;
   const T& max;
   bool operator() (const T& e) { return e >= min and e <= max; }
};

//---------------------------------------------------------
int main() {

   vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   cout << span(v) << endl;

   cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
}
~~~

</details>

<details>
<summary>Solution 2 - lambda</summary>

~~~cpp
int min=3,
    max=6;
    
// [&min, &max] en référence pour ne pas copier les valeurs
cout << count_if(v.begin(), v.end(),
                 [&min, &max](int e) {return e >= min and e <= max; });
~~~

</details>