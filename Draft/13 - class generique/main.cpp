#include <iostream>
#include <type_traits>
#include <vector>
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
//   static_assert(std::is_arithmetic<T>::value, "T is not an arithmetic value");
   T x;
   T y;
   T z;
};

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
int main() {

   const Coord<int> origin;
   origin.afficher();
   cout << endl;

   Coord<int> p1;
   p1.setCoord(1, 2);
   p1.afficher();
   cout << endl;

   Coord<double> p2(3, 4);
   p2.afficher();
   cout << endl;

   p2.deplacer(1, 1);   // conversion int => double
   p2.afficher();
   cout << endl;

   Coord<string> p3("x", "y");
   p3.afficher();
   cout << endl;
}