# new et delete

Soit le code suivant

~~~cpp
#include <iostream>

using namespace std;

class C {
   int i;
public:
   C() : i(0) { cout << "CD " << flush; }
   C(int i) : i(i) { cout << "C" << i << " " << flush; }
   ~C() { cout << "D" << i << " " << flush; }
};

int main() {
   auto p1 = f();
   auto p2 = f(2);
   g(p2);
   p2 = f(3);
   g(p1);
   g(p2);
}
~~~

Ecrivez les fonctions `f`, `g` et éventuelles surcharges de sorte que le programme affiche ce qui suit à l’exécution

~~~text
CD C2 D2 C3 D0 D3
~~~


<details>
<summary>Solution</summary>

~~~cpp
C*   f()      { return new C();  }
C*   f(int i) { return new C(i); }
void g(C* p)  { delete p;        }
~~~

</details>
