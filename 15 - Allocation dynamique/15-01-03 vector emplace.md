# vector::emplace 

Soit la classe C suivante

~~~cpp
class C {
   int i;
public:
   C() : i(0) { cout << "CD " << flush; }
   C(int i) : i(i) { cout << "C" << i << " " << flush; }
   C(C const& c) : i(c.i) { cout << "Cp" << i << " " << flush; }
   C& operator=(C const& c) { i = c.i; cout << "=" << i << " " << flush; return *this; }
   ~C() { cout << "D" << i << " " << flush; }
};
~~~

Qu’affiche le code suivant à chacune de ses lignes

| Code                 | Affichage                                     |
|----------------------|-----------------------------------------------|
| `int main() { `      |  |
| `vector<C> v(2);`   |                                               |
| `v.pop_back();`      |                                               |
| `v.push_back(C(1));` |                                               |
| `v.clear();`         |                                               |
| `v.emplace_back(2);` |                                               |
| `v.emplace_back(3);` |                                               |
| `v.front() = C(4);`  |                                               |
| `v.pop_back();`      |                                               |
| `}`                  |                                               |


<details><summary>Solution</summary>

| Code                 | Affichage                                     |
|----------------------|-----------------------------------------------|
| `int main() { `      |  |
| `vector<C> v(2);`   | CD CD                                              |
| `v.pop_back();`      | D0                                              |
| `v.push_back(C(1));` | C1 Cp1 D1                                              |
| `v.clear();`         | D1 D0                                              |
| `v.emplace_back(2);` | C2                                              |
| `v.emplace_back(3);` | C3                                              |
| `v.front() = C(4);`  | C4 =4 D4                                              |
| `v.pop_back();`      | D3                                              |
| `}`                  | D4                                              |

</details>
