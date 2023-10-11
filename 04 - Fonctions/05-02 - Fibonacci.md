# Fibonacci

La suite de Fibonacci est décrite comme suit

`Fn = Fn-1 + Fn-2` avec `F0 = 0` et `F1 = 1`


|F0 |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|...|
|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13| 21| 34| 55|...|

Ecrire une fonction récursive *fibo* qui retourne la valeur de `Fn` pour `n` reçu en paramètre.<br>


[Wikipedia - Fibonacci](https://en.wikipedia.org/wiki/Fibonacci_sequence)

<details>
<summary>Solution</summary>

~~~cpp
int fibo(int n) {

   // cas trivial
   if (n < 2)
      return n;

   // appels récursifs
   return fibo(n-2) + fibo(n-1);
}
~~~

</details>
