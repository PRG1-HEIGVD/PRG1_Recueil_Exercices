# Surcharges avec fonctions ordinaires

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
1. *Cas simplifié* Si une fonction non générique est appelable par type exact pour tous ses arguments, il n'est pas nécessaire de considérer les alternatives génériques. 

2. Déduire les arguments génériques pour toutes les fonctions génériques, et établir la liste des fonctions appelables, y compris par conversion pour les paramètres non génériques
	1. si elle est vide, il y a erreur de compilation 	
3. Parmi ces fonctions appelables, pour chacun des paramètres, établir celles qui sont appelables le plus simplement, i.e. 
	1. par type exact
	2. sinon par conversion simple (ajout d'un `const`) 
	3. sinon par promotion numérique
	4. sinon par conversion de type 
4. Faire l'intersection des ensembles sélectionnés par chaque paramètre
	1. s'il est vide, il y a ambiguité
	2. s'il a 1 élément, cette fonction est appelée
5. S'il reste plusieurs fonctions
	1. si une est plus spécialisée que toutes les autres, elle est appelée
	2. sinon, il y a ambiguité
	
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
4. fct no 2 : plus spécialisée que 1, **la fct no 2 est appelée**

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
   - 3 : types différents déduits pour `T` (`char` et `float`)
   - 6 : pas de conversion `char` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 4\right\\}$ par type exact
     - 6 par promotion `char` vers `int`
   - $P_{2} = \left\\{1\right\\}$ par type exact 
     - 4 et 5 par conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$, **la fct no 1 est appelée**

--------------------

</details>

~~~cpp
// no 3
fct(pf, s)
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables. 
   - 3 : types différents déduits pour `T` (`float*` et `short`)
   - 5 : pas de conversion `float*` vers `int`
   - 6 : pas de conversion `float*` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2\right\\}$ par type exact 
     - 4 par promotion `short` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$
4. fct no 2 plus spécialisée que 1, **la fct no 2 est appelée**

--------------------

</details>

~~~cpp
// no 4
fct(pi, f);
~~~

<details>
<summary>Solution</summary>
Cas simplifié: il existe une fonction ordinaire avec exactement les bons types pour tous les paramètres (n°6); c'est elle qui est appelée.
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
fct(pi, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4, 6\right\\}$ sont appelables. 
   - 3 : types différents déduits pour `T` (`int*` et `int`)
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
fct(f, f);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4, 5\right\\}$ sont appelables. 
   - 2 : Pas de déduction de `T` pour `T* = float`
   - 6 : pas de conversion `float` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
     - 5 requiert une conversion `float` vers `int`
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 et 5 requièrent une conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. fct no 3 : plus spécialisée que la 1 => **la fct no 3 est appelée**

--------------------

</details>

~~~cpp
// no 8
fct(i, i);
~~~

<details>
<summary>Solution</summary>
Cas simplifié: il existe une fonction ordinaire avec exactement les bons types pour tous les paramètres (n°5); c'est elle qui est appelée.
--------------------

</details>

~~~cpp
// no 9
fct(d, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 4, 5\right\\}$ sont appelables. 
   - 2 : `double` n'est pas compatible pour `T*`
   - 3 : types différents déduits pour `T` (`double` et `int`)
   - 6 : pas de conversion de `double` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 4\right\\}$ par type exact
     - 5 par conversion 
   - $P_{2} = \left\\{1, 4, 5\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{1, 4\right\\}$
4. fct no 4 : plus spécialisée que la 1 => **la fct no 4 est appelée**

--------------------

</details>

~~~cpp
// no 10
fct(c, c);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4, 5\right\\}$ sont appelables. 
   - 2 : `char` n'est pas compatible pour `T*`
   - 6 : pas de conversion de `char` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
     - 5 par promotion `char` vers `int`
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 et 5 par promotion `char` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. fct no 3 : plus spécialisée que la 1 => **la fct no 3 est appelée**

--------------------

</details>

~~~cpp
// no 11
fct(c, s);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 4, 5\right\\}$ sont appelables. 
   - 2 : Pas de déduction pour `T* = char`
   - 3 : types différents déduits pour `T` (`char` et `short`)
   - 6 : pas de conversion `char` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 4\right\\}$ par type exact
     - 5 par promotion `char` vers `int`
   - $P_{2} = \left\\{1\right\\}$ par type exact
     - 4 et 5 par promotion `char` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$
4. **la fct no 1 est appelée**

--------------------

</details>

~~~cpp
// no 12
fct(pd, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables. 
   - 3 : types différents déduits pour `T` (`double*` et `int`)
   - 5 : pas de conversion `double*` vers `int`
   - 6 : pas de conversion `double*` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 2, 4\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2, 4\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{1, 2, 4\right\\}$
4. fct no 2 : plus spécialisée que la 1<br>
   fct no 4 : plus spécialisée que la 1<br>
   pas d'ordre de spécialisation entre la 2 et la 4 => **appel ambigu**

--------------------

</details>

~~~cpp
// no 13
fct(i, c);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 4, 5\right\\}$ sont appelables. 
   - 2 : pas de déduction pour `T* = int`
   - 3 : types différents déduits pour `T` (`int` et `char`)
   - 6 : pas de conversion `int` vers `int*`
