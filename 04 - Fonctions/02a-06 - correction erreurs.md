# Correction d'erreurs
Quelles modifications faut-il apporter au programme ci-dessous pour le rendre correct ?<br>
**NB** Aucune ligne de code ne doit être ajoutée !

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
   f;
   g(1, 2.0);
   h(64, 65);

   return EXIT_SUCCESS;
}

void f {
   cout << "Appel de f\n";
}

//------------------------------------------------------------
void g(int i, j) {
   cout << "Appel de g avec i = " << i << " et j = " << j << "\n";
}

//------------------------------------------------------------
void h(int i; char c) {
   cout << "Appel de h avec i = " << i << " et c = '" << c << "'\n";
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

// Erreur 1 : f, g et h doivent figurer avant main

//------------------------------------------------------------
// Erreur 2 : paire de parenthèses vides obligatoire
void f() {
   cout << "Appel de f\n";
}

//------------------------------------------------------------
// Erreur 3 : chaque paramètre doit faire l'objet
//            d'une déclaration de type
void g(int i, int j) { 
   cout << "Appel de g avec i = " << i << " et j = " << j << "\n";
}

//------------------------------------------------------------
// Erreur 4 : on liste les arguments en les séparant
//            par une virgule et non un point-virgule
void h(int i, char c) { 
   cout << "Appel de h avec i = " << i << " et c = '" << c << "'\n";
}

//------------------------------------------------------------
int main() {
   f();         // Erreur 5 : paire de parenthèses vides obligatoire
   g(1, 2.0);   // OK. Conversion implicite (dégradante)
                // Possible warning du compilateur
   h(64, 65);
   return EXIT_SUCCESS;
}
~~~
</details>
