# Fonctions surchargées (2 paramètres)

Que produisent les appels aux fonctions ci-dessous ?<br>
Indiquer les cas d'ambiguité.

~~~cpp
void fct (      int,          float)  {cout << "Fonction no 1" << endl;}
void fct (      int,          double) {cout << "Fonction no 2" << endl;}
void fct (      float&,       int&)   {cout << "Fonction no 3" << endl;}
void fct (const float&, const int&)   {cout << "Fonction no 4" << endl;}

      int       i = 1;
      int&     ri = i;
      char      c = 'A';
      float     f = 2.f;
      double    d = 3.0;
const double& rdC = d;
~~~

**Méthode**<br>

1. établir la liste des fonctions appelables 
2. Parmi ces fonctions appelables, pour chacun des paramètres, établir celles qui sont appelables le plus simplement, i.e. 
	1. par type exact
	2. sinon par conversion simple (ajout d'un `const`) 
	3. sinon par promotion numérique
	4. sinon par conversion de type 
3. Faire l'intersection des ensembles sélectionnés par chaque paramètre
4. Si cet ensemble compte une seule fonction, elle est appelée. S'il en compte plusieurs ou aucune, il y a ambiguité

<br>

~~~cpp
// no 1
fct(i, c);	
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables. 
   - Pour 3, pas de conversion de `int` vers `float&` ni de `char` vers `int&`. 
2. Paramètres 
   - $P_{1} = \left\\{1, 2\right\\}$
     - `i` de type `int` 
     - 1 et 2 par type exact 
	 - 4 par conversion `int` vers `float`.
   - $P_{2} = \left\\{4\right\\}$ 
     - `c` de type `char`
     - 4 par promotion numérique
     - 1, 2 par conversion de type. 
3. $P_{1} \cap P_{2} = \emptyset$ 
4. **ambiguité**

</details>

~~~cpp
// no 2
fct(2.0, 1);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables.
	- Pour 3, pas de conversion de `const double` vers `float&` ni de `const int` vers `int&`.
2. Paramètres 
	- $P_{1} = \left\\{1, 2, 4\right\\}$
		- `2.0` de type `const double`
		- 1 et 2 par conversion `double` vers `int`.
		- 4 par conversion `double` vers `float`.
	- $P_{2} = \left\\{4\right\\}$
		- `1` de type `const int`
		- 4 par type exact
		- 1, 2 par conversion de type.
3. $P_{1} \cap P_{2} = \left\\{4\right\\}$ 
4. **Fonction no 4**

</details>

~~~cpp
// no 3
fct(i, f);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables
	- Pour 3, pas de conversion de `int` vers `float&` ni de `float` vers `int&`.
2. Paramètres 
	- $P_{1} = \left\\{1, 2\right\\}$
		- `i` de type `int`
		- 1 et 2 par type exact
		- 4 par conversion `int` vers `float`.
	- $P_{2} = \left\\{1\right\\}$
		- `1` de type `float`
		- 1 par type exact
		- 2 par promotion `float` vers `double`
        - 4 par conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$
4. **Fonction no 1**

</details>

~~~cpp
// no 4
fct(ri, f);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ sont appelables.
	- Pour 3, pas de conversion de `int&` vers `float&` ni de `float` vers `int&`.
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$
		- `i` de type `int&`
		- 1 et 2 par type exact et copie par valeur
		- 4 par conversion `int` vers `float`.
	- $P_{2} = \left\\{1\right\\}$
		- `1` de type `float`
		- 1 par type exact
		- 2 par promotion `float` vers `double`
		- 4 par conversion `float` vers `int`
3. $P_{1} \cap P_{2} = \left\\{1\right\\}$
4. **Fonction no 1**

</details>

~~~cpp
// no 5
fct(f, 1);
~~~

<details>
<summary>Solution</summary>


1. $S = \left\\{1, 2, 4\right\\}$ sont appelables.
	- Pour 3, pas de conversion de `const int` vers `int&`.
2. Paramètres
	- $P_{1} = \left\\{4\right\\}$
		- `i` de type `float&`
		- 4 par conversion simple `float&` vers `const float&`.
		- 1 et 2 par conversion de type `float` vers `int` 
	- $P_{2} = \left\\{4\right\\}$
		- `1` de type `const int`
		- 4 par type exact
		- 1 et 2 par conversion de type `const int` vers `float` et `double` resp.
3. $P_{1} \cap P_{2} = \left\\{4\right\\}$
4. **Fonction no 4**

</details>

~~~cpp
// no 6
fct(i, d);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$ 
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par type exact
    - $P_{2} = \left\\{2\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{2\right\\}$
4. **Fonction no 2**


</details>

~~~cpp
// no 7
fct(f, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 3, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{3\right\\}$ par type exact, 4 requiert une conversion simple -> `const`, 1 et 2 requièrent une conversion de type
	- $P_{2} = \left\\{3\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \left\\{3\right\\}$
4. **Fonction no 3**

</details>

~~~cpp
// no 8
fct(2.0, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2, 4\right\\}$ par conversion de type
	- $P_{2} = \left\\{4\right\\}$ par type conversion simple `int` vers `const int`
3. $P_{1} \cap P_{2} = \left\\{4\right\\}$
4. **Fonction no 4**

</details>

~~~cpp
// no 9
fct(2, c);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par type exact
	- $P_{2} = \left\\{4\right\\}$ par promotion numérique
3. $P_{1} \cap P_{2} = \emptyset$
4. **ambiguité**

</details>

~~~cpp
// no 10
fct(c, 2);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par promotion numérique
	- $P_{2} = \left\\{4\right\\}$ par type exact
3. $P_{1} \cap P_{2} = \emptyset$
4. **ambiguité**

</details>

~~~cpp
// no 11
fct(rdC, i);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2, 4\right\\}$ par conversion de type
	- $P_{2} = \left\\{4\right\\}$ par conversion simple `int` vers `const int`
3. $P_{1} \cap P_{2} = \left\\{4\right\\}$
4. **Fonction no 4**

</details>

~~~cpp
// no 12
fct(f, rdC);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$, 3 sans conversion de `const double&` vers `int&`
2. Paramètres
	- $P_{1} = \left\\{4\right\\}$ par conversion simple `float` vers `const float`
	- $P_{2} = \left\\{2\right\\}$ par type exact 
3. $P_{1} \cap P_{2} = \emptyset$
4. **ambiguité**

</details>

~~~cpp
// no 13
fct('a', rdC);
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par promotion numérique 
	- $P_{2} = \left\\{2\right\\}$ par type exact 
3. $P_{1} \cap P_{2} = \left\\{2\right\\}$
4. **Fonction no 2**

</details>

~~~cpp
// no 14
fct(2.0, 'a');
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2, 4\right\\}$ par conversion de type
	- $P_{2} = \left\\{4\right\\}$ par promotion numérique
3. $P_{1} \cap P_{2} = \left\\{4\right\\}$
4. **Fonction no 4**

</details>

~~~cpp
// no 15
fct('a', 2L);	
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par promotion numérique
	- $P_{2} = \left\\{1, 2, 4\right\\}$ par conversion 
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$
4.  **ambiguité**

</details>

~~~cpp
// no 16
fct('a', 2.0L);	
~~~

<details>
<summary>Solution</summary>

1. $S = \left\\{1, 2, 4\right\\}$
2. Paramètres
	- $P_{1} = \left\\{1, 2\right\\}$ par promotion numérique `char` -> `int`
	- $P_{2} = \left\\{1, 2, 4\right\\}$ par conversion `long double` vers ...
3. $P_{1} \cap P_{2} = \left\\{1, 2\right\\}$
4.  **ambiguité**

</details>