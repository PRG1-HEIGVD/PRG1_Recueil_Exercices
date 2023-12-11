# Point avec un identifiant unique et un compteur
Reprenez la classe Point de l'exercice 03-01 et faites les modifications / ajouts nécessaires afin d'y intégrer les fonctionnalités suivantes :

- Attribuer automatiquement un numéro unique à chaque nouveau point créé (1 au premier, 2 au second…). On ne cherchera pas à réutiliser les numéros d'objets éventuellement détruits.
- Maintenir à jour le mombre de points qui existent à un instant donné.


Le code ci-dessous doit s'exécuter correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>
#include <cstdlib>

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
<summary>Solution</summary>

~~~cpp
#include <iostream>

using namespace std;

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

// -----------------------------------------------------------------

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
}

// -----------------------------------------------------------------
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
