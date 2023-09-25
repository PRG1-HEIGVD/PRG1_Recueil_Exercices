# Priorité des opérateurs

Ajouter toutes les parenthèses aux expressions suivantes pour exprimer
explicitement l'ordre d'évaluation de l'expression qui existe implicitement
en vertu de l'ordre de priorité des opérateurs. 

Par exemple, l'expression

~~~cpp
a + b * c; 
~~~

doit être ré-écrite 

~~~cpp
(a + (b * c)); 
~~~

puisque la multiplication est prioritaire sur l'addition. De même, l'expression

~~~cpp
a / b * c; 
~~~

doit être ré-écrite

~~~cpp
((a / b) * c); 
~~~

Les opérateurs `/` et `*` de même priorité étant évalués de gauche à droite. Vous pouvez vous aider de la page [C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence) de cppreference.com

---

~~~cpp 
1 * 2 + 3 / 4 * 2
~~~

<details>
<summary>Solution</summary>

~~~cpp 
((1 * 2) + ((3 / 4) * 2))
~~~
</details>

---


~~~cpp 
a + b < c * d + e or f - g + h == i
~~~

<details>
<summary>Solution</summary>

~~~cpp 
(((a + b) < ((c * d) + e)) or (((f - g) + h) == i))
~~~
</details>

---

~~~cpp 
a == b < c
~~~

<details>
<summary>Solution</summary>

~~~cpp 
(a == (b < c))
~~~
</details>

---


~~~cpp 
a < b or c == d and e > b
~~~

<details>
<summary>Solution</summary>

~~~cpp 
((a < b) or ((c == d) and (e > b)))
~~~
</details>

---

~~~cpp 
++++a; 
~~~

<details>
<summary>Solution</summary>

~~~cpp
(++(++a)) 
~~~
</details>

---


~~~cpp 
+ a - - b * - c + - + d
~~~

<details>
<summary>Solution</summary>

~~~cpp 
(((+a) - ((-b) * (-c))) + (-(+d)))
~~~
</details>

---


~~~cpp 
a * b % c + d % e / f - g
~~~

<details>
<summary>Solution</summary>

~~~cpp 
((((a * b) % c) + ((d % e) / f)) - g)
~~~
</details>

---


~~~cpp 
+ a - b or c == d > e < f and g
~~~

<details>
<summary>Solution</summary>

~~~cpp 
(((+ a) - b) or ((c == ((d > e) < f)) and g))
~~~
</details>

---
