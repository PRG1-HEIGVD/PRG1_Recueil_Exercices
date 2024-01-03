# Stack - spécialisation

Reprendre l'exercice [13-01-09 stack - opérateur](13-01-09%20-%20stack_G%20-%20operateur.md).

Nous souhaitons cette fois manipuler des `int` et des `const int*` dans le même code.

~~~cpp
const vector data = {0, 1, 2, 3, 4, 5};

// int
Stack<int, 10> s1;
for (int i : data) {
   s1.push(i);
}
cout << s1 << endl;

// const int*
Stack<const int*, 10> s2;
for (const int& i : data) {
   s2.push(&i);
}
cout << string(s2) << endl;
~~~

... qui doit produire ce résultat

~~~
[0] 0
[1] 1
[2] 2
[3] 3
[4] 4
[5] 5

[0] 0
[1] 1
[2] 2
[3] 3
[4] 4
[5] 5
~~~

Que faut-il changer / ajouter ?

<details>
<summary>Solution</summary>

⚠️ la spécialisation partielle d'une méthode d'une classe générique n'est pas possible en C++

Seul changement, **ajouter une spécialisation** de l'`operator std::string()` dans l'implémentation.<br>
Cette solution n'est pas satisfaisante dans la mesure où ce sera toujours pour `10` x `const int*`

~~~cpp
template <>
Stack<const int*, 10>::operator std::string() const {
   std::string result;
   for (size_t i=0; i<this->size(); ++i)
      result += "[" + std::to_string(i) + "] " + std::to_string(*this->data[i]) + '\n';
   return result;
}
~~~

</details>

### Tous les fichiers ...

<details>
<summary>Solution - main.cpp</summary>

~~~cpp
#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

   const vector data = {0, 1, 2, 3, 4, 5};

   // int
   Stack<int, 10> s1;
   for (int i : data) {
      s1.push(i);
   }
   cout << s1 << endl;

   // const int*
   Stack<const int*, 10> s2;
   for (const int& i : data) {
      s2.push(&i);
   }
   cout << string(s2) << endl;


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
#include <string>

//---------------------------------------------------------
template <typename T, int n=100>
class Stack;

//---------------------------------------------------------
template <typename T, int n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s);

//---------------------------------------------------------
template <typename T, int n>
class Stack {

friend std::ostream& operator<< <>(std::ostream& os, const Stack<T, n>& s);

public:
   Stack () = default;
   Stack (const Stack& s);
   bool   push(const T&  v);
   bool   pop();
   bool   top(T& v)  const;
   bool   full()     const;
   bool   empty()    const;
   size_t size()     const;

   bool operator== (const Stack<T, n>& other) const;
   explicit operator std::string() const;

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
// friends
//---------------------------------------------------------
template <typename T, int n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   return os << std::string(s);
}

//---------------------------------------------------------
// class Stack
//---------------------------------------------------------
template <typename T, int n>
Stack<T, n>::Stack (const Stack& s) {
   this->index = s.index;
   this->data  = s.data;
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
bool Stack<T, n>::operator== (const Stack<T, n>& other) const {
   return std::equal(this->data.begin(), this->data.end(), other.data.begin());
}

//---------------------------------------------------------
template <typename T, int n>
Stack<T, n>::operator std::string() const {
   std::string result;
   for (size_t i=0; i<this->size(); ++i)
      result += "[" + std::to_string(i) + "] " + std::to_string(this->data[i]) + '\n';
   return result;
}

//---------------------------------------------------------
template <>
Stack<const int*, 10>::operator std::string() const {
   std::string result;
   for (size_t i=0; i<this->size(); ++i)
      result += "[" + std::to_string(i) + "] " + std::to_string(*this->data[i]) + '\n';
   return result;
}

#endif //STACK_IMPL_H
~~~

</details>

