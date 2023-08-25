# Fonction *compteur*
Ecrire un programme C++ qui appelle 3 fois la même fonction afficher, cette dernière se contentant d'afficher, à chaque appel, le nombre total de fois où elle a été appelée, sous la forme :
> Appel numéro n
> 
On supposera que la fonction afficher est une fonction sans argument ni valeur de retour.


<details>
<summary>Solution no 1</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;
static int compteur; // initialisation à 0 inutile car faite par défaut

void afficher();

int main() {
   for (int i = 1; i <= 3; ++i)
   afficher();
   return EXIT_SUCCESS;
}

void afficher() {
   cout << "Appel no " << ++compteur << endl;
}
~~~
Première solution (déconseillée toutefois !) : utiliser une variable globale statique (ici déclarée explicitement static de manière à ce qu'elle ne soit visible que dans notre fichier)

</details>

<details>
<summary>Solution no 2</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

void afficher();

int main() {
   for (int i = 1; i <= 3; ++i)
   afficher();
   return EXIT_SUCCESS;
}

void afficher() {
   static int compteur; // déjà initialisée à 0 par défaut
   cout << "Appel no " << ++compteur << endl;
}
~~~
</details>
