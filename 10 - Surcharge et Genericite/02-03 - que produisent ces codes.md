# Que produisent ces codes


~~~cpp
template
T somme(T a, T b) {
    return (a + b);
}

int main() {
   int   a = 1;
   float b = 2.5;
   cout << somme(a, a) << " / " << somme(b, a) ;
}
~~~

<details>
<summary>Solution</summary>

Erreur de compilation, le `template` est incomplet.

------------------------------------------------
</details>

~~~cpp
template <typename T>
T somme(T a, T b) {
   return (a + b);
}

int main() {
   int   a = 1;
   float b = 2.5;
   cout << somme<int>  (a, b) << " / " << somme<float>(a, b);
}
~~~

<details>
<summary>Solution</summary>

`3 / 3.5`

- l'appel `somme<int>. (a, b)` fait la somme en `int`    => 1 + 2 = 3
- l'appel `somme<float>(a, b)` fait la somme en `float ` => 1.0f + 2.5f = 3.5f

------------------------------------------------
</details>

~~~cpp
template <typename T>
T somme(T a, T b) {
   return (a + b);
}

int main() {
   int  a = 1;
   char d = 'd'; // d vaut 100
   cout << somme<char>(d, a) << " / " << somme<int> (d, a);
}
~~~

<details>
<summary>Solution</summary>

`e / 101`

- l'appel `somme<char>(d, a)` fait la somme en `char`<br>
    100 + 1 = 100 en entier à cause du `+`<br>
    et retourne ceci dans T qui est un `char` => 'e';
- l'appel `somme<int>(d, a)`  fait la somme en `int ` => 100 + 1 = 101

------------------------------------------------
</details>

~~~cpp
template <typename T1, typename T2>
T1 somme(T1 a, T2 b) {
   return (a + (T1)b);
}

int main() {
   int   a = 1;
   float b = 2.5;
   cout << somme(a, b) << " / " << somme(b, a);
}
~~~

<details>
<summary>Solution</summary>

`3 / 3.5`

- l'appel `somme(a, b)` utilise `int` pour `T1` et `float` pour `T2`
	- la somme se fait en double (`int` converti en `double` et `float` promu en `double`)
	- le résultat `3.5` est casté en `T1` => `3`
- l'appel `somme(b, a)` utilise `float ` pour `T1` et `int` pour `T2`
	- la somme se fait en double (`float` promu en `double` et `int` converti en `double`)
	- le résultat `3.5` est casté en `T1` => `3.5f`

------------------------------------------------
</details>

~~~cpp
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
   float b = 2.5;
   cout << somme(a, a) << " / " << somme(b, a);
   return 0;
}
~~~

<details>
<summary>Solution</summary>

`2 / 3.5`

Il y a surcharge de la fonction *somme* générique

1. `template <typename T1, typename T2> T1 somme(T1 a, T2 b)`
1. `template <typename T> T1 somme(T a, T b)`

<br>

- l'appel `somme(a, a)` avec (`int`, `int`) va appeler `T somme(T a, T b)` et retourner 2
- l'appel `somme(b, a)` avec (`float`, `int`) va appeler `T1 somme(T1 a, T2 b)` et retourner 3.5


------------------------------------------------
</details>


