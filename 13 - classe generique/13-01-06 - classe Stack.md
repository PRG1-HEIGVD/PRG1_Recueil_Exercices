# classe générique Stack

Reprendre l'exercice [09-01-07 stack](../09%20-%20Tableaux/01-07%20-%20stack.md) et l'écrire cette fois de manière générique.

A la compilation, l'utilisateur doit pouvoir choisir le type de données à manipuler `<T>` et la capacité `n` de la pile.<br>
Cette valeur est fixée par défaut à 100.

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

//---------------------------------------------------------
template <typename T, int n=100>
class Stack {
   
public:
   bool   push(const T&  v);
   bool   pop();
   bool   top(T& v)  const;
   bool   full()     const;
   bool   empty()    const;
   size_t size()     const;

   void   display()  const;

private:
   size_t index  = 0;
   array<T, n> data;
};

int main() {

   Stack<int, 10> s;
   int i = 1;

   s.display();
   cout << endl;

   while (not s.full()) {
      s.push(i*=2);
   }

   s.top(i);
   cout << "top  : " << i        << endl;
   cout << "size : " << s.size() << endl;
   cout << endl;

   s.display();
   cout << endl;

   while (not s.empty()) {
      s.pop();
   }

   s.display();
   cout << endl;

   return EXIT_SUCCESS;
}

//---------------------------------------------------------
template <typename T, int n>
bool Stack<T, n>::push(const T& v) {
   if (this->full())
      return false;
   this->data[this->index] = v;
   ++this->index;
   return true;
}

//---------------------------------------------------------
template <typename T, int n>
bool Stack<T, n>::pop() {
   if (this->empty())
      return false;
   --this->index;
   return true;
}

//---------------------------------------------------------
template <typename T, int n>
bool Stack<T, n>::top(T& v) const {
   if (this->empty())
      return false;
   v = this->data[this->index - 1];
   return true;
}

//---------------------------------------------------------
template <typename T, int n>
bool Stack<T, n>::full() const {
   return this->index == this->data.size();
}

//---------------------------------------------------------
template <typename T, int n>
bool Stack<T, n>::empty() const {
   return this->index == 0;
}

//---------------------------------------------------------
template <typename T, int n>
size_t Stack<T, n>::size() const {
   return this->index;
}

//---------------------------------------------------------
template <typename T, int n>
void Stack<T, n>::display() const {
   cout << "size : " << this->index << endl;
   cout << "data : ";

   cout << "[";
   for (size_t i=0; i<this->index; ++i) {
      if(i) cout << ", ";
      cout << this->data[i];
   }
   cout << "]" << endl;
}
~~~

</details>

