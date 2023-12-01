# Tri par insertion

Effectuez le tri par insertion sur les tableaux suivants. 
Indiquez l'état du tableau après chaque écriture dans 
le tableau, même si elle écrit une valeur déjà présente. 
Indiquez à part le contenu de la variable tampon

~~~
1) 3 2 5 1 4
~~~

<details>
<summary>Solution</summary>

~~~
TABLEAU   | TMP 
3 2 5 1 4 | 2
3 3 5 1 4 
2 3 5 1 4 | 5
2 3 5 1 4 | 1
2 3 5 5 4
2 3 3 5 4
2 2 3 5 4
1 2 3 5 4 | 4
1 2 3 5 5
1 2 3 4 5
~~~

</details>


~~~
2) 4 3 2 5 1
~~~

<details>
<summary>Solution</summary>

~~~
TABLEAU   | TMP 
4 3 2 5 1 | 3
4 4 2 5 1
3 4 2 5 1 | 2
3 4 4 5 1
3 3 4 5 1
2 3 4 5 1 | 5
2 3 4 5 1 | 1
2 3 4 5 5
2 3 4 4 5
2 3 3 4 5
2 2 3 4 5
1 2 3 4 5
~~~

</details>

~~~
3) 5 4 2 3 1
~~~

<details>
<summary>Solution</summary>

~~~
TABLEAU   | TMP 
5 4 2 3 1 | 4
5 5 2 3 1 
4 5 2 3 1 | 2
4 5 5 3 1
4 4 5 3 1
2 4 5 3 1 | 3
2 4 5 5 1
2 4 4 5 1
2 3 4 5 1 | 1
2 3 4 5 5
2 3 4 4 5
2 3 3 4 5
2 2 3 4 5
1 2 3 4 5
~~~

</details>