2. Paramètres 
   - $P_{1} = \left\\{1, 4, 5\right\\}$ par type exact
   - $P_{2} = \left\\{1\right\\}$ par type exact
     - 4 et 5 par promotion `char` vers `int` 
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$
4. **la fct no 1 est appelée**

--------------------

</details>

~~~cpp
// no 14
fct(pc, pd);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2\right\\}$ sont appelables.
   - 3 : types différents déduits pour `T` (`char*` et `double*`)
   - 4 : pas de conversion `double*` vers `int`
   - 5 : pas de conversion `char*` vers `int` ni `double*` vers `int`
   - 6 : pas de conversion `char*` vers `int*` ni `double*` vers `float`
2. Paramètres
   - $P_{1} = \left\\{1, 2\right\\}$ par type exact
   - $P_{2} = \left\\{1, 2\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$
4. fct no 2 : plus spécialisée que la 1 => **la fct no 2 est appelée**

--------------------

</details>

~~~cpp
// no 15
fct(d, d);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4, 5\right\\}$ sont appelables. 
   - 2 : pas de déduction pour `T* = double`
   - 6 : pas de conversion `double` vers `int*` 
2. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
     - 5 par conversion `double` vers `int`
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 et 5 par conversion `double` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. fct no 3 : plus spécialisée que la 1 => **la fct no 3 est appelée**

--------------------

</details>

~~~cpp
// no 16
fct(s+1, i);
~~~

<details>
<summary>Solution</summary>

Pour l'expression `s+1`, le `short` est promu en `int` pour l'opération.<br>
Au final, nous avons un appel `f(int, int)`.
Cas simplifié: il existe une fonction ordinaire avec exactement les bons types pour tous les paramètres (n°5); c'est elle qui est appelée.

--------------------

</details>

~~~cpp
// no 17
fct(s+d, d);
~~~

<details>
<summary>Solution</summary>

Pour l'expression `s+d`, le `short` est converti en `double` pour l'opération.<br>
Au final, nous avons `f(double, double)`

1. $S = \left\\{1, 3, 4, 5 \right\\}$ sont appelables. 
   - 2 : pas de déduction pour `T* = double`
   - 6 : pas de conversion `double` vers `int*`
3. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
     - 5 par conversion `double` vers `int`
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 et 5 par conversion `double` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. fct no 3 : plus spécialisée que la 1 => **la fct no 3 est appelée**

--------------------

</details>

~~~cpp
// no 18
fct<>(i, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4\right\\}$ sont appelables. 
   - 2 : pas de déduction pour `T* = int`
   - 5 et 6 : fonctions non génériques pas appelables par `fct<>`
2. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
   - $P_{2} = \left\\{1, 3, 4\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{1, 3, 4\right\\}$
4. **Ambiguité** entre 3 et 4, qui ne sont pas plus spécialisées l'une que l'autre
--------------------

</details>

~~~cpp
// no 19
fct<>(c, c);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4\right\\}$ sont appelables. 
   - 2 : pas de déduction pour `T* = char`
   - 5 et 6 : fonctions non génériques
2. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par type exact
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 par promotion `char` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. fct no 3 : plus spécialisée que la 1 => **la fct no 3 est appelée**

--------------------

</details>

~~~cpp
// no 20
fct<int>(d, d);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4\right\\}$ sont appelables.
   - 1 : la fonction est `fct(int,double)`
   - 2 : pas de conversion `double` vers `int*`
   - 3 : la fonction est `fct(int,int)`
   - 4 : la fonction est `fct(int,int)`
2. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par conversion `double` vers `int`
   - $P_{2} = \left\\{1\right\\}$ par type exact
     	- 3 ou 4 par conversion  `double` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$
4. **la fct no 1 est appelée**

--------------------

</details>

~~~cpp
// no 21
fct<char>(d, c);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 3, 4\right\\}$ sont appelables. 
   - 1 : `T=char` spécifié, `U=char` déduit : `f(char, char)`
   - 2 : pas de conversion `double` vers `char*`
   - 3 : fonction: `f(char, char)`
   - 4 : fonction: `f(char, int)`
2. Paramètres
   - $P_{1} = \left\\{1, 3, 4\right\\}$ par conversion `double` vers `char`
   - $P_{2} = \left\\{1, 3\right\\}$ par type exact
     - 4 par promotion `char` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1, 3\right\\}$
4. 3 est plus spécialisée que 1, **la fct no 3 est appelée**

--------------------

</details>

