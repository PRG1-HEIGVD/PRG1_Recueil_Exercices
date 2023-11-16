# Calcul vectoriel

On décide d'utiliser un tableau de 3 `double` pour représenter un vecteur à 3 dimensions via

~~~cpp
using Vec3d = array<double,3>;
~~~

Ecrivez les fonctions `to_string`, `produit`, `produit_scalaire` et `produit_vectoriel` pour que le programme suivant compile 

~~~cpp
#include <iostream>
#include <array>
using namespace std;

using Vec3d = array<double,3>;

int main() {
   Vec3d a{1., 2., 3.};
   Vec3d b{2., 4., 3.};
   cout << "a = " << to_string(a) << endl
        << "b = " << to_string(b) << endl;

   Vec3d c = produit(a, 2.);
   cout << "c = a*2 = " << to_string(c) << endl;

   cout << "a.b = " << produit_scalaire(a, b)
        << ", a.c = " << produit_scalaire(a, c)
        << ", b.c = " << produit_scalaire(b, c) << endl;

   Vec3d d = produit_vectoriel(a, b);
   cout << "d = a^b = " << to_string(d) << endl;
   cout << "a.d = " << produit_scalaire(a, d)
        << ", b.d = " << produit_scalaire(b, d) << endl;

   Vec3d e = produit_vectoriel(a, a);
   cout << "e = a^a = " << to_string(e) << endl;
}
~~~

et affiche 

~~~
a = (1,2,3)
b = (2,4,3)
c = a*2 = (2,4,6)
a.b = 19, a.c = 28, b.c = 38
d = a^b = (-6,3,0)
a.d = 0, b.d = 0
e = a^a = (0,0,0)
~~~


<details>
<summary>Solution</summary>

~~~cpp
string to_string(Vec3d const& v) {
   return(stringstream() << '(' << v[0] << ',' << v[1] << ',' << v[2] << ')').str();
}

Vec3d produit(Vec3d const& v, double d) {
   Vec3d r(v);         // copie de v
   for(double& e : r)
      e *= d;          // multiplication de tous les éléments par d
   return r;
}

double produit_scalaire(Vec3d const& a, Vec3d const& b) {
   double r{};
   for(size_t i = 0; i < a.size(); ++i)
      r += a[i] * b[i];
   return r;
}

Vec3d produit_vectoriel(Vec3d const& a, Vec3d const& b) {
   return {a[1]*b[2] - a[2]*b[1],
           a[2]*b[0] - a[0]*b[2],
           a[0]*b[1] - a[1]*b[0]
   };
}
~~~
</details>
