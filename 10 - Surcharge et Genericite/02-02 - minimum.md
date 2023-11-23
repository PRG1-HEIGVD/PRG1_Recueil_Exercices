# min(a, b, c)

Reprendre l'exercice [04-01 - minimum](../04%20-%20Fonctions/04-01%20-%20minimum.md) en le rendant générique.

<details>
<summary>Solution</summary>

~~~cpp
template<typename T>
T& min(T& a, T& b, T& c) {
   return a < c ? (a < b ? a : b) : (b < c ? b : c);
}
~~~

</details>
