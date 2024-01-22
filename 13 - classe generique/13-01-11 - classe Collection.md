# classe générique Collection

Soit le programme principal

~~~cpp
#include <cstdlib>
#include <iostream>

#include <vector>
#include <list>

#include "Collection.h"

using namespace std;

int main() {

   // vector<int>
   Collection<int, std::vector> s1;
   for (int i : {0, 1, 2, 3, 4, 5}) {
      s1.add(i);
   }
   cout << s1 << endl;
   s1.remove(2);
   cout << s1 << endl;
   s1.clear();

   // list<string>
   Collection<string, std::list> s2;
   for (const string& s : {"chien"s, "chat"s, "souris"s}) {
      s2.add(s);
   }
   cout << string(s2) << endl;
   cout << endl;
   
   cout << "taille de s2 : " << s2.size() << endl;
   cout << "s2 " << (s2.empty() ? "est" : "n'est pas") << " vide" << endl;

   return EXIT_SUCCESS;
}
~~~

.. qui doit produire ce résultat

~~~
[0, 1, 2, 3, 4, 5]
[0, 1, 3, 4, 5]
[chien, chat, souris]

taille de s2 : 3
s2 n'est pas vide
~~~

<br>

Ecrire la classe `Collection`

💡Le container est passé en paramètre générique `Collection<int, std::vector> s1;`

<details>
<summary>Solution - Collection.h</summary>

~~~cpp
#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
class Collection;

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
std::ostream& operator<< (std::ostream& os, const Collection<T, Container>& s);

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
class Collection {

friend std::ostream& operator<< <>(std::ostream& os, const Collection<T, Container>& s);

public:
   Collection () = default;
   Collection (const Collection& s);
   void   add   (const T&  v);
   bool   remove(const T&  v);
   void   clear ();
   bool   empty () const;
   size_t size  () const;

   explicit operator std::string() const;

private:
   Container<T> data;
};

#include "Collection_Impl.h"

#endif //COLLECTION_H
~~~

</details>

<details>
<summary>Solution - Collection_Impl.h</summary>

~~~cpp
#ifndef COLLECTION_IMPL_H
#define COLLECTION_IMPL_H

#include <iostream>
#include <sstream>
#include <algorithm> // find

//---------------------------------------------------------
// friends
//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
std::ostream& operator<< (std::ostream& os, const Collection<T, Container>& s) {
   return os << std::string(s);
}

//---------------------------------------------------------
// class Collection
//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
Collection<T, Container>::Collection (const Collection<T, Container>& s) {
   this->data  = s.data;
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
void Collection<T, Container>::add(const T& v) {
   this->data.push_back(v);
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
bool Collection<T, Container>::remove(const T& v) {
   auto it=find(data.begin(), data.end(), v);
   bool is_found = it != data.end();
   if (is_found) {
      this->data.erase(it);
   }
   return is_found;
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
void Collection<T, Container>::clear() {
   this->data.erase(data.begin(), data.end());
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
bool Collection<T, Container>::empty() const {
   return this->data.empty();
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
size_t Collection<T, Container>::size() const {
   return this->data.size();
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
Collection<T, Container>::operator std::string() const {
   std::stringstream result;
   result << "[";
   for (auto it=data.begin(); it!=data.end(); ++it) {
      if (it !=data.begin()) result << ", ";
      result << *it;
   }
   result << "]";
   return result.str();
}

#endif //COLLECTION_IMPL_H
~~~

</details>
