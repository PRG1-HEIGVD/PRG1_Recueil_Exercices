# Voitures
Écrivez une classe Voiture en C++ qui représente une voiture avec les caractéristiques suivantes : 
- capacité du réservoir, 
- consommation moyenne, 
- et le nombre de litres actuellement dans le réservoir. 
- La classe devrait avoir une méthode effectuerTrajet qui prend en paramètre la distance à parcourir en kilomètres et retourne le coût du trajet en carburant. Assurez-vous que le réservoir est mis à jour correctement après chaque trajet.

- Le prix de l'essence est le même pour toutes les voitures.
- La classe devrait également avoir une méthode getPrixEssence pour obtenir le prix actuel de l'essence, ainsi qu'une méthode setPrixEssence pour mettre à jour ce prix.

- Fournissez également des fonctions auxiliaires afficherPrixEssence, afficherVoiture, et afficherCoutTrajet qui affichent respectivement le prix de l'essence, les détails de la voiture, et le coût du trajet.

__Note :__
- Le coût du trajet ne prend en compte que les frais d'essence
- Faire l'hypothèse que le réservoir est toujours complètement vidé avant d'être complètement rempli (jamais de plein partiel)	


Le code ci-dessous doit s'exécuter correctement et affiche le résultat ci-après.

~~~cpp
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

    afficherPrixEssence(Voiture::getPrixEssence());
        
    Voiture::setPrixEssence(1.95);
    afficherPrixEssence(Voiture::getPrixEssence());   

    Voiture v(52, 6.7);

    afficherVoiture(v);   
    afficherCoutTrajet(v.effectuerTrajet(1000));
    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(200));
    afficherVoiture(v);

    return EXIT_SUCCESS;
}
~~~

~~~text
Prix de l'essence : 1.70 Frs

Prix de l'essence : 1.95 Frs

Capacite du reservoir [l]      : 52
Consommation moyenne [l/100km] : 6.7
Nb litres restants             : 52.0

Cout du trajet : 130.65 Frs

Capacite du reservoir [l]      : 52
Consommation moyenne [l/100km] : 6.7
Nb litres restants             : 37.0

Cout du trajet : 26.13 Frs

Capacite du reservoir [l]      : 52
Consommation moyenne [l/100km] : 6.7
Nb litres restants             : 23.6
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iomanip>
#include <iostream>
using namespace std;

class Voiture {
public:
   Voiture(unsigned capaciteReservoir, double consommationMoyenne);

   unsigned getCapaciteReservoir() const { return capaciteReservoir; }
   double getConsommationMoyenne() const { return consommationMoyenne; }
   double getNbLitresDansReservoir() const { return nbLitresDansReservoir; }
   static double getPrixEssence() { return prixEssence; }

   static void setPrixEssence(double prix);

   double effectuerTrajet(double nbKm); // en valeur de retour : le coût du trajet
private:
   static double prixEssence;     // en Frs
   unsigned capaciteReservoir;    // en litres
   double consommationMoyenne;    // litres aux 100 km
   double nbLitresDansReservoir;  // nb de litres actuellement dans le réservoir
};

double Voiture::prixEssence = 1.7;

Voiture::Voiture(unsigned capaciteReservoir, double consommationMoyenne)
        : capaciteReservoir(capaciteReservoir),
          consommationMoyenne(consommationMoyenne),
          nbLitresDansReservoir(capaciteReservoir) {
}

double Voiture::effectuerTrajet(double nbKm) {
   const double consommation = nbKm * consommationMoyenne / 100;
   nbLitresDansReservoir -= consommation;
   while (nbLitresDansReservoir <= 0)
      nbLitresDansReservoir += capaciteReservoir;
   return consommation * prixEssence;
}

void Voiture::setPrixEssence(double prix) {
   prixEssence = prix;
}

void afficherPrixEssence(double prix) {
   cout << fixed << setprecision(2)
        << "Prix de l'essence : " << prix << " Frs"
        << endl << endl << defaultfloat;
}

void afficherVoiture(const Voiture& v) {
   cout << "Capacite du reservoir [l]      : " << v.getCapaciteReservoir() << endl
        << fixed << setprecision(1)
        << "Consommation moyenne [l/100km] : " << v.getConsommationMoyenne() << endl
        << "Nb litres restants             : " << v.getNbLitresDansReservoir()
        << endl << endl << defaultfloat;
}

void afficherCoutTrajet(double montant) {
   cout << fixed << setprecision(2)
        << "Cout du trajet : " << montant << " Frs"
        << endl << endl << defaultfloat;
}

int main() {

   afficherPrixEssence(Voiture::getPrixEssence());

   Voiture::setPrixEssence(1.95);
   afficherPrixEssence(Voiture::getPrixEssence());

   Voiture v(52, 6.7);

   afficherVoiture(v);
   afficherCoutTrajet(v.effectuerTrajet(1000));
   afficherVoiture(v);
   afficherCoutTrajet(v.effectuerTrajet(200));
   afficherVoiture(v);
}
~~~



</details>
