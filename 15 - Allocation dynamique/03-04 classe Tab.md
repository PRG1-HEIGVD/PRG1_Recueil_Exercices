## Tableau dynamique

Soit le `main` proposé et le résultat attendu.

Implémenter la classe `Tab` qui contient une propriété privée `T* data` sur un espace mémoire réservé dynamiquement.

~~~cpp
int main() {

   const size_t N = 3;

   try {
      cout << "------------" << endl;
      cout << "   tab1     " << endl;
      cout << "------------" << endl;
      Tab<int, N> tab1;
      for (size_t i = 0; i < N; ++i) {
         tab1.at(i) = (int) i;
      }
      cout << tab1 << endl;
      cout << "size : " << tab1.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab2     " << endl;
      cout << "------------" << endl;
      Tab<int, N> tab2;
      tab2 = tab1;
      cout << tab2 << endl;
      cout << "size : " << tab2.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab3     " << endl;
      cout << "------------" << endl;
      const Tab<int, N> tab3(tab1);
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
tab3.at(3)  : exception : Tab::at


fin de programme
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <algorithm>

using namespace std;

//----------------------------------------------------------
template <typename T, size_t n>
class Tab;

//----------------------------------------------------------
template <typename T, size_t n>
ostream& operator<< (ostream& os, const Tab<T, n>& tab);

//----------------------------------------------------------
template <typename T, size_t n>
class Tab {
   friend ostream& operator<< <>(ostream& os, const Tab<T, n>& tab);

public:
   Tab();
   Tab(const Tab& other);
   ~Tab();

   Tab<T, n>& operator= (const Tab& other);

   T& operator[] (size_t pos);
   T  operator[] (size_t pos) const;

   T& at(size_t pos);
   T  at(size_t pos) const;

   size_t size() const { return n; };

private:
   T* data = nullptr;
};

//----------------------------------------------------------
int main() {

   const size_t N = 3;

   try {
      cout << "------------" << endl;
      cout << "   tab1     " << endl;
      cout << "------------" << endl;
      Tab<int, N> tab1;
      for (size_t i = 0; i < N; ++i) {
         tab1.at(i) = (int) i;
      }
      cout << tab1 << endl;
      cout << "size : " << tab1.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab2     " << endl;
      cout << "------------" << endl;
      Tab<int, N> tab2;
      tab2 = tab1;
      cout << tab2 << endl;
      cout << "size : " << tab2.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   tab3     " << endl;
      cout << "------------" << endl;
      const Tab<int, N> tab3(tab1);
      cout << tab3 << endl;
      cout << "size : " << tab3.size() << endl;
      cout << endl;

      cout << "------------" << endl;
      cout << "   [] / at  " << endl;
      cout << "------------" << endl;
      cout << "tab1[0]     = 1; " << endl
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
//    friend
//----------------------------------------------------------
template <typename T, size_t n>
ostream& operator<< (ostream& os, const Tab<T, n>& tab) {
   os << "[";
   for (size_t i=0; i<n; ++i) {
      if (i) os << ", ";
      os << tab[i];
   }
   os << "]";
   return os;
}

//----------------------------------------------------------
//    class Tab
//----------------------------------------------------------
template <typename T, size_t n>
Tab<T, n>::Tab() {
//   cout << "Tab::Tab()" << endl;
   this->data = new T[n];
}

//----------------------------------------------------------
template <typename T, size_t n>
Tab<T, n>::Tab(const Tab& other) {
//   cout << "Tab::Tab(const Tab& other)" << endl;
   this->data = new T[n];
   copy(other.data, other.data+n, this->data);
}

//----------------------------------------------------------
template <typename T, size_t n>
Tab<T, n>::~Tab() {
//   cout << "Tab::~Tab()" << endl;
   delete[] this->data;
}

//----------------------------------------------------------
template <typename T, size_t n>
Tab<T, n>& Tab<T, n>::operator= (const Tab& other) {
//   cout << "Tab::operator= (const Tab& other)" << endl;

   if (this == &other)
      return *this;

   copy(other.data, other.data+n, this->data);
   return *this;
}

//----------------------------------------------------------
template <typename T, size_t n>
T& Tab<T, n>::operator[] (size_t pos) {
//   cout << "Tab::operator[]" << endl;
   return this->data[pos];
}

//----------------------------------------------------------
template <typename T, size_t n>
T Tab<T, n>::operator[] (size_t pos) const {
//   cout << "Tab::operator[] (size_t pos) const" << endl;
   return this->data[pos];
}

//----------------------------------------------------------
template <typename T, size_t n>
T& Tab<T, n>::at(size_t pos) {
//   cout << "Tab::at(size_t pos)" << endl;
   if (pos >= n)
      throw out_of_range("Tab::at(size_t pos)");
   return this->data[pos];
}

//----------------------------------------------------------
template <typename T, size_t n>
T Tab<T, n>::at(size_t pos) const {
//   cout << "Tab::at(size_t pos) const" << endl;
   if (pos >= n)
      throw out_of_range("Tab::at(size_t pos) const");
   return this->data[pos];
}
~~~

</details>
