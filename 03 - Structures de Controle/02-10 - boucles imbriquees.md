# boucles imbriquées

Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?

~~~cpp
// 1
for (int i = 1; i <= 3; ++i) {
   for (int j = 1; j <= 4; ++j) {
      cout << "*";
   }
   cout << endl;
}
~~~   

Votre réponse : <textarea cols="20" rows="4" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~
****
****
****
~~~
</details>

~~~cpp
// 2
for (int i = 0; i < 4; ++i) {
   for (int j = 0; j < 3; ++j) {
      cout << "*";
   }
   cout << endl;
}
~~~   

Votre réponse : <textarea cols="20" rows="4" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~
***
***
***
***
~~~
</details>

~~~cpp
// 3
for (int i = 1; i <= 4; ++i) {
   for (int j = 1; j <= i; ++j) {
      cout << "*";
   }
   cout << endl;
}
~~~   

Votre réponse : <textarea cols="20" rows="4" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~
*
**
***
****
~~~
</details>

~~~cpp
// 4
for (int i = 1; i <= 3; ++i) {
   for (int j = 1; j <= 5; ++j) {
      if (j % 2 == 0) {
         cout << "o";
      } else {
         cout << "x";
      }
   }
   cout << endl;
}
~~~   

Votre réponse : <textarea cols="20" rows="4" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~
xoxox
xoxox
xoxox
~~~
</details>

~~~cpp
for (int i = 1; i <= 3; ++i) {
   for (int j = 1; j <= 5; ++j) {
      if ( (i + j) % 2 == 0) {
         cout << "o";
      } else {
         cout << "x";
      }
   }
   cout << endl;
}
~~~


Votre réponse : <textarea cols="20" rows="4" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~
oxoxo
xoxox
oxoxo
~~~
</details>