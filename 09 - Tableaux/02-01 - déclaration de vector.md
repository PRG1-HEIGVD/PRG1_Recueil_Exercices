# Déclaration de vector

Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

~~~cpp
vector<int> v(2,3);
for(auto e : v) cout << e << ' '; 
~~~
<details>
<summary>Solution</summary>

~~~
3 3 
~~~
</details>


~~~cpp
vector<int> v(4);
for(auto e : v) cout << e << ' '; 
~~~
<details>
<summary>Solution</summary>

~~~
0 0 0 0 
~~~
</details>

~~~cpp
vector<int> v{1, 2, 3};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
1 2 3 
~~~
</details>

~~~cpp
vector<int> v{1., 2, 3};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>
Erreur à la compilation. 

~~~
error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]
vector<int> v{1., 2, 3};
              ^~
~~~
</details>

~~~cpp
vector<double> v{1., 2, 3};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>

~~~
1 2 3
~~~
</details>

~~~cpp
vector<int> v(3) = {1, 2, 3};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary>
Erreur à la compilation. 

~~~
error: expected ';' at end of declaration
vector<int> v(3) = {1, 2, 3};
                ^
~~~
</details>


~~~cpp
vector v{1., 2., 3.};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary> 

~~~
1 2 3
~~~

v est de type `vector<double>`
</details>


~~~cpp
vector v{1., 2, 3};
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary> 
Erreur à la compilation

~~~
error: no viable constructor or deduction guide for deduction of template arguments of 'vector'
vector v{1., 2, 3};
       ^
~~~
</details>


~~~cpp
vector v(3,2.f);
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary> 

~~~
2 2 2
~~~

v est de type `vector<float>`
</details>


~~~cpp
vector v(4);
for (auto e: v) cout << e << ' ';
~~~
<details>
<summary>Solution</summary> 
Erreur à la compilation

~~~
error: no viable constructor or deduction guide for deduction of template arguments of 'vector'
vector v(4);
       ^
~~~
</details>

