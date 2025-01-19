# Point avec constructeurs

Modifiez la classe Point de l'exercice [02-01](02-01%20Point.md) 
pour pouvoir donner une valeur initiale aux points

Complétez le code suivant afin qu'il s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>

using namespace std;

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2,2.4);
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

using namespace std;

class Point {
public:
    Point();
    Point(double x, double y);
    
    void setX(double x);
    void setY(double y);
    
    double getX() const;
    double getY() const;
    
    void deplacer(double dx, double dy);
    void afficher() const;
private:
    double x, y;
};

Point::Point() : Point(0.,0.) { }

Point::Point(double x, double y) : x(x), y(y) { }

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
    centre.afficher();

    Point p(1.2,2.4);
    p.afficher();
    
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
~~~



</details>
