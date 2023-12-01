# Surcharge et spécialisation

Que produisent les appels aux fonctions ci-dessous ?
Indiquer les cas d'ambiguité.

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

**Méthode**<br>

1. déduire les arguments génériques pour toutes les fonctions génériques, et établir la liste des fonctions appelables, y compris par conversion pour les paramètres non génériques
	1. si elle est vide, il y a erreur de compilation 	
2. Parmi ces fonctions appelables, pour chacun des paramètres, établir celles qui sont appelables le plus simplement, i.e. 
	1. par type exact
	2. sinon par conversion simple (ajout d'un `const`) 
	3. sinon par promotion numérique
	4. sinon par conversion de type 
3. Faire l'intersection des ensembles sélectionnés par chaque paramètre
   	1. s'il est vide, il y a ambiguité
   	2. s'il a 1 élément, cette fonction est appelée
4. S'il reste plusieurs fonctions
	1. si une est plus spécialisée que toutes les autres, elle est appelée
 	2. sinon, il y a ambiguité 		
<br>

**Cas simplifié**<br>
Si une fonction non générique est appelable par type exact pour tous ses arguments, il n'est pas nécessaire de 
considérer les alternatives génériques. 

<br>

~~~cpp
// no 1
fct(pd, d);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables. 
   - 3 : types différents déduits pour `T` (`double*` et `double`)
   - 5 : pas de conversion `double*` vers `int`
   - 6 : pas de conversion `double*` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4\right\\}$ par type exact 
   - $P_{2} = \left\\{1, 2\right\\}$ par type exact 
     - 4 : conversion `double` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$ 
4. fct no 2 : plus spécialisée que 1 

--------------------

</details>

~~~cpp
// no 2
fct(c, f);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 4, 5\right\\}$ sont appelables. 
   - 2 : `T* = char` pas déductible
   - 3 : `T = char` et `T = float` non compatibles
   - 6 : pas de conversion `char` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 4\right\\}$ par type exact
     - 6 par promotion `char` vers `int`
   - $P_{2} = \left\\{1\right\\}$ par type exact 
     - 4 et 5 par conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$, la  fct no 1 est appelée 

--------------------

</details>

~~~cpp
// no 3
fct(pf, s)
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables. 
   - 3 : `T = float*` et `T = short` non compatibles
   - 5 : pas de conversion `float*` vers `int`
   - 6 : pas de conversion `float*` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2\right\\}$ par type exact 
     - 4 par promotion `short` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$
4. fct no 2 : plus spécialisée que 1

--------------------

</details>

~~~cpp
// no 4
fct(pi, f);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4, 6\right\\}$ sont appelables. 
   - 3 : `T = int*` et `T = float` non compatibles
   - 5 : pas de conversion `int*` vers `int`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4, 6\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2, 6\right\\}$ par type exact 
     - 6 par conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 2, 6\right\\}$
4. fct no 6 : fonction non générique toujours plus spécialisée que les fonctions générique
</details>

~~~cpp
// no 5
fct(pc, pc);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 3\right\\}$ sont appelables. 
   - 4 : pas de conversion `char*` vers `int`
   - 5 : pas de conversion `char*` vers `int`
   - 6 : pas de conversion `char*` vers `float`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 3\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2, 3\right\\}$ par type exact 
3. $P_{1} \cap P_{2} = \left\\{1, 2, 3\right\\}$
4. fct no 2 : plus spécialisée que la 1<br>
   fct no 3 : plus spécialisée que la 1<br>
   pas d'ordre de spécialisation entre la 2 et la 3 => **appel ambigu**

--------------------

</details>

~~~cpp
// no 6
fct(pi,  i)
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4, 6\right\\}$ sont appelables. 
   - 3 : `T = int*` et `T = int` non compatibles
   - 5 : pas de conversion `int*` vers `int`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4, 6\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2, 4\right\\}$ par type exact
      - 6 par conversion `int` vers `float`
3. $P_{1} \cap P_{2} = \left\\{1, 2, 4\right\\}$
4. fct no 2 : plus spécialisée que la 1<br>
   fct no 4 : plus spécialisée que la 1<br>
   pas d'ordre de spécialisation entre la 2 et la 4 => **appel ambigu**

--------------------

</details>

~~~cpp
// no 7
fct(f,   f)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 8
fct(i,   i)`    | {1,    3, 4, 5   } | {1,    3, 4, 5   } | {1,    3, 4, 5   } | 5 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 9
fct(d,   i)`    | {1,    3, 4      } | {1,       4      } | {1,       4      } | 4 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 10
fct(c,   c)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 11
fct(c,   s)`    | {1,    3, 4      } | {1               } | {1               } | 1                  |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 12
fct(pd,  i)`    | {1, 2, 3, 4      } | {1, 2,    4      } | {   2,    4      } | ambiguité {2, 4}   |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 13
fct(i,   c)`    | {1,    3, 4, 5   } | {1               } | {1               } | 1                  |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 14
fct(pc, pd)`    | {1, 2, 3, 4      } | {1, 2            } | {   2            } | 2                  |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 15
fct(d,   d)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 16
fct(s+1, i)`    | {1,    3, 4, 5   } | {1,    3, 4, 5   } | {1,    3, 4, 5   } | 5 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 17
fct(s+d, d)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 18
fct<>(i, i)`    | {1,    3, 4      } | {1,    3, 4      } | {1,    3, 4      } | ambiguité {3, 4}   |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 19
fct<>(c, c)`    | {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 20
fct<int>(d, d)` | {1,    3, 4      } | {1               } | {1               } | 1                  |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

~~~cpp
// no 21
fct<char>(d, c)`| {1,    3, 4      } | {1,    3         } | {1,    3         } | 3 plus spécialisée |
~~~

<details>
<summary>Solution</summary>

--------------------

</details>

