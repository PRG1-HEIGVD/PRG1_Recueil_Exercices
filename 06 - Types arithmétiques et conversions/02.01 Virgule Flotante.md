# Représentation en virgule flotante

Ecrivez un programme C++ qui demande un nombre réel à l'utilisateur et affiche sa mantisse normalisée et son exposant en base 10 et en base 2.

Exemples d'exécution : 

~~~
Entrez un nombre réel : 3.1415
3.1415 = 3.1415 * 10^0
3.1415 = 1.57075 * 2^1
~~~

~~~
Entrez un nombre réel : 2023.09
2023.09 = 2.02309 * 10^3
2023.09 = 1.97567 * 2^10
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>

using namespace std;

void calculer_representation( double r, double base,
                              double& mantisse, int& exposant ) {
   mantisse = r;
   exposant = 0;
   while (mantisse < 1) {
      mantisse *= base;
      --exposant;
   }
   while (mantisse >= base) {
      mantisse /= base;
      ++exposant;
   }
}

int main() {

   cout << "Entrez un nombre réel : ";
   double r; cin >> r;

   double mantisse;
   int exposant;
   
   calculer_representation(r, 10., mantisse, exposant);
   cout << r << " = " << mantisse << " * 10^" << exposant << endl;
   
   calculer_representation(r, 2., mantisse, exposant);
   cout << r << " = " << mantisse << " * 2^" << exposant << endl;
}
~~~
</details>


