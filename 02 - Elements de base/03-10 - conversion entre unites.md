# Conversion de mètres en miles, pieds et pouces

Ecrire un programme C++ permettant de réaliser les trois conversions d'unités suivantes :
- mètres en miles
- mètres en pieds (feet en anglais)
- mètres en pouces (inches en anglais).
  
Le nombre de mètres est saisi par l'utilisateur sous la forme d'un entier > 0. On suppose ladite saisie correcte.

Un exemple d'exécution :
~~~
Entrez le nombre de metres a convertir (entier > 0) : 1000
1000 [m]
= 0.621371 [mile]
= 3280.84 [ft]
= 39370.1 [inch]
~~~



<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    const double metres_en_miles = 6.213711922e-4;
    const double metres_en_ft    = 3.280839895;
    const double metres_en_inch  = 39.37007874;

    // Saisie utilisateur
    int nb_metres;
    cout << "Entrez le nombre de metres a convertir (entier > 0) : ";
    cin >> nb_metres;

    cout << nb_metres << " [m]" << endl
         << "= " << nb_metres * metres_en_miles << " [mile]" << endl
         << "= " << nb_metres * metres_en_ft    << " [ft]"   << endl
         << "= " << nb_metres * metres_en_inch  << " [inch]" << endl;

    return EXIT_SUCCESS;
}
~~~
   
   



</details>
