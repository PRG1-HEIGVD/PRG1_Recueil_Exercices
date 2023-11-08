# Déplacer un point

Soient les directions et les déclarations

~~~cpp
enum class Direction {HAUT, BAS, GAUCHE, DROITE};

struct Coord {
   int x = 0;
   int y = 0;
};

using Point = Coord;
~~~

Ecrire une fonction *deplacer* permettant de déplacer un point  d'une unité dans une direction donnée.

Le point et la direction sont reçus en paramètre.

<details>
<summary>Solution</summary>

~~~cpp
void deplacer (Point& p, Direction d) {
   switch (d) {
      case Direction::HAUT   : ++p.y; break;
      case Direction::BAS    : --p.y; break;
      case Direction::GAUCHE : --p.x; break;
      case Direction::DROITE : ++p.x; break;
   }
}
~~~
</details>

