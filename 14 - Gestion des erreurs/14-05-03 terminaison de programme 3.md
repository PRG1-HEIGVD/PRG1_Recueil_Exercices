# Terminaison de programme (3)

Que va afficher le programme ci-dessous ?

1.  
~~~cpp
#include <cstdlib>
#include <iostream>
using namespace std;

void f();

int main() {

   try {
      f();
   } catch (int n) {
      cout << "Exception int dans main : " << n << endl;   
   } catch (...) {
      cout << "Exception autre que int dans main" << endl;   
   }

   cout << "Fin main\n";   
   return EXIT_SUCCESS;
}

void f() {
   try {
      int n = 1;
      throw n;
   } catch (int n) {
      cout << "Exception int dans f : " << n << endl;   
      throw;
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

~~~text
Exception int dans f : 1
Exception int dans main : 1
Fin main
~~~

</details>


2.  
~~~cpp
#include <cstdlib>
#include <iostream>
using namespace std;

void f();

int main() {

   try {
      f();
   } catch (int n) {
      cout << "Exception int dans main : " << n << endl;   
   } catch (...) {
      cout << "Exception autre que int dans main" << endl;   
   }

   cout << "Fin main\n";   
   return EXIT_SUCCESS;
}

void f() {
   try {
      double x = 1.;
      throw x;
   } catch (int n) {
      cout << "Exception int dans f : " << n << endl;   
      throw;
   }
}
~~~

<details>
<summary>Solution</summary>

~~~text
Exception autre que int dans main
Fin main
~~~

</details>
