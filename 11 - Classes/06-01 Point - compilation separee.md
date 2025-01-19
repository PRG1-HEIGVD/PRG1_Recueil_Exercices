# Point avec opérateur en compilation séparée
Reprenez le code de l'exercice [04-01](04-01%20Point%20avec%20operateurs.md) et réorganisez-le en compilation séparée.

~~~text
Point.h
Point.cpp
main.cpp
~~~

Le résultat de l'exécution du programme ne doit pas changer.

~~~text
p1(1.2,2.4), p2(3.0,4.2)
p1 + p2 = (4.2,6.6)
p2 + p1 = (4.2,6.6)
p1 + 2. = (3.2,4.4)
2. + p1 = (3.2,4.4)
p1 != p2
p1 == p3
~~~



<details>
<summary>Point.h</summary>

~~~cpp
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <utility>

class Point {
public:
    Point();
    Point(double x, double y);
    Point(const Point& p);
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    void deplacer(double dx, double dy);
    void afficher() const;    
private:
    double x, y;
};

// -----------------------------------------------------------------
std::pair<double, double> analyserPoint(const Point& p);
std::ostream& operator<<(std::ostream& cout, const Point& p);
Point operator+(const Point& lhs, const Point& rhs);
Point operator+(const Point& lhs, double rhs);
Point operator+(double rhs, const Point& lhs);
bool operator== (const Point& lhs, const Point& rhs);

// -----------------------------------------------------------------
#endif /* POINT_H */
~~~

</details>

<details>
<summary>Point.cpp</summary>

~~~cpp
#include <iostream>
#include <utility>
#include <iomanip>

#include "Point.h"

using namespace std;

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& p) : Point(p.x, p.y) {}

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

// -----------------------------------------------------------------
pair<double, double> analyserPoint(const Point& p){
    return {p.getX(), p.getY()};
}

ostream& operator<<(ostream& cout, const Point& p){
    return cout << fixed << setprecision(1) 
            << "(" << p.getX() << "," 
            << p.getY() << ")"; 
}

Point operator+(double rhs, const Point& lhs){
    return lhs + rhs;
}

Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

Point operator+(const Point& lhs, double rhs) {
    return Point(lhs.getX() + rhs, lhs.getY() + rhs);
}

bool operator==(const Point& lhs, const Point & rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}
~~~

</details>

<details>
<summary>main.cpp</summary>

~~~cpp
#include <iostream>

#include "Point.h"

using namespace std;

int main() {

    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;
    
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 + 2. = " << p1 + 2. << endl;
    cout << "2. + p1 = " << 2. + p1 << endl;

    
    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1);
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;

    return EXIT_SUCCESS;
}
~~~

</details>
