# if ... else -> ?:

Réécrivez les extraits de code suivants en une seule ligne en utilisant un ou des opérateurs ternaires 

~~~cpp 
if (a > 0) {
   b += a;
} else {
   b -= 2*a; 
}
~~~

<details>
<summary>Solution</summary>

~~~cpp 
b += a > 0 ? a : -2*a; 
// plus propre que 
b = a > 0 ? b + a : b - 2*a; 
~~~

</details>

~~~cpp 
if (d == 0.) {
   r = 1e100;
} else {
   r = n/d; 
}
~~~

<details>
<summary>Solution</summary>


~~~cpp 
r = d == 0. ? 1e100 : n/d;

// ou en utilisant le fait que la conversion de double en bool est équivalent à (d != 0)
r = d ? n / d : 1e100; 
~~~

</details>

~~~cpp 
if (a > 0) {
   b += 1;
} else if (a == 0) {
   b = 0;
} else {
   b *= 2;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp 
b = a > 0 ? b + 1 : ( a == 0 ? 0 : 2 * b);
~~~
</details>
