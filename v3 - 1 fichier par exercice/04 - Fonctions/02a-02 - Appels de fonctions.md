# Que produit ce code

Déterminer "à la main" ce que poduit ce code.

~~~cpp
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

double k(double x) { return 2 * (x + 1);        }
double h(double x) { return x * x + k(x) - 1;   }
double g(double x) { return 4 * h(x);           }
double f(double x) { return g(x) + sqrt(h(x));  }

int main() {
    double x1 = f(2),
           x2 = g(h(2)),
           x3 = k(g(2) + h(2)),
           x4 = f(0) + f(1) + f(2),
           x5 = f(-1) + g(-1) + h(-1) + k(-1);
       
   cout << "x1 = " << x1 << endl;
   cout << "x2 = " << x2 << endl;
   cout << "x3 = " << x3 << endl;
   cout << "x4 = " << x4 << endl;
   cout << "x5 = " << x5 << endl;

   return EXIT_SUCCESS;
}
~~~

<details>
<summary>Solution</summary>

~~~
x1 = 39
x2 = 400
x3 = 92
x4 = 62
x5 = 0
~~~
</details>
