# Point
Implémenter une structure Point permettant de manipuler un point du plan.

Complétez le code suivant afin qu'il s'exécute correctement et affiche le résultat ci-après.

~~~cpp
#include <iostream>

using namespace std;

int main() {
   Point centre{};
   centre.afficher();

   Point p{1.2, 2.4};
   p.afficher();
   p.deplacer(0.8, 0.6);
   p.afficher();

   p.x = 5.5;
   p.y = 10.3;
   cout << p.x << " -- " << p.y << endl;
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

struct Point {
   double x, y;
   void deplacer(double dx, double dy);
   void afficher() const;
};

void Point::deplacer(double dx, double dy) {
   x += dx;
   y += dy;
}

void Point::afficher() const {
   cout << "(" << x << "," << y << ")" << endl;
}

int main() {
   Point centre{};
   centre.afficher();

   Point p{1.2, 2.4};
   p.afficher();
   p.deplacer(0.8, 0.6);
   p.afficher();

   p.x = 5.5;
   p.y = 10.3;
   cout << p.x << " -- " << p.y << endl;
}
~~~



</details>