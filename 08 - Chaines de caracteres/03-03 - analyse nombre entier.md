# Analyse d'un nombre entier
En utilisant exclusivement les services offerts par la classe string, écrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir un nombre entier (de type int) ≥ 0, affiche à l'écran combien de chiffres contient ce nombre et ce que valent le premier chiffre et le dernier chiffre du nombre.

**NB** On supposera ici la saisie utilisateur correcte. 

Exemple d'exécution
~~~
Entrez un nombre entier >= 0 : 123

Nombre saisi       : 123
Nombre de chiffres : 3
Premier chiffre    : 1
Dernier chiffre    : 3

~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cout << "Entrez un nombre entier >= 0 : ";
    cin >> n;

    string s = to_string(n);

    cout << endl
         << "Nombre saisi       : " << n << endl
         << "Nombre de chiffres : " << s.length() << endl
         << "Premier chiffre    : " << s.at(0) << endl
         << "Dernier chiffre    : " << s.at(s.length() - 1) << endl;

    return EXIT_SUCCESS;
}
~~~



</details>