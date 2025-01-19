# Somme des n premiers entiers naturels 

Compléter le programme C++ ci-dessous qui met à disposition une fonction `sommeNPremiersEntiers` permettant de sommer les n premiers entiers ≥ 0 et dont le prototype est

~~~cpp
int sommeNPremiersEntiers(int n);
~~~

Faire en sorte d'implémenter `sommeNPremiersEntiers` en tenant compte de toutes les situations problématiques potentielles.

_NB_ L'exercice doit être résolu en utilisant exclusivement une(des) exception(s) prédéfinie(s).

~~~cpp
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


int sommeNPremiersEntiers(int n);
void test(int n);

int main() {

   test(-1);
   test(0);
   test(1);
   test(65535);
   test(65536);

   return EXIT_SUCCESS;
}

void test(int n) {
   cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
   try {
      cout << " = " << sommeNPremiersEntiers(n) << endl;
   } catch (const exception& e) {
      cout << ": " << e.what() << endl;
   }
}
~~~

**Rappel** Hiérarchie des exceptions

~~~mermaid
graph TD
  exception(Exception)
  
  bad_alloc(Bad Alloc)
  logic_error(Logic Error)
  invalid_argument(Invalid Argument)
  out_of_range(Out of Range)

  runtime_error(Runtime Error)
  overflow_error(Overflow Error)
  range_error(Range Error)

  exception     --> bad_alloc
  exception     --> logic_error
  logic_error   --> invalid_argument
  logic_error   --> out_of_range
  exception     --> runtime_error
  runtime_error --> overflow_error
  runtime_error --> range_error
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
using namespace std;

using ullong = unsigned long long;

int sommeNPremiersEntiers(int n);
void test(int n);

int main() {

   test(-1);
   test(0);
   test(1);
   test(65535);
   test(65536);

   return EXIT_SUCCESS;
}

int sommeNPremiersEntiers(int n) {
   if (n < 0)
      throw invalid_argument("Argument non valide: n doit etre >= 0");      
   const ullong SOMME = (ullong) n * ((ullong) n + 1) / 2;
   if (SOMME > numeric_limits<int>::max())
      throw overflow_error("Un debordement est survenu dans les calculs");
   return (int) SOMME;
}

void test(int n) {
   cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
   try {
      cout << " = " << sommeNPremiersEntiers(n) << endl;
   } catch (const exception& e) {
      cout << ": " << e.what() << endl;
   }
}

// sommeNPremiersEntiers(-1): Argument non valide: n doit etre >= 0
// sommeNPremiersEntiers(0) = 0
// sommeNPremiersEntiers(1) = 1
// sommeNPremiersEntiers(65535) = 2147450880
// sommeNPremiersEntiers(65536): Un debordement est survenu dans les calculs
~~~



</details>
