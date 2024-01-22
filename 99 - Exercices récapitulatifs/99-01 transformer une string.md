# transformer une string

Ecrire la fonction `transformer` qui modifie la chaine de 
caractère reçue en premier paramètre en remplaçant les 
caractères présents dans le 2ème paramètre par celui 
présent dans le 3ème paramètre à la même place. Elle retourne 
le nombre de caractères modifiés. 

Par exemple, si on appelle `transformer(s,"abc","bca");`, tous les `a` 
de la chaine `s` sont remplacés par `b`, tous les `b` sont 
remplacés par `c`, et tous les `c` sont remplacés par `a`. 

Par ailleurs, la détection des caractères à remplacer doit 
être indépendante de la casse, mais leur remplacement en tenir
compte. Ainsi, avec l'appel ci-dessus, on doit aussi remplacer
`A` par `B`, `B` par `C`, et `C` par `A`. L'appel à
`transformer(s,"AbC","bCa");` aurait exactement le même effet. 

Pour faciliter le déboggage, vérifiez via une assertion que les 2ème et 3ème 
paramètres sont de même taille.

Il faut que le code ci-dessous

~~~cpp
int main() {
   string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
   cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << endl;
   cout << s << endl;
   cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << endl;
   cout << s << endl;
}
~~~

affiche le résultat suivant 

~~~text
67
Lorbm ipsum aolor sit fmbt: honsbhtbtur faipishind blit! Pefsbllus cfhilisis ft aolor bdbt hondub! Auis in lfhus plfhbrft fntb honsbhtbtur tbmpor! Fliqufm lorbm nunh: lforbbt quis cbudift fhhumsfn: vulputftb vitfb justo!
67
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>     // cout, endl via ostream
#include <string>       // string
#include <string_view>  // string_view
#include <cctype>       // isupper, toupper
#include <algorithm>    // transform
#include <cassert>      // assert

using namespace std;

size_t transformer(string & s,       // par référence car modifié
                   string from,      // par valeur car besoin d'une copie
                   string_view to  ) // via string_view car en lecture seulement
{
   assert(from.size() == to.size());
   size_t nb_of_changes = 0;
   transform(from.cbegin(), from.cend(),
             from.begin(), ::toupper);
   for(char& c : s) {
      size_t p = from.find(::toupper(c));
      if (p != string::npos) {
         ++nb_of_changes;
         c = isupper(c) ? ::toupper(to[p]) : ::tolower(to[p]);
      }
   }
   return nb_of_changes;
}

int main() {
   string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
   cout << transformer(s,"abcdefgh.!,:","hgfedcab!.:,") << endl;
   cout << s << endl;
   cout << transformer(s,"hgfedcab!.:,","abcdefgh.!,:") << endl;
   cout << s << endl;
}
~~~

</details>