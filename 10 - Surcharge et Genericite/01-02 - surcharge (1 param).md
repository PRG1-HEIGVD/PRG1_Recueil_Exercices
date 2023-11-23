# fonctions surchargées (1 paramètre)

Que produisent les appels aux fonctions ci-dessous ?<br>
Indiquer les cas d'ambiguité.

~~~cpp
double      f(signed char) { cout << "Fonction no 1"; return 0.; }
signed char f(int&)        { cout << "Fonction no 2"; return 0 ; }
int         f(const int&)  { cout << "Fonction no 3"; return 0 ; }
float       f(unsigned)    { cout << "Fonction no 4"; return 0 ; }
unsigned    f(double)      { cout << "Fonction no 5"; return 0 ; }
float       f(float&)      { cout << "Fonction no 6"; return 0.; }
~~~

<br>

~~~cpp
f('a');
~~~
<details>
<summary>Solution</summary>

- `Fonction no 1` sur une machine avec `signed char    (type exact)
- `Fonction no 3` sur une machine avec `unsigned char` (ajustement de type)

NB : la no 2 n'est pas possible (`int&` sur une constante `'a'`)

</details>

~~~cpp
f(42);
~~~

<details>
<summary>Solution</summary>

- `Fonction no 3` (type exact)

</details>

~~~cpp
int i = 42;
f(++i);	
~~~

<details>
<summary>Solution</summary>

Les opérateurs suffixés, typiquement `++i` et `--i` retournent une référence sur la variable [cppreference](https://en.cppreference.com/w/cpp/language/operators)

- `Fonction no 2`

</details>

~~~cpp
int j = 42;
f(j--);	
~~~

<details>
<summary>Solution</summary>

Les opérateurs postfixés, typiquement `i++` et `i--` retournent une copie de la variable [cppreference](https://en.cppreference.com/w/cpp/language/operators)

- `Fonction no 3`

</details>

~~~cpp
f(2ull);
~~~
<details>
<summary>Solution</summary>

`2ull` est un `unsigned long long`

4 fonctions sont candidates et il n'y a pas de priorité de choix => **ambiguité**

- Fonction no 1 (conversion de `unsigned long long` en `signed char`
- Fonction no 3 (conversion de `unsigned long long` en `const int&`
- Fonction no 4 (conversion de `unsigned long long` en `unsigned `
- Fonction no 5 (conversion de `unsigned long long` en `double`

</details>

~~~cpp
long   a;
double b;
f(a < b);
~~~

<details>
<summary>Solution</summary>

La comparaison d'un `long int` avec un `double` n'est pas directement possible.<br>Un ajustemnet de type est nécessaire `long` => `double`

Ensuite la comparaison retoure un `bool`.<br>En l'absence de correspondance exacte, il y a promotion `bool` => `int`

- `Fonction no 3`

</details>

~~~cpp
float r = 2.f;
f(r *= 2.l);
~~~

<details>
<summary>Solution</summary>

La multiplication d'un `float` par un `long double` n'est pas directement possible.<br>Un ajustemnet de type est nécessaire `float` => `long double`

L'opérateur `*=` retourne une référence à la variable.<br>
La seule fonction possible est la 6, au prix d'une conversion dégradante `long double` => `float`

- `Fonction no 6`

</details>

~~~cpp
f(f(2u));
~~~

<details>
<summary>Solution</summary>

Dans une premier temps, `f(2u)` appelle la Fonction no 4 qui retourne un `float` mais sans référence.<br>
L'appel de f(`double`) correspond à la Fonction no 5

- `Fonction no 5`

</details>

~~~cpp
f('2') ? f(2.0) : f(-2.0); 
~~~

<details>
<summary>Solution</summary>

Comme vu précédemment, `f('2')` appelle la Fonction no 3 (sur une machine avec `unsigned char`).<br>
La fonction retournant `false`, `f(-2.0)` est appelé ce qui correspond à la Fonction no 5

- `Fonction no 3` et `Fonction no 5`

</details>
