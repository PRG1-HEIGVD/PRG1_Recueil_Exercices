# Que produit ce code

... sachant que
- *entier*    est stocké à l'adresse 0x7ff7bfeff3a8
- *ptrEntier* est stocké à l'adresse 0x7ff7bfeff3a0

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
   int   entier   = 17;
   int* ptrEntier = &entier;
   
   cout << "entier           : " <<  entier           << endl;
   cout << "adr entier       : " << &entier           << endl;
   cout << "ptrEntier        : " <<  ptrEntier        << endl;
   cout << "adr ptrEntier    : " << &ptrEntier        << endl;
   cout << "valeur pointee   : " << *ptrEntier        << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
//      entier           : 17
//      adr entier       : 0x7ff7bfeff3a8
//      ptrEntier        : 0x7ff7bfeff3a8
//      adr ptrEntier    : 0x7ff7bfeff3a0
//      valeur pointee   : 17
~~~

</details>
