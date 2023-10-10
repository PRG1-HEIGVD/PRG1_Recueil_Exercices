# Analyse d'une adresse
Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir (sur la même ligne) un nom et un numéro de rue, affiche séparément à l'écran, d'une part le nom de la rue, d'autre part le numéro de la rue.

Exemple d'exécution
~~~
Entrez le nom et le numero de la rue : Impasse des Acacias 24a

Le nom de la rue est : Impasse des Acacias
Le no de la rue est  : 24a
~~~

**NB** Le cas des noms de rues contenant des chiffres (p. ex. Avenue du 1er Mars) n'est pas à traiter ici. 

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
   const string CHIFFRES = "0123456789";
   string adresse;
   cout << "Entrez le nom et le numero de la rue : ";
   getline(cin, adresse);
   size_t pos_no_rue = adresse.find_first_of(CHIFFRES);
   if (pos_no_rue == string::npos) // pas de numéro de rue 
       pos_no_rue = adresse.size();
   cout << endl
        << "Le nom de la rue est : " << adresse.substr(0, pos_no_rue) << endl
        << "Le no de la rue est  : " << adresse.substr(pos_no_rue) << endl;
   return EXIT_SUCCESS;        
}

// Entrez le nom et le numero de la rue : Impasse des Acacias 24a
// 
// Le nom de la rue est : Impasse des Acacias
// Le no de la rue est  : 24a
~~~



</details>