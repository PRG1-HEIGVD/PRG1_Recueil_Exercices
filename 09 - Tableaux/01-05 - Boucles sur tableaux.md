# Boucles sur tableaux 

Indiquer ce que va afficher chacune des séquences d'instructions suivantes

~~~cpp
// no 1
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 1; i < 10; ++i) t[i] = t[i - 1]; 
for(auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 1 1 1 1 1 1 1 1 1 
~~~
</details>

~~~cpp
// no 2
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 9; i > 0; --i) { t[i] = t[i - 1]; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 1 2 3 4 5 4 3 2 1 
~~~
</details>

~~~cpp
// no 3
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 0; i < 9; ++i) { t[i] = t[i + 1]; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
2 3 4 5 4 3 2 1 0 0 
~~~
</details>

~~~cpp
// no 4
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 8; i >= 0; --i) { t[i] = t[i + 1]; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
0 0 0 0 0 0 0 0 0 0 
~~~
</details>

~~~cpp
// no 5
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 1; i < 10; ++i) { t[i] = t[i] + t[i - 1]; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 3 6 10 15 19 22 24 25 25 
~~~
</details>

~~~cpp
// no 6
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 1; i < 10; i = i + 2) { t[i] = 0; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 0 3 0 5 0 3 0 1 0 
~~~
</details>

~~~cpp
// no 7
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 0; i < 5; ++i) { t[i + 5] = t[i]; }
for (auto e: t) cout << e << ' ';
~~~

<details>
<summary>Solution</summary>

~~~
1 2 3 4 5 1 2 3 4 5 
~~~
</details>

~~~cpp
// no 8
array<int, 10> t{1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
for (int i = 1; i < 5; ++i) { t[i] = t[9 - i]; }
for (auto e: t) cout << e << ' ';   
~~~

<details>
<summary>Solution</summary>

~~~
1 1 2 3 4 4 3 2 1 0 
~~~
</details>