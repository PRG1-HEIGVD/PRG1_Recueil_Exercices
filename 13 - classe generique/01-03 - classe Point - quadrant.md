# classe générique Point - quadrant 

Reprendre l'exercice précédant [01-02 - classe Point](01-02%20-%20classe%20Point.md)

Soit le dessin

~~~
vector<Point<int>> dessin {{"p1",  1,  2},
                           {"p2",  4,  2},
                           {"p3",  9,  8},
                           {"p4", -1,  5},
                           {"p5",  3, -1},
                           {"p6",  7,  0}};
~~~

Ecrire le code permettant de compter combien de `point` se trouvent dans l'un des quandrants `I`, `II`, `III`, `IV` choisi.<br>
**NB** : Une coordonnée sur un axe, voire les deux, n'est sur aucun quadrant.

Donner un exemple d'appel.

<details>
<summary>Solution avec foncteur générique</summary>

~~~cpp
enum class Quadrant {I=1, II, III, IV};

template <typename T>
struct DansQuadrant {
   Quadrant q;
   bool operator() (const Point<T>& p) {
      switch (q) {
         case Quadrant::I   : return p.getCoord().getX() > T() and p.getCoord().getY() > T();
         case Quadrant::II  : return p.getCoord().getX() < T() and p.getCoord().getY() > T();
         case Quadrant::III : return p.getCoord().getX() < T() and p.getCoord().getY() < T();
         case Quadrant::IV  : return p.getCoord().getX() > T() and p.getCoord().getY() < T();
         default            : return false;
      }
   }
};

cout << count_if(dessin.begin(), dessin.end(), DansQuadrant<int>{Quadrant::I});
~~~

</details>


<details>
<summary>Solution alternative avec fonction générique</summary>

~~~cpp
enum class Quadrant { I, II, III, IV };

template<typename T, Quadrant q>
bool est_dans_quadrant (Point<T> const& p) {
   switch (q) {
      case Quadrant::I :
         return p.getCoord().getX() > 0 and p.getCoord().getY() > 0;
      case Quadrant::II :
         return p.getCoord().getX() < 0 and p.getCoord().getY() > 0;
      case Quadrant::III :
         return p.getCoord().getX() < 0 and p.getCoord().getY() < 0;
      case Quadrant::IV :
         return p.getCoord().getX() > 0 and p.getCoord().getY() < 0;
      default:
         return false;
   }
}

cout << count_if(dessin.begin(), dessin.end(),est_dans_quadrant<int,Quadrant::I>);
~~~

</details>

