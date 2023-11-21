# fonctions surchargées

Soient les fonctions

~~~cpp
double      f (signed char)   { cout << "signed char ";  return 0.; }
signed char f (int &)         { cout << "int & ";        return 0;  }
int         f (const int &)   { cout << "const int & ";  return 0;  }
float       f (unsigned)      { cout << "unsigned ";     return 0;  }
unsigned    f (double)        { cout << "double ";       return 0;  }
float       f (float&)        { cout << "float& ";       return 0.; }
~~~

Que produisent les appels ci-dessous

| Appel										| Résultat  |
|---											|---        |
| f('a');									|           |
| f(42);									|           |
| int i = 42;<br>f(++i);			|           |
| int j = 42;<br>f(j--);			|           |
| const float pi = 3.14f;<br>f(pi);|   |
| f(2ull);									|           |
| long a; double b;<br>f (a<b);|           |
| float r = 2.f;<br>f(r *= 2.l)	|           |
| f(f(2u));								|           |
| f('2') ? f(2.0) : f(-2); 		|           |

<details>
<summary>Solution</summary>

| Appel										| Résultat           |
|---											|---                 |
| f('a');									| const int &        |
| f(42);									| const int &        |
| int i = 42;<br>f(++i);			| int &              |
| int j = 42;<br>f(j--);			| const int &        |
| const float pi = 3.141592f;<br>f(pi);| double     |
| f(2ull);									| Appel ambigu       |
| long a; double b;<br>f (a<b);| const int &        |
| float r = 2.f;<br>f(r *= 2.l)	| float &            |
| f(f(2u));								| unsigned double    |
| f('2') ? f(2.0) : f(-2); 		| const int & double |

</details>

