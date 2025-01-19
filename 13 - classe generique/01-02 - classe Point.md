# classe générique Point 

Sur la base de la classe générique `Coord` de l'exercice [01-01 - classe Coord](01-01%20-%20classe%20Coord.md) et **sans faire d'héritage**, écrire la classe générique `Point` qui permet d'obtenir le résultat indiqué pour les instructions suivantes.

~~~cpp
const Point<int> origin;

cout << "p1       : ";
Point<int> p1("p1"s);
p1.afficher();
cout << endl;

cout << "p2       : ";
Point<double> p2("p2"s, Coord(1.2, 3.4));
p2.afficher();
cout << endl;

cout << "p3       : ";
Point<double> p3("p3"s, 1.2, 3.4);
p3.afficher();
cout << endl;

cout << "p3.1     : ";
p3.setNom("p3.1"s);
p3.afficher();
cout << endl;

cout << "p1(-1, 1): ";
p1.setCoord(Coord(-1, 1));
p1.afficher();
cout << endl;

cout << "p1->     : ";
p1.deplacer(-1, 1);
p1.afficher();
cout << endl;

cout << "p1(x)    : ";
cout << p1.getNom() << " " << p1.getCoord().getX();
~~~

~~~
p1       : p1(0, 0)
p2       : p2(1.2, 3.4)
p3       : p3(1.2, 3.4)
p3.1     : p3.1(1.2, 3.4)
p1(-1, 1): p1(-1, 1)
p1->     : p1(-2, 2)
p1(x)    : p1 -2
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
using namespace std;

//------------------------------------------------------------
template <typename T>
class Coord {
public:
   Coord()           : Coord(T(), T()) {};
   Coord(T x, T y)   : x(x), y(y)      {};

   void  setCoord(T x, T y);
   T getX() const { return x; }
   T getY() const { return y; }

   void deplacer(T dx, T dy);
   void afficher() const;

private:
   T x;
   T y;
};

//------------------------------------------------------------
template <typename T>
class Point {
public:
   Point() : nom(), coord() {}
   Point(const string& nom)                        : nom(nom), coord()       {}
   Point(const string& nom, const Coord<T>& coord) : nom(nom), coord(coord)  {}
   Point(const string& nom, T x, T y)              : nom(nom), coord(x, y)   {}

   void setNom   (const string&   nom);
   void setCoord (const Coord<T>& coord);

   string   getNom ()   const { return nom;   }
   Coord<T> getCoord () const { return coord; }

   void deplacer(T dx, T dy);
   void afficher() const;
private:
   string   nom;
   Coord<T> coord;
};

//------------------------------------------------------------
int main() {

   const Point<int> origin;

   cout << "p1       : ";
   Point<int> p1("p1"s);
   p1.afficher();
   cout << endl;

   cout << "p2       : ";
   Point<double> p2("p2"s, Coord(1.2, 3.4));
   p2.afficher();
   cout << endl;

   cout << "p3       : ";
   Point<double> p3("p3"s, 1.2, 3.4);
   p3.afficher();
   cout << endl;

   cout << "p3.1     : ";
   p3.setNom("p3.1"s);
   p3.afficher();
   cout << endl;

   cout << "p1(-1, 1): ";
   p1.setCoord(Coord(-1, 1));
   p1.afficher();
   cout << endl;

   cout << "p1->     : ";
   p1.deplacer(-1, 1);
   p1.afficher();
   cout << endl;

   cout << "p1(x)    : ";
   cout << p1.getNom() << " " << p1.getCoord().getX();
}

//------------------------------------------------------------
//   class Coord
//------------------------------------------------------------
template <typename T>
void Coord<T>::setCoord(T x, T y) {
   this->x = x;
   this->y = y;
}

//------------------------------------------------------------
template <typename T>
void Coord<T>::deplacer(T dx, T dy) {
   this->x += dx;
   this->y += dy;
}

//------------------------------------------------------------
template <typename T>
void Coord<T>::afficher() const {
   cout << "(" << this->x << ", " << this->y << ")";
}

//------------------------------------------------------------
//   class Point
//------------------------------------------------------------
template <typename T>
void Point<T>::setNom   (const string& nom) {
   this->nom = nom;
}

//------------------------------------------------------------
template <typename T>
void Point<T>::setCoord (const Coord<T>& coord) {
   this->coord = coord;
}

//------------------------------------------------------------
template <typename T>
void Point<T>::deplacer(T dx, T dy) {
   this->coord.deplacer(dx, dy);
}

//------------------------------------------------------------
template <typename T>
void Point<T>::afficher() const {
   cout << this->nom;
   this->coord.afficher();
}
~~~

</details>
