# Ré-écriture de boucles (2)

Attention, dans les exercices qui suivent, votre code doit être valide quelque soit la valeur de `n` et les variables doivent avoir la même portée (scope) que dans le code original.

1. Réécrire la boucle suivante avec une boucle `while`
  
~~~cpp 
for (int i = 0; i < n; ++i) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
{ // bloc nécessaire pour limiter le scope de la variable de boucle i 
   int i = 0;
   while (i < n) {
      cout << i << endl;
      ++i;
   }
}
~~~
</details>

2. Réécrire la boucle suivante avec une boucle `do ... while`

~~~cpp 
for (int i = 0; i < n; ++i) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
if (int i = 0; i < n) { // déclaration dans le if pour limiter le scope de la variable de boucle i
   do {
      cout << i << endl;
      ++i; 
   } while (i < n);
}
~~~

ou

~~~cpp
{ // bloc nécessaire pour limiter le scope de la variable de boucle i
   int i = 0;
   if (i < n) { 
      do {
         cout << i << endl;
         ++i; 
      } while (i < n);
   }
}
~~~
</details>

---

3. Réécrire la boucle suivante avec une boucle `for`

~~~cpp 
int i = 0; 
while (i-- > n) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
int i = 0; // déclaration hors du for pour ne pas limiter le scope de la variable 
for (; i-- > n;) {
    cout << i << endl;
}
~~~
</details>

4. Réécrire la boucle suivante avec une boucle `do ... while`

~~~cpp 
int i = 0; 
while (i-- > n) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
int i = 0; 
if (i-- > n) {
   do {
      cout << i << endl;
   } while (i-- > n);
}
~~~
</details>

---

5. Réécrire la boucle suivante avec une boucle `for`

~~~cpp 
int i = 0; 
do {
  cout << i << endl;
  ++i; 
} while (i < n);   
~~~

<details>
<summary>Solution</summary>

~~~cpp
int i = 0; 
cout << i << endl; 
for (++i; i < n; ++i) {
    cout << i << endl;
}
~~~
</details>

6. Réécrire la boucle suivante avec une boucle `while`

~~~cpp 
int i = 0; 
do {
  cout << i << endl;
  ++i; 
} while (i < n);   
~~~

<details>
<summary>Solution</summary>

~~~cpp
int i = 0; 
cout << i << endl; 
while (++i, i < n) {
    cout << i << endl;
}
~~~
</details>
