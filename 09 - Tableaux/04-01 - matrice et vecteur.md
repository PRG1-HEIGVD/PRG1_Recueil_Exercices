# Matrice et vecteur 

En utilisant des alias de types de `std::array`, définissez
les types `Matrix3x3` et `Vec3` ainsi que les fonctions `produit`,
`to_string(Vec3)` et `to_string(Matrix3x3)` de sorte que le code suivant 

~~~cpp
int main() {

   Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
   Vec3 v = {1, 2, 3};
   Vec3 w = produit(m,v);

   cout << to_string(m) << " * "
        << to_string(v) << " = "
        << to_string(w) << endl;
}
~~~

affiche

~~~
[[1, 1, 0]
 [0, 2, 0]
 [0, 0, 1]] * [1, 2, 3] = [3, 4, 3]
~~~

<details>
<summary>Solution</summary>

~~~cpp
using Matrice3x3 = array<array<double, 3>,3>;
using Vec3 = array<double, 3>;

string to_string (Vec3 const& v) {
   stringstream out;
   out << '[';
   for (size_t i = 0; i < v.size(); ++i) {
      if (i)
         out << ", ";
      out << v[i];
   }
   out << ']';
   return out.str();
}

string to_string (Matrice3x3 const& v) {
   stringstream out;
   out << '[';
   for (size_t i = 0; i < v.size(); ++i) {
      if (i)
         out << "\n ";
      out << to_string(v[i]);
   }
   out << ']';
   return out.str();
}

Vec3 produit(Matrice3x3 const& m, Vec3 const& v) {
   Vec3 w{};
   for(size_t i = 0; i < m.size(); ++i) {
      for(size_t j = 0; j < m.size(); ++j) {
         w[i] += m[i][j] * v[j];
      }
   }
   return w;
}
~~~
</details>

