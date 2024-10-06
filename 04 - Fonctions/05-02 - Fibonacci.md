# Fibonacci

La suite de Fibonacci est décrite comme suit

$$F_n = F_{n-1} + F_{n-2} \text{ avec } F_0 = 0 \text{ et }  F_1 = 1$$

|$F_0$|$F_1$|$F_2$|$F_3$|$F_4$|$F_5$|$F_6$|$F_7$|$F_n$|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|  0  |  1  |  1  |  2  |  3  |  5  |  8  | 13  | ... |

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
