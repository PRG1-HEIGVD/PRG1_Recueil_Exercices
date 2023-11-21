# Suppression du ou des éléments centraux

Sans faire usage de `vector::erase`, écrire une fonction C++ qui supprime l'élément central 
d'un `vector<int>` si celui-ci est de taille impaire, respectivement les 2 éléments centraux 
si celui-ci est de taille paire. L'ordre des éléments non supprimés doit être préservé.

Avec la fonction `to_string` de l'exercice 02-03, le programme ci-dessous

~~~cpp
int main() {
   for (vector<int> v: {vector<int>{},
                        {1},
                        {1, 2},
                        {1, 2, 3},
                        {1, 2, 3, 4},
                        {1, 2, 3, 4, 5},
                        {1, 2, 3, 4, 5, 6}}) {
      cout << to_string(v) << " -> ";
      supprimer_centre(v);
      cout << to_string(v) << endl;
   }
}
~~~ 

doit afficher 

~~~
[] -> []
[1] -> []
[1, 2] -> []
[1, 2, 3] -> [1, 3]
[1, 2, 3, 4] -> [1, 4]
[1, 2, 3, 4, 5] -> [1, 2, 4, 5]
[1, 2, 3, 4, 5, 6] -> [1, 2, 5, 6]
~~~

<details>
<summary>Solution</summary>

~~~cpp
void supprimer_centre(vector<int>& v) {
   if (v.empty())
      return;
   int n = 2 - v.size() % 2; // nombre d'éléments à supprimer
   for (size_t i = 1 + v.size() / 2; i < v.size(); ++i) {
      v[i - n] = v[i];
   }
   v.resize(v.size()-n);
}
~~~
</details>

