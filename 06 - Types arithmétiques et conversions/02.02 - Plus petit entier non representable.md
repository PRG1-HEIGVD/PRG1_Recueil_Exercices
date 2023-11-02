# Plus petit entier non représentable en type réel

Ecrivez le code C++ permettant de déterminer le plus petit entier positif qui n'est pas représentable exactement en type `float`, en utilisant chacune des 4 méthodes suivantes
- force brute en testant tous les entiers à partir de 0
- en ne considérant que les valeurs de type $2^n+1$ avec $n$ entier
- à partir de `numeric_limits<float>::epsilon()`
- à partir de `numeric_limits<float>::digits`

Faites de même pour le type `double`

<details><summary>Indice</summary>

Si le type `float` utilisait 24 bits de mantisse plutôt que 23, le nombre recherché
aurait la valeur `000000000000000000000001` stockée dans ces 24 bits, et donc 
sa valeur serait de `0b1000000000000000000000001` 
avec le `1` implicite placé devant.

</details>

<details><summary>Solution</summary>

Pour le bien de votre apprentissage, ne consulez la solution que pour vérifier la vôtre ou après avoir sincèrement essayé de 
résoudre le problème sans y parvenir. 

<details><summary>Code C++</summary>

~~~cpp
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {

   // float
   {
      int i = 0;
      while (int(float(i)) == i) {
         ++i;
      }
      cout << i << endl;

      // Note : while(float(i) == i) { ++i; } ne fonctionne pas.
      // La comparaison s'effectue en float et est donc toujours vraie -> boucle infinie

      int j = 1;
      while (int(float(j + 1)) == j + 1)
         j *= 2;
      cout << j + 1 << endl;

      cout << int(2.f / numeric_limits<float>::epsilon()) + 1 << endl;

      cout << int(pow(2.f, numeric_limits<float>::digits)) + 1 << endl;
   }

   // double
   {
      bool je_suis_tres_tres_patient = false;
      if (je_suis_tres_tres_patient) {
         long long i = 0;
         while ((long long) (double(i)) == i) {
            ++i;
         }
         cout << i << endl;
      }

      long long j = 1;
      while ((long long) (double(j + 1)) == j + 1)
         j *= 2;
      cout << j + 1 << endl;

      cout << (long long) (2. / numeric_limits<double>::epsilon()) + 1 << endl;

      cout << (long long) (pow(2., numeric_limits<double>::digits)) + 1 << endl;
   }
}
~~~

</details>
</details>
