# Stack

Ecrire l'implémentation d'une pile de *n* entiers (connu à la compilation) sur la base d'un `array`.


Une pile contient

- un entier `size` qui indique combien d'éléments sont stockés dans la pile, et donc aussi l'indice de son sommet
- les `data`, ici `std::array<int, 10>`

Le code ci-après doit produire le résulat indiqué

~~~cpp
int main() {

   Stack s;
   int i = 1;

   display(s);
   cout << endl;

   while (not full(s)) {
      push(s, i*=2);
   }

   cout << "top  : " << top(s)  << endl;
   cout << "size : " << size(s) << endl;
   cout << endl;

   display(s);
   cout << endl;

   while (not empty(s)) {
      pop(s);
   }

   display(s);
   cout << endl;
}
~~~

~~~
size : 0
data : []

top  : 1024
size : 10

size : 10
data : [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]

size : 0
data : []
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <array>

//---------------------------------------------------------
using Data = std::array<int, 10>;
struct Stack {
   size_t size = 0;
   Data   data = {};
};

//---------------------------------------------------------

void   push  (      Stack& s, int  v);
void   pop   (      Stack& s);
int    top   (const Stack& s);
bool   full  (const Stack& s);
bool   empty (const Stack& s);
size_t size  (const Stack& s);
void   display  (const Stack& s);

//---------------------------------------------------------

using namespace std;

int main() {

   Stack s;
   int i = 1;

   display(s);
   cout << endl;

   while (not full(s)) {
      push(s, i*=2);
   }

   cout << "top  : " << top(s) << endl;
   cout << "size : " << size(s) << endl;
   cout << endl;

   display(s);
   cout << endl;

   while (not empty(s)) {
      pop(s);
   }

   display(s);
   cout << endl;
}

//---------------------------------------------------------

void push(Stack& s, int v) {
//   if (full(s)) return;
   s.data[s.size] = v;
   ++s.size;
}

void pop(Stack& s) {
//   if (empty(s)) return;
   --s.size;
}

int top(const Stack& s) {
//   if (empty(s)) return INT_MIN;
   return s.data[s.size - 1];
}

bool full(const Stack& s) {
   return s.size == s.data.size();
}

bool empty(const Stack& s) {
   return s.size == 0;
}

size_t size(const Stack& s) {
   return s.size;
}

void display(const Stack& s) {
   cout << "size : " << s.size << endl;
   cout << "data : ";

   cout << "[";
   for (size_t i = 0; i < s.size; ++i) {
      if(i) cout << ", ";
      cout << s.data[i];
   }
   cout << "]" << endl;
}
~~~
</details>

