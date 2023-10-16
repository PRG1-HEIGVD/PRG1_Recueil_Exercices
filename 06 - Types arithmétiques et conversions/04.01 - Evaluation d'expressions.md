# Evaluation d'expressions

Que va afficher le programme ci-dessous ? Expliquer les résultats obtenus.

~~~cpp
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
   cout << fixed << setprecision(0);
   cout << "1) " << 3 * 1000 * 1000 * 1000 << endl;
   cout << "2) " << 3.0 * 1000 * 1000 * 1000 << endl;
   cout << "3) " << 100000 * 100000 * 100000.0 << endl;
   cout << "4) " << 100000.0 * 100000 * 100000 << endl;
   cout << "5) " << 1E7 + 1.0 << endl;
   cout << "6) " << 1E7f + 1.f << endl;
   cout << "7) " << 1E8 + 1.0 << endl;
   cout << "8) " << 1E8f + 1.f << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~
1) -1294967296
2) 3000000000
3) 141006540800000
4) 1000000000000000
5) 10000001
6) 10000001
7) 100000001
8) 100000000
~~~

### Explications
1) Résultat indéfini car multiplication entière induisant un débordement. Le résultat affiché est probable pour un entier codé en complément à 2. 
2) Résultat juste car multiplications successives réelles
3) Résultat indéfini car la première multiplication s'effectue sur les entiers => débordement. Le résultat affiché est probable pour un entier codé en complément à 2.
4) Résultat juste car multiplications successives réelles
5) Résultat juste.
6) Résultat juste.
7) Résultat juste.
8) Résultat arrondi (en base 2) dû à la précision insuffisante des calculs avec le type `float`
</details>
