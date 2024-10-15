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
using namespace std;

string milieu(const string & str) {
    if (str.size() < 3)
      return str;
    else
      return str.substr((str.size() - 1) / 2 , 2 - str.size() % 2); 
}

/* Solution plus verbeuse
string milieu(string_view str) {
    const size_t str_taille = str.length();

    if (str_taille == 0) return "";

    string str_milieu;
    if(str_taille % 2 == 0){ // pair
        str_milieu = str.substr(str_taille / 2 - 1, 2);
    }else{ // impair
        str_milieu = str.substr(str_taille / 2, 1);
    }
    return str_milieu;
}
*/

int main() {
    cout << "Merci de saisir une chaîne de caractères : \n";
    string str; cin >> str;

    cout << "\"" << str << "\" - Milieu = \"" << milieu(str) << "\"\n";

    return 0;
}

~~~



</details>
