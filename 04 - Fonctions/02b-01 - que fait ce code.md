# Mystère, mystère !
Déterminer "à la main" ce que va afficher, à l'exécution, le programme ci-dessous.

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;
void mystere(int& a, int& b);

int main() {
   int x = 3, y = 4;
   mystere(x, y);
   cout << "x = " << x << " " << "y = " << y << endl;
   return EXIT_SUCCESS;
}

void mystere(int& a, int& b) {
   a = a - b;
   b = b + a;
   a = b - a;
}

~~~

<details>
<summary>Solution</summary>

~~~cpp
x = 4
y = 3
 
Ce code permet d'échanger les valeurs a et b, mais ne fonctionne pas si on cherche à échanger une variable avec elle-même
~~~
</details>
