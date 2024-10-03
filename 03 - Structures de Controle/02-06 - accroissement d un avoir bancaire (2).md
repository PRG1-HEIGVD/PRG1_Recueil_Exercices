# Accroissement d'un avoir bancaire (2)

Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir 
- un montant initial
- un taux d'intérêt annuel (en %)
- un nombre d'années

détermine et affiche le montant disponible sur le compte après ce nombre d'années
- Les saisies utilisateur sont supposées correctes
- Le taux d'intérêt annuel est supposé rester constant au cours du temps

Exemples d'exécution : 

~~~
Entrez le montant initial > 1000
Entrez le taux d'interet annuel en % > 11
Entrez le nombre d'annees > 10
Le montant disponible après 10 ans est de 2839.42 CHF
~~~

~~~
Entrez le montant initial > 1000
Entrez le taux d'interet annuel en % > -3
Entrez le nombre d'annees > 20
Le montant disponible après 20 ans est de 543.794 CHF
~~~

~~~
Entrez le montant initial > 1000
Entrez le taux d'interet annuel en % > 5
Entrez le nombre d'annees > 1
Le montant disponible après 1 an est de 1050 CHF
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
using namespace std;

int main() {
   cout << "Entrez le montant initial > ";
   double montant_initial; // en CHF
   cin >> montant_initial;

   cout << "Entrez le taux d'interet annuel en % > ";
   double taux_interet_annuel; // en %
   cin >> taux_interet_annuel;

   cout << "Entrez le nombre d'annees > ";
   int nb_annees;
   cin >> nb_annees;

   double montant = montant_initial;
   for (int annee = 0; annee < nb_annees; ++annee) {
      montant *= (1. + taux_interet_annuel / 100.);
   }

   cout << "Le montant disponible après "
        << nb_annees << " an" << (nb_annees > 1 ? "s" : "")
        << " est de " << montant << " CHF" << endl;
}
~~~
</details>

