# Premiere et derniere lettre d'une string

Complétez le code ci-dessous en écrivant la fonction `premiere_et_derniere_lettres` 
qui retourne les premières et dernières lettres de la 
chaine de caractère reçue en paramètre. 

~~~cpp
#include <iostream>
using namespace std;

// insérez ici votre code

int main() {
   string s = "Hello";
   auto [ prem, der ] = premiere_et_derniere_lettres(s);
   cout << prem << " -> " << der << endl;
}
~~~

<details>
<summary>Solutions</summary>

*Note: les solutions ci-dessous utilisent `std::string_view`. Si vous n'avez pas 
encore vu ce type présenté en fin de chapitre 8, vous pouvez le remplacer par 
`const string&` qui lui est ici équivalent.*

Plusieurs solutions sont possible. La plus simple consiste à utiliser `std::pair` 

~~~cpp
#include <utility>
pair<char,char> premiere_et_derniere_lettres(string_view sv) {
   return {sv.front(), sv.back()};
}
~~~

mais attention, cette approche ne fonctionne que si l'on doit retourner exactement 2 paramètres. 
Une solution plus générale consiste à définir une structure servant uniquement à retourner les valeurs. 

~~~cpp
struct deux_char {
   char c1, c2;
};

deux_char premiere_et_derniere_lettres(string_view sv) {
   return {sv.front(), sv.back()};
}
~~~

Une variation sur le même thème définit la structure dans la fonction, ce qui 
la cache en partie du monde extérieur. Dans ce cas, le type de retour de 
la fonction doit être `auto`.

~~~cpp
auto premiere_et_derniere_lettres(string_view sv) {
   struct deux_char {
      char c1, c2;
   };
   return deux_char{sv.front(), sv.back()};
}
~~~

Une dernière alternative consiste à utiliser une 
structure anonyme dans la fonction dont la seule 
instance est la valeur retournée. 

~~~cpp 
auto premiere_et_derniere_lettres(string_view sv) {
   struct {
      char c1, c2;
   } ret {sv.front(), sv.back()};
   return ret;
}
~~~

</details>

