# Remplacer toutes les occurrences
Ecrire une fonction qui remplace toutes les occurences d'un "mot" dans un "texte" par un mot alternatif. Le texte, le mot et son alternative sont des chaines de caractère. La fonction ne modifie pas le texte original mais retourne le texte modifié.  

Le code ci-dessous vous permet de tester votre fonction. 

~~~cpp
#include <string>
#include <utility>
#include <iostream>

using namespace std;

// Ecrivez ici la fonction remplacer_occurences

int main() {
   string texte{"Les sanglots longs de violons de l'automne "
                "bercent mon coeur d'une langueur monotone"};
   cout << texte << endl;
   for (auto p: {pair<string, string>{"on", "ON"},
                 {"on", "o"},
                 {"on", "oin"},
                 {"o", "ooo"}}) {
      cout << remplacer_occurences(texte, p.first, p.second) << endl;
   }
}
~~~

Si votre fonction est correcte, il devrait compiler et afficher 

~~~
Les sanglots longs de violons de l'automne bercent mon coeur d'une langueur monotone
Les sanglots lONgs de violONs de l'automne bercent mON coeur d'une langueur mONotONe
Les sanglots logs de violos de l'automne bercent mo coeur d'une langueur mootoe
Les sanglots loings de violoins de l'automne bercent moin coeur d'une langueur moinotoine
Les sanglooots looongs de viooolooons de l'autooomne bercent mooon coooeur d'une langueur mooonoootooone
~~~


<details>
<summary>Solution</summary>

Une première approche utiliser `string::find` pour trouver les mots à
remplacer et `string::replace` pour les remplacer.

Le paramètre `texte` est passé par valeur parce que l'on a besoin  
d'une copie du texte. Les paramètres `mot` et `alt` sont passés
comme `string_view` comme ils ne sont accédés qu'en lecture.

~~~cpp
string remplacer_occurences(string texte, string_view mot, string_view alt) {
   if(mot.empty()) 
      return texte;
   
   size_t pos = 0;
   while( true ) {
      pos = texte.find(mot, pos);
      if(pos == string::npos) {
         break;
      }
      texte.replace(pos, mot.size(), alt); 
      pos += alt.size(); // pos est positionné après le mot inséré
   }
   return texte;
}
~~~

L'approche ci-dessus est inefficace quand la taille du mot à remplacer et celle
du mot qui le remplace sont différentes. Chaque `replace` déplace la fin de
la chaine de caractère de la différence de longueur entre `mot` et `alt`.

Une approche plus efficace consiste à partir d'une `string` vide et
de la remplir petit à petit avec la partie du `texte` qui n'est pas
`mot` et avec `alt` à la place des `mot`s.

Ici, le paramètre `texte` et passé en `string_view` puisqu'il est
juste accédé en lecture. `texte.substr(pos, nxt - pos)` retourne lui
aussi une `string_view`, et il n'y a donc aucune copie effectuée en
dehors des écritures dans la chaine résultat.

~~~cpp
string remplacer_occurences(string_view texte, string_view mot, string_view alt) {
   if(mot.empty())
      return string(texte);

   string r;
   size_t pos = 0;
   while( true ) {
      size_t nxt = texte.find(mot, pos);
      r += texte.substr(pos, nxt - pos); // tout le texte avant le mot
      if(nxt == string::npos) {
         break;
      }
      r += alt; // le texte qui remplace le mot
      pos = nxt + mot.size(); // avancer après le mot trouvé
   }
   return r;
}
~~~

</details>
