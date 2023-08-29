# Portée des variables
Déterminer "à la main" ce que va afficher, à l'exécution, le programme ci-dessous.

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

int a, b;

//------------------------------------------------------------
int f(int c) {
   int n = 0;
   a = c;
   if (n < c) {
      n = a + b;
   }
   return n;
}

//------------------------------------------------------------
int g(int c) {
   int n = 0;
   int a = c;
   if (n < f(c)) {
      n = a + b;
   }
   return n;
}

//------------------------------------------------------------
int main() {
   int i = 1;
   int b = g(i);
   cout << "resultat : " << a + b + i << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>Indice</summary>
Les variables globales, tout comme les statics valent "0" par défaut.
</details>

<details>
<summary>Solution</summary>
resultat : 3
</details>
