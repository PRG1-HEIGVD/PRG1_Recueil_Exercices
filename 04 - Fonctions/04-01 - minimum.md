# min(a, b, c)
Écrire une fonction *min* qui retourne le minimum de 3 valeurs reçues en paramètre.

Les instructions suivantes doivent être possibles:

~~~cpp
int a = 5;
int b = 2;
int c = 9;

cout << min(a, b, c);
min(a, b, c) = 1;
int& d = min(a, b, c);
~~~

**NB** ne pas utiliser de `if`

<details>
<summary>Solution</summary>

~~~cpp

int& min(int& a, int& b, int& c) {
      return a < c ? (a < b ? a : b) : (b < c ? b : c);
}

~~~

</details>

<details>
<summary>Solution plus propre</summary>

~~~cpp

int& min(int& a, int& b) {
   return a < b ? a : b;
}

int& min(int& a, int& b, int& c) {
   return min(a, min(b,c));
}

~~~

</details>
