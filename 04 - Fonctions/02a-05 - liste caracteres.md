# Affichage de caractères compris entre 2 bornes
Ecrire une fonction qui a 2 paramètres de type *unsigned char* et qui affiche, sur une même ligne, tous les caractères compris entre le premier et le deuxième paramètre (bornes comprises), pour autant que le premier représente un caractère qui précède le deuxième.
La fonction retourne une valeur booléenne indiquant si oui ou non il y a eu affichage de caractères.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

bool listerCaracteres(unsigned char c1,
                      unsigned char c2);

int main() {
   cout << "Test 1" << endl;
   listerCaracteres('A', 'A');
   
   cout << "Test 2" << endl;
   listerCaracteres('A', 'B');
   
   cout << "Test 3" << endl;
   listerCaracteres('B', 'A');
   
   cout << "Test 4" << endl;
   listerCaracteres('0', '9');
   
   cout << "Test 5" << endl;
   listerCaracteres(65, 66);
   
    cout << "Test 6" << endl;
    unsigned char c1 = numeric_limits<unsigned char>::max() - 1,
                  c2 = numeric_limits<unsigned char>::max();
    listerCaracteres(c1, c2);

    cout << "Test 7" << endl;
    listerCaracteres('\x93', '\x9B'); // du caract 147 au caract 155
   
    cout << "Fin des tests" << endl;
    return EXIT_SUCCESS;
}

//------------------------------------------------------------
bool listerCaracteres(unsigned char c1,
                      unsigned char c2) {
   if (c1 >= c2) {
      return false;
   
   }
   else {
      const unsigned NB_CHAR = c2 - c1 + 1;
      for (unsigned i = 0; i < NB_CHAR; ++i)
         cout << (unsigned char)(c1 + i);
      cout << endl;
      return true;
   }
}
// Test 1
// Test 2
// AB
// Test 3
// Test 4
// 0123456789
// Test 5
// AB
// Test 6
// ■
// Test 7
// ôöòûùÿÖÜø
// Fin des tests
~~~
</details>
