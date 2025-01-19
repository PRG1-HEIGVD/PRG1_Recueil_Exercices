# Point

Modifiez la structure Point de l'exercice [01-01](01-01%20Structure%20Point.md) 
pour mettre en oeuvre une classe Point qui stocke les coordonnées x,y dans des 
attributs privés. 

Complétez le code suivant afin qu'il s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>

using namespace std;

int main() {
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();
    
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
~~~

~~~text
(0,0)
(1.2,2.4)
(2,3)
5.5 -- 10.3
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class Point {
public:
    void setX(double x);
    void setY(double y);
    
    double getX() const;
    double getY() const;
    
    void deplacer(double dx, double dy);
    void afficher() const;
private:
    double x, y;
};

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

void Point::deplacer(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::afficher() const {
    cout << "(" << x << "," << y << ")" << endl;
}

int main() {
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();
    
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
~~~



</details>
