# Recherche dichotomique

Ecrire une fonction recherche récursive qui exploite 
le fait que le tableau dans lequel on cherche est trié
par ordre croissant. On compare alors la valeur 
cherchée à celle au milieu du tableau, ce qui permet 
de ne chercher que dans une moitié du tableau à l'étape 
suivante. 

La fonction doit être capable de traiter tout type de 
tableau d'entiers (`vector`, `array`, `const vector`, `const array`, tableau C, ...)

Le programme suivant 

~~~cpp
int main() {
   for (vector<int> const& v:
           {vector<int>{1, 2, 3, 5, 7, 11, 13, 17},
            {1, 3, 5, 7, 9, 11, 13, 15, 17},
            {2, 4, 6, 8, 10, 12, 14, 16, 18},
            {5, 10, 15, 20},
            {11},
            {1},
            {}
           }) {
      for (int e: {3, 11, 15}) {
         cout << to_string(v)
              << (recherche(v, e) ? " contient " : " ne contient pas ")
              << e << endl;
      }
   }
}
~~~

Doit afficher 

~~~
[1, 2, 3, 5, 7, 11, 13, 17] contient 3
[1, 2, 3, 5, 7, 11, 13, 17] contient 11
[1, 2, 3, 5, 7, 11, 13, 17] ne contient pas 15
[1, 3, 5, 7, 9, 11, 13, 15, 17] contient 3
[1, 3, 5, 7, 9, 11, 13, 15, 17] contient 11
[1, 3, 5, 7, 9, 11, 13, 15, 17] contient 15
[2, 4, 6, 8, 10, 12, 14, 16, 18] ne contient pas 3
[2, 4, 6, 8, 10, 12, 14, 16, 18] ne contient pas 11
[2, 4, 6, 8, 10, 12, 14, 16, 18] ne contient pas 15
[5, 10, 15, 20] ne contient pas 3
[5, 10, 15, 20] ne contient pas 11
[5, 10, 15, 20] contient 15
[11] ne contient pas 3
[11] contient 11
[11] ne contient pas 15
[1] ne contient pas 3
[1] ne contient pas 11
[1] ne contient pas 15
[] ne contient pas 3
[] ne contient pas 11
[] ne contient pas 15
~~~

Conseil : utiliser les méthodes `first` et `last` de `std::span`. 

<details>
<summary>Solution</summary>

~~~cpp
bool recherche(span<const int> s, int e) {
   if(s.empty()) return false;
   size_t mid = s.size() / 2;
   if(e < s[mid])
      return recherche(s.first(mid),e);
   else if(e > s[mid])
      return recherche(s.last(s.size() - mid - 1), e);
   else // e == s[mid]
      return true;
}
~~~
</details>

