# Surcharge des opérateurs
Soit MonEntier une classe encapsulant un entier (de type int) sans en fournir 
ni setter ni getter.

Compléter le code ci-après de telle sorte que, à l'exécution, celui-ci produise le résultat suivant :

~~~text
n = 0
n = 1
false
true
n = 1
n = 2
n = 3
n = 8
n = 8
n = 12
~~~

~~~cpp
int main() {
   MonEntier m0, m1(1), m2 = 5;
   const MonEntier m3{7};

   cout << m0 << endl
        << m1 << endl;
   
   cout << boolalpha;
   cout << (m0 == m1) << endl;
   cout << (m0 != m1) << endl;   
   cout << noboolalpha;
   
   cout << m1++ << endl;
   cout << m1 << endl;
   cout << ++m1 << endl;
   
   cout << m1 + m2 << endl;
   m1 += m2;
   cout << m1 << endl;
   cout << m3 + m2 << endl;
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
using namespace std;

class MonEntier {
   int x;
public:
   MonEntier(int x = 0) : x(x) {}
   MonEntier& operator+=(const MonEntier& rhs);
   MonEntier& operator++();
   MonEntier operator++(int);
   friend bool operator==(const MonEntier& lhs, const MonEntier& rhs);
   friend ostream& operator<<(ostream& os, const MonEntier& rhs);
};

MonEntier operator+(MonEntier lhs, const MonEntier& rhs);

// Depuis C++20, définir operator!= est inutile si operator==
// existe. Le compilateur le fait par défaut. Avant, il fallait
// écrire ...
bool operator!=(const MonEntier& lhs, const MonEntier& rhs);

int main() {
   MonEntier m0, m1(1), m2 = 5;
   const MonEntier m3{7};

   cout << m0 << endl
        << m1 << endl;

   cout << boolalpha;
   cout << (m0 == m1) << endl;
   cout << (m0 != m1) << endl;
   cout << noboolalpha;

   cout << m1++ << endl;
   cout << m1 << endl;
   cout << ++m1 << endl;

   cout << m1 + m2 << endl;
   m1 += m2;
   cout << m1 << endl;
   cout << m3 + m2 << endl;
}

MonEntier& MonEntier::operator+=(const MonEntier& rhs) {
   x += rhs.x;
   return *this;
}

MonEntier operator+(MonEntier lhs, const MonEntier& rhs) {
   return lhs += rhs;
}

MonEntier& MonEntier::operator++() {
   ++x;
   return *this;
}

MonEntier MonEntier::operator++(int) {
   MonEntier temp(*this);
   operator++();
   return temp;
}

// en C++20, on peut se contenter de
// bool operator==(const MonEntier& lhs, const MonEntier& rhs) = default;
// avant, il fallait écrire
bool operator==(const MonEntier& lhs, const MonEntier& rhs) {
   return lhs.x == rhs.x;
}

// inutile en C++20. Avant, il fallait écrire
bool operator!=(const MonEntier& lhs, const MonEntier& rhs) {
   return not (lhs == rhs);
}

ostream& operator<<(ostream& os, const MonEntier& rhs) {
   return os << "n = " << rhs.x;
}
~~~

</details>