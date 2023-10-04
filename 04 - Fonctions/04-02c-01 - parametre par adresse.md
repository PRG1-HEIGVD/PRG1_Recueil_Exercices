# Paramètre par adresse

Que produit le code ci-dessous ?

~~~cpp
#include <iostream>
#include <cstdlib>
using namespace std;

void adresse(int* param) {

   *param += 1;            // param à l'adresse 0x16eea3648

   cout << "param          : " <<  param << endl;
   cout << "adr param      : " << &param << endl;
   cout << "valeur pointee : " << *param << endl;
}

int main() {
   int entier = 17;        // entier à l'adresse 0x16eea3698
   cout << "entier         : " <<  entier << endl;
   cout << "adr entier     : " << &entier << endl;

   adresse(&entier);

   cout << "entier         : " <<  entier << endl;
   cout << "adr entier     : " << &entier << endl;

   return EXIT_SUCCESS;
}
~~~

| Element          | Affichage |
|---               |---        |
| entier           |           |
| adr entier       |           |
| param            |           |
| adr param        |           |
| valeur pointee   |           |
| entier           |           |
| adr entier       |           |


<details>
<summary>Solution</summary>

| Element          | Affichage    |
|---               |---           |
| entier           | 17           |
| adr entier       | 0x16eea3698  |
| param            | 0x16eea3698  |
| adr param        | 0x16eea3648  |
| valeur pointee   | 18           |
| entier           | 18           |
| adr entier       | 0x16eea3698  |

</details>
