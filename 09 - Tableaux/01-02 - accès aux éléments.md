# Accès aux éléments 

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

~~~cpp
// no 1
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.front() << ' ' << a.back();
~~~
<details>
<summary>Solution</summary>

~~~
1 5
~~~
</details>

~~~cpp
// no 2
array<int, 5> a{1, 2, 3, 4, 5};
cout << a[1] << ' ' << a[3];
~~~
<details>
<summary>Solution</summary>

~~~
2 4
~~~
</details>

~~~cpp
// no 3
array<int, 5> a{1, 2, 3, 4, 5};
cout << a[5];
~~~
<details>
<summary>Solution</summary>
Comportement indéterminé
</details>

~~~cpp
// no 4
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.at(1) << ' ' << a.at(3);
~~~
<details>
<summary>Solution</summary>

~~~
2 4
~~~
</details>

~~~cpp
// no 5
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.at(5);
~~~
<details>
<summary>Solution</summary>
Erreur à l'exécution :

~~~
libc++abi: terminating due to uncaught exception of type std::out_of_range: array::at
~~~
</details>
