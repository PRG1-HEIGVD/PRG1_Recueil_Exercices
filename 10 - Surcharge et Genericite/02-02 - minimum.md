# min(a, b, c)

Reprise de l'exercice [04-01 - minimum](../04%20-%20Fonctions/04-01%20-%20minimum.md)

Écrire une fonction *min* qui retourne le minimum de 3 valeurs de **type quelconque** reçues en paramètre.

Les instructions suivantes doivent être possibles:

~~~cpp
int    a = 5;
int    b = 2;
int    c = 9;

double d = 5.0;
double e = 2.0;
double f = 9.0;

cout << min(a, b, c);
min(a, b, c) = 1;
int& min_abc = min(a, b, c);

cout << min(d, e, f);
min(d, e, f) = 1;
double& min_def = min(d, e, f);
~~~

<details>
<summary>Solution</summary>

~~~cpp
template<typename T>
T& min(T& a, T& b, T& c) {
   return a < c ? (a < b ? a : b) : (b < c ? b : c);
}
~~~

</details>
