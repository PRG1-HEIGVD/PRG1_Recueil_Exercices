# Compter le nombre d'occurrences
Ecrire une fonction qui renvoie combien de fois un caractère donné se trouve dans une chaîne de caractères (de type string) donnée.

Exemple d'exécution
~~~
Entrez votre prenom et votre nom : Alexandre Dumas

Votre prenom est   : Alexandre
Votre nom est      : Dumas
Votre acronyme est : ADS
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