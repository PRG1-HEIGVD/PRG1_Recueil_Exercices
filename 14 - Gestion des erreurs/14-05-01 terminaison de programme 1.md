# Terminaison de programme (1)

Que va afficher le programme ci-dessous, lorsque l'utilisateur saisit :

1. la valeur 1 ?
2. la valeur 0 ?
3. la valeur 2 ?
   
~~~cpp
#include <cstdlib>
#include <iostream>
using namespace std;

void onExit() {
   cout << "Appel de exit\n";
   system("PAUSE");
}

int main() {

   atexit(onExit);

   int n;
    
   cout << "Donnez un entier : ";
   cin >> n;
   
   try {
      cout << "Debut du premier bloc try\n";
      if (n) throw n;
      cout << "Fin du premier bloc try\n";   
   } catch (int n) {
      if (n == 1)
         cout << "catch 1 : n = " << n << endl;   
      else
         exit(EXIT_FAILURE);
   }

   cout << "... suite du programme\n";
   
   try {
      cout << "Debut du second bloc try\n";
      throw n;
      cout << "Fin du second bloc try\n";   
   } catch (int n) {
      cout << "catch 2 : n = " << n << endl;   
   }

   cout << "Fin du programme\n";
  
   return EXIT_SUCCESS;
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
<summary>la valeur 1</summary>

~~~text
Donnez un entier : 1
Debut du premier bloc try
catch 1 : n = 1
... suite du programme
Debut du second bloc try
catch 2 : n = 1
Fin du programme
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>

<details>
<summary>la valeur 0</summary>

~~~text
Donnez un entier : 0
Debut du premier bloc try
Fin du premier bloc try
... suite du programme
Debut du second bloc try
catch 2 : n = 0
Fin du programme
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>

<details>
<summary>la valeur 2</summary>

~~~text
Donnez un entier : 2
Debut du premier bloc try
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>
