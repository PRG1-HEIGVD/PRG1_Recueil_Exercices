# Librairie

Créer une librairie qui met à disposition 2 fonctions

1. *saisir(..)* qui recoit 3 paramètres
	- le message à afficher de type *string*
	- la valeur min
	- la valeur max
	
	La fonction retourne la valeur saisie dans l'intervalle [min .. max].
	<br>**NB** les erreurs de flux ne sont pas gérées

2. *afficher(..)* qui recoit 2 paramètres
	- le message à afficher de type *string*
	- la valeur à afficher

	Aucune valeur de retour est prévue.

**Important**

- la problématique des inclusions multiples doit être gérée
- les librairies utiles doivent être incluses au bon endroit

~~~
votre saisie [0..10] : 12
votre saisie [0..10] : -1
votre saisie [0..10] : 9
votre saisie : 9
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include "annexe.hpp"

int main() {

   int i = saisir("votre saisie", 0, 10);
   afficher("votre saisie", i);

   return EXIT_SUCCESS;
}
~~~

~~~cpp
#ifndef ANNEXE_HPP
#define ANNEXE_HPP

#include <string>

int saisir(const std::string& msg,
           int min, int max);

void afficher(const std::string& msg,
              int valeur);

#endif //ANNEXE_HPP
~~~

~~~cpp
#include "annexe.hpp"
#include <iostream>

int saisir(const std::string& msg,
           int min, int max) {

   int saisie;
   do {
      std::cout << msg << " [" << min << ".." << max << "] : ";
      std::cin >> saisie;
   } while (saisie < min or saisie > max);
   return saisie;

}

void afficher(const std::string& msg,
              int valeur) {
   std::cout << msg << " : " << valeur;
}
~~~

</details>
