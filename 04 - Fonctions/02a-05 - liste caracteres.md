# Affichage de caractères compris entre 2 bornes
Ecrire une fonction qui a 2 paramètres de type *char* et qui affiche, sur une même ligne, tous les caractères compris entre le premier et le deuxième paramètre (bornes comprises), pour autant que le premier représente un caractère qui précède le deuxième.

La fonction retourne une valeur booléenne indiquant si oui ou non il y a eu affichage de caractères.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

bool listerCaracteres(char c1,
                      char c2);

int main() {
   cout << "Test 1 : ";
   listerCaracteres('A', 'A');
   cout << endl;

   cout << "Test 2 : ";
   listerCaracteres('A', 'B');
   cout << endl;

   cout << "Test 3 : ";
   listerCaracteres('B', 'A');
   cout << endl;

   cout << "Test 4 : ";
   listerCaracteres('0', '9');
   cout << endl;

   cout << "Test 5 : ";
   listerCaracteres(65, 66);
   cout << endl;

   cout << "Test 6 : ";
   listerCaracteres('\x93', '\x9B'); // du caract 147 au caract 155
   cout << endl;

   cout << "Fin des tests" << endl;
   return EXIT_SUCCESS;
}

//------------------------------------------------------------
bool listerCaracteres(char c1,
                      char c2) {
   if (c1 >= c2) {
      return false;
   }
   else {
      for (char c = c1; c <= c2; ++c)
         cout << c;
      return true;

   }
}

//      Test 1 :
//      Test 2 : AB
//      Test 3 :
//      Test 4 : 0123456789
//      Test 5 : AB
//      Test 6 : ���������
//

~~~
</details>
