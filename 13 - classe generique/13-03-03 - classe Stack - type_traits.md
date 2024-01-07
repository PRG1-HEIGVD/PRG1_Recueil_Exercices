# classe générique Stack -  type_traits

Reprise de l'exercice [13-01-10 - classe Stack - specialisation](13-01-10%20-%20classe%20Stack%20-%20specialisation.md)

Pourrions-nous éviter de faire une spécialisation mais à la place de rendre le code spécifique au type reçu.

💡Utiliser [`type_traits`](https://cplusplus.com/reference/type_traits/)

<details>
<summary>Solution</summary>

~~~cpp
#include <type_traits>

template <typename T, int n>
Stack<T, n>::operator std::string() const {
   std::stringstream result;
   for (size_t i = 0; i < this->size(); ++i)
      if constexpr (std::is_pointer<T>::value)
         result << "[" << i << "] " << *this->data[i] << '\n';
      else
         result << "[" << i << "] " << this->data[i] << '\n';
   return result.str();
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
#include <sstream>
#include <type_traits>

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
   std::stringstream result;
   for (size_t i = 0; i < this->size(); ++i)
      if constexpr (std::is_pointer<T>::value)
         result << "[" << i << "] " << *this->data[i] << '\n';
      else
         result << "[" << i << "] " << this->data[i] << '\n';
   return result.str();
}

#endif //STACK_IMPL_H
~~~

</details>

