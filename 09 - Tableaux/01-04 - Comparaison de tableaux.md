# Comparaison d'arrays

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

~~~cpp
// no 1
array<int, 3> a{1, 2, 3};
array<int, 3> b{1, 3, 2};
cout << boolalpha << (a < b); 
~~~
<details>
<summary>Solution</summary>

~~~
true
~~~
</details>


~~~cpp
// no 2
array<int, 3> a{1, 2, 3};
array<int, 4> b{1, 2, 3, 4};
cout << boolalpha << (a < b); 
~~~
<details>
<summary>Solution</summary>

Erreur à la compilation. Les 2 arrays à comparer doivent être de même longueur.
~~~
error: invalid operands to binary expression ('array<int, 3>' and 'array<int, 4>')
~~~
</details>

~~~cpp
// no 2
array<int, 3> a{1, 2, 3};
array<short, 3> b{2, 3, 1};
cout << boolalpha << (a < b);
~~~
<details>
<summary>Solution</summary>

Erreur à la compilation. Les 2 arrays à comparer doivent être de même type.
~~~
error: invalid operands to binary expression ('array<int, 3>' and 'array<short, 3>')
~~~
</details>

~~~cpp
// no 3
array<int, 4> a{1, 2, 3};
array<int, 4> b{1, 2, 3, -1};
array<int, 4> c{1, 2, 3, 1};
cout << boolalpha << (a < b) << endl 
     << (a < c) << endl
     << (b < c);
~~~
<details>
<summary>Solution</summary>

~~~
false true true
~~~

l'array a contient `1 2 3 0`
</details>
