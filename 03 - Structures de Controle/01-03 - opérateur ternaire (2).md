# ?: -> if ... else

Réécrivez les extraits de code suivants en n'utilisant pas d'opérateur ternaire mais uniquement `if ... else`

~~~cpp 
a = a >= 1 ? 42 : a * a; 
~~~

<textarea style="font-size: 15pt" cols="80" rows="6"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a >= 1) {
   a = 42;
} else { 
   a *= a;
} 
~~~
</details>

~~~cpp 
b = a == 2 ? 32 : ( a < 5 ? 12 : 23 );
~~~

<textarea style="font-size: 15pt" cols="80" rows="8"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a == 2) {
   b = 32;  
} else if (a < 5) {
   b = 12;
} else {
   b = 23;
}         
~~~
</details>

~~~cpp 
c = a < 0 ? ( b < 0 ? a : -a ) : ( b < 5 ? a + b : a - b );
~~~

<textarea style="font-size: 15pt" cols="80" rows="12"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a < 0) {
   if (b < 0) {
      c = a;
   } else {
      c = -a; 
   }
} else if (b < 5) {
   c = a + b;
} else {  
   c = a - b;
}               
~~~

</details>