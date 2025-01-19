# classe générique Coord - distance

Reprendre l'exercice précédant [01-02 - classe Point](01-02%20-%20classe%20Point.md) et ajouter

- à la classe `Coord` une méthode générique `distance` qui retourne **dans un type choisi** la distance d'une coordonnée **par rapport à une autre coordonnée** reçue en paramètre.

- à la classe `Point` une méthode générique `distance` qui retourne **dans un type choisi** la distance d'une coordonnée **par rapport à un autre point** reçu en paramètre.

~~~
p1(2, 3)
p2(7, -1)
distance entre deux coordonnees : 6.40312
distance entre deux points      : 6.40312
~~~

Donner un exemple d'appel pour un point.

<details>
<summary>Appels</summary>

~~~cpp
cout << "distance : " << p1.getCoord().distance<double>(p2.getCoord()) << endl;
cout << "distance : " << p1.distance<double>(p2)                       << endl;
~~~

</details>

<details>
<summary>Solution - distance entre deux coordonnées</summary>

~~~cpp
template <typename T>
template <typename U>
U Coord<T>::distance(const Coord& other) const {
   return U( std::sqrt( (other.x - x) * (other.x - x)
                      + (other.y - y) * (other.y - y) ));
}
~~~

</details>

<details>
<summary>Solution - distance entre deux points</summary>

~~~cpp
template <typename T>
template <typename U>
U Point<T>::distance(const Point& other) const {

   const Coord<T>& thisCoord  = this->getCoord();
   const Coord<T>& otherCoord = other.getCoord();

   return thisCoord. template distance<U>(otherCoord);
}
~~~

</details>




<details>
<summary>Solution - code complet</summary>

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

   template <typename U>
   U distance(const Coord& other) const;

private:
   T x;
   T y;
};

//------------------------------------------------------------
template <typename T>
class Point {
public:
   Point() : nom(), coord(Coord<T>()) {}
   Point(const string& nom)                        : nom(nom), coord(Coord<T>())       {}
   Point(const string& nom, const Coord<T>& coord) : nom(nom), coord(coord)            {}
   Point(const string& nom, T x, T y)              : nom(nom), coord(Coord<T>(x, y))   {}

   void setNom   (const string&   nom);
   void setCoord (const Coord<T>& coord);

   string   getNom ()   const { return nom;   }
   Coord<T> getCoord () const { return coord; }

   void deplacer(T dx, T dy);
   void afficher() const;

   template <typename U>
   U distance(const Point& other) const;

private:
   string   nom;
   Coord<T> coord;
};

//------------------------------------------------------------
int main() {
   Point p1("p4", 2,  3);
   Point p2("p5", 7, -1);
   cout << "distance : " << p1.getCoord().distance<double>(p2.getCoord()) << endl;
   cout << "distance : " << p1.distance<double>(p2)                       << endl;

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
template <typename T>
template <typename U>
U Coord<T>::distance(const Coord& other) const {
   return U( std::sqrt( (other.x - x) * (other.x - x)
                      + (other.y - y) * (other.y - y) ));
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
   this->coord.afficher();;
}

//------------------------------------------------------------
template <typename T>
template <typename U>
U Point<T>::distance(const Point& other) const {

   const Coord<T>& thisCoord  = this->getCoord();
   const Coord<T>& otherCoord = other.getCoord();

   return thisCoord. template distance<U>(otherCoord);
}
~~~

</details>