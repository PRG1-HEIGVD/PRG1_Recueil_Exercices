# Suppression d'une valeur

Sans faire usage de `vector::erase`, écrire une fonction C++ qui supprime tous les 
éléments égaux à une valeur donnée. L'ordre des éléments non supprimés doit être préservé.

Avec la fonction `to_string` de l'exercice 02-03, le programme ci-dessous

~~~cpp
int main() {
   for (vector<int> v: {vector<int>{},
                        {2},
                        {1, 2, 2, 2, 3, 1, 2, 4},
                        {2, 3, 4, 3, 2, 1},
                        {2, 2, 2},
                        {5, 4, 3, 2, 1, 2}}) {
      cout << to_string(v) << " -> ";
      supprimer_valeur(v,2);
      cout << to_string(v) << endl;
   }
}
~~~ 

doit afficher 

~~~
[] -> []
[2] -> []
[1, 2, 2, 2, 3, 1, 2, 4] -> [1, 3, 1, 4]
[2, 3, 4, 3, 2, 1] -> [3, 4, 3, 1]
[2, 2, 2] -> []
[5, 4, 3, 2, 1, 2] -> [5, 4, 3, 1]
~~~

<details>
<summary>Solution</summary>

Il est possible de résoudre ce problème en un seul passage sur le `vector` en 
utilisant 2 indices différents, l'un en lecture, l'autre en écriture. 

~~~cpp
void supprimer_valeur(vector<int>& v, int val) {
   size_t write_idx = 0;
   for(size_t read_idx = 0; read_idx < v.size(); ++read_idx) {
      if (v[read_idx] != val) {
         v[write_idx] = v[read_idx];
         ++write_idx;
      }
   }
   v.resize(write_idx);
}
~~~

On peut éventuellement optimiser ce code en évitant d'écrire les éléments initiaux
sur eux-même tant que l'on n'a pas rencontré un élément à supprimer. Mais l'impact 
de cette optimisation est marginal. 

~~~cpp
void supprimer_valeur(vector<int>& v, int val) {
   size_t write_idx = 0;
   while(write_idx < v.size() and v[write_idx] != val) {
      ++write_idx;
   }
   for(size_t read_idx = write_idx; read_idx < v.size(); ++read_idx) {
      if (v[read_idx] != val) {
         v[write_idx] = v[read_idx];
         ++write_idx;
      }
   }
   v.resize(write_idx);
}
~~~

Par contre, il faut absolument éviter d'écrire un code similaire à celui ci-dessous, qui 
requiert n passages sur le `vector` pour supprimer n valeurs, ce qui est très inefficace. 

~~~cpp
void supprimer_un_element(vector<int>& v, size_t pos) {
   // pre-requis : v.size() > 0
   for (size_t j = pos + 1; j < v.size(); ++j) {
      v[j - 1] = v[j];
   }
   v.pop_back();
}

void supprimer_valeur(vector<int>& v, int val) {
   for (size_t i = 0; i < v.size(); ++i) {
      if (v[i] == val) {
         supprimer_un_element(v, i);
         --i;
      }
   }
}
~~~

</details>

