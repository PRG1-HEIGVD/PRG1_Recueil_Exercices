# Contrôler et tester les saisies, Gestionnaire d'étudiants

Modifier le programme de l'exercice précédent, 03-02 "Gestionnaire d'étudiants" afin d'y ajouter un contrôle de l'état du flux cin et les valeurs saisies par l'utilisateur.

Un exemple de l'exécution  du programme avec les nouvelles fonctionnalités :

~~~
Entrez le nom de l'étudiant : Fouad Hanna
Entrez l'âge de l'étudiant : -5
La valeur doit être dans l'intervalle [0, 100].
Entrez l'âge de l'étudiant : f
Saisie invalide. Veuillez entrer un nombre valide.
Entrez l'âge de l'étudiant : 29
Entrez la note en mathématiques (max. 6): -1
La valeur doit être dans l'intervalle [0, 6].
Entrez la note en mathématiques (max. 6): s
Saisie invalide. Veuillez entrer un nombre valide.
Entrez la note en mathématiques (max. 6): 4.9
Entrez la note en PRG1 (max. 6): 33
La valeur doit être dans l'intervalle [0, 6].
Entrez la note en PRG1 (max. 6): ee
Saisie invalide. Veuillez entrer un nombre valide.
Entrez la note en PRG1 (max. 6): 5.6
Nom               Age  Note Math     Note PRG1    Admis
-------------------------------------------------------
Fouad Hanna        29        4.9           5.6     true
-------------------------------------------------------
Moyenne : 5.25
Résultat : Admis
~~~

Ps. Privilégiez l'utilisation des fonctions pour organiser votre code.  



<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

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

int saisir_int_dans_intervalle(const std::string& prompt, const int & min, const int & max) {
    int valeur = 0;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valeur) {
            if (valeur >= min && valeur <= max) {
                return valeur; // La valeur est valide
            } else {
                std::cout << "La valeur doit être dans l'intervalle [" << min << ", " << max << "]." << std::endl;
            }
        } else {
            std::cout << "Saisie invalide. Veuillez entrer un nombre valide." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

double saisir_double_dans_intervalle(const std::string& prompt, const double & min, const double & max) {
    double valeur = 0.0;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valeur) {
            if (valeur >= min && valeur <= max) {
                return valeur; // La valeur est valide
            } else {
                std::cout << "La valeur doit être dans l'intervalle [" << min << ", " << max << "]." << std::endl;
            }
        } else {
            std::cout << "Saisie invalide. Veuillez entrer un nombre valide." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void saisir_infos(std::string & nom, int & age, double & note_math, double & note_prg1){
    // Demandez à l'utilisateur de saisir les données
    std::cout << "Entrez le nom de l'étudiant : ";
    std::getline(std::cin, nom);

    age = saisir_int_dans_intervalle("Entrez l'âge de l'étudiant : ", 0, 100);

    note_math = saisir_double_dans_intervalle("Entrez la note en mathématiques (max. 6): ", 0.0, 6.0);

    note_prg1 = saisir_double_dans_intervalle("Entrez la note en PRG1 (max. 6): ", 0.0, 6.0);
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