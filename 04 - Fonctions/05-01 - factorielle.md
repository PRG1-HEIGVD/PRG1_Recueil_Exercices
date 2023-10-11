# Factorielle

La factorielle d'un nombre est décrite comme suit

`5! = 1 * 2 * 3 * 4 * 5`<br>
`6! = 1 * 2 * 3 * 4 * 5 * 6` ou `6! = 6 * 5!`<br>

Ainsi `n! = n * (n-1)!` avec `1! = 1` et `0! = 1` pour `n >= 0`

Ecrire une fonction récursive *facto* qui retourne la valeur de `n!` pour *n* reçu en paramètre.

[Wikipedia - Factorial](https://en.wikipedia.org/wiki/Factorial)

<details>
<summary>Solution</summary>

~~~cpp
int facto(int n) {

   // cas trivial
   if (n == 0)
      return 1;

   // appel récursif
   return n * facto( n - 1 );
}
~~~

</details>
