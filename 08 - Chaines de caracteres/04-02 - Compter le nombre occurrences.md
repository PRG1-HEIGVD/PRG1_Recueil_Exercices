# Compter le nombre d'occurrences
Ecrire une fonction qui renvoie combien de fois un caractère donné se trouve dans une chaîne de caractères (de type string) donnée. Vous ne pouvez pas utiliser l'opérateur [] ni la méthode
at() pour résoudre cet exercice. 

Exemple d'exécution
~~~
Entrez une chaine de caractères : 
Les sanglots longs des violons de l'automne
Entrez le caractère à compter : 
o
Le nombre d'occurences du caractère 'o' dans la chaine "Les sanglots longs des violons de l'automne" = 5
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
using namespace std;

size_t nb_occ(string_view str, char c) {
   size_t resultat = 0,
          pos = 0;
   while ( (pos = str.find(c, pos)) != string::npos ) {
      ++resultat;
      ++pos;
   } 
   return resultat; 
}


int main() {

    string str;
    char c;

    cout << "Entrez une chaine de caractères : \n";
    getline(cin, str);
    
    cout << "Entrez le caractère à compter : \n";
    cin >> c;

    cout << "Le nombre d'occurences du caractère " 
         << "'" << c << "'" 
         << " dans la chaine \"" << str << "\" = "
         << nb_occ(str, c) << "\n";  

    return EXIT_SUCCESS;
}
~~~



</details>
