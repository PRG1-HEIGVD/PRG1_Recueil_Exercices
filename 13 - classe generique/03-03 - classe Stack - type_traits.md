# classe générique Stack -  type_traits

Reprise de l'exercice [01-10 - classe Stack - specialisation](01-10%20-%20classe%20Stack%20-%20specialisation.md)

En utilisant le header [`<type_traits>`](https://cplusplus.com/reference/type_traits/) et un [`constexpr if`](https://en.cppreference.com/w/cpp/language/if#Constexpr_if),
écrivez un opérateur `<<` qui fonctionne pour les types pointeurs et non pointeurs sans utiliser ni surcharge 
ni spécialisation. 

<details>
<summary>Solution</summary>

~~~cpp
#include <type_traits>   // std::is_pointer

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   for (size_t i = 0; i < s.index; ++i) {
      if constexpr (std::is_pointer<T>::value)
         os << "[" << i << "] " << *s.data[i] << '\n';
      else
         os << "[" << i << "] " << s.data[i] << '\n';
   }
   return os;
}
~~~

Notons qu'il est indispensable ici d'utiliser `if constexpr`. 

Si on oublie le `constexpr`, le code  ne compile pas pour les types T qui ne disposent pas de l'opérateur `*` unaire, i.e. pour les  types qui en sont pas des pointeurs ou des itérateurs. 

Avec `constexpr`, la branche qui n'est pas exécutée n'est pas non plus compilée.

### Tous les fichiers ...

<details>
<summary>main.cpp</summary>

~~~cpp
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
}
~~~

</details>

<details>
<summary>Stack.h</summary>

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
<summary>Stack_Impl.h</summary>

~~~cpp
#ifndef STACK_IMPL_H
#define STACK_IMPL_H

#include <ostream>
#include <sstream>
#include <type_traits>
#include "Stack.h"

//-- friends ----------------------------------------------

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   for (size_t i = 0; i < s.index; ++i) {
      if constexpr (std::is_pointer<T>::value)
         os << "[" << i << "] " << *s.data[i] << '\n';
      else
         os << "[" << i << "] " << s.data[i] << '\n';
   }
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
   // en cas de pop() sur une stack vide. sinon --index suffit
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

</details>

