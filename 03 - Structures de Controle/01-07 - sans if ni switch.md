# Sans if ni switch

Réécrivez les extraits de code suivants en n'utilisant ni `if` ni `switch` mais exclusivement des opérateurs de comparaisons et des opérateurs logiques.

~~~cpp
if (i < 1) {
   b = true;
} else {
   b = i > 2;
}
~~~

Votre réponse : <textarea cols="40" rows="1" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~cpp
b = (i < 1) or (i > 2);
~~~
</details>

~~~cpp
if (j == 0) {
   b = true;
} else {
   if (i / j < k) {
      b = false;
   } else {
      b = true;
   }
}
~~~

Votre réponse : <textarea cols="40" rows="1" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~cpp
b = (j == 0) or (i / j >= k);
~~~

</details>

~~~cpp
if (j == 0) {
   b = false;
} else {
   if (i / j < k) {
      b = true;
   } else {
      b = false;
   }
}
~~~

Votre réponse : <textarea cols="40" rows="1" style="font-size: 15pt"></textarea>

<details>
<summary>Solution</summary>

~~~cpp
b = (j != 0) and (i / j < k);
~~~

</details>