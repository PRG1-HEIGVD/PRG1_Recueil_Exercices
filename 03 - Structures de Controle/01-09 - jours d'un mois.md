# Nombre de jours d'un mois

Compléter le programme C++ ci-dessous pour qu'il affiche combien le mois choisi (1 pour janvier, 2 pour février, etc) compte de jours. Si l'utilisateur entre la valeur 2, le programme doit répondre : "Ce mois comporte 28 ou 29 jours"

~~~cpp
#include <iostream>
using namespace std;

int main() {
   cout << "Entrez un no de mois (1-12) : ";
   int no_mois; cin >> no_mois;
   
   cout << "Ce mois comporte ";
   
   // votre code vient ici
   
   cout << " jours." << endl;
}
~~~

Exemple d'exécution
~~~
Entrez un no de mois (1-12) : 5
Ce mois comporte 31 jours.
~~~

Réalisez ce programme de 3 manières différentes

- En utilisant `if ... else`
- En utilisant `switch`
- En utilisant ni l'un ni l'autre, mais seulement des opérateurs logiques et / ou l'opérateur ternaire

<details>
<summary>Solution if else</summary>

~~~cpp
if ( no_mois == 2 ) {
   cout << "28 ou 29";
} else if (no_mois == 4 || no_mois == 6 || no_mois == 9 || no_mois == 11) {
   cout << "30";
} else {
   cout << "31";
} 
~~~

</details>

<details>
<summary>Solution switch</summary>

~~~cpp
switch (no_mois) {
   case 2: cout << "28 ou 29"; break;
   case 4: [[fallthrough]];
   case 6: [[fallthrough]];
   case 9: [[fallthrough]];
   case 11: cout << "30"; break;
   default: cout << "31"; break;
}
~~~

</details>

<details>
<summary>Solution opérateurs</summary>

~~~cpp
   cout << ( no_mois == 2 ? "28 ou 29" :
             no_mois == 4 ||
             no_mois == 6 ||
             no_mois == 9 ||
             no_mois == 11 ? "30" : "31"
           ); 
}
~~~

ou

~~~cpp
   cout << ( no_mois == 2 ? "28 ou 29" :
             (no_mois <= 6 && no_mois % 2 == 0) || 
             (no_mois >= 9 && no_mois % 2 != 0) ? "30" : "31"
           );
~~~

</details>
