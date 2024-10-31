# Lecture et ajout de texte dans un fichier

Modifier le programme en C++ de l'exercice 01-01 pour faire ce qui suit :

- Demander à l'utilisateur de saisir le nom du fichier de sortie.
- Lire le contenu du fichier de sortie, s'il existe et l'afficher sur la console.
- Demander à l'utilisateur de saisir du text et ajouter (append) le texte saisi dans le fichier de sortie. Si le fichier existe déjà, il ne doit pas être écrasé.
- S'assurer que le programme gère les erreurs d'ouverture de fichier.
- Pour terminer la saisie, l'utilisateur pourra taper #exit# dans une ligne séprée ou utiliser Ctrl+D.

Ps. Ctrl+D et Ctrl+Z simule le EOF pour les systèmes Unix et Windows, respectivement.   

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <fstream>
#include <string>

bool lire_fichier(const std::string& nom_fichier){
    std::ifstream fichier_entree(nom_fichier);

    // Vérifier si l'ouverture du fichier a réussi
    if (!fichier_entree) {
        return false;
    }

    while (fichier_entree) {
        std::string strInput;
        std::getline(fichier_entree, strInput); // lire une ligne
        std::cout << strInput << "\n";
    }

    fichier_entree.close();

    return true;
}

bool ecrire_fichier(const std::string& nom_fichier) {

    // Ouvrir le fichier en mode append
    std::ofstream fichier_sortie(nom_fichier, std::ios::app);

    // Vérifier si l'ouverture du fichier a réussi
    if (!fichier_sortie) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier. \n";
        return false;
    }

    std::string texte;
    const std::string terminer = "#exit#";

    // Demandez à l'utilisateur de saisir du texte
    std::cout << "Entrez le texte à enregistrer dans le fichier (Ctrl+D ou #exit# pour terminer la saisie) :\n";
    while (std::getline(std::cin, texte)) {
        if (texte == terminer) break;
        // Écrivez le texte dans le fichier
        fichier_sortie << texte << std::endl;
    }

    // Fermer le fichier
    fichier_sortie.close();

    std::cout << "Le texte a été enregistré avec succès dans le fichier." << std::endl;

    return true;
}

int main() {
    std::string nom_fichier;

    // Demander à l'utilisateur le nom du fichier où enregistrer le texte
    std::cout << "Entrez le nom du fichier où enregistrer le texte : ";
    std::getline(std::cin, nom_fichier);

    lire_fichier(nom_fichier);

    ecrire_fichier(nom_fichier);

    return EXIT_SUCCESS;
}
~~~



</details>
