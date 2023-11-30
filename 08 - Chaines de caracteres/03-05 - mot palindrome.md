# Palindrome ou pas ?
Écrivez un programme C++ qui lit un mot depuis le clavier, le stocke dans une chaîne de caractères, et vérifie si le mot est un palindrome. Un palindrome se lit de la même manière de gauche à droite et de droite à gauche. Voici des exemples de palindromes : 'radar', 'kayak', et 'sos'. Modifiez le programme pour qu'il lise et vérifie continuellement des mots.

PS. Nous ne considérons pas ici les caractères accentués.

Pensez à organiser votre code avec les fonctions.

Exemple d'exécution

~~~
Entrez un mot (ou 'quitter' pour sortir) : sos
Le mot 'sos' est un palindrome.
Entrez un mot (ou 'quitter' pour sortir) : kayak
Le mot 'kayak' est un palindrome.
Entrez un mot (ou 'quitter' pour sortir) : heig-vd
Le mot 'heig-vd' n'est pas un palindrome.
Entrez un mot (ou 'quitter' pour sortir) : quitter
Fermeture du programme. Au revoir !
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool est_palindrome(string_view mot) {
    int longueur = mot.length();
    for (int i = 0; i < longueur / 2; i++) {
        if (toupper(mot[i]) != toupper(mot[longueur - 1 - i])) {
            return false;
        }
    }
    return true;
}

int main() {
    string mot;

    do {
        cout << "Entrez un mot (ou 'quitter' pour sortir) : ";
        cin >> mot;

        if (mot == "quitter") {
            cout << "Fermeture du programme. Au revoir !" << endl;
            break;
        }

        cout << "Le mot '" << mot
             << (est_palindrome(mot) ? "' est " : "' n'est pas ")
             << "un palindrome." << endl;

    } while (true);

    return 0;
}
~~~



</details>