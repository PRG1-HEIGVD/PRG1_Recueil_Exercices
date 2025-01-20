On veut écrire une fonction générique `concat` qui concatène plusieurs plages 
d'éléments contenus dans un ou plusieurs `vector` et écrit le résultat dans 
une autre plage, ainsi qu'une fonction d'aide `total_size` qui permet de 
calculer le nombre d'éléments concaténés à priori, i.e. sans effectuer la 
concaténation.

Soient les déclarations ci-dessous

~~~cpp
template <typename T> using Iterateur = typename vector<T>::const_iterator;
template <typename T> using Plage     = pair<Iterateur<T>, Iterateur<T>>;
template <typename T> using vPlages   = vector<Plage<T>>;

const vector<int> v1 {11, 12, 13, 14, 15, 16};
const vector<int> v2 {21, 22, 23, 24};
      vector<int> v3 {31, 32};

const vPlages<int> plages {{v1.cbegin() + 3, v1.cend()},        // v1 => 14, 15, 16
                           {v1.cbegin(),     v1.cend() - 3},    // v1 => 11, 12, 13
                           {v2.cbegin(),     v2.cend()},        // v2 => 21, 22, 23, 24
                           {v3.cbegin(),     v3.cend()}};       // v3 => 31, 32

total_size(plages.begin(), plages.end());                       // => 12
concat1(plages.cbegin(), plages.cend(), v4.begin());            // 14, 15, 16, 11, 12, 13, 21, 22, 23, 24, 31, 32
~~~

Ecrire les **deux fonctions génériques**

- `total_size(..)`
  - Prend en paramètre deux itérateurs `[first, last)` sur un `vPlages<T>`.
  - Retourne un `size_t` correspondant à la somme des tailles des plages.
- `concat(..)`
  - Prend en paramètre deux itérateurs `[first, last)` sur un `vPlages<T>`<br>
    et un itérateur `result` à la position initiale d'écriture.
  - Retourne un itérateur sur l'élément qui suit immédiatement la dernière écriture.

~~~cpp
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//------------------------------------------------------------
template <typename T> using Iterateur = typename vector<T>::const_iterator;
template <typename T> using Plage     = pair<Iterateur<T>, Iterateur<T>>;
template <typename T> using vPlages   = vector<Plage<T>>;

//------------------------------------------------------------
#include "total_size.cpp"
#include "concat.cpp"

//------------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i) os << ", ";
      os << v[i];
   }
   return os << "]";
}

//------------------------------------------------------------
int main() {

   const vector<int> v1 {11, 12, 13, 14, 15, 16};
   const vector<int> v2 {21, 22, 23, 24};
   vector<int>       v3 {31, 32};

   cout << v1 << endl;
   cout << v2 << endl;
   cout << v3 << endl;

   const vPlages<int> plages {{v1.cbegin()+3, v1.cend()},
                              {v1.cbegin(),   v1.cend()-3},
                              {v2.cbegin(),   v2.cend()},
                              {v3.begin(),    v3.end()}};  
   cout << endl;

   size_t n = total_size(plages.begin(), plages.end());
   cout << "total_size : " << n << endl << endl;
   vector<int> v4 ( n );

   concat(plages.cbegin(), plages.cend(), v4.begin());
   cout << v4 << endl;

   vector<long> v5 ( 1000 );
   v5.erase(concat(plages.crbegin(), plages.crend(), v5.begin()), v5.end());
   cout << v5 << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>total_size.cpp</summary>

~~~cpp
#include <algorithm> // for_each
#include <iterator>  // distance

using namespace std;


//------------------------------------------------------------
//    avec <algorithm>
//------------------------------------------------------------
template <typename InputIterator>
size_t total_size2(InputIterator first, InputIterator last) {
   size_t size = 0;
   for_each(first, last, [&size] (auto p) { size += (size_t)distance(p.first, p.second); });
   return size;
}

//------------------------------------------------------------
//    sans <algorithm>
//------------------------------------------------------------
template <typename InputIterator>
size_t total_size1(InputIterator first, InputIterator last) {
   size_t size = 0;
   for (InputIterator it=first; it!=last; ++it) {
     size += distance(it->first, it->second);
   }
   return size;
}

template <typename InputIterator>
size_t total_size3(InputIterator first, InputIterator last) {
   size_t size = 0;
   for (InputIterator it=first; it!=last; ++it) {
      size += size_t(it->second - it->first);
   }
   return size;
}
~~~
</details>

<details>
<summary>concat.cpp</summary>

~~~cpp
#include <algorithm> // for_each

using namespace std;

//------------------------------------------------------------
//    avec <algorithm>
//------------------------------------------------------------
template <typename InputIterator, typename OutputIterator>
OutputIterator concat2(InputIterator first, InputIterator last, OutputIterator result) {
   for (InputIterator itRead=first; itRead!=last; ++itRead) {
      result = copy(itRead->first, itRead->second, result);
   }
   return result;
}

//------------------------------------------------------------
//    sans <algorithm>
//------------------------------------------------------------
template <typename InputIterator, typename OutputIterator>
OutputIterator concat1(InputIterator first, InputIterator last, OutputIterator result) {
   while (first != last) {
      auto itRead = first->first;
      while (itRead != first->second) {
         *result = *itRead;
         ++result;
         ++itRead;
      }
      ++first;
   }
   return result;
}

//------------------------------------------------------------
template <typename InputIterator, typename OutputIterator>
OutputIterator concat3(InputIterator first, InputIterator last, OutputIterator result) {
   for (;first != last;++first) {
      for (auto itRead = first->first;
           itRead != first->second;
           ++itRead, ++result) {
         *result = *itRead;
      }
   }
   return result;
}
~~~
</details>