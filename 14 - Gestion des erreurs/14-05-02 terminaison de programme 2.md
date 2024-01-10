# Terminaison de programme (2)

Que va afficher le programme ci-dessous, lorsque l'utilisateur saisit :

1. la valeur 1 ?
2. la valeur 2 ?
3. la valeur 3 ?
4. la valeur 4 ?
   
~~~cpp
#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;

void onExit() {
   cout << "Appel de exit\n";
   system("PAUSE");
}

void onTerminate() {
   cout << "Appel de terminate\n";
   // exit(EXIT_FAILURE); // pour éviter que le programme ne "plante"
}

int main() {

   atexit(onExit);
   set_terminate(onTerminate);
   
   int n;
   float x;
   double y;
     
   cout << "Donnez un entier : ";
   cin >> n;
   
   try {
      switch (n) {
         case 1: throw n;
         case 2: x = n; throw x;
         case 3: y = n; throw y; 
      }
   } catch (int n) {
      cout << "catch(int n) : n = " << n << endl;   
   } catch (float x) {
      cout << "catch(float x) : x = " << x << endl;
      exit(EXIT_FAILURE);   
   }

   cout << "Fin du programme\n";
   
   return EXIT_SUCCESS;
}

~~~

<details>
<summary>la valeur 1</summary>

~~~text
Donnez un entier : 1
catch(int n) : n = 1
Fin du programme
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>

<details>
<summary>la valeur 2</summary>

~~~text
Donnez un entier : 2
catch(float x) : x = 2
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>

<details>
<summary>la valeur 3</summary>

~~~text
Donnez un entier : 3
Appel de terminate
~~~

</details>

<details>
<summary>la valeur 4</summary>

~~~text
Donnez un entier : 4
Fin du programme
Appel de exit
Appuyez sur une touche pour continuer...
~~~

</details>