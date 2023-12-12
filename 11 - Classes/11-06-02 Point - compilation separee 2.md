# Point avec un identifiant unique et un compteur en compilation séparée
Reprenez le code de l'exercice 03-02 et réorganisez-le en compilation séparée.

~~~text
Point.h
Point.cpp
main.cpp
~~~

Le résultat de l'exécution du programme ne doit pas changer.

~~~text
Point ID = 1, (1.2,2.4), maxX = 100, maxY = 100
Nombre de points : 1
-------------------------------------------
Point ID = 2, (3,4.2), maxX = 10, maxY = 10
Nombre de points : 2
-------------------------------------------
Point ID = 3, (5,10), maxX = 100, maxY = 100
Nombre de points : 2
-------------------------------------------
~~~

<details>
<summary>Point.h</summary>

~~~cpp
#ifndef POINT_H
#define POINT_H

class Point {
public:
   Point();
   Point(double x, double y, double maxX = 100., double maxY = 100.);
   ~Point();

   void setX(double x);
   void setY(double y);

   double getX() const { return x; }
   double getY() const { return y; }
   double getMaxX() const { return maxX; }
   double getMaxY() const { return maxY; }
   double getPointId() const { return id; }
   static double getNbPoints() { return nbPoints; }

   void deplacer(double dx, double dy);
   void afficher() const;
private:
   double x, y;
   double maxX, maxY;
   int id;
   static int prochainId;
   static int nbPoints;
};
#endif /* POINT_H */
~~~

</details>

<details>
<summary>Point.cpp</summary>

~~~cpp
#include <iostream>

#include "Point.h"

using namespace std;

int Point::nbPoints = 0;
int Point::prochainId = 1;

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y, double maxX, double maxY) : x(x), y(y), maxX(maxX), maxY(maxY), id(prochainId) {
    ++prochainId;
    ++nbPoints;
}

Point::~Point() {
    --nbPoints;
}

void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

void Point::deplacer(double dx, double dy) {
    if(x + dx <= maxX && y + dy <= maxY){
        x += dx;
        y += dy;    
    }        
}

void Point::afficher() const {
    cout << "Point ID = " << id << ", (" << x << "," << y << ")" << ", maxX = " << maxX << ", maxY = " << maxY << endl;
}
~~~
</details>

<details>
<summary>main.cpp</summary>

~~~cpp
#include <iostream>
#include <cstdlib>

#include "Point.h"

using namespace std;

int main() {

    Point p1(1.2, 2.4);
    p1.afficher();
    
    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;
   
    {
        Point p2(3., 4.2, 10., 10.);
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;
    }

    Point p3(5, 10);
    p3.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    return EXIT_SUCCESS;
}
~~~

</details>
