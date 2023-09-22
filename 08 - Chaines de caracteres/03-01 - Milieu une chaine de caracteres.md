# Milieu d'une chaîne de caractères

Ecrire une fonction C++ qui prend en paramètre une chaîne de caractères str (de type string) et qui retourne une chaîne de caractères (de type string) contenant :
- le caractère médian de str, si str comporte un nombre impair de caractères
- les 2 caractères médians de str, si str comporte un nombre pair de caractères
  
Exemples  
`milieu("ABC") renvoie "B"; milieu("ABCD") renvoie "BC"`


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string_view>

std::string milieu(std::string_view str) {
    const size_t str_taille = str.length();

    if (str_taille == 0) return "";

    std::string str_milieu;
    if(str_taille % 2 == 0){ // pair
        str_milieu = str.substr(str_taille / 2 - 1, 2);
    }else{ // impair
        str_milieu = str.substr(str_taille / 2, 1);
    }
    return str_milieu;
}

int main() {
    std::cout << "Merci de saisir une chaîne de caractères : \n";
    std::string str; std::cin >> str;

    std::cout << "\"" << str << "\" - Milieu = \"" << milieu(str) << "\"\n";

    return 0;
}

~~~



</details>