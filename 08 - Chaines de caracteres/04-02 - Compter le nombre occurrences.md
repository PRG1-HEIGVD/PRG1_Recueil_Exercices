# Compter le nombre d'occurrences
Ecrire une fonction qui renvoie combien de fois une suite de caractères donnée se trouve dans une chaîne de caractères (de type string) donnée. 

Exemple d'exécution
~~~
Entrez une chaine de caractères : 
Les sanglots longs de violons de l'automne bercent mon coeur d'une langueur monotone
Entrez la suite de caractères à compter : 
on
La suite de caractères "on" apparait 5 fois dans la chaine "Les sanglots longs de violons de l'automne bercent mon coeur d'une langueur monotone"
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

size_t nb_occ(string_view str, string_view sub) {
   size_t cnt = 0, pos = 0;
   while ( (pos = str.find(sub, pos)) != string::npos ) {
      ++cnt;
      ++pos;
   }
   return cnt;
}

int main() {

   string str, sub;

   cout << "Entrez une chaine de caractères : \n";
   getline(cin, str);

   cout << "Entrez la suite de caractères à compter : \n";
   getline(cin, sub);

   cout << "La suite de caractères " << "\"" << sub << "\""
        << " apparait "  << nb_occ(str, sub)
        << " fois dans la chaine \"" << str << "\"" << endl;
}
~~~

</details>
