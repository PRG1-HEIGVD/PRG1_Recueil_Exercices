# rotateRight

Ecrire la fonction *rotateRight* permettant de décaler toutes les vateurs d'un vecteur vers la droite, la dernière valeur prenant la position d'indice 0

~~~cpp
avant : [1, 2, 3, 4, 5, 6, 7, 8, 9]
après : [9, 1, 2, 3, 4, 5, 6, 7, 8]
~~~

<details>
<summary>Solution</summary>

~~~cpp
void rotateRight(vector<int>& v) {
   if (v.size() > 1) {
      int tmp = v.back();
      for (size_t i = v.size() - 1; i > 0; --i) {
         v[i] = v[i - 1];
      }
      v[0] = tmp;
   }
}
~~~
</details>

