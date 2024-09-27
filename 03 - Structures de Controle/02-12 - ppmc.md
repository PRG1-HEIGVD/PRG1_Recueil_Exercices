# ppmc
  
Ecrire un programme C++ permettant de calculer le ppmc (plus petit multiple commun) de deux nombres entiers (> 0) m et n saisis (sur la même ligne) par l'utilisateur.
Faire en sorte que la saisie utilisateur soit vérifiée. On suppose toutefois que l'utilisateur entre des valeurs du bon type.

Exemples d'exécution :

~~~
Donnez 2 nombres entiers positifs : 25 65
ppmc(25,65) = 325
~~~

~~~
Donnez 2 nombres entiers positifs : 2 -3
Donnez 2 nombres entiers positifs : -5 7
Donnez 2 nombres entiers positifs : 561 357
ppmc(561,357) = 3927
~~~

<details>
<summary>Solution 1 - la plus simple</summary>

~~~cpp
#include <iostream>
using namespace std;

int main() {

   int n, m;
   do {
      cout << "Donnez 2 nombres entiers positifs : ";
      cin >> n >> m;
   } while (n <= 0 or m <= 0);

   // Calcul du ppmc
   int ppmc = m;
   while (ppmc % n != 0)
      ppmc += m;

   // Affichage du résultat
   cout << "ppmc(" << n << "," << m << ") = " << ppmc << endl;
}
~~~
</details>


<details>
<summary>Solution 2 - un peu plus efficace</summary>

~~~cpp
#include <iostream>
using namespace std;

int main() {

   int n, m;
   do {
      cout << "Donnez 2 nombres entiers positifs : ";
      cin >> n >> m;
   } while (n <= 0 or m <= 0);

   // Calcul du ppmc
   
   int mini = m < n ? m : n; 
   int maxi = m < n ? n : m; 
   int ppmc = maxi;
   while (ppmc % mini != 0)
      ppmc += maxi;

   // Affichage du résultat
   cout << "ppmc(" << n << "," << m << ") = " << ppmc << endl;
}
~~~
</details>



<details>
<summary>Solution 3 - comme appris à l'école</summary>

~~~cpp
#include <iostream>
using namespace std;

int main() {

   int n, m;
   do {
      cout << "Donnez 2 nombres entiers positifs : ";
      cin >> n >> m;
   } while (n <= 0 or m <= 0);

   // Calcul du ppmc

   int div = 2; // premier nombre premier
   int nt = n, mt = m; // copies de m et n que l'on va modifier dans l'algorithme qui suit

   while(nt > 1) {
      if(nt % div == 0) { // recherche de tous les diviseurs premiers de n
         nt /= div;
         if(mt % div == 0) { // si un diviseur premier de n divise aussi m, on évite de le compter 2 fois
            mt /= div;
         }
      } else {
         ++div;
      }
   }
   // mt est maintenant le produit des diviseurs premiers de m qui ne sont pas diviseurs de n
   int ppmc = n * mt;

   // Affichage du résultat
   cout << "ppmc(" << n << "," << m << ") = " << ppmc << endl;
}
~~~

</details>


<details>
<summary>Solution 4 - la plus efficace</summary>

~~~cpp
#include <iostream>
using namespace std;

int main() {

   int n, m;
   do {
      cout << "Donnez 2 nombres entiers positifs : ";
      cin >> n >> m;
   } while (n <= 0 or m <= 0);

   // Calcul du pgcd calculé par l'algorithme d'Euclide
   // https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide

   int a = m, b = n;
   while(b != 0) {
      int t = b;
      b = a % b;
      a = t;
   }
   int pgcd = a;

   // calcul ppmc à partir du pgcd

   int ppmc = m / pgcd * n;

   // Affichage du résultat
   cout << "ppmc(" << n << "," << m << ") = " << ppmc << endl;
}
~~~
</details>
