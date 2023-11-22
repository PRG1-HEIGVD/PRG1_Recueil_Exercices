# Eléments strictement croissants ou pas ?

Ecrire une fonction C++ qui renvoie true si les éléments d'un tableau d'entiers sont ordonnés de manière strictement croissante et false dans le cas contraire. On admettra ici qu'un tableau vide ou à 1 seul élément est ordonné de manière strictement croissante.

Le programme suivant 

~~~cpp
int main() {
   for (vector<int> const& v:
           {vector<int>{1, 2, 3, 4, 6, 9},
            {1, 2, 3, 4, 6, 5},
            {1, 2, 3, 3, 4, 4},
            {1},
            {}})
      cout << to_string(v)
           << (est_strictement_croissant(v) ? " est" : " n'est pas")
           << " strictement croissant" << endl;

   array a { 2, 3, 5, 7, 11, 13};
   cout << to_string(a)
        << (est_strictement_croissant(a) ? " est" : " n'est pas")
        << " strictement croissant" << endl;
}
~~~

Doit afficher 

~~~
[1, 2, 3, 4, 6, 9] est strictement croissant
[1, 2, 3, 4, 6, 5] n'est pas strictement croissant
[1, 2, 3, 3, 4, 4] n'est pas strictement croissant
[1] est strictement croissant
[] est strictement croissant
[2, 3, 5, 7, 11, 13] est strictement croissant
~~~


<details>
<summary>Solution</summary>

~~~cpp
bool est_strictement_croissant(span<const int> s) {
   for(size_t i = 1; i < s.size(); ++i) 
      // boucle sur toutes les paires d'indices (i-1, i)
      if(s[i] <= s[i-1])
         return false;
   return true;
}
~~~
</details>

