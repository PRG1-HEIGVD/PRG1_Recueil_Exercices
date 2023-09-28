# Analyse d'un caractère

Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir un caractère, détermine / affiche à l'écran si ce caractère :

1. est une lettre de l'alphabet
2. est une lettre minuscule de l'alphabet 
3. est un chiffre
4. est un symbole de ponctuation

Un exemple d'exécution :
~~~text
Entrez un caractere : a

Code ASCII de 'a'                   : 97
'a' est une lettre de l'alphabet    : vrai
'a' est une lettre minuscule        : vrai
'a' est un chiffre                  : faux
'a' est un caractere de ponctuation : faux
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string vraiFaux(bool b) {
   return b ? "vrai" : "faux";
}

int main() {
   unsigned char c;
   cout << "Entrez un caractere : ";
   cin >> c;
   cout << endl
        << "Code ASCII de '" << c << "'                   : "
        << (int) c << endl
        << "'" << c << "' est une lettre de l'alphabet    : "
        << vraiFaux(isalpha(c)) << endl
        << "'" << c << "' est une lettre minuscule        : "
        << vraiFaux(islower(c)) << endl        
        << "'" << c << "' est un chiffre                  : "
        << vraiFaux(isdigit(c)) << endl
        << "'" << c << "' est un caractere de ponctuation : "
        << vraiFaux(ispunct(c)) << endl;
           
   return EXIT_SUCCESS;
}
~~~



</details>