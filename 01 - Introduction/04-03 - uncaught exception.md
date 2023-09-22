# Uncaught Exception

Compiler et exécutez le programme ci-dessous avec le debugger (l'insecte vert
à droite du triangle vert dans CLion) pour déterminer à quelle valeur de i le
programme plante.

Pour le voir, vous devrez naviguer dans la colonne de gauche du debugger jusqu'à la fonction `main`.

~~~cpp
#include <array>

int main() {
   std::array a { 1, 2, 3};
   for(int i = 0; i < 10; ++i)
      a.at(i) = i;
   cout << "hello" << endl;
}
~~~

<details>
<summary>Solution</summary>
Le programme s'arrête quand i vaut 3
</details>
