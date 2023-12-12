# Point avec opérateurs
Reprenez la classe Point de l'exercice 01-01 et faites les modifications / ajouts / suppressions nécessaires afin que le code ci-dessous s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>
#include <cstdlib>
#include <utility>
#include <iomanip>

using namespace std;

int main() {

   Point p1(1.2, 2.4);
   Point p2(3., 4.2);

   cout << "p1" << p1 << ", p2" << p2 << endl;

   cout << "p1 + p2 = " << p1 + p2 << endl;
   cout << "p2 + p1 = " << p2 + p1 << endl;

   cout << "p1 * 2. = " << p1 * 2. << endl;
   cout << "3. * p1 = " << 3. * p1 << endl;

   cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
   Point p3(p1);
   cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
}
~~~

~~~text
p1(1.2,2.4), p2(3.0,4.2)
p1 + p2 = (4.2,6.6)
p2 + p1 = (4.2,6.6)
p1 * 2. = (2.4,4.8)
3. * p1 = (3.6,7.2)
p1 != p2
p1 == p3
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

class Point {
public:
   // constructeurs
   Point();
   Point(double x, double y);

   // setters
   void setX(double x);
   void setY(double y);

   // getters
   double getX() const { return x; }
   double getY() const { return y; }

   // operateurs d'affectation composée
   Point& operator+=(const Point& rhs);
   Point& operator*=(double d);
private:
   double x, y;
};

// operateurs sous forme de fonctions externes --------------------

ostream& operator<<(ostream& cout, const Point& p);

Point operator+(Point lhs, const Point& rhs);

Point operator*(Point lhs, double rhs);
Point operator*(double rhs, Point lhs);

bool operator== (const Point& lhs, const Point& rhs);
// -----------------------------------------------------------------

int main() {

   Point p1(1.2, 2.4);
   Point p2(3., 4.2);

   cout << "p1" << p1 << ", p2" << p2 << endl;

   cout << "p1 + p2 = " << p1 + p2 << endl;
   cout << "p2 + p1 = " << p2 + p1 << endl;

   cout << "p1 * 2. = " << p1 * 2. << endl;
   cout << "3. * p1 = " << 3. * p1 << endl;

   cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
   Point p3(p1);
   cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
}

// -----------------------------------------------------------------
Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y) : x(x), y(y) {}

void Point::setX(double x){
   this->x = x;
}

void Point::setY(double y){
   this->y = y;
}

// -----------------------------------------------------------------
ostream& operator<<(ostream& cout, const Point& p){
   return cout << fixed << setprecision(1)
               << "(" << p.getX() << ","
               << p.getY() << ")";
}

Point& Point::operator+=(const Point& rhs) {
   x += rhs.x;
   y += rhs.y;
   return *this;
}

Point operator+(Point lhs, const Point& rhs) {
   return lhs += rhs;
}

Point& Point::operator*=(double d) {
   x *= d;
   y *= d;
   return *this;
}

Point operator*(double rhs, Point lhs){
   return lhs *= rhs;
}

Point operator*(Point rhs, double lhs){
   return rhs *= lhs;
}

bool operator==(const Point& lhs, const Point & rhs) {
   return lhs.getX() == rhs.getX() and lhs.getY() == rhs.getY();
}

// -----------------------------------------------------------------
~~~



</details>