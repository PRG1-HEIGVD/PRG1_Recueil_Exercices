# Contrôler et tester les saisies, Gestionnaire d'étudiants

Modifier le programme de l'exercice précédent, 03-02 "Gestionnaire d'étudiants" afin d'y ajouter un contrôle de l'état du flux cin et les valeurs saisies par l'utilisateur.

L'age de l'étudiant est un entier compris entre 1 et 100.
La note est une valeure réelle comprise entre 1 et 6.

Un exemple de l'exécution  du programme avec les nouvelles fonctionnalités :

~~~
Entrez le nom de l'étudiant : Fouad Hanna
Entrez l'âge de l'étudiant : -5
Saisie invalide. Veuillez entrer un entier entre 1 et 100
f
Saisie invalide. Veuillez entrer un entier entre 1 et 100
21
Entrez la note en mathématiques (max. 6): -2
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
s
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
4.9
Entrez la note en PRG1 (max. 6): 33
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
ee
Saisie invalide. Veuillez entrer une valeur entre 1 et 6
5.6
Nom               Age  Note Math     Note PRG1    Admis
-------------------------------------------------------
Fouad Hanna        21        4.9           5.6      Oui
-------------------------------------------------------
Moyenne : 5.25
Résultat : Admis
~~~

Note: privilégier l'utilisation des fonctions pour organiser le code.  



<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void afficher_ligne(const string & s_col1,
                    const string & s_col2,
                    const string & s_col3,
                    const string & s_col4,
                    const string & s_col5) {
    ios backup(nullptr);
    backup.copyfmt(cout); // enregistrer le formatage actuel

    const int w_col1 = 15;
    const int w_col2 = 6;
    const int w_col3 = 11;
    const int w_col4 = 14;
    const int w_col5 = 9;
    const int w_total = w_col1 + w_col2 + w_col3 + w_col4 + w_col5;

    cout << left << setw(w_col1) << s_col1
         << right << setw(w_col2) << s_col2
         << right << setw(w_col3) << s_col3
         << right << setw(w_col4) << s_col4
         << right << setw(w_col5) << s_col5
         << endl;

    cout << right << setw(w_total) << setfill('-') << "" << "\n";

    cout.copyfmt(backup); // restaurer le formatage précédent
}

void afficher_resume(double moyenne, bool admis){
    cout << "Moyenne : " << moyenne << endl;

    cout << "Résultat : " << (admis ? "Admis" : "Non admis") << endl;
}

string lire_string(const string& message) {
    cout << message;
    string s;
    getline(cin, s);
    return s;
}

int lire_int(const string& message, int min, int max) {
    cout << message;

    int i;
    bool valid;
    do{
        valid = (cin >> i) && i >= min && i <= max;
        if(!valid){
            cin.clear();
            cout << "Saisie invalide. Veuillez entrer un entier entre " << min << " et " << max << "\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(!valid);

    return i;
}

double lire_double(const string& message, double min, double max) {
    cout << message;

    double d;
    bool valid;
    do{
        valid = (cin >> d) && d >= min && d <= max;
        if(!valid){
            cin.clear();
            cout << "Saisie invalide. Veuillez entrer une valeur entre " << min << " et " << max << "\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(!valid);

    return d;
}

double calculer_moyenne(double note_math, double note_prg1) {
    return (note_math + note_prg1) / 2.0;
}

bool est_admis(double moyenne) {
    const double min_admis = 3.8;
    return (moyenne >= min_admis);
}

string double_to_str(double value){
    stringstream out_str;
    out_str << value;
    return out_str.str();
}

int main() {
    const int age_min = 1; const int age_max = 100;
    const double note_min = 1; const double note_max = 6;

    string nom = lire_string("Entrez le nom de l'étudiant : ");;
    int age = lire_int("Entrez l'âge de l'étudiant : ", age_min, age_max);
    double note_math = lire_double("Entrez la note en mathématiques (max. 6): ", note_min, note_max);
    double note_prg1 = lire_double("Entrez la note en PRG1 (max. 6): ", note_min, note_max);
    double moyenne = calculer_moyenne(note_math, note_prg1);
    bool admis = est_admis(moyenne);

    afficher_ligne("Nom", "Age", "Note Math", "Note PRG1", "Admis");
    afficher_ligne(nom, to_string(age), double_to_str(note_math), double_to_str(note_prg1), admis ? "Oui" : "Non");
    afficher_resume(moyenne, admis);

    return 0;
}
~~~



</details>
