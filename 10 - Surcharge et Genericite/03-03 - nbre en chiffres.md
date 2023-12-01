# Nbre en Chiffres

Soit la déclaration

~~~cpp
enum class Chiffre { ZERO,  UN,  DEUX,  TROIS,  QUATRE,  CINQ,  SIX,  SEPT,  HUIT,  NEUF };
~~~

Ecrire le code nécessaire afin d'afficher une valeur en chiffres écrits en toutes lettres.

~~~
cout << nbreToEnums(123);       // UN DEUX TROIS
~~~

<details>
<summary>Solution</summary>

~~~cpp
enum class Chiffre { ZERO,  UN,  DEUX,  TROIS,  QUATRE,  CINQ,  SIX,  SEPT,  HUIT,  NEUF };
array      CHIFFRE {"ZERO","UN","DEUX","TROIS","QUATRE","CINQ","SIX","SEPT","HUIT","NEUF" };

ostream& operator<< (ostream& os, Chiffre chiffre) {
   cout << CHIFFRE[size_t(chiffre)];
   return os;
}

ostream& operator<< (ostream& os, span<const Chiffre> tab) {
   for (size_t i=0; i<tab.size(); ++i) {
      if (i) cout << " ";
      cout << tab[i];
   }
   return os;
}

vector<Chiffre> nbreToEnums(int valeur) {
   if (valeur == 0)
      return vector<Chiffre>();

   vector<Chiffre> result((size_t)log10(valeur)+1);
   size_t i=result.size()-1;
   while(valeur) {
      result.at(i--) = ( Chiffre(valeur % 10) );
      valeur /= 10;
   }
   return result;
}
~~~

-----------------------------------------------------

</details>
