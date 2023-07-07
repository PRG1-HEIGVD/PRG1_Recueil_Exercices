# Chapitre 6 - Types arithmétiques et conversions

- [2.8 - Evaluation d'expressions](#28-evaluation-dexpressions)
- [2.9 - Conversions implicites](#29-conversions-implicites)
- [2.10 - Evaluation d'expressions (3)](#210-evaluations-dexpressions-3)

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

[Solution](Ch6%20-%20Types%20arithmétiques%20et%20conversions%20-%20solutions.md#28-evaluation-dexpressions)

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

auto r1 = n + c + p;
auto r2 = 2 * x + c;
auto r3 = (char) n + c;
auto r4 = (float) z + n / 2;
auto r5 a + b;
~~~

Pour chacune des variables `r1` à `r5`, indiquez :
- combien de conversions implicites sont mises en œuvre et lesquelles
- ce qu'elle vaut et quel est sont type

[Solution](Ch6%20-%20Types%20arithmétiques%20et%20conversions%20-%20solutions.md#29-conversions-implicites)

## 2.10 Evaluations d'expressions (3)

Soient les déclarations suivantes :
~~~cpp
int i = 5, j = 11; 

double x1 = (double) j / i;
double x2 = double(j / i);
double x3 = j / i + .5;
double x4 = (double) j / i + .5;
double x5 = (int)( j + .5) / i;
~~~

Que valent les variables x1 à x5 ? 

[Solution](Ch6%20-%20Types%20arithmétiques%20et%20conversions%20-%20solutions.md#210-evaluations-dexpressions-3)
