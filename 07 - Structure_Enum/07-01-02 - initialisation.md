# struct - déclaration
Soient les `struct` ci-dessous.

~~~cpp
struct Coord {
   int x, y, z;
}

struct Cercle {
   Coord centre;
   int   rayon;
}
~~~

Que valent les déclarations proposées ?

1. `Cercle cercle = {1, {2, 3, 4}};`
2. `Cercle cercle = {1};`
3. `Cercle cercle = {};`
4. `Cercle cercle = {1, {2, 3}};`
5. `Cercle cercle = {1, 2, 3, 4};`
6. `Coord  coord  = {x=1, y=2, z=3};`
7. `Coord  coord  = {.x=1, .y=2, .z=3};`
8. `Coord  coord  = {.x=1,       .z=3};`
9. `Coord  coord;`

<details>
<summary>Solutions</summary>

| no |  R  |  X  |  Y  |  Z  | Commentaire                                         |
|--- |---  |---  |---  |---  |---                                                  |
| 1  | 1   | 2   | 3   | 4   | l'agégat est complet                                |
| 2  | 1   | 0   | 0   | 0   | seul le rayon est renseignl, le reste à `0`         |
| 3  | 0   | 0   | 0   | 0   | l'agrégat est vide, donc tout est à `0`             |
| 4  | 1   | 2   | 3   | 0   | manque la valeur de Z, => à `0`                     |
| 5  | 1   | 2   | 3   | 4   | tout est renseigné en séquence                      |
| 6  | X   | X   | X   | X   | erreur de syntaxe, manque les `.`  exemple : `.x=1` |
| 7  | -   | 1   | 2   | 3   | tout est renseigné par nom                          |
| 8  | -   | 1   | 0   | 3   | la valeur manquante est déterminée et vaut `0`      |
| 9  | ?   | ?   | ?   | ?   | les valeurs sont indéterminées.                     |

</details>
