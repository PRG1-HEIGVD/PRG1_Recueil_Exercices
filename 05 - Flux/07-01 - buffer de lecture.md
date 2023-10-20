## Buffer de lecture

### Objectif
- Compréhension du buffer de saisie

### A faire
Déterminer avec précision ce que contient le buffer d'entrée après chacune des instructions du programme ci-dessous.

L’utilisateur saisi dans l’ordre les informations suivantes lorsque le programme est en attente.
<br>**NB :** `_`  = espace et `↩︎` = enter

- `45_23_21.2↩︎`
- `4_1_94_3.94_123↩︎`
- `7_3.45n↩︎`
- `43a1↩︎`



| Instruction 	                                       |  Buffer           | Commentaire                              |
|-------------------------------------------------------|-------------------|------------------------------------------|
|`cout << "entrer des valeurs : ";`                     |                   |                                          |
|`while(cin.get() != '\n');`                            |                   |                                          |
|`cout << endl;`                                        |                   |                                          |
|`cin  >> a;`                                           |                   |                                          |
|`cin  >> b;`                                           |                   |                                          |
|`cin.ignore(numeric_limits<streamsize>::max(), '\n');` |                   |                                          |
|`cin  >> x;`                                           |                   |                                          |
|`cin  >> y;`                                           |                   |                                          |
|`cout << "voulez-vous sauver [o/n] : ";`               |                   |                                          |
|`cin  >> c;`                                           |                   |                                          |
|`cout << "sauver : " << c << endl;`                    |                   |                                          |
|`cin  >> a;`                                           |                   |                                          |
|`cin  >> b;`                                           |                   |                                          |
|`cin  >> x;`                                           |                   |                                          |

**Documentation :** [cin.get](https://cplusplus.com/reference/istream/istream/get) et [cin.ignore](https://cplusplus.com/reference/istream/istream/ignore)

<details>
<summary>Programme complet</summary>

~~~cpp
#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cout et cin
#include <limits>    // numeric_limits<streamsize>::max()

using namespace std;

int main() {
   int      a, b;
   double   x, y;
   char     c;
   
   cout << "entrer des valeurs : ";   
   while(cin.get() != '\n');
   cout << endl;
   cin  >> a;
   cin  >> b;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin  >> x;
   cin  >> y;
   cout << "voulez-vous sauver [o/n] : ";
   cin  >> c;
   cout << "sauver : " << c << endl;
   cin  >> a;
   cin  >> b;
   cin  >> x;

   cout << "presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
~~~

</details>

<details>
<summary>Solutions</summary>

| Instruction 	                        |  Buffer           | Commentaire                              |
|----------------------------------------|-------------------|------------------------------------------|
|`cout << "entrer des valeurs : ";`      | `∅`               | le buffer d'entrée est initialisé ∅      |
|`while(cin.get() != '\n');`             | `∅`               | les valeurs `45_23_21.2↩︎` sont perdues  |
|`cout << endl;`                         | `∅`               | ne modifie pas le buffer d'entrée        |
|`cin  >> a;`                            | `_1_94_3.94_123↩︎`| `4_1_94_3.94_123↩︎` 4 => a                |
|`cin  >> b;`                            | `_94_3.94_123↩︎`  | `_1_94_3.94_123↩︎` 1 => b                 |
|`cin.ignore(...);`                      | `∅`               | les valeurs `_94_3.94_123↩︎` sont perdues|
|`cin  >> x;`                            | `_3.45n↩︎`        | `7_3.45n↩︎` 7 => x                        |
|`cin  >> y;`                            | `n↩︎`             | `3.45n↩︎` 3.45 => y                       |
|`cout << "voulez-vous sauver [o/n] : ";`| `n↩︎`             | ne modifie pas le buffer d'entrée        |
|`cin  >> c;`                            | `↩︎`              | `n↩︎` 'n' => c                            |
|`cout << "sauver : " << c << endl;`     | `↩︎`              | ne modifie pas le buffer d'entrée        |
|`cin  >> a;`                            | `a1↩︎`            | `43a1↩︎` 43 => a                          |
|`cin  >> b;`                            | `a1↩︎`            | 'a' pas un `int` => plante le flux       |
|`cin  >> x;`                            | `a1↩︎`            | le flux est planté, passe tout droit     |

### Conclusions

1. le buffer ne peut pas être traité s'il est vide (lu, traité, ...)
1. lorsque le buffer est vide, une lecture met l'exécution du programme en pause jusqu'à la saisie de valeur(s) suivi de ENTER `↩︎`
1. les espaces précédants une valeurs sont consommés
1. la lecture s'arrête dès la rencontre d'un caractère incompatible avec le type considéré (12 345 => 12, 345 et 1a2 => 1, 'a', 2)
1. les valeurs non consommées restent dans le flux (dans cet exemple : lecture de 'n' dans c)
1. une valeur incompatible avec l'opérateur de flux (ex 'a' => int) fait planter le flux, ce qui ne déclanche pas d'erreur
1. lorsque le flux est planté, les lectures sont ignorées (le flux n'est pas utilisable, ni même pour vider le flux)
1. une bonne pratique est de **vider le flux après utilisation** y compris le `↩︎` restant<br>avec typiquement `cin.ignore(numeric_limits<streamsize>::max(), '\n');`

</details>

