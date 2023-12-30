# classe générique Coord - distance 

Reprendre l'exercice précédant [11-01-02 - class Point](13-01-02%20-%20class%20Point.md) et ajouter à la classe générique `Coord` une méthode générique `distance` qui retourne dans un type choisi la distance d'une coordonnée par rapport à l'origine `(T(), T())`.

~~~
p4       : p4(2, 3)
distance : 3.60555
~~~

Donner un exemple d'appel pour un point.

<details>
<summary>Appel</summary>

~~~cpp
Point p4("p4", 2, 3);
cout << "p4       : ";
p4.afficher();
cout << endl;
cout << "distance : ";
cout << p4.getCoord().distance<double>() << endl;
~~~

</details>

<details>
<summary>Solution</summary>

~~~cpp
#include <cmath> // sqrt

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
template <typename U>
U Coord<T>::distance() const {
   return U( std::sqrt(x * x + y * y) );
}
~~~

</details>