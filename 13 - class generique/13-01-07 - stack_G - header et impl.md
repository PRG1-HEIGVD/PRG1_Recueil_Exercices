# Stack - générique

Reprendre l'exercice [13-01-06 stack](13-01-06%20-%20stack_G.md) et l'adapter pour faire de la compilation séparée tel quel :

- le fichier `Stack.h` contienne la déclaration de la classe
- le fichier `Stack_Impl.h` contienne les définitions des méthodes


<details>
<summary>Solution - main.cpp</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

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
~~~

</details>

<details>
<summary>Solution - Stack.h</summary>

~~~cpp
#ifndef STACK_H
#define STACK_H

#include <array>

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
   std::array<T, n> data;
};

#include "Stack_Impl.h"

#endif //STACK_H
~~~

</details>

<details>
<summary>Solution - Stack_Impl.h</summary>

~~~cpp
#ifndef STACK_IMPL_H
#define STACK_IMPL_H

#include <iostream>

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
   std::cout << "size : " << this->index << std::endl;
   std::cout << "data : ";

   std::cout << "[";
   for (size_t i=0; i<this->index; ++i) {
      if(i) std::cout << ", ";
      std::cout << this->data[i];
   }
   std::cout << "]" << std::endl;
}

#endif //STACK_IMPL_H
~~~

</details>

