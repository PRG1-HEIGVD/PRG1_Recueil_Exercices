# Voitures en compilation séparée
Reprenez le code de l'exercice 03-03 et réorganisez-le en compilation séparée.

~~~text
Voiture.h
Voiture.cpp
main.cpp
~~~

Le résultat de l'exécution du programme ne doit pas changer.

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
<summary>Voiture.h</summary>

~~~cpp
#ifndef VOITURE_H
#define VOITURE_H

class Voiture {
public:
   Voiture(unsigned capaciteReservoir, double consommationMoyenne);
   unsigned getCapaciteReservoir() const;
   double getConsommationMoyenne() const;
   double getNbLitresDansReservoir() const;
   double effectuerTrajet(double nbKm); // en valeur de retour : le coût du trajet
   static double getPrixEssence();
   static void setPrixEssence(double prix);
private:
   static double prixEssence;        // en Frs
   const unsigned capaciteReservoir; // en litres
   const double consommationMoyenne; // litres aux 100 km
   double nbLitresDansReservoir;     // nb de litres actuellement dans le réservoir
};

#endif /* VOITURE_H */
~~~

</details>

<details>
<summary>Voiture.cpp</summary>

~~~cpp
#include "Voiture.h"

double Voiture::prixEssence = 1.7;

Voiture::Voiture(unsigned capaciteReservoir, double consommationMoyenne)
: capaciteReservoir(capaciteReservoir),
  consommationMoyenne(consommationMoyenne),
  nbLitresDansReservoir(capaciteReservoir) {
}                     

unsigned Voiture::getCapaciteReservoir() const {
   return capaciteReservoir;
}

double Voiture::getConsommationMoyenne() const {
   return consommationMoyenne;
}

double Voiture::getNbLitresDansReservoir() const {
   return nbLitresDansReservoir;
}

double Voiture::effectuerTrajet(double nbKm) {
   const double CONSOMMATION = nbKm * consommationMoyenne / 100;
   nbLitresDansReservoir -= CONSOMMATION;
   while (nbLitresDansReservoir <= 0)
      nbLitresDansReservoir += capaciteReservoir;
   return CONSOMMATION * prixEssence;
}

double Voiture::getPrixEssence() {
   return prixEssence;
}

void Voiture::setPrixEssence(double prix) {
   prixEssence = prix;   
}
~~~
</details>

<details>
<summary>main.cpp</summary>

~~~cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Voiture.h"

using namespace std;

/*
* Ces trois fonctions sont auxiliares dans le main, 
* la fonction afficherVoiture pourrait eventuellement etre definie dans Voiture.h et Voiture.cpp
*/

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

   return EXIT_SUCCESS;
}
~~~

</details>
