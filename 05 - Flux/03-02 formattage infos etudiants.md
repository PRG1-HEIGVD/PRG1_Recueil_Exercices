# Formattage cout, Gestionnaire d'étudiants

Écrivez un programme en C++ qui permet à l'utilisateur de saisir les données d'un étudiant, de calculer sa moyenne, et d'afficher un résumé de l'étudiant avec un formatage propre.

Le programme doit :

- Demander à l'utilisateur de saisir 
  - le nom, 
  - l'âge, 
  - la note en mathématiques (sur 6), et 
  - la note en science (sur 6) de l'étudiant.
- Calculer la moyenne de l'étudiant.
- Déterminer si l'étudiant est admis (si la moyenne est supérieure ou égale à 3.8).
- Afficher un tableau avec le nom, l'âge, les notes, la moyenne, et le statut d'admission de l'étudiant.

Un exemple de l'exécution  du programme :

~~~
Entrez le nom de l'étudiant : Fouad Hanna
Entrez l'âge de l'étudiant : 19
Entrez la note en mathématiques (max. 6): 5.2
Entrez la note en PRG1 (max. 6): 5.3
Nom               Age  Note Math     Note PRG1    Admis
-------------------------------------------------------
Fouad Hanna        19        5.2           5.3     true
-------------------------------------------------------
Moyenne : 5.25
Résultat : Admis
~~~

Ps. Utilisez les fonctions de formatage et privilégiez l'utilisation des fonctions pour organiser votre code.  



<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <iomanip>
#include <string>

const int setw_col1 = 15;
const int setw_col2 = 6;
const int setw_col3 = 11;
const int setw_col4 = 14;
const int setw_col5 = 9;

const int setw_total = setw_col1 + setw_col2 + setw_col3 + setw_col4 + setw_col5;

void afficher_entete(){
    std::ios etat(nullptr);
    etat.copyfmt(std::cout); // enregistrer le formatage actuel

    std::cout << std::left << std::setw(setw_col1) << "Nom"
              << std::right << std::setw(setw_col2) << "Age"
              << std::right << std::setw(setw_col3) << "Note Math"
              << std::right << std::setw(setw_col4) << "Note PRG1"
              << std::right << std::setw(setw_col5) << "Admis"
              << std::endl;

    std::cout << std::right << std::setw(setw_total) << std::setfill('-') << "" << "\n";

    std::cout.copyfmt(etat); // restaurer le formatage précédent
}

void afficher_resultat(const std::string & nom, const int & age, const double & note_math, const double & note_prg1, const double & moyenne, const bool & admis){
    // Affichez les données de l'étudiant avec le formatage
    std::cout << std::left << std::setw(setw_col1) << nom
              << std::right << std::setw(setw_col2) << age
              << std::right << std::setw(setw_col3) << note_math
              << std::right << std::setw(setw_col4) << note_prg1
              << std::right << std::setw(setw_col5) << std::boolalpha << admis
              << std::endl;

    std::cout << std::right << std::setw(setw_total) << std::setfill('-') << "" << "\n";

    // Affichez la moyenne
    std::cout << "Moyenne : " << moyenne << std::endl;

    // Affichez le résultat de la réussite
    std::cout << "Résultat : " << (admis ? "Admis" : "Non admis") << std::endl;
}

void saisir_infos(std::string & nom, int & age, double & note_math, double & note_prg1){
    // Demandez à l'utilisateur de saisir les données
    std::cout << "Entrez le nom de l'étudiant : ";
    std::getline(std::cin, nom);
    std::cout << "Entrez l'âge de l'étudiant : ";
    std::cin >> age;
    std::cout << "Entrez la note en mathématiques (max. 6): ";
    std::cin >> note_math;
    std::cout << "Entrez la note en PRG1 (max. 6): ";
    std::cin >> note_prg1;
}

bool calculer_moyenne(const double & note_math, const double & note_prg1, double & moyenne){
    // Calculez la moyenne des notes
    moyenne = (note_math + note_prg1) / 2.0;

    const double min_admis = 3.8;

    // Déterminez si l'étudiant est admis (moyenne supérieure ou égale à 60)
    return (moyenne >= min_admis);
}

int main() {

    std::string nom;
    int age;
    double note_math, note_prg1;
    bool admis;

    saisir_infos(nom, age, note_math, note_prg1);

    double moyenne = 0;
    admis = calculer_moyenne(note_math, note_prg1, moyenne);

    afficher_entete();
    afficher_resultat(nom, age, note_math, note_prg1, moyenne, admis);





    return 0;
}

~~~



</details>