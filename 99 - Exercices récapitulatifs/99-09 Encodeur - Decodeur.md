Écrivez deux fonctions en C++, `encodeFile` et `decodeFile`. 

- Fonction `encodeFile` :

  - Entrée :
      - inputFilename : le nom du fichier texte source à chiffrer.
      - outputFilename : le nom du fichier de sortie où le texte encodé sera enregistré.
      - shift : un entier représentant le décalage utilisé pour l'encodage.
  - Traitement :
    Chaque lettre alphabétique est décalée de nombre donné de positions dans l'alphabet. 
    Le décalage est cyclique, les majuscules et les minuscules doivent être décalées dans leurs casses respectives : 
    <br>
  
    ~~~text
    encode 'a', décalage 2 -> 'c'
    encode 'a', décalage -1 -> 'z'
    encode 'Z', décalage 3 -> 'C'    
    ~~~
   
    Pour les caractères non alphabétiques, aucun décalage n'est effectué.

  - Sortie :
  Le fichier outputFilename doit contenir le texte encodé.

- Fonction `decodeFile` :

  - Entrée :
    Les mêmes que pour encodeFile.
  - Traitement :
    Cette fonction doit inverser le processus d'encodage (décoder), en prenant le nom du fichier encodée et la même valeur de décalage pour retourner la contenu originale décodé. Pensez à éviter au maximum le code en double.
  - Sortie :
    Le fichier outputFilename doit contenir le texte décodé.

- Gestion des erreurs :
Votre code doit pouvoir gérer les cas où les fichiers ne peuvent pas être ouverts ou créés.

- Supposons que le décalage peut être un entier positif ou négatif.

~~~cpp
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

#include "encodeFile.cpp"
#include "decodeFile.cpp"

int main() {
    encodeFile("src/source.txt",  "src/chiffre.txt", 3);
    decodeFile("src/chiffre.txt", "src/claire.txt",  3);

    system("cat src/chiffre.txt");  // afficher le contenu
    system("cat src/claire.txt");   // .. des fichiers créés

    return EXIT_SUCCESS;
}
~~~

<details>
<summary>encodeFile</summary>

~~~cpp
void encodeFile(const std::string& inputFilename, const std::string& outputFilename, int shift) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Erreur lors de la création du fichier de sortie." << std::endl;
        return;
    }

    shift %= 26;
    std::string line;
    while (std::getline(inputFile, line)) {
        for (char &c : line) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                c = ((c - base + shift + 26) % 26) + base;
            }
        }
        outputFile << line << std::endl;
    } 

    inputFile.close();
    outputFile.close();
}
~~~

</details>

<details>
<summary>decodeFile</summary>

~~~cpp
void decodeFile(const std::string& inputFilename, const std::string& outputFilename, int shift) {
    encodeFile(inputFilename, outputFilename, -shift);
}
~~~

</details>
