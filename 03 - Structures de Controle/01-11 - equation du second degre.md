# `a*x^2+b*x+c=0`

Complétez le programme suivant qui demande à l'utilisateur les paramètres a, b et c d'une 
équation du second degré pour qu'il en affiche toutes les solutions réelles s'il y en a.

Prenez soin d'envisager tous les cas possibles pour les paramètres a, b, et c.   

~~~cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";
   double a, b, c;
   cin >> a >> b >> c;
   
   // votre code vient ici.
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {

   cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";
   double a, b, c;
   cin >> a >> b >> c;

   if (a == 0) {
      if (b == 0) {
         if (c == 0) {
            cout << "tout x est un solution" << endl;
         }
         else {
            cout << "pas de solution" << endl;
         }
      } else {
         cout << "1 solution : " << -c/b << endl;
      }
   } else {
      double discriminant = b * b - 4 * a * c;
      if(discriminant < 0 ) {
         cout << "pas de solution" << endl;
      } else if (discriminant == 0) {
         cout << "1 solution : " << - b / (2 * a) << endl;
      } else {
         double d = sqrt(discriminant);
         double r1 = (-b + d) / (2 * a);
         double r2 = (-b - d) / (2 * a);
         cout << "2 solutions : " << r1 << " et " << r2 << endl;
      }
   }
}
~~~
</details>