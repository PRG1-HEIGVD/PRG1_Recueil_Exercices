# Balle qui rebondit

Lorsqu'une balle tombe d'une hauteur initiale , sa vitesse d'impact au sol est
$v_0 = \sqrt{2 \cdot g \cdot h_0}$ (où $g = 9.81 m/s^2$, la constante de gravité terrestre).
Immédiatement après le rebond, sa vitesse est $v_1 = \epsilon \cdot v_0$ (où $\epsilon$  est le coefficient de rebond de la balle). 
Elle remonte alors à la hauteur $h_1 = \frac{v_1^2}{2 \cdot g}$ .


Ecrire un programme C++ qui calcule et affiche la hauteur à laquelle la balle remonte après un nombre donné de rebonds.
Les données suivantes seront entrées par l'utilisateur et le programme devra vérifier la validité partielle de ces données (partielle… car on supposera que l'utilisateur entre bien une valeur numérique) : 
- $\epsilon$, le coefficient de rebond, tel que $0 \leq \epsilon < 1$ 
- $h_0$. la hauteur initiale, telle que $h_0 \geq 0$
- $n$ , le nombre de rebonds, tel que $n \geq 0$

## IMPORTANT
- Pour calculer la racine carrée d'un valeur `x`, on écrit `sqrt(x)` en C++. Il faut également inclure la libraire `<cmath>`
- Pour la vérification  des saisies utilisateur, utiliser des boucles `do … while`.
- Cherchez à résoudre le problème, non pas du point de vue formel (équations), mais par simulation du système physique.

Exemples d'exécution : 

~~~
Coefficient de rebond (0 <= coeff < 1) : 0.9
Hauteur initiale [m]  (h0 >= 0)        : 10
Nombre de rebonds     (n >= 0)         : 5
La hauteur atteinte apres 5 rebonds : 3.48678 [m]
~~~

~~~
Coefficient de rebond (0 <= coeff < 1) : -2
Coefficient de rebond (0 <= coeff < 1) : 1.3
Coefficient de rebond (0 <= coeff < 1) : 0.8
Hauteur initiale [m]  (h0 >= 0)        : -4
Hauteur initiale [m]  (h0 >= 0)        : 100
Nombre de rebonds     (n >= 0)         : -2
Nombre de rebonds     (n >= 0)         : 10
La hauteur atteinte apres 10 rebonds : 1.15292 [m]
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>  // cin, cout, endl
#include <cmath>     // sqrt
using namespace std;

const double g = 9.81; // constante de gravité terrestre

int main() {

   double eps;    // coefficient de rebond de la balle
   do {
      cout << "Coefficient de rebond (0 <= coeff < 1) : ";
      cin >> eps;
   } while (eps < 0.0 || eps >= 1.0);

   double h0; // hauteur avant rebond [m]
   do {
      cout << "Hauteur initiale [m]  (h0 >= 0)        : ";
      cin >> h0;
   } while (h0 < 0.0);

   int n; // nombre de rebonds à simuler
   do {
      cout << "Nombre de rebonds     (n >= 0)         : ";
      cin >> n;
   } while (n < 0);

   // Calculs proprement dits
   // Chaque itération correspond à un rebond

   for (int i = 0; i < n; ++i) {
      double v0 = sqrt(2 * g * h0);    // vitesse avant rebond
      double v1 = eps * v0;            // vitesse après rebond
      double h1 = (v1 * v1) / (2 * g); // hauteur après rebond
      h0 = h1; // ... qui devient la hauteur avant rebond suivant
   }

   // Affichage du résultat
   cout << "La hauteur atteinte apres "
        << n << " rebond" << (n > 1 ? "s" : "")  << " : "
        << h0 << " [m]" << endl;
}
~~~
</details>