# classe générique Stack -  spécialisation

Reprendre l'exercice [01-09 Stack - opérateur](01-09%20-%20classe%20Stack%20-%20operateur.md).

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
<summary>Solution par spécialisation</summary>

⚠️ la spécialisation partielle d'une méthode d'une classe générique n'est pas possible en C++

Seul changement, **ajouter une spécialisation** de l'`operator <<` dans l'implémentation.
Cette solution n'est pas satisfaisante dans la mesure où ce sera toujours pour `10` x `const int*`.

~~~cpp
template <>
std::ostream& operator<< (std::ostream& os, const Stack<const int*, 10>& s) {
   for (size_t i = 0; i < s.index; ++i) {
      os << "[" << i << "] "<< *s.data[i] << '\n';
   }
   return os;
}
~~~

</details>

<details>
<summary>Solution par surcharge</summary>

Une meilleure solution consiste à ne faire différer le code que pour l'affichage d'un élément. 
Plutôt que d'utiliser l'opérateur `<<` pour les afficher, on crée une fonction `__display_stack_element`
que l'on surcharge pour les types pointeurs. 

~~~cpp 
template <typename T>
std::ostream& __display_stack_element(std::ostream& os, T t) {
   return os << t;
}

template <typename T>
std::ostream& __display_stack_element(std::ostream& os, T* t) {
   return os << *t;
};

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   for (size_t i = 0; i < s.index; ++i) {
      os << "[" << i << "] ";
      __display_stack_element(os, s.data[i]);
      os << '\n';
   }
   return os;
}
~~~

### Tous les fichiers ...

<details>
<summary>Solution - main.cpp</summary>

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

template <typename T>
std::ostream& __display_stack_element(std::ostream& os, T t) {
   return os << t;
}

template <typename T>
std::ostream& __display_stack_element(std::ostream& os, T* t) {
   return os << *t;
};

template <typename T, size_t n>
std::ostream& operator<< (std::ostream& os, const Stack<T, n>& s) {
   for (size_t i = 0; i < s.index; ++i) {
      os << "[" << i << "] ";
      __display_stack_element(os, s.data[i]);
      os << '\n';
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

💡Une meilleure solution sera vue à l'exercice [13-03-03 - classe Stack - type_traits](13-03-03%20-%20classe%20Stack%20-%20type_traits.md).
