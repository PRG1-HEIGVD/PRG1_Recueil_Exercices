# Séquence croissante

Ecrire la fonction générique `plus_long_sequence_croissante` qui reçoit en entrée 
une les itérateurs qui décrivent une plage d'éléments, ainsi qu'une 
fonction de comparaison, et qui retourne la plus long séquence croissante sous la 
forme d'une paire d'itérateurs. 

Si l'utilisateur ne spécifie pas de fonction de comparaison, on utilise l'opérateur `<`. 

Le code suivant 

~~~cpp
int main() {
   vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};

   cout << "Plus long sequence croissante (1): ";
   auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
   for (auto it = r1.first; it != r1.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence croissante (2): ";
   auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
   for (auto it = r2.first; it != r2.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence décroissante : ";
   auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
   for (auto it = r3.first; it != r3.second; ++it)
      cout << *it << ' ';

   cout << endl;
}
~~~

affiche le résultat suivant 

~~~text
Plus long sequence croissante (1): 1 2 2 3 4 
Plus long sequence croissante (2): 1 2 2 3 4 
Plus long sequence décroissante : 5 4 3 1 
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <utility>
#include <functional>

using namespace std;

template<typename Iterator, typename Comp>
pair<Iterator, Iterator> plus_long_sequence_croissante(Iterator first, Iterator last, Comp comp) {
   if(first == last)
      return {first, last};

   pair<Iterator, Iterator> output(first, next(first));
   Iterator new_first = first;
   while(++first != last) {
      if(comp(*first, *prev(first))) { // pas croissante, on commence une nouvelle séquence
         new_first = first;
      }
      if(distance(new_first, first) + 1 > distance(output.first, output.second)) {
         output.first = new_first;
         output.second = next(first);
      }
   }
   return output;
}

template<typename Iterator>
pair<Iterator, Iterator> plus_long_sequence_croissante(Iterator first, Iterator last) {
   return plus_long_sequence_croissante(first, last, less<typename Iterator::value_type>{});
}

int main() {
   vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};

   cout << "Plus long sequence croissante (1): ";
   auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
   for (auto it = r1.first; it != r1.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence croissante (2): ";
   auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
   for (auto it = r2.first; it != r2.second; ++it)
      cout << *it << ' ';

   cout << "\nPlus long sequence décroissante : ";
   auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
   for (auto it = r3.first; it != r3.second; ++it)
      cout << *it << ' ';

   cout << endl;
}
~~~
</details>
