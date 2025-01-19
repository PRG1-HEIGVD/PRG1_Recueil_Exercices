# classe générique Point - déplacer 

Reprendre l'exercice précédant [01-04 - classe Point - lister points](01-04%20-%20classe%20Point%20-%20lister%20points.md)


Sans écrire une fonction ou une méthode complémentaire, écrire le code permettant de déplacer ce dessin de `dx`, `dy`.<br>
Donner un exemple d'appel.

<details>
<summary>déplacer</summary>

~~~cpp
int dx = 1;
int dy = 2;
for_each(dessin.begin(), dessin.end(),
         [dx, dy](Point<int>& p){ p.deplacer(dx, dy); });
~~~

</details>

<details>
<summary>code complet</summary>

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
   U distance() const;

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
private:
   string   nom;
   Coord<T> coord;
};

//------------------------------------------------------------
template <typename T>
void listerPoints(const vector<Point<T>>& v) {
   for (const Point<T>& p : v) {
      p.afficher();
      cout << endl;
   }
}

//------------------------------------------------------------
int main() {
   vector<Point<int>> dessin {{"p1",  1,  2},
                              {"p2",  4,  2},
                              {"p3",  9,  8},
                              {"p4", -1,  5},
                              {"p5",  3, -1},
                              {"p6",  7,  0}};

   listerPoints(dessin);
   
   int dx = 1;
   int dy = 2;
   for_each(dessin.begin(), dessin.end(),
            [dx, dy](Point<int>& p){ p.deplacer(dx, dy); });
   cout << endl;
   
   listerPoints(dessin);
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
U Coord<T>::distance() const {
   return U( std::sqrt(x * x + y * y) );
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
~~~

</details>
