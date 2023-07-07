# Chapitre 6 - Types arithmétiques et conversions

- [2.8 - Evaluation d'expressions](#28-evaluation-dexpressions)
- [2.9 - Conversions implicites](#29-conversions-implicites)

## 2.8 Evaluation d'expressions

Que va afficher le programme ci-dessous ? Expliquer les résultats obtenus.

~~~cpp
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
   cout << fixed << setprecision(0);
   cout << "1) " << 3 * 1000 * 1000 * 1000 << endl;
   cout << "2) " << 3.0 * 1000 * 1000 * 1000 << endl;
   cout << "3) " << 100000 * 100000 * 100000.0 << endl;
   cout << "4) " << 100000.0 * 100000 * 100000 << endl;
   cout << "5) " << 1E7 + 1.0 << endl;
   cout << "6) " << 1E7f + 1.f << endl;
   cout << "7) " << 1E8 + 1.0 << endl;
   cout << "8) " << 1E8f + 1.f << endl;
}
~~~

### Solution 
~~~
1) -1294967296
2) 3000000000
3) 141006540800000
4) 1000000000000000
5) 10000001
6) 10000001
7) 100000001
8) 100000000
~~~

### Explications
1) Résultat indéfini car multiplication entière induisant un débordement. Le résultat affiché est probable pour un entier codé en complément à 2. 
2) Résultat juste car multiplications successives réelles
3) Résultat indéfini car la première multiplication s'effectue sur les entiers => débordement. Le résultat affiché est probable pour un entier codé en complément à 2.
4) Résultat juste car multiplications successives réelles
5) Résultat juste.
6) Résultat juste.
7) Résultat juste.
8) Résultat arrondi (en base 2) dû à la précision insuffisante des calculs avec le type float

## 2.9 Conversions implicites

Soient les déclarations suivantes :
~~~cpp
char c = 'A';
int n = 7;
int a = -2;
unsigned b = 1;
long p = 10;
float x = 1.25f;
double z = 5.5;
~~~

Pour chacune des expressions suivantes, indiquez :
• combien de conversions implicites sont mises en œuvre et lesquelles
• ce que vaut l'expression et quel est le type du résultat

~~~
1) n+c+p
2) 2 * x +c
3) (char)n+c
4) (float) z + n / 2
5) a+b
~~~

### Solution 
Rappel Les promotions numériques : bool → int, char → int et short → int
1) 2 conversions implicites : c est tout d'abord converti en int, avant d'être ajouté à n.
Le résultat (72), de type int, est ensuite converti en long, avant d'être ajouté à p. Au final, on obtient la valeur 82 de type long.
2) 3 conversions implicites : c (de type char) est tout d'abord converti en int (promotion numérique), ce qui donne 65. On évalue ensuite 2 * x en convertissant 2 (de type int) en float, ce qui donne 2.5 de type float.
Pour effectuer l'addition, on convertit la valeur entière 65 en float, avant de l'ajouter au résultat précédent (2.5).
Au final, on obtient la valeur 67.5 de type float.
3) 2 conversions implicites : c est tout d'abord converti en int (promotion numérique).
n est ensuite converti explicitement en char (cast) avant d'être reconverti, implicitement cette fois, en int.
Au final, on obtient la valeur 72 de type int.
4) 1 conversion implicite : z est tout d'abord converti en float (cast), ce qui donne 5.5.
La division entière n / 2 est ensuite effectuée; on obtient la valeur 3. Cette valeur (3) est ensuite convertie en float, avant d'être ajoutée à 5.5. Au final, on obtient la valeur 8.5 de type float.
5) 1 conversion implicite (de type ajustement de type) de int en unsigned int. Au final, on obtient UINT_MAX (soit 4'294'967'295).
