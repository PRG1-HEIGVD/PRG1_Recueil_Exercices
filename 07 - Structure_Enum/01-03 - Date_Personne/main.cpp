#include <iostream>
#include <cstdlib>

#include "date.h"
#include "personne.h"

using namespace std;
int main() {

   Date uneDate = set(30, 10, 2023);
   cout << "une date     : "; afficher(uneDate);
   cout << endl << endl;

   Personne anna = set("Anna", "Yverdon", uneDate);
   afficher(anna);

   cout << endl;

   return EXIT_SUCCESS;
}
