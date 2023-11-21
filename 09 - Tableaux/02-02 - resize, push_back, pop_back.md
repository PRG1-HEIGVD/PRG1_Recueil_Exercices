# resize, push_back, pop_back

Ecrivez les fonctions `my_resize`, `my_push_back` et `my_pop_back` de sorte que le code
suivant compile et aie l'effet décrit en commentaire.

~~~cpp
int main() {
   vector<int> v{1, 2, 3, 4, 5, 6};
   my_push_back(v, 7);     // v contient {1, 2, 3, 4, 5, 6, 7}
   my_pop_back(v);         // v contient {1, 2, 3, 4, 5, 6}
   my_pop_back(v);         // v contient {1, 2, 3, 4, 5}
   my_resize(v,3);         // v contient {1, 2, 3}
   my_resize(v,5,1);       // v contient {1, 2, 3, 1, 1}
   my_resize(v,8);         // v contient {1, 2, 3, 1, 1, 0, 0, 0}
}
~~~

Attention, la fonction `my_resize` ne peut pas utiliser `vector::resize`, la
fonction `my_push_back` ne peut pas utiliser `vector::push_back`, et la
fonction `my_pop_back` ne peut pas utiliser `vector::pop_back`.

<details>
<summary>Solution</summary>

~~~cpp
void my_resize(vector<int>& v, size_t n, int value = int()) {
   while(v.size() < n)
      v.push_back(value);
   while(v.size() > n)
      v.pop_back();
}

void my_push_back(vector<int>& v, int value) {
   v.resize(v.size()+1,value);
}

void my_pop_back(vector<int>& v) {
   v.resize(v.size()-1);
}
~~~
</details>

