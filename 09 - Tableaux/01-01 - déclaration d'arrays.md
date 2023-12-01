# Déclaration d'arrays

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

~~~cpp
// no 1
array<int,3> a;
for(int e : a) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>
Le contenu de a est indéterminé 
</details>

~~~cpp
// no 2
array<int,3> a{1,2};
for(int e : a) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
1 2 0 
~~~
</details>

~~~cpp
// no 3
array<int,3> a{1,2,3,4};
for(int e : a) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>
Erreur à la compilation
</details>

~~~cpp
// no 4
array<int,3> a{};
for(int e : a) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
0 0 0
~~~
</details>

~~~cpp
// no 5
array<string,3> a;
for(const string & e : a) cout << e.size() << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
0 0 0
~~~

Le comportement est déterminé. Un array de string est toujours initialisé
</details>
