# classe générique Coord - concept 

Reprise de l'exercice [03-01 - classe Coord - assert](03-01%20-%20classe%20Coord%20-%20assert.md)

🤔 Probablement que votre solution permettait d'écrire ceci ?

~~~cpp
Coord<string> p3("x", "y");
p3.afficher();  // p3 : (x, y)
~~~

<br>
Restreinde le type générique utilisé à des valeurs numériques ?

💡Utiliser cette fois la notion de [`concept`](https://en.cppreference.com/w/cpp/language/constraints)

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

//------------------------------------------------------------
template <typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

template <Arithmetic T>
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
   T z;
};

//------------------------------------------------------------
int main() {

   cout << "origine  : ";
   const Coord<int> origin;
   origin.afficher();
   cout << endl;

   cout << "p1       : ";
   Coord<int> p1;
   p1.setCoord(1, 2);
   p1.afficher();
   cout << endl;

   cout << "p2       : ";
   Coord<double> p2(3, 4);
   p2.afficher();
   cout << endl;

   cout << "p2->     : ";
   p2.deplacer(1, 1);            // conversion int => double
   cout << "(" << p2.getX() << ", " << p2.getY() << ")";
   cout << endl;

   cout << "p3       : ";
   Coord<string> p3("x", "y");   // ne compile pas
   p3.afficher();
   cout << endl;
}

//------------------------------------------------------------
template <Arithmetic T>
void Coord<T>::setCoord(T x, T y) {
   this->x = x;
   this->y = y;
}

//------------------------------------------------------------
template <Arithmetic T>
void Coord<T>::deplacer(T dx, T dy) {
   this->x += dx;
   this->y += dy;
}

//------------------------------------------------------------
template <Arithmetic T>
void Coord<T>::afficher() const {
   cout << "(" << this->x << ", " << this->y << ")";
}
~~~

</details>
