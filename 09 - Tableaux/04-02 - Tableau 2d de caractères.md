# Matrice de caractères

Ecrire un programme C++ qui crée un objet de la classe vector permettant de stocker une matrice (irrégulière) de caractères et de l'afficher. Le programme principal est 

~~~cpp
int main() {
   Matrice m = creer();
   afficher(m);
}
~~~

avec vos définitions de `Matrice`, `creer` et `afficher`, il doit afficher 

~~~
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxy
abcdefghijklmnopqrstuvwx
abcdefghijklmnopqrstuvw
abcdefghijklmnopqrstuv
abcdefghijklmnopqrstu
abcdefghijklmnopqrst
abcdefghijklmnopqrs
abcdefghijklmnopqr
abcdefghijklmnopq
abcdefghijklmnop
abcdefghijklmno
abcdefghijklmn
abcdefghijklm
abcdefghijkl
abcdefghijk
abcdefghij
abcdefghi
abcdefgh
abcdefg
abcdef
abcde
abcd
abc
ab
a
~~~

<details>
<summary>Solution</summary>

~~~cpp
using Ligne = vector<char>;
using Matrice = vector<Ligne>;

Matrice creer(size_t t = 26) {
   Matrice m;
   m.reserve(t);
   for(size_t i = 0; i < t; ++i) {
      m.push_back(Ligne());
      m.back().reserve(t - i);
      for (size_t j = 0; i + j < t; ++j) {
         m.back().push_back(static_cast<char>('a' + j));
      }
   }
   return m;
}

void afficher(Matrice const& m) {
   for(Ligne const& ligne : m) {
      for(char c : ligne)
         cout << c;
      cout << endl;
   }
}
~~~
</details>

