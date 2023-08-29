# Année bissextile

Ecrire un programme C++ affichant à l'écran si les années 1900, 2000, 2010 et 2020 sont bissextiles ou non.

Pour ce faire, écrire une fonction booléenne *estBissextile* prenant en paramètre l'année à tester.

**Rappel** Une année est bissextile si
- elle est divisible par 400 ...
- ou alors par 4 mais pas par 100.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

//------------------------------------------------------------
bool estBissextile(int annee) {
    return (annee % 400 == 0) or (annee % 4 == 0 and annee % 100 != 0);

    // Autres variantes possibles :
    // return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
    // return annee % 400 == 0 or annee % 4 == 0 and annee % 100 != 0;
    // return annee % 400 == 0 || annee % 4 == 0 && annee % 100 != 0;
    // return !(annee % 400) || !(annee % 4) && annee % 100; }

//------------------------------------------------------------
void test(int annee) {
    cout << annee << " : " << boolalpha << estBissextile(annee) << endl;
}

//------------------------------------------------------------
int main() {
   test(1900);      // false
   test(2000);      // true
   test(2010);      // false
   test(2020);      // true
   return EXIT_SUCCESS;
}

~~~
</details>
