# Mémoire

Soit la fonction principale suivante

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;

int main() {
   array  a  {1, 2, 3};
   vector v  {1.1, 2.2, 3.3};
   string s  ("HEIG-VD"s);
   list   l  {"chien"s, "chat"s, "souris"s};

   cout << "array"   << endl;    display(a.cbegin(), a.cend());
   cout << "vector"  << endl;    display(v.cbegin(), v.cend());
   cout << "string"  << endl;    display(s.cbegin(), s.cend());
   cout << "list"    << endl;    display(l.cbegin(), l.cend());
}
~~~

Ecrire la ou les fonction(s) générique(s) `display(...)` qui reçoit deux itérateurs `first` et `last` et liste toutes les valeurs contenues ainsi que leur emplacement mémoire.

~~~text
array
1       0x16b977548
2       0x16b97754c
3       0x16b977550

vector
1.1     0x600002bf1240
2.2     0x600002bf1248
3.3     0x600002bf1250

string
H       0x16b977508
E       0x16b977509
I       0x16b97750a
G       0x16b97750b
-       0x16b97750c
V       0x16b97750d
D       0x16b97750e

list
chien   0x6000025f0280
chat    0x6000025f02b0
souris  0x6000025f02e0
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;

template<typename Iterator>
void display(Iterator first, Iterator last) {
   for (Iterator it = first; it != last; ++it) {
      cout << *it    << "\t";
      cout << (const void*)&(*it) << endl;
   }
   cout << endl;
}

int main() {
   array  a  {1, 2, 3};
   vector v  {1.1, 2.2, 3.3};
   string s  ("HEIG-VD"s);
   list   l  {"chien"s, "chat"s, "souris"s};

   cout << "array"   << endl;    display(a.cbegin(), a.cend());
   cout << "vector"  << endl;    display(v.cbegin(), v.cend());
   cout << "string"  << endl;    display(s.cbegin(), s.cend());
   cout << "list"    << endl;    display(l.cbegin(), l.cend());
}
~~~

</details>
