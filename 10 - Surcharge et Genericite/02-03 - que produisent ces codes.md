# Que produisent ces codes


~~~cpp
// no 1
template
T somme(T a, T b) {
    return (a + b);
}

int main() {
   int   a = 1;
   float b = 2.5f;
   cout << somme(a, a) << " / " << somme(b, b) ;
}
~~~

<details>
<summary>Solution</summary>

Erreur de compilation, le `template` est incomplet.

------------------------------------------------
</details>

~~~cpp
// no 2
template <typename T>
T somme(T a, T b) {
   return (a + b);
}

int main() {
   int   a = 1;
   float b = 2.5f;
   cout << somme(a, b) << " / " << somme(a, b);
}
~~~

<details>
<summary>Solution</summary>

Erreur de compilation, la déduction de type n'est pas possible, les types sont différents.

------------------------------------------------
</details>

~~~cpp
// no 3
template <typename T>
T somme(T a, T b) {
   return (a + b);
}

int main() {
   int   a = 1;
   float b = 2.5f;
   cout << somme<int>(a, b) << " / " << somme<float>(a, b);
}
~~~

<details>
<summary>Solution</summary>

`3 / 3.5`

- l'appel `somme<int>  (a, b)` fait la somme en `int`   => 1 + 2 = 3
- l'appel `somme<float>(a, b)` fait la somme en `float` => 1.0f + 2.5f = 3.5f

------------------------------------------------
</details>

~~~cpp
// no 4
template <typename T>
T somme(T a, T b) {
   return (a + b);
}

int main() {
   int  a = 1;
   char d = 'd'; // d vaut 100
   cout << somme<char>(d, a) << " / " << somme<int>(d, a);
}
~~~

<details>
<summary>Solution</summary>

`e / 101`

- l'appel `somme<char>(d, a)` fait la somme en `char`<br>
    100 + 1 = 100 en entier à cause du `+` => promotion en `int`<br>
    et retourne ceci dans T qui est un `char` => 'e';
- l'appel `somme<int>(d, a)`  fait la somme en `int ` => 100 + 1 = 101

------------------------------------------------
</details>

~~~cpp
// no 5
template <typename T1, typename T2>
T1 somme(T1 a, T2 b) {
   return (a + (T1)b);
}

int main() {
   int   a = 1;
   float b = 2.5f;
   cout << somme(a, b) << " / " << somme(b, a);
}
~~~

<details>
<summary>Solution</summary>

`3 / 3.5`

- l'appel `somme(a, b)` utilise `int` pour `T1` et `float` pour `T2`
	- la somme se fait en int (`int` comme reçu et `float` casté en  `int`)
	- le résultat `3` est transmis en valeur de retour de type `int`
- l'appel `somme(b, a)` utilise `float ` pour `T1` et `int` pour `T2`
	- la somme se fait en `float`
	- le résultat `3.5` est transmis en valeur de retour de type `float`

------------------------------------------------
</details>

~~~cpp
// no 6
template <typename T1, typename T2>
T1 somme(T1 a, T2 b) {
   return (a + b);
}

template <typename T>
T somme(T a, T b) {
   return (a + b + 1);
}

int main() {
   int   a = 1;
   float b = 2.5f;
   cout << somme(a, a) << " / "
        << somme(b, a) << " / "
        << somme(a, b) << " / "
        << somme(b, b);
   return 0;
}
~~~

<details>
<summary>Solution</summary>

`3 / 3.5 / 3 / 6`

Il y a surcharge de la fonction *somme(..)* générique

1. `template <typename T1, typename T2> T1 somme(T1 a, T2 b)`
1. `template <typename T> T1 somme(T a, T b)`

<br>

- l'appel `somme(a, a)` avec (`int`, `int`) va appeler `T somme(T a, T b)` instancié en `int somme(int, int)`et retourner `1 + 1 + 1 = 3`
- l'appel `somme(b, a)` avec (`float`, `int`) va appeler `T1 somme(T1 a, T2 b)` instancié en `float somme(float, int)` et retourner `2.5f + (float)1 = 3.5f` en `float`
- l'appel `somme(a, b)` avec (`int`,`float`) va appeler `T1 somme(T1 a, T2 b)` instancié en `int somme(int, float)`et retourner `(float)1 + 2.5f = 3.5f` casté en `int`, soit `3`
- l'appel `somme(b, b)` avec (`float`, `float`) va appeler `T somme(T a, T b)` instancié en `float somme(float, float)` et retourner `2.5f + 2.5f + (float)1 = 6.f`


------------------------------------------------
</details>


