# Types numériques (théorie)

1. Dressez la liste exhaustive de tous les types entiers signés supportés par C++ 

<details>
<summary>Solution</summary>

~~~cpp 
// chaque ligne correspond à un type qui peut s'écrire de diverse manières.

signed char;
signed short int; signed short; short int; short; 
signed int; int; signed;
signed long int; signed long; long int; long;
signed long long int; signed long long; long long int; long long; 
~~~

Notons que l'ordre des mots clés peut également varier. Par exemple, le type `signed long long int` peut 
aussi s'écrire 

~~~cpp 
signed long long int; 
signed long int long; 
signed int long long; 
long signed long int; 
long signed int long;
// etcetera ... 
~~~

</details>

2. Idem pour les entiers non signés 

<details>
<summary>Solution</summary>

~~~cpp 
unsigned char;
unsigned short int; unsigned short; 
unsigned int; unsigned;
unsigned long int; unsigned long; 
unsigned long long int; unsigned long long; 
~~~

</details>

3. Le type int est-il signé ou non signé par défaut ?

<details>
<summary>Solution</summary>
signé
</details>

4. Le type char est-il signé ou non signé par défaut ? 


<details>
<summary>Solution</summary>
cela dépend du compilateur
</details>

5. Le domaine de définition des entiers est-il fixé par la norme ou dépend-il de l'environnement utilisé ?

<details>
<summary>Solution</summary>
Dépend de l'environnement utilisé
</details>