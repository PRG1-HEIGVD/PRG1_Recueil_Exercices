## Tableau dynamique

Soit le `main` proposé et le résultat attendu.

Implémenter la classe `Tab` qui contient les propriétés privées suivantes

| Propriété | Details                                                 |
|:----------|:--------------------------------------------------------|
| `T* _data` | Un pointeur sur une zone mémoire réservée dynamiquement |
| `_size`   | La taille de la zone mémoire réservée dynamiquement     |

~~~cpp
int main() {

   const size_t n = 3;

   try {
      cout << "------------" << endl;
      cout << "   tab1     " << endl;
      cout << "------------" << endl;
      Tab<int> tab1(n);
      for (size_t i = 0; i < n; ++i) {
         tab1.at(i) = (int) i;
      }
      cout << tab1 << endl;
      cout << "size : " << tab1.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab2     " << endl;
      cout << "------------" << endl;
      Tab<int> tab2(n);
      tab2 = tab1;
      cout << tab2 << endl;
      cout << "size : " << tab2.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab3     " << endl;
      cout << "------------" << endl;
      const Tab<int> tab3(tab1);
      cout << tab3 << endl;
      cout << "size : " << tab3.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   [] / at  " << endl;
      cout << "------------" << endl;
      cout << "tab1[0]     = 1; " << endl;
      tab1[0] = 1;
      cout << "tab1[0]     : " << tab1[0] << endl;
      cout << endl;
      cout << "tab1.at(1)  = 2; " << endl;
      tab1.at(2) = 2;
      cout << "tab1.at(1)  : " << tab1.at(2) << endl;

      try {
         cout << "tab1[3]     : " << tab1[3] << endl;
         cout << "tab3.at(3)  : " << tab3.at(3) << endl;
      }
      catch (out_of_range &e) {
         cout << "exception : " << e.what() << endl;
      }

      cout << endl;

   }
   catch (bad_alloc& e) {
      cout << e.what() << endl;
   }

   cout << endl;
   cout << "fin de programme" << endl;
   return EXIT_SUCCESS;
}
~~~

~~~
------------
   tab1     
------------
[0, 1, 2]
size : 3

------------
   tab2     
------------
[0, 1, 2]
size : 3

------------
   tab3     
------------
[0, 1, 2]
size : 3

------------
   [] / at  
------------
tab1[0]     = 1; 
tab1[0]     : 1

tab1.at(1)  = 2; 
tab1.at(1)  : 2
tab1[3]     : 0
tab3.at(3)  : exception : Tab::at(size_t pos) const


fin de programme
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <algorithm>

//----------------------------------------------------------
template <typename T>
class Tab;

//----------------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Tab<T>& tab);

template <typename T>
void swap(Tab<T>& a, Tab<T>& b);

//----------------------------------------------------------
template <typename T>
class Tab {
   friend std::ostream& operator<< <>(std::ostream& os, const Tab<T>& tab);
   friend void swap<>(Tab& a, Tab& b);

public:
   Tab(size_t n);
   ~Tab();

   Tab(const Tab& other);
   Tab& operator= (const Tab& other);

   T& operator[] (size_t pos);
   T  operator[] (size_t pos) const;

   T& at(size_t pos);
   T  at(size_t pos) const;

   size_t size() const { return _size; };

private:
   size_t _size;
   T* _data;
};

//----------------------------------------------------------
int main() {
   using namespace std;

   const size_t n = 3;

   try {
      cout << "------------" << endl;
      cout << "   tab1     " << endl;
      cout << "------------" << endl;
      Tab<int> tab1(n);
      for (size_t i = 0; i < n; ++i) {
         tab1.at(i) = (int) i;
      }
      cout << tab1 << endl;
      cout << "size : " << tab1.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab2     " << endl;
      cout << "------------" << endl;
      Tab<int> tab2(n);
      tab2 = tab1;
      cout << tab2 << endl;
      cout << "size : " << tab2.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab3     " << endl;
      cout << "------------" << endl;
      const Tab<int> tab3(tab1);
      cout << tab3 << endl;
      cout << "size : " << tab3.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   [] / at  " << endl;
      cout << "------------" << endl;
      cout << "tab1[0]     = 1; " << endl;
      tab1[0] = 1;
      cout << "tab1[0]     : " << tab1[0] << endl;
      cout << endl;
      cout << "tab1.at(1)  = 2; " << endl;
      tab1.at(2) = 2;
      cout << "tab1.at(1)  : " << tab1.at(2) << endl;

      try {
         cout << "tab1[3]     : " << tab1[3] << endl;
         cout << "tab3.at(3)  : " << tab3.at(3) << endl;
      }
      catch (out_of_range &e) {
         cout << "exception : " << e.what() << endl;
      }

      cout << endl;

   }
   catch (bad_alloc& e) {
      cout << e.what() << endl;
   }

   cout << endl;
   cout << "fin de programme" << endl;
   return EXIT_SUCCESS;
}

//----------------------------------------------------------
//    friends
//----------------------------------------------------------
template <typename T>
std::ostream& operator<< (std::ostream& os, const Tab<T>& tab) {
   os << "[";
   for (size_t i=0; i<tab.size(); ++i) {
      if (i) os << ", ";
      os << tab[i];
   }
   os << "]";
   return os;
}

template <typename T>
void swap(Tab<T>& a, Tab<T>& b) {
   using std::swap;
   swap(a._size, b._size);
   swap(a._data, b._data);
}

//----------------------------------------------------------
//    class Tab
//----------------------------------------------------------
template <typename T>
Tab<T>::Tab(size_t n) : _size(n), _data(new T[n])
{
}

//----------------------------------------------------------
template <typename T>
Tab<T>::Tab(const Tab& other) : Tab(other._size) {
   std::copy_n(other._data, _size, _data);
}

//----------------------------------------------------------
template <typename T>
Tab<T>::~Tab() {
   delete[] _data;
}

//----------------------------------------------------------
template <typename T>
Tab<T>& Tab<T>::operator= (const Tab& other) {
   if ( _size != other._size ) {
      // la taille change, on utilise la technique "copy and swap"
      Tab tmp(other);
      swap(tmp, *this);
   } else if ( _data != other._data ) {
      // la taille ne change pas, il suffit de
      // copier les données.
      // attention, seulement garantie faible si
      // std::copy_n lève une exception
      std::copy_n(other._data, _size, _data);
   }
   return *this;
}

//----------------------------------------------------------
template <typename T>
T& Tab<T>::operator[] (size_t pos) {
   return _data[pos];
}

//----------------------------------------------------------
template <typename T>
T Tab<T>::operator[] (size_t pos) const {
   return _data[pos];
}

//----------------------------------------------------------
template <typename T>
T& Tab<T>::at(size_t pos) {
   if (pos >= _size)
      throw std::out_of_range("Tab::at(size_t pos)");
   return _data[pos];
}

//----------------------------------------------------------
template <typename T>
T Tab<T>::at(size_t pos) const {
   if (pos >= _size)
      throw std::out_of_range("Tab::at(size_t pos) const");
   return _data[pos];
}

~~~

</details>
