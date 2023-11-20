# Les chiffres romains
_Wikipédia_ La numération romaine est un système de numération additive utilisé par les Romains de l'Antiquité. Les chiffres romains sont représentés à l'aide de symboles combinés entre eux, notamment par les signes I, V, X, L, C, D et M, représentant respectivement les nombres 1, 5, 10, 50, 100, 500 et 1000.

Un nombre écrit en chiffres romains se lit de gauche à droite. En première approximation, sa valeur se détermine en faisant la somme des valeurs individuelles de chaque symbole, sauf quand l'un des symboles précède un symbole de valeur supérieure; dans ce cas, on soustrait la valeur du premier symbole au deuxième.

Exemple : `XIV = X + IV = 10 + (5 - 1) = 14`

En s'inspirant de ce qui précède, on demande ici d'écrire une fonction permettant de convertir un nombre romain (supposé correct) en entier décimal.

Ecrire également un petit programme de test (main) permettant de vérifier le bon fonctionnement de votre fonction de conversion.

~~~
 "I" = 1
 "II" = 2
 "III" = 3
 "IV" = 4
 "V" = 5
 "VI" = 6
 "VII" = 7
 "VIII" = 8
 "IX" = 9
 "X" = 10
 "MMMMDCCCLXXXVIII" = 4888
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string_view>
using namespace std;

int valeur_chiffre(char chiffre_romain){
    switch (chiffre_romain) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

int romain_en_entier(string_view nb_romain){
    int somme = 0, prev_valeur = 0;

    for (int i = nb_romain.size() - 1; i >= 0; i--) {
        int valeur = valeur_chiffre(nb_romain[i]);
        if (valeur < prev_valeur) {
            somme -= valeur;
        } else {
            somme += valeur;
        }
        prev_valeur = valeur;
    }

    return somme;
}

int main() {
    string_view tests[] = {"I", "II", "III", "IV", "V",
                            "VI", "VII", "VIII", "IX", "X",
                            "MMMMDCCCLXXXVIII"};
    for (string_view s : tests) {
        cout << "\"" << s << "\" = " << romain_en_entier(s) << '\n';
    }

    return 0;
}
~~~



</details>
