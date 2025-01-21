# Que produit ce code
Que produit le code ci-dessous ?

| # | a | b | c | min | d |
|---|---|---|---|-----|---|
| 1)|   |   |   |     |   |
| 2)|   |   |   |     |   |
| 3)|   |   |   |     |   |
| 4)|   |   |   |     |   |
| 5)|   |   |   |     |   |

~~~cpp
#include <cstdlib>
#include <iostream>

using namespace std;

int& min(int& a, int& b, int& c) {
      return a < c ?
         a < b ? a : b :
         b < c ? b : c ;
}

int main() {

   int a = 12,
       b = 7,
       c = 9;

   cout << "1) a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   int& d = min(a, b, c);
   cout << "d:" << d << endl << endl;

   b=5;
   cout << "2) b = 5;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   d=3;
   cout << "3) d = 3;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   a=1;
   cout << "4) a = 1;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   cout << "5) min(a, b, c) = 0;" << endl;
   min(a, b, c) = 0;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   return EXIT_SUCCESS;
}

~~~

<details>
<summary>Solution</summary>

| # | a | b | c | min | d |
|---|---|---|---|-----|---|
| 1)| 12| 7 | 9 |  7  | 7 |
| 2)| 12| 5 | 9 |  5  | 5 |
| 3)| 12| 3 | 9 |  3  | 3 |
| 4)|  1| 3 | 9 |  1  | 3 |
| 5)|  0| 3 | 9 |  0  | 3 |

</details>
