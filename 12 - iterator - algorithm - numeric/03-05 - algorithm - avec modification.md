# Algorithm - avec modification
Soit l'opérateur de flux et les vecteurs déclarés.

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
copy(v.begin(), v.end(), a.begin());

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
// no 2
copy(a.begin(), a.end(), v.rbegin());

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
// no 3
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
// no 4
int mult(int a, int b) { return a * b; }
transform(a.begin(), a.end(), v.begin(), v.begin(), mult);

cout << span<int>(v) << endl;
~~~

<details>
<summary>Solution</summary>

~~~
[1, 4, 9, 4, 5, 1, 2, 3, 4]
~~~

------------------------------

</details>

~~~cpp
// no 5
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
// no 6
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
