# Parcours d'un tableau

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à l'exécution, aie un comportement indéfini ou cause une boucle infinie. Indiquez-le_ 

~~~cpp
// no 1
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 1; i <= 3; ++i)
   cout << a.at(i) << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
2 3 4
~~~
</details>

~~~cpp
// no 2
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = a.size()-1; i >= 0; --i)
   cout << a.at(i) << ' ';
~~~
<details>
<summary>Solution</summary>

Erreur à l'exécution quand i vaut `size_t(-1) == std::numeric_limits<size_t>::max()`. Par exemple, 

~~~
5 4 3 2 1 libc++abi: terminating due to uncaught exception of type std::out_of_range: array::at
~~~
</details>

~~~cpp
// no 3
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 0; i < a.size(); ++i)
   cout << a.at(i) << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
1 2 3 4 5 
~~~
</details>

~~~cpp
// no 4
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 3; i < a.size(); --i)
   cout << a.at(i) << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
4 3 2 1  
~~~
</details>

~~~cpp
// no 5
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 3; i > 0; --i)
   cout << a.at(i) << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
4 3 2 
~~~
</details>

~~~cpp
// no 6
array<int, 5> a{1, 2, 3, 4, 5};
for(int i : a)
   cout << i << ' ';
~~~
<details>
<summary>Solution</summary>
   
~~~
1 2 3 4 5
~~~
</details>

~~~cpp
// no 7
array<int, 5> a{1, 2, 3, 4, 5};
for(int i : a)
   i *= i;
for(int i : a)
   cout << i << ' '; 
~~~
<details>
<summary>Solution</summary>
   
~~~
1 2 3 4 5 
~~~
</details>

~~~cpp
// no 8
array<int, 5> a{1, 2, 3, 4, 5};
for(int& i : a)
   i *= i;
for(int i : a)
   cout << i << ' '; 
~~~
<details>
<summary>Solution</summary>
   
~~~
1 4 9 16 25 
~~~
</details>
