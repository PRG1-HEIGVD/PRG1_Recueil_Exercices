# Déclaration de span + subspan

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

~~~cpp
// no 1
vector v { 1, 2, 3, 4, 5, 6, 7, 8};
span s {v.data(), 3};
for(int e : s) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 2 3 
~~~

--------

</details>


~~~cpp
// no 2
vector v { 1, 2, 3, 4, 5, 6, 7, 8};
span s {v.data() + 2, 4};
for(int e : s) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
3 4 5 6 
~~~

--------

</details>

~~~cpp
// no 3
vector v { 1, 2, 3, 4, 5, 6, 7, 8};
span s {v};
for(int e : s.subspan(3,2)) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
4 5 
~~~

--------

</details>

~~~cpp
// no 4
array a { 1, 2, 3, 4, 5, 6, 7, 8};
span s {&a[3],4};
for(int e : s) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
4 5 6 7 
~~~

--------

</details>

~~~cpp
// no 5
array a { 1, 2, 3, 4, 5, 6, 7, 8};
span s {a.data() + 4, 5};
for(int e : s) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

Comportement indéfini. Le dernier élément du `span` déborde de l'`array` qui parcourt. 

--------

</details>

~~~cpp
// no 6
vector v { 1, 2, 3, 4, 5, 6, 7, 8};
span s {v.data() + 5, 7};
for(size_t i = 0; i < s.size(); ++i)
   cout << s[i] << ' ';
~~~
<details>
<summary>Solution</summary>

Comportement indéfini. Le dernier élément du `span` déborde du `vector` qui parcourt.

--------

</details>


~~~cpp
// no 7
vector v { 1, 2, 3, 4, 5, 6, 7, 8};
span s {v.data() + 5, 7};
for(size_t i = 0; i < s.size(); ++i)
   cout << s.at(i) << ' ';
~~~
<details>
<summary>Solution</summary> 

Erreur à la compilation. En C++20 `std::span` ne possède pas de méthode `at`. Il est actuellement prévu qu'elle soit disponible dans le future standard C++26. 

--------

</details>
