# Triangle d'étoiles

Ecrire un programme C++ qui affiche un triangle comme dans l'exemple ci-dessous.
La hauteur du triangle (càd le nombre de lignes) est fixée par l’utilisateur.
Faire en sorte :
- que l'utilisateur soit invité à refaire sa saisie s'il entre une hauteur négative ou nulle
- que la dernière ligne du triangle s'affiche sur le bord gauche de l'écran

Exemple d'exécution

~~~
Hauteur du triangle (h > 0) : -4
Hauteur du triangle (h > 0) : 0
Hauteur du triangle (h > 0) : 7

      *      
     ***     
    *****    
   *******   
  *********  
 *********** 
*************
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
using namespace std;

const char etoile = '*';
const char blanc = ' ';

int main() {

   int hauteur;
   do {
      cout << "Hauteur du triangle (h > 0) : ";
      cin >> hauteur;
   } while (hauteur <= 0);

   cout << endl;
   for (int ligne = 0; ligne < hauteur; ++ligne) {
      for (int i = 0; i < hauteur - ligne - 1; ++i)
         cout << blanc;
      for (int i = 0; i < 1 + 2 * ligne; ++i)
         cout << etoile;
      // la suite est optionnelle, mais logique si le caractère blanc est visible
      for (int i = 0; i < hauteur - ligne - 1; ++i)
         cout << blanc;
      cout << endl;
   }
}
~~~
</details>

