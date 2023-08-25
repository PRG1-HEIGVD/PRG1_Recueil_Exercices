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
1. un commentaire "/*" doit être fermé
2. manque un # => **#include** ...
3. use => using
4. spacename => namespace
5. Main => main
6. manque l' "}" fermante
7. out => cout
8. 'Hello' => "Hello"
9. Return => return + valeur
10. end n'est pas une instruction
11. manque l' "}" fermante

*Sans doute écrite trop top le matin ;)*
</details>
