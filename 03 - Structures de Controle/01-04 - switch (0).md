# switch -> if ... else

Soit le programme suivant

~~~cpp
#include <iostream>
using namespace std;

int main() {
   int n; cin >> n;
   
   switch (n) {
      case 0:  cout << "A";
      case 1:
      case 2:  cout << "B";
               break;
      case 3:
      case 4:
      case 5:  cout << "C";
      default: cout << "D";
   }
}
~~~

Que va-t-il afficher lorsque l'utilisateur entre comme valeur 

~~~
0
~~~

<details>
<summary>Solution</summary>

~~~
AB
~~~
</details>

~~~
1
~~~

<details>
<summary>Solution</summary>

~~~
B
~~~
</details>

~~~
2
~~~

<details>
<summary>Solution</summary>

~~~
B
~~~
</details>

~~~
4
~~~

<details>
<summary>Solution</summary>

~~~
CD
~~~
</details>

~~~
6
~~~

<details>
<summary>Solution</summary>

~~~
D
~~~
</details>

~~~
-1
~~~

<details>
<summary>Solution</summary>

~~~
D
~~~
</details>
