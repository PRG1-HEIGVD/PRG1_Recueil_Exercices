# Que produisent ces codes

Soit l'opérateur de flux et le vecteur déclarés.

~~~cpp
template <typename T>
ostream& operator<< (ostream& os, span<T> s) {
   os << "[";
   for (size_t i=0; i<s.size(); ++i) {
      if (i) os << ", ";
      os << s[i];
   }
   return os << "]";
}

array  a {1, 2, 3};
vector v {1, 2, 3, 4, 5, 1, 2, 3, 4};
~~~

Que produisent les codes ci-après

<br>


~~~cpp
// no 1
cout << count(v.begin(), v.end(), *v.begin());
~~~

<details>
<summary>Solution</summary>

~~~
2
~~~

------------------------------

</details>

~~~cpp
// no 2
cout << count(v.begin(), v.end(), 6);
~~~

<details>
<summary>Solution</summary>

⚠️ aucune valeur trouvée, retourne `v.end()`<br>
**résultat indéterminé**

------------------------------

</details>

~~~cpp
// no 3
search(v.begin(), a.begin(),
       v.end(),   a.end());
~~~

<details>
<summary>Solution</summary>

⚠️ l'ordre des paramètres est faut, les itérateurs ne sont donc pas compatibles.<br>
**ne compile pas**

------------------------------

</details>

~~~cpp
// no 4
auto it = search(v.begin(),     v.end(),
                 a.begin() + 1, a.end());

cout << distance(v.begin(), it);
~~~

<details>
<summary>Solution</summary>

Recherche de [2, 3] dans le vecteur v
~~~
1
~~~

------------------------------

</details>

~~~cpp
// no 5
auto it = search(v.begin() + 1,     v.end(),
                 a.begin(),         a.end());

cout << distance(v.begin(), it);
~~~

<details>
<summary>Solution</summary>

Recherche de [1, 2, 3] dans le vecteur v depuis la position 1

~~~
5
~~~

------------------------------

</details>

~~~cpp
// no 6
auto resultat = equal(v.begin(), v.begin() + 3,
                      a.begin(), a.end());

cout << resultat;
~~~

<details>
<summary>Solution</summary>

~~~
true
~~~

------------------------------

</details>

~~~cpp
// no 6
auto resultat = equal(v.begin(), v.begin() + 3,
                      a.begin(), a.end());

cout << resultat;
~~~

<details>
<summary>Solution</summary>

~~~
true
~~~

------------------------------

</details>

~~~cpp
// no 7
auto resultat = equal(v.begin(), v.begin(),
                      v.begin(), v.end());

cout << resultat;
~~~

<details>
<summary>Solution</summary>

~~~
true
~~~

🤣 mais alors `v == v` aurait très bien fait l'affaire

------------------------------

</details>

~~~cpp
// no 8
copy(v.begin(), v.end(),a.begin());

cout << span<int>(a) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 2, 3]
~~~

⚠️ des valeurs ont été écrites au delà du array `a`

------------------------------

</details>

~~~cpp
// no 9
copy(a.begin(), a.end(),v.rbegin());

cout << span<int>(v) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 2, 3, 4, 5, 1, 3, 2, 1]
~~~

------------------------------

</details>

~~~cpp
// no 10
int mult(int a, int b) { return a * b; }
transform(a.begin(), a.end(), a.begin(), a.begin(), mult);

cout << span<int>(a) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 4, 9]
~~~

------------------------------

</details>

~~~cpp
// no 11
int mult(int a, int b) { return a * b; }
transform(v.begin(), v.end(),a.begin(), v.begin(), mult);

cout << span<int>(v) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 4, 9, 4, 10, 3, 8, 15, 4]
~~~

------------------------------

</details>

~~~cpp
// no 12
remove(v.begin(), v.end(), 5);

cout << span<int>(v) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 2, 3, 4, 1, 2, 3, 4, 4]
~~~

------------------------------

</details>

~~~cpp
// no 13
remove(v.begin(), v.end(), 2);

cout << span<int>(v) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 3, 4, 5, 1, 3, 4, 3, 4]
~~~

------------------------------

</details>
