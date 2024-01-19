# vérifier deux string_view

Pour que la fonction de l'exercice [99-01](99-01%20transformer%20une%20string.md) 
puisse être utilisée pour encoder / décoder du texte sans perte d'information, 
il est nécessaire que les 2 chaines passées en paramètres 2 et 3 
- contiennent les mêmes caractères, en ne tenant pas compte de la casse
- ne contiennent pas de doublons 

écrire une fonction vérifier qui retourne vrai si ces critères sont 
respectés, et faux sinon. Il est recommandé d'utiliser `<algoritm>`. 

Le code suivant

~~~cpp
void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}
~~~

affiche le résultat suivant 

~~~text
"abcdef" compatible avec "FEDBAC"
"abcdef" incompatible avec "xyz123"
"abcA" incompatible avec "cAba"
~~~

<details>
<summary>Solution</summary>

La solution la plus efficace utiliser `std::sort` et `std::unique` pour 
créer des versions comparables des 2 chaines, sans doublons. 

Il est possible d'écrire des versions moins efficaces en vérifiant 
explicitement les deux conditions avec des doubles boucles. 

~~~cpp
#include <iostream>     // cout, endl via ostream
#include <string>       // string
#include <string_view>  // string_view
#include <cctype>       // toupper
#include <algorithm>    // transform, sort, unique

using namespace std;

string ensemble_trie(string_view s) {
   auto a = string(s);
   transform(a.cbegin(), a.cend(),a.begin(), ::toupper);
   sort(a.begin(),a.end());
   a.erase(unique(a.begin(), a.end()),a.end());
   return a;
}

bool verifier(string_view a, string_view b) {
   string ea = ensemble_trie(a);
   string eb = ensemble_trie(b);
   return a.size() == ea.size()
          and b.size() == eb.size()
          and ea == eb;
}

void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}
~~~
</details>