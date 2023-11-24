# Classes - Constructeurs et fonctions membres
Implémenter une classe Point permettant de manipuler un point du plan.

Complétez le code suivant afin qu'il s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <cstdlib>
using namespace std;

int main() {
   Point centre;
   centre.afficher();

   Point p(1.2, 2.4);
   p.afficher();
   p.deplacer(0.8, 0.6);
   p.afficher();

   return EXIT_SUCCESS;
}
~~~

~~~text
(0,0)
(1.2,2.4)
(2,3)
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
public:
    Point();
    Point(double x, double y);
    void deplacer(double dx, double dy);
    void afficher() const;
private:
    double x, y;
};

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y) : x(x), y(y) {}

void Point::deplacer(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::afficher() const {
    cout << "(" << x << "," << y << ")" << endl;
}


int main() {
    Point centre;
    centre.afficher();

    Point p(1.2, 2.4);
    p.afficher();
    p.deplacer(0.8, 0.6);
    p.afficher();

    return EXIT_SUCCESS;
}
~~~



</details>