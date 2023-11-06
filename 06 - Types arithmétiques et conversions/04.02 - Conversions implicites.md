# Conversions implicites 

Soient les déclarations et modificiations du flux ci-dessous 

~~~cpp 
signed char sc = -1;
signed int s = -1;

unsigned char uc = 1;
unsigned int u = 1;
double d = 1;

cout << setprecision(10) << boolalpha;

// Notes : 
// pow(2,8)  vaut 256
// pow(2,16) vaut 65536
// pow(2,32) vaut 4294967296
~~~

Qu'affichent les lignes suivantes ? Justifiez votre réponse
- en ré-écrivant l'expression en rendant explicites toutes les conversions implicites
- en ajoutant toutes les parenthèses qui traduisent l'ordre implicite des opérateurs

---

~~~cpp
cout << s * d + u;
~~~

<details>
<summary>Solution</summary>

`0`

équivalent à `((double(-1) * 1.) + double(1u))`
</details>

---

~~~cpp
cout << s * u + d;
~~~

<details>
<summary>Solution</summary>

`4294967296`

équivalent à `(double(unsigned(-1) * 1u) + 1.)`
</details>

---

~~~cpp
cout << d * u + s;
~~~

<details>
<summary>Solution</summary>

`0`

équivalent à `((1. * double(1u)) + double(-1))`
</details>

---

~~~cpp
cout << sc * uc + d;
~~~

<details>
<summary>Solution</summary>

`0`

équivalent à `(double(int(-1) * int(1)) + 1.)`
</details>

---

~~~cpp
cout << sc * uc + s;
~~~

<details>
<summary>Solution</summary>

`-2`

équivalent à `(((int(-1) * int(1u)) + -1)`
</details>

---

~~~cpp
cout << sc * uc - u;
~~~

<details>
<summary>Solution</summary>

`4294967294`

équivalent à `(unsigned(int(-1) * int(1u)) - 1u)`
</details>

---

~~~cpp
cout << (s < u);
~~~

<details>
<summary>Solution</summary>

`false`

équivalent à `(unsigned(-1) < 1u)` avec `unsigned(-1)` qui vaut `4294967295`
</details>

---

~~~cpp
cout << (s < d);
~~~

<details>
<summary>Solution</summary>

`true`

équivalent à `(double(-1) < 1.)`
</details>

---

~~~cpp
cout << (-u < d);
~~~

<details>
<summary>Solution</summary>

`false`

équivalent à `(double(-1u) < 1)` avec `-1u` qui vaut `4294967295`
</details>

---

~~~cpp
cout << (-uc < d);
~~~

<details>
<summary>Solution</summary>

`true`

équivalent à `(double(-int(1)) < 1.)`
</details>

---

~~~cpp
cout << (-d < u);
~~~

<details>
<summary>Solution</summary>

`true`

équivalent à `(-1. < double(1u))`
</details>


