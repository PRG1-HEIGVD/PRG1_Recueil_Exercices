# Volume d'une pyramide à base rectangulaire

Ecrire un programme C++ mettant à disposition une fonction permettant de calculer le volume d'une pyramide à base rectangulaire.

Appliquer la fonction pour calculer le volume des 2 pyramides suivantes :
1) Pyramide 1 : base de longueur 10 et de largeur 3.5; hauteur = 12
2) Pyramide 2 : base de longueur 3.6 et de largeur 2.4; hauteur = 2.7

Afficher les résultats avec un chiffre après la virgule.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------
double volumePyramide(double longueur,
                      double largeur,
                      double hauteur) {
   return longueur * largeur * hauteur / 3.0;
}

//------------------------------------------------------------
void afficher(const string& texte,
              double valeur,
              int precision) {
   cout << fixed << setprecision(precision) << texte << valeur << endl;
}

//------------------------------------------------------------
int main() {
    afficher("volume pyramide 1 = ", volumePyramide(10, 3.5, 12), 1);
    afficher("volume pyramide 2 = ", volumePyramide(3.6, 2.4, 2.7), 1); // 7.8
    return EXIT_SUCCESS;
}
~~~
</details>
