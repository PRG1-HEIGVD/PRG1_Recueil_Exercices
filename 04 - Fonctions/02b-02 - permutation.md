# Permutation circulaire droite de 3 réels
Ecrire un programme C++ qui met à disposition une fonction sans valeur de retour et prenant 3 paramètres de type double permettant d'effectuer une permutation circulaire droite de ces 3 valeurs.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

void permutationCirculaireDroite(double& x,
                                 double& y,
                                 double& z);

void afficher(double x,
              double y,
              double z);

//------------------------------------------------------------
int main() {
   double x = 1, y = 2, z = 3;
   for (int i = 1; i <= 3; ++i) {
      permutationCirculaireDroite(x, y, z);
      afficher(x, y, z);
   }
   return EXIT_SUCCESS;
}

//------------------------------------------------------------
void permutationCirculaireDroite(double& x,
                                 double& y,
                                 double& z) {
   double tmp = z;
   z = y;
   y = x;
   x = tmp;
}

//------------------------------------------------------------
void afficher(double x,
              double y,
              double z) {
   cout << "x = " << x << ", "
        << "y = " << y << ", "
        << "z = " << z << endl;
}
~~~
</details>
