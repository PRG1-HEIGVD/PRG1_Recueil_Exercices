# continue et break dans boucle do… while

Qu'affiche le programme suivant ? 


~~~cpp
#include <iostream>
using namespace std;

int main() {
   int n = 0;

   do {
      if (n % 2 == 0) {
         cout << n << "/2 ";
         n += 3;
         continue;
      }
      if (n % 3 == 0) {
         cout << n << "/3 ";
         n += 5;
      }
      if (n % 5 == 0) {
         cout << n << "/5 ";
         break;
      }
      ++n;
   } while (true);
}
~~~

Conseil : essayer de trouver la réponse "à la main", puis vérifier votre réponse en l'exécutant pas à pas dans un debugger.

<details>
<summary>Solution</summary>

~~~
0/2 3/3 9/3 15/3 20/5 
~~~
</details>
