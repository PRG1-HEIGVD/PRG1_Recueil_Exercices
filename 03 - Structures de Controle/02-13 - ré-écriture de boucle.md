# Ré-écriture de boucles

1. Réécrire la boucle suivante 

~~~cpp 
for (; i < 10; ++i) {
   cout << i << endl;
}
~~~

- avec une boucle `while`
- avec une boucle `do ... while`

Attention, votre code doit être valide quelque soit la valeur de départ de `i` et quelque soit l'utilisation subséquente de la valeur de `i` en sortie de la boucle

<details>
<summary>Solution avec while</summary>

~~~cpp
while (i < 10) {
   cout << i << endl;
   ++i;
}
~~~
</details>

<details>
<summary>Solution avec do ... while</summary>

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

2. Réécrire la boucle suivante

~~~cpp 
while (i-- > 10) {
   cout << i << endl;
}
~~~


- avec une boucle `for`
- avec une boucle `do ... while`

<details>
<summary>Solution avec for</summary>

~~~cpp
for (; i-- > 10;) {
    cout << i << endl;
}
~~~
</details>

<details>
<summary>Solution avec do ... while</summary>

~~~cpp
if (i > 10) {
   do {
      --i;
      cout << i << endl;
   } while (i > 10);
}
--i;   // nécessaire pour que i aie la même valeur en fin de boucle
~~~
</details>

---

3. Réécrire la boucle suivante

~~~cpp 
do {
  cout << i << endl;
  ++i; 
} while (i < 10);   
~~~

- avec une boucle `for`
- avec une boucle `while`

<details>
<summary>Solution avec for</summary>

~~~cpp
cout << i << endl; 
for (++i; i < 10; ++i) {
    cout << i << endl;
}
~~~
</details>

<details>
<summary>Solution avec while</summary>

~~~cpp
cout << i << endl; 
++i;
while (i < 10) {
    cout << i << endl;
    ++i; 
}
~~~
</details>
