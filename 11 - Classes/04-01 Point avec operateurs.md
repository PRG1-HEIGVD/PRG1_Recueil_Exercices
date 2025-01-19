# Point avec opérateurs
Reprenez la classe Point de l'exercice [03-01](03-01%20Point%20avec%20constructeurs.md) et faites les modifications / ajouts / suppressions nécessaires afin que le code ci-dessous s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>

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

using namespace std;

class Point {
public:
   Point();
   Point(double x, double y);

   Point& operator+=(Point const& other);
   Point& operator*=(double d);

private:
   double x, y;

   friend ostream& operator<< (ostream& out, Point const& pt);
   friend bool operator == (Point const& lhs, Point const& rhs);
};

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y) : x(x), y(y) {}

ostream& operator<< (ostream& out, Point const& pt) {
   return out << "(" << pt.x << "," << pt.y << ")";
}

Point& Point::operator+=(const Point& other) {
   x += other.x;
   y += other.y;
   return *this;
}

Point operator+ (Point pt1, Point const& pt2) {
   return pt1 += pt2;
}

Point& Point::operator*=(double d) {
   x *= d; y *= d; return *this;
}

Point operator* (Point pt, double d) {
   return pt *= d;
}

Point operator* (double d, Point pt) {
   return pt *= d;
}

bool operator == (Point const& lhs, Point const& rhs) {
   return lhs.x == rhs.x and lhs.y == rhs.y;
}

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

</details>
