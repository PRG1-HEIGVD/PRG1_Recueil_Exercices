# Remplacement de valeurs par une valeur donnée

Ecrire une fonction C++ qui remplace toutes les valeurs paires d'un tableau d'entiers par une valeur donnée.

Avec la fonction `to_string` de l'exercice 03-02, le code suivant 

~~~cpp
int main() {
   vector v { 1, 2, 3, 4, 3, 6, 4, 1, 2};
   cout << to_string(v) << " -> ";
   remplacer_valeurs_paires(v, 0);
   cout << to_string(v) << endl;

   vector a { 3, 4, 5, 6, 2, 4, 3};
   cout << to_string(a) << " -> ";
   remplacer_valeurs_paires(a, -1);
   cout << to_string(a) << endl;
}
~~~

Doit afficher 

~~~cpp
[1, 2, 3, 4, 3, 6, 4, 1, 2] -> [1, 0, 3, 0, 3, 0, 0, 1, 0]
[3, 4, 5, 6, 2, 4, 3] -> [3, -1, 5, -1, -1, -1, 3]
~~~


<details>
<summary>Solution</summary>

~~~cpp
void remplacer_valeurs_paires(span<int> s, int val) {
   for (int& e : s)
      if (e % 2 == 0)
         e = val;
}
~~~
</details>

