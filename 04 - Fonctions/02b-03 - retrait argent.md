# Retrait d'argent
Ecrire un programme C++ mettant à disposition une fonction permettant de retirer un certain montant sur un compte bancaire.

La fonction :

- doit prendre 2 paramètres : le solde courant du compte et le montant du retrait (que l'on
supposera tous deux ≥ 0)
- doit vérifier les contraintes métier suivantes :
  - le solde courant ne peut jamais être négatif
  - si le solde courant est insuffisant pour retirer l'intégralité du montant souhaité, seul
  le montant maximal possible est retiré
- doit retourner le montant du retrait effectif réalisé

Vérifier le bon fonctionnement de la fonction en appliquant le scénario de test suivant :

- Solde initial du compte = 500
- Premier retrait = 300
- Afficher le montant du retrait effectif et le solde courant du compte
- Deuxième retrait = 300
- Afficher le montant du retrait effectif et le solde courant du compte

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double retrait(double  montantRetrait,
               double& soldeCourant);
               
void afficher(const string& texte,
              double valeur,
              int precision);

//------------------------------------------------------------
int main() {
   double soldeCourant = 500,
          retraitEffectif;
   retraitEffectif = retrait(300, soldeCourant);
   afficher("Montant retrait effectif = ", retraitEffectif, 1);
   afficher("Solde courant            = ", soldeCourant,    1);
   
   retraitEffectif = retrait(300, soldeCourant);
   afficher("Montant retrait effectif = ", retraitEffectif, 1);
   
   afficher("Solde courant            = ", soldeCourant,    1);
   return EXIT_SUCCESS;
}

//------------------------------------------------------------
double retrait(double  montantRetrait,
               double& soldeCourant) {
   double retraitEffectif;
   if (soldeCourant > montantRetrait) {
      retraitEffectif = montantRetrait;
      soldeCourant = soldeCourant - montantRetrait;
   }
   
   else {
      // soldeCourant <= montantRetrait
      retraitEffectif = soldeCourant;
      soldeCourant = 0;
   }
   
   return retraitEffectif;
}

//------------------------------------------------------------
void afficher(const string& texte, double valeur, int precision) {
   cout << texte << fixed << setprecision(precision) << valeur << endl;
}

//------------------------------------------------------------
// Montant retrait effectif = 300.0
// Solde courant            = 200.0
// Montant retrait effectif = 200.0
// Solde courant            = 0.0

~~~

**NB** La fonction retrait peut s'écrire sans déclaration de variable locale et de façon plus compacte en utilisant <cmath> :
~~~cpp
double retrait(double montantRetrait, double& soldeCourant) {
   montantRetrait = fmin(montantRetrait, soldeCourant); soldeCourant -= montantRetrait;
   return montantRetrait;
}
~~~
</details>
