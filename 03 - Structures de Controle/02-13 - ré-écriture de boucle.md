# Ré-écriture de boucles

1. Réécrire la boucle suivante avec une boucle `while`
   Attention, votre code doit être valide quelque soit la valeur de départ de `i` et quelque soit l'utilisation subséquente de la valeur de `i` en sortie de la boucle

~~~cpp 
for (; i < 10; ++i) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
while (i < 10) {
   cout << i << endl;
   ++i;
}
~~~
</details>

2. Réécrire la boucle suivante avec une boucle `do ... while`

~~~cpp 
for (; i < 10; ++i) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
if (i < 10) {
   do {
      cout << i << endl;
      ++i; 
   } while (i < 10);
}
~~~
</details>

---

3. Réécrire la boucle suivante avec une boucle `for`

~~~cpp 
while (i-- > 10) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
for (; i-- > 10;) {
    cout << i << endl;
}
~~~
</details>

4. Réécrire la boucle suivante avec une boucle `do ... while`

~~~cpp 
while (i-- > 10) {
   cout << i << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
if (i > 10) {
   do {
      --i;
      cout << i << endl;
   } while (i > 10);
}
--i;   // nécessaire pour que i ait la même valeur en fin de boucle
~~~
</details>

---

5. Réécrire la boucle suivante avec une boucle `for`

~~~cpp 
do {
  cout << i << endl;
  ++i; 
} while (i < 10);   
~~~

<details>
<summary>Solution</summary>

~~~cpp
cout << i << endl; 
for (++i; i < 10; ++i) {
    cout << i << endl;
}
~~~
</details>

6. Réécrire la boucle suivante avec une boucle `while`

~~~cpp 
do {
  cout << i << endl;
  ++i; 
} while (i < 10);   
~~~

<details>
<summary>Solution</summary>

~~~cpp
cout << i << endl; 
++i;
while (i < 10) {
    cout << i << endl;
    ++i; 
}
~~~
</details>
