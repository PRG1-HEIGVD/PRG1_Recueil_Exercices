# Que produisent ces codes

Soit le vecteur déclaré.

~~~cpp
vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
~~~

Que valent les vecteurs après chacun des instructions ci-après.<br>
⚠️ les instructions sont dépendantes les unes des autres.

<br>


~~~cpp
// no 1
vector v1(v.begin(), v.end());
~~~

<details>
<summary>Solution</summary>

~~~
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
~~~

------------------------------

</details>

~~~cpp
// no 2
vector v2(v.begin() + 1, v.end() - 2);
~~~

<details>
<summary>Solution</summary>

~~~
[2, 3, 4, 5, 6, 7, 8]
~~~

------------------------------

</details>

~~~cpp
// no 3
vector v3(v.rbegin() + 1, v.rend() - 2);
~~~

<details>
<summary>Solution</summary>

~~~
[9, 8, 7, 6, 5, 4, 3]
~~~

------------------------------

</details>

~~~cpp
// no 4
v3.assign(v2.begin() + 1, v2.end() - 4);
~~~

<details>
<summary>Solution</summary>

~~~
[3, 4]
~~~

------------------------------

</details>

~~~cpp
// no 5
v3.erase(v3.begin());
~~~

<details>
<summary>Solution</summary>

~~~
[4]
~~~

------------------------------

</details>

~~~cpp
// no 6
v3.insert(v3.begin(), v.begin(), v.begin() + 2);
~~~

<details>
<summary>Solution</summary>

~~~
[1, 2, 4]
~~~

------------------------------

</details>

~~~cpp
// no 7
v3.insert(v3.begin(), v.rbegin(), v.rbegin() + 2);
~~~

<details>
<summary>Solution</summary>

~~~
[10, 9, 1, 2, 4]
~~~

------------------------------

</details>
