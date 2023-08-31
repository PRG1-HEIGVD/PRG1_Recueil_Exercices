# Taille et domaine de définition des types entiers

Ecrire un programme C++ qui détermine / affiche à l'écran, pour un type entier 

- sa taille en bytes
- sa taille en bits (sans utiliser `sizeof` ni le résultat précédent)
- l'intervalle des valeurs possibles
- s'il est signé ou pas

Ce type est défini à la première ligne du programme via une ligne du type 

~~~cpp
using type = unsigned long int;
~~~

## Exemples d'exécution

Avec `using type = unsigned int;`

~~~ 
Taille : 4 bytes = 32 bits
Plage de valeurs : 0 -> 4294967295
Ce type est non-signé
~~~

Avec `using type = signed char;`

~~~
Taille : 1 byte = 8 bits
Plage de valeurs : -128 -> 127
Ce type est signé
~~~

Testez votre programme avec les types `int`, `unsigned int`,
`long`, `unsigned long long`, et `char`.


<details><summary>Solution</summary>

~~~cpp
int main() {
   
   using type = unsigned;

   cout << "Taille : " << sizeof(type)
        << " byte" << ( sizeof(type) < 2 ? "" : "s" ) << " = "
        << (numeric_limits<type>::digits + numeric_limits<type>::is_signed)
        << " bits\nPlage de valeurs : "
        << +numeric_limits<type>::lowest()
        << " -> " <<
        +numeric_limits<type>::max()
        << "\nCe type est "
        << ( numeric_limits<type>::is_signed ? "" : "non-" )
        << "signé" << endl;
}
~~~

Notes : 

- il est nécessaire de faire la somme de `digits` et du booléen `is_signed`, le premier ne comptant pas le bit de signe
- le signed `+` devant `lowest()` et `max()` permet - par promotion numérique en `int` - d'afficher la valeur numérique pour les types `char` et non le caractère ASCII correspondant

</details>
