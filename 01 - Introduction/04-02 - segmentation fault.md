# Segmentation Fault

Compilez et exécutez le programme ci-dessous

~~~cpp
#include <iostream>

using namespace std;

int main() {
   int* p = nullptr;
   *p = 42;
   cout << "hello" << endl;
}
~~~

<details>
<summary>Solution</summary>

Le programme devrait compiler, mais crasher à l'exécution en affichant un message similaire à 

~~~
Process finished with exit code -1073741819 (0xC0000005)
~~~

Ce message peut varier d'une machine à l'autre

</details>
