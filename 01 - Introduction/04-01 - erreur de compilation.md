# Erreur de syntaxe
Le programme ci-dessous contient plusieurs erreurs de syntaxe.

Corriger ce code afin qu'il passe la compilation.

~~~cpp
/* programme avec erreurs
include iostream;
use spacename std;
int Main()
   out < 'Hello' < endln;
   Return;
end;
~~~

<details>
<summary>Solution</summary>

~~~cpp
// programme sans erreurs ... ou
/* programme sans erreurs */
#include <iostream>
using namespace std;
int main() {

   cout << "Hello" << endl;
   // ou
   // cout << "Hello\n";
   
   return 0;
   // ou mieux
   // return EXIT_SUCCESS;
}
~~~
### Explications
1. un commentaire "/*" doit être fermé
1. manque un # => **#include** ...
1. use spacename => us**ing** **name**space
1. Main => main
1. manque une "}" ouvrante
1. out => **c**out
1. 'Hello' => "Hello" ( *serait ok pour un caractère : 'a'* )
1. Return => **r**eturn + valeur
1. end n'est pas une instruction
1. manque une "}" fermante

*Sans doute écrit trop top le matin ;)*
</details>
