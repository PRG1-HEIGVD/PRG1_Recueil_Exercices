# Point avec des limites de déplacement
Reprenez la classe Point de l'exercice 01-01 et faites les modifications / ajouts nécessaires afin d'y intégrer les fonctionnalités suivantes :

- Chaque point a une limite max de déplacement sur l'axe horizontal et une autre pour l'axe vertical.
- Ces limites ne peuvent pas être modifiées après la création d'un point et peuvent être différentes d'un point à l'autre. Par defaut la limite est 100.
- Le déplacement d'un point n'est valable que s'il respecte la limite max des deux axes.


Le code ci-dessous doit s'exécuter correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    Point p1(1.2, 2.4);
    cout << "p1"; p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1"; p1.afficher();

    Point p2(3., 4.2, 10., 10.);
    cout << "p2"; p2.afficher();
    p2.deplacer(15, 2);
    cout << "p2"; p2.afficher();
    p2.deplacer(3, 2);
    cout << "p2"; p2.afficher();

    return EXIT_SUCCESS;
}
~~~

~~~text
p1(1.2,2.4), maxX = 100, maxY = 100
p1(2.2,5.4), maxX = 100, maxY = 100
p2(3,4.2), maxX = 10, maxY = 10
p2(3,4.2), maxX = 10, maxY = 10
p2(6,6.2), maxX = 10, maxY = 10
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
    Point(double x, double y, double maxX = 100., double maxY = 100.);
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    double getMaxX() const;
    double getMaxY() const;
    void deplacer(double dx, double dy);
    void afficher() const;
private:
    double x, y;
    const double maxX;
    const double maxY;
};

// -----------------------------------------------------------------



int main() {

    Point p1(1.2, 2.4);
    cout << "p1"; p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1"; p1.afficher();

    Point p2(3., 4.2, 10., 10.);
    cout << "p2"; p2.afficher();
    p2.deplacer(15, 2);
    cout << "p2"; p2.afficher();
    p2.deplacer(3, 2);
    cout << "p2"; p2.afficher();

    return EXIT_SUCCESS;
}

// -----------------------------------------------------------------
Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y, double maxX, double maxY) : x(x), y(y), maxX(maxX), maxY(maxY) {}


void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

double Point::getMaxX() const {
    return this->maxX;
}

double Point::getMaxY() const {
    return this->maxY;
}

void Point::deplacer(double dx, double dy) {
    if(x + dx <= maxX && y + dy <= maxY){
        x += dx;
        y += dy;    
    }        
}

void Point::afficher() const {
    cout << "(" << x << "," << y << ")" << ", maxX = " << maxX << ", maxY = " << maxY << endl;
}
// -----------------------------------------------------------------
~~~



</details>