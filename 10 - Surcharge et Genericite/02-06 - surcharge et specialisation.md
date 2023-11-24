# Surcharge et spécialisation

Soient les fonctions et les déclarations suivantes

~~~cpp
template <typename T, typename U> int fct(T,       U)      { .. } // 1
template <typename T, typename U> int fct(T*,      U)      { .. } // 2
template <typename T>             int fct(T,       T)      { .. } // 3
template <typename T>             int fct(T,       int)    { .. } // 4
                                  int fct(int,     int)    { .. } // 5
                                  int fct(int*,    float)  { .. } // 6
int     i  = 1;
char    c  = 65;     // code ASCII de 'A'
short   s  = 2;
float   f  = 1.7f;
double  d  = 3.1;
int*    pi = &i;     // ptr sur i
char*   pc = &c;     // ptr sur c
float*  pf = &f;     // ptr sur f
double* pd = &d;     // ptr sur d
~~~

Pour chacun des appels, indiquer :

- **Fonctions viables** (surcharge)<br>
liste des fonctions viables après résolutions des cas de surcharge

- **Plus spécialisée(s)**<br>
si applicable, la liste des fonctions après détermination de l’ordre de spécialisation.<br>
Indiquer également les cas d’ambiguïté.

<br>

| no | Appel            | param no 1         | param no 2         | ∩                  | Fonction appelée    |
|----|------------------|--------------------|--------------------|--------------------|---------------------|
| ex | `fct(pd,  d)`    | {1, 2, 3, 4      } | {1, 2            } | {1, 2            } |  2 plus spécialisée |
|  1 | `fct(c,   f)`    |                    |                    |                    |                     |
|  2 | `fct(pf,  s)`    |                    |                    |                    |                     |
|  3 | `fct(pi,  f)`    |                    |                    |                    |                     |
|  4 | `fct(pc, pc)`    |                    |                    |                    |                     |
|  5 | `fct(pi,  i)`    |                    |                    |                    |                     |
|  6 | `fct(f,   f)`    |                    |                    |                    |                     |
|  7 | `fct(i,   i)`    |                    |                    |                    |                     |
|  8 | `fct(d,   i)`    |                    |                    |                    |                     |
|  9 | `fct(c,   c)`    |                    |                    |                    |                     |
| 10 | `fct(c,   s)`    |                    |                    |                    |                     |
| 11 | `fct(pd,  i)`    |                    |                    |                    |                     |
| 12 | `fct(i,   c)`    |                    |                    |                    |                     |
| 13 | `fct(pc, pd)`    |                    |                    |                    |                     |
| 14 | `fct(d,   d)`    |                    |                    |                    |                     |
| 15 | `fct(s+1, i)`    |                    |                    |                    |                     |
| 16 | `fct(s+d, d)`    |                    |                    |                    |                     |
| 17 | `fct<>(i, i)`    |                    |                    |                    |                     |
| 18 | `fct<>(c, c)`    |                    |                    |                    |                     |
| 19 | `fct<int>(d, d)` |                    |                    |                    |                     |
| 20 | `fct<char>(d, c)`|                    |                    |                    |                     |

<details>
<summary>Solution</summary>

| no | Appel            | param no 1         | param no 2         | ∩                  | Fonction appelée    |
|----|------------------|--------------------|--------------------|--------------------|---------------------|
| ex | `fct(pd,  d)`    | {1, 2, 3, 4      } | {1, 2            } | {1, 2            } |  2 plus spécialisée |
|  1 | `fct(c,   f)`    | {1,    3, 4      } | {1,              } | {1               } |  1                  |
|  2 | `fct(pf,  s)`    | {1, 2, 3, 4      } | {1, 2            } | {1, 2            } |  2 plus spécialisée |
|  3 | `fct(pi,  f)`    | {1, 2, 3, 4,    6} | {1, 2,          6} | {1, 2,          6} |  6 plus spécialisée |
|  4 | `fct(pc, pc)`    | {1, 2, 3, 4      } | {1, 2, 3         } | {   2, 3         } |  ambiguité {2, 3}   |
|  5 | `fct(pi,  i)`    | {1, 2, 3, 4,    6} | {1, 2,    4      } | {   2,    4      } |  ambiguité {2, 4}   |
|  6 | `fct(f,   f)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |
|  7 | `fct(i,   i)`    | {1,    3, 4, 5   } | {1,    3, 4, 5   } | {1,    3, 4, 5   } |  5 plus spécialisée |
|  8 | `fct(d,   i)`    | {1,    3, 4      } | {1,       4      } | {1,       4      } |  4 plus spécialisée |
|  9 | `fct(c,   c)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |
| 10 | `fct(c,   s)`    | {1,    3, 4      } | {1               } | {1               } |  1                  |
| 11 | `fct(pd,  i)`    | {1, 2, 3, 4      } | {1, 2,    4      } | {   2,    4      } |  ambiguité {2, 4}   |
| 12 | `fct(i,   c)`    | {1,    3, 4, 5   } | {1               } | {1               } |  1                  |
| 13 | `fct(pc, pd)`    | {1, 2, 3, 4      } | {1, 2            } | {   2            } |  2                  |
| 14 | `fct(d,   d)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |
| 15 | `fct(s+1, i)`    | {1,    3, 4, 5   } | {1,    3, 4, 5   } | {1,    3, 4, 5   } |  5 plus spécialisée |
| 16 | `fct(s+d, d)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |
| 17 | `fct<>(i, i)`    | {1,    3, 4      } | {1,    3, 4      } | {1,    3, 4      } |  ambiguité {3, 4}   |
| 18 | `fct<>(c, c)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |
| 19 | `fct<int>(d, d)` | {1,    3, 4      } | {1               } | {1               } |  1                  |
| 20 | `fct<char>(d, c)`| {1,    3, 4      } | {1,    3         } | {1,    3         } |  3 plus spécialisée |

</details>
