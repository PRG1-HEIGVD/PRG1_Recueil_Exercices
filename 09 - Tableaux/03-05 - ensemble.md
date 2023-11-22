# Ensemble

Ecrire une fonction C++ qui renvoie retourne un tableau
contenant les mêmes éléments que le tableau reçu en paramètre, 
mais sans aucune duplication.

Le programme suivant 

~~~cpp
int main() {
   for (vector<int> const& v:
           {vector<int>{ 1, 2, 4, 1, 2, 5, 3, 6, 2, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 2, 3, 4},
            {1},
            {}
           })
      cout << to_string(v) << " -> " << to_string(ensemble(v)) << endl;

   array a {1, 3, 2, 4, 2, 1, 3};
   cout << to_string(a) << " -> " << to_string(ensemble(a)) << endl;
}
~~~

Doit afficher 

~~~
[1, 2, 4, 1, 2, 5, 3, 6, 2, 1] -> [1, 2, 4, 5, 3, 6]
[1, 1, 1, 1, 1, 1] -> [1]
[1, 2, 3, 4] -> [1, 2, 3, 4]
[1] -> [1]
[] -> []
[1, 3, 2, 4, 2, 1, 3] -> [1, 3, 2, 4]
~~~


<details>
<summary>Solution</summary>

~~~cpp
bool inclut(span<const int> s, int val) {
   for (int e : s)
      if (e == val) return true;
   return false;
}

vector<int> ensemble(span<const int> s) {
   vector<int> v;
   for (int e : s) {
      if (not inclut(v, e))
         v.push_back(e);
   }
   return v;
}
~~~
</details>

