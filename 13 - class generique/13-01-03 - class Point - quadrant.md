# classe générique Point - quadrant 

Reprendre l'exercice précédant [11-01-02 - class Point](13-01-02%20-%20class%20Point.md)

Soit le dessin

~~~
vector<Point<int>> dessin {{"p1",  1,  2},
                           {"p2",  4,  2},
                           {"p3",  9,  8},
                           {"p4", -1,  5},
                           {"p5",  3, -1},
                           {"p6",  7,  0}};
~~~

Ecrire le code permettant de compter combien de `point` se trouvent dans l'un des quandrants `I`, `II`, `III`, `IV` choisi.

Donner un exemple d'appel.

<details>
<summary>Solution</summary>

~~~cpp
enum class Quadrant {I=1, II, III, IV};

template <typename T>
struct DansQuadrant {
   Quadrant q;
   bool operator() (const Point<T>& p) {
      switch (q) {
         case Quadrant::I   : return p.getCoord().getX() >= 0 and p.getCoord().getY() >= 0;
         case Quadrant::II  : return p.getCoord().getX() <= 0 and p.getCoord().getY() >= 0;
         case Quadrant::III : return p.getCoord().getX() <= 0 and p.getCoord().getY() <= 0;
         case Quadrant::IV  : return p.getCoord().getX() >= 0 and p.getCoord().getY() <= 0;
      }
   }
};

cout << count_if(dessin.begin(), dessin.end(), DansQuadrant<int>{Quadrant::I});
~~~

</details>
