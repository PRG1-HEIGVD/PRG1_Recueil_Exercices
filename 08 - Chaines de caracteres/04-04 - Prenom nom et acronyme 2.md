# Prénom, nom et acronyme 2
Ecrire un programme C++ qui après avoir demandé à l'utilisateur de saisir son prénom et son nom (sur la même ligne), affiche à l'écran son prénom, son nom ainsi que son acronyme.
**NB**  L'acronyme s'obtient en concaténant la première lettre du prénom, la première lettre du nom et la dernière lettre du nom, le tout mis entièrement en majuscules.

**IMPORTANT**
- On supposera que l'utilisateur n'entre qu'un seul prénom.
- Il est demandé de tenir compte des cas où le **nom serait constitué de plusieurs mots**

Il n'est pas demandé ici de tenir compte des cas où l'utilisateur n'entrerait que son prénom, que son nom, voire ni son prénom, ni son nom.

Exemple d'exécution
~~~
Entrez votre prenom et votre nom : Ludwig van Beethoven

Votre prenom est   : Ludwig
Votre nom est      : van Beethoven
Votre acronyme est : LVN

Entrez votre prenom et votre nom : Valery Giscard d'Estaing 

Votre prenom est   : Valery
Votre nom est      : Giscard d'Estaing 
Votre acronyme est : VGG
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string toupper_str(string_view input){
    string result(input);
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main() {

   string s;
   cout << "Entrez votre prenom et votre nom : ";
   getline(cin, s);

   size_t posPremiereLettrePrenom = s.find_first_not_of(" \t");
   
   size_t posPremierBlancApresPrenom =
      s.find_first_of(" \t", posPremiereLettrePrenom);
   
   size_t posPremiereLettreNom =
      s.find_first_not_of(" \t", posPremierBlancApresPrenom);
   
   size_t posDerniereLettreNom = s.find_last_not_of(" \t");

   string prenom = s.substr(posPremiereLettrePrenom, 
                            posPremierBlancApresPrenom - posPremiereLettrePrenom);

   string nom = s.substr(posPremiereLettreNom, 
                         posDerniereLettreNom - posPremiereLettreNom + 1);
         
   string acronyme{prenom.at(0), nom.at(0), nom.at(nom.length() - 1)};   
   acronyme = toupper_str(acronyme);
   
      
   cout << endl
        << "Votre prenom est   : " << prenom << endl
        << "Votre nom est      : " << nom << endl
        << "Votre acronyme est : " << acronyme << endl;

   return EXIT_SUCCESS;
}

// Entrez votre prenom et votre nom : Ludwig van Beethoven
// 
// Votre prenom est   : Ludwig
// Votre nom est      : van Beethoven
// Votre acronyme est : LVN
// 
// Entrez votre prenom et votre nom : Valery Giscard d'Estaing 
// 
// Votre prenom est   : Valery
// Votre nom est      : Giscard d'Estaing 
// Votre acronyme est : VGG

~~~



</details>