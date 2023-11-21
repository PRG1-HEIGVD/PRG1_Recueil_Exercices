# Stack

Ecrire l'implémentation d'un pile de *n* entiers (connu à la compilation) sur la base d'un *array*.


Une pile contient

- un sommet *top* qui détermine l'indice dans le tabeau où sera ajouté la prochaine valeur
- les *data*, ici *array\<int, 10\>*

Le code ci-après doit produire le résulat indiqué

~~~cpp
   Stack s;
   int i = 0;

   show_stack(s);
   cout << endl;

   while (not is_stack_full(s)) {
      push(s, ++i);
   }

   top(s, i);
   cout << "top  : " << i << endl;
   cout << endl;

   show_stack(s);
   cout << endl;

   while (not is_stack_empty(s)) {
      pop(s);
   }

   show_stack(s);
   cout << endl;
~~~

~~~
top  : 0
data : []

top  : 10

top  : 10
data : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

top  : 0
data : []
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

//---------------------------------------------------------
using Data = array<int, 10>;
struct Stack {
   size_t top  = 0;
   Data   data = {};
};

//---------------------------------------------------------
bool push            (      Stack& s, int  v);
bool pop             (      Stack& s);
bool top             (const Stack& s, int& v);
bool is_stack_full   (const Stack& s);
bool is_stack_empty  (const Stack& s);
void show_stack      (const Stack& s);
//---------------------------------------------------------

int main() {

   Stack s;
   int i = 0;

   show_stack(s);
   cout << endl;

   while (not is_stack_full(s)) {
      push(s, ++i);
   }

   top(s, i);
   cout << "top  : " << i << endl;
   cout << endl;

   show_stack(s);
   cout << endl;

   while (not is_stack_empty(s)) {
      pop(s);
   }

   show_stack(s);
   cout << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
bool push(Stack& s, int v) {
   if (is_stack_full(s))
      return false;
   s.data[s.top] = v;
   ++s.top;
   return true;
}

//---------------------------------------------------------
bool pop(Stack& s) {
   if (is_stack_empty(s))
      return false;
   --s.top;
   return true;
}

//---------------------------------------------------------
bool top(const Stack& s, int& v) {
   if (is_stack_empty(s))
      return false;
   v = s.data[s.top - 1];
   return true;
}

//---------------------------------------------------------
bool is_stack_full(const Stack& s) {
   return s.top == s.data.size();
}

//---------------------------------------------------------
bool is_stack_empty(const Stack& s) {
   return s.top == 0;
}

//---------------------------------------------------------
void show_stack      (const Stack& s) {
   cout << "top  : " << s.top << endl;
   cout << "data : ";

   cout << "[";
   for (size_t i=0; i<s.top; ++i) {
      if(i) cout << ", ";
      cout << s.data[i];
   }
   cout << "]" << endl;
}

~~~
</details>

