# classe générique Stack -  opérateurs

Reprendre l'exercice [01-07 Stack](01-07%20-%20classe%20Stack%20-%20header%20et%20impl.md) pour les instructions suivantes

~~~cpp
Stack<int, 10> s;
for (int i=0; i<6; ++i) {
   s.push(i);
}

// cast Stack<T, n> => string
cout << string(s) << endl;

// constructeur par copie
Stack copie(s);

// opérateur de flux <<
cout << copie     << endl;

// opérateur ==
cout << boolalpha << (s == copie) << endl;
~~~

... qui produit ce résultat

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

true
~~~

<details>
<summary>Solution - main.cpp</summary>

~~~cpp
#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

   Stack<int, 10> s;
   for (int i=0; i<6; ++i) {
      s.push(i);
   }

   // cast Stack<T, n> => string
   cout << string(s) << endl;

   // constructeur par copie
   Stack copie(s);

   // opérateur de flux <<
   cout << copie     << endl;

   // opérateur ==
   cout << boolalpha << (s == copie) << endl;
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

//- Pré-déclarations --------------------------------------
template <typename T, size_t n> class Stack;
template <typename T, size_t n> std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s);
template <typename T, size_t n> bool operator == (const Stack<T, n>& lhs, const Stack<T, n>& rhs);

//--class Stack --------------------------------------------

template <typename T, size_t n = 100>
class Stack {
   
   friend std::ostream& operator << <>(std::ostream& os, const Stack& s);
   friend bool operator == <>(const Stack& lhs, const Stack& rhs);

public:
   Stack() : index{}, data{} {}
   // Constructeur de copie pas nécessaire. la version par défaut suffit

   // méthodes définies dans Stack_Impl.h
   void push(const T& v);
   void pop();
   const T& top() const;

   // méthodes triviales définies en ligne
   bool full() const { return index == n; }
   bool empty() const { return index == 0; }
   size_t size() const { return index; }
   size_t capacity() const { return n; }

   // conversion explicite Stack -> string
   explicit operator std::string() const;

private:
   size_t index;
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

#include <ostream>
#include <sstream>
#include "Stack.h"

//-- friends ----------------------------------------------

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   for (size_t i = 0; i < s.index; ++i)
      os << "[" << i << "] " << s.data[i] << '\n';
   return os;
}

template <typename T, size_t n>
bool operator == (const Stack<T, n>& lhs, const Stack<T, n>& rhs) {
   // deux piles sont égales si elles contiennent le même nombre d'éléments
   // et que ces éléments sont égaux. Le contenu de data à partir de
   // l'indice index n'a pas d'importance.

   return lhs.index == rhs.index and
          std::equal(lhs.data.begin(), lhs.data.begin() + lhs.index, rhs.data.begin());
}

//- class Stack -------------------------------------------

template <typename T, size_t n>
void Stack<T, n>::push(const T& v) {
   data.at(index++) = v;
}

template <typename T, size_t n>
void Stack<T, n>::pop() {
   data.at(--index);
   // Note : accès à data uniquement pour lever une exception
   // en cas de pop() sur une stack vide. sinon --index; suffit
}

template <typename T, size_t n>
const T& Stack<T, n>::top() const {
   return data.at(index - 1);
}

template <typename T, size_t n>
Stack<T, n>::operator std::string() const {
   return (std::stringstream() << *this).str();
}

#endif //STACK_IMPL_H
~~~

</details>

