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
libc++abi: terminating due to uncaught exception of type std::out_of_range: array::at
~~~

Ce message peut varier d'une machine à l'autre

</details>
