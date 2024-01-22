# Type générique - Bataille navale

Nous souhaitons créer une structure pour le développement d'un jeu de bataille navale.

Déclarer les types de données permettant de définir une surface de jeu

- les cellules peuvent être : `eau`, `bateau`, `touché`, `coulé`
- les cellules seront représentées respectivement par les caractères `.` `B` `x` `O`
- les dimensions `width` et `height` de la surface seront déterminées à la compilation

Après avoir fait toutes les déclarations, créer un jeu de **8 lignes** par **6 colonnes**.<br>Sur cette base, créer **manuellement** une situation de jeu et écrire l'opérateur de flux `<<` afin de représenter cette situation à l'écran.

~~~
----------
|....xxB.|
|........|
|..B..O..|
|..x..O..|
|..B..O..|
|........|
----------
~~~

<details>
<summary> Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <array>

using namespace std;

//------------------------------------------------------------
enum class Cell        {Eau, Bateau, Touche, Coule};
const array CellChar = {'.', 'B',    'x',    'O'};

//------------------------------------------------------------
template <typename T, size_t width>
using Row = array<T, width>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
using Grid = array<Row<T, width>, height>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
ostream& operator<< (ostream& os, const Grid<T, width, height>& g);

//------------------------------------------------------------
int main() {
   const Cell E = Cell::Eau;
   const Cell B = Cell::Bateau;
   const Cell T = Cell::Touche;
   const Cell C = Cell::Coule;

   using Game = Grid<Cell, 8, 6>;

   Game game = {{{E, E, E, E, T, T, B, E},
                 {E, E, E, E, E, E, E, E},
                 {E, E, B, E, E, C, E, E},
                 {E, E, T, E, E, C, E, E},
                 {E, E, B, E, E, C, E, E},
                 {E, E, E, E, E, E, E, E}}};

   cout << game << endl;
}

//------------------------------------------------------------
template <typename T, size_t width, size_t heigth>
ostream& operator<< (ostream& os, const Grid<T, width, heigth>& g) {
   os << std::string(width+2, '-') << endl;
   for (const Row<T, width>& r : g) {
      os << '|';
      for (Cell c : r)
         os << CellChar.at((size_t)c);
      os << '|' << endl;
   }
   return os << string(width+2, '-') << endl;
}
~~~

</details>
