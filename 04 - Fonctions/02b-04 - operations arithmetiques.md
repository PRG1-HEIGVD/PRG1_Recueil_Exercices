# Fonction *Opérations arithmétiques*
Ecrire une fonction qui reçoit en paramètres d'entrée 2 nombres réels (de type double) et un caractère, et qui fournit en paramètre de sortie le résultat correspondant à l'une des 4 opérations appliquées à ses 2 premiers paramètres, en fonction de la valeur du troisième paramètre, à savoir : addition pour le caractère '+', soustraction pour '-', multiplication pour '*' et division pour '/'. Si l'un de ces 4 caractères est passé en argument, la fonction doit renvoyer true comme valeur (statut) de retour; dans le cas contraire, elle doit renvoyer false. Ne pas tenir compte des risques de division par zéro.

Ecrire aussi un petit programme (main) utilisant cette fonction pour effectuer les 4 opérations sur les 2 nombres fournis en entrée par l'utilisateur. Ne pas tenir compte des éventuelles erreurs de saisie utilisateur.
<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

//------------------------------------------------------------
bool operation(double operandeGauche,
               double operandeDroite,
               char operateur,
               double& resultat);
               
void test(double operandeGauche,
          double operandeDroite,
          char operateur);

//------------------------------------------------------------
int main() {
   double operandeGauche, operandeDroite;
   cout << "Donnez 2 nombres reels : ";
   cin >> operandeGauche >> operandeDroite; // saisie non contrôlée ici
   test(operandeGauche, operandeDroite, '+');
   test(operandeGauche, operandeDroite, '-');
   test(operandeGauche, operandeDroite, '*');
   test(operandeGauche, operandeDroite, '/');
   test(operandeGauche, operandeDroite, '?');
   return EXIT_SUCCESS;
}

//------------------------------------------------------------
bool operation(double operandeGauche,
               double operandeDroite,
               char operateur,
               double& resultat) {
   bool OK = true; // statut de retour de la fonction
   
   switch (operateur) {
      case '+': resultat = operandeGauche + operandeDroite; break;
      case '-': resultat = operandeGauche - operandeDroite; break;
      case '*': resultat = operandeGauche * operandeDroite; break;
      case '/': resultat = operandeGauche / operandeDroite; break; 
      default: OK = false; break;

   }
  return OK;
}

//------------------------------------------------------------
void test(double operandeGauche,
          double operandeDroite,
          char operateur) {
   double resultat;
   if (operation(operandeGauche, operandeDroite, operateur, resultat)) {
      cout << operandeGauche << " " << operateur << " "
           << operandeDroite << " = " << resultat << endl;
   }

   else {
      cout << "L'operation " << "'" << operateur << "'" << " est illicite" << endl;
   }
}

// Donnez 2 nombres reels : 3 5
// 3 + 5 = 8
// 3 - 5 = -2
// 3 * 5 = 15
// 3 / 5 = 0.6
// L'operation '?' est illicite
~~~

</details>
