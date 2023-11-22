# fonctions surchargées (2 paramètres)

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

1. établir la liste des fonctions possibles pour chacun des paramètres
	1. par type exact
	2. sinon par promotion
	3. sinon par conversion
2. choisir la fonction correspondante à la seule intersection
3. s'il en reste plusieurs, il y a ambiguité

<br>

~~~cpp
fct(i, c);	
~~~

<details>
<summary>Solution</summary>

- `int`   {1, 2, 4} : 4 par conversion
- `char` 	{1, 2, 4} : 1 et 2 par promotion, 4 par conversion
- intersection {1, 2, 4} => **ambiguité**

</details>

~~~cpp
fct(2.0, 1);
~~~

<details>
<summary>Solution</summary>

- `const double` {1, 2, 4} : tous par conversion
- `const int`    {      4} : type exact
- intersection {4} => **Fonction no 4**

</details>

~~~cpp
fct(i, f);
~~~

<details>
<summary>Solution</summary>

- `int`   {1, 2, 4} : 4 par conversion
- `float` {1      } : type exact
- intersection {1} => **Fonction no 1**

</details>

~~~cpp
fct(ri, f);	
~~~

<details>
<summary>Solution</summary>

- `int&` 	{1, 2} : par copie
- `float` {1   } : type exact
- intersection {1} => **Fonction no 1**

</details>

~~~cpp
fct(f, 1);
~~~

<details>
<summary>Solution</summary>

- `float`     {3, 4} : type exact
- `const int` {   4} : type exact
- intersection {4} => **Fonction no 4**

</details>

~~~cpp
fct(i, d);
~~~

<details>
<summary>Solution</summary>

- `int`    {1, 2, 4} : 4 par conversion
- `double` {   2   } : type exact
- intersection {2} => **Fonction no 2**

</details>

~~~cpp
fct(f, i);
~~~

<details>
<summary>Solution</summary>

- `float` {3   } : type exact
- `int`   {3, 4} : type exact
- intersection {3} => **Fonction no 3**

</details>

~~~cpp
fct(2.0, i);
~~~

<details>
<summary>Solution</summary>

- `const double` {1, 2,    4} : tous par conversion
- `int`          {      3, 4} : type exact
- intersection {4} => **Fonction no 4**

</details>

~~~cpp
fct(2, c);
~~~

<details>
<summary>Solution</summary>

- `const int` {1, 2, 4} : 1 et 2 type exact, 4 par conversion
- `char`      {1, 2, 4} : 1 et 2 promotion, 4 par conversion
- intersection {1, 2, 4} => **ambiguité**

</details>

~~~cpp
fct(c, 2);
~~~

<details>
<summary>Solution</summary>

- `char`       {1, 2, 4} : 1 et 2 par promotion, 4 par conversion
- `const int`  {1, 2, 4} : 1 et 2 par conversion, 4 type exact
- intersection {1, 2, 4} => **ambiguité**

</details>

~~~cpp
fct(rdC, i);
~~~

<details>
<summary>Solution</summary>

- `const double&` {1, 2,    4} : tous par conversion
- `int`           {      3, 4} : type exact
- intersection {4} => **Fonction no 4**

</details>

~~~cpp
fct(f, rdC);
~~~

<details>
<summary>Solution</summary>

- `float`         {1, 2, 3, 4} : 1 et 2 par conversion, 3 et 4 type exact
- `const double&` {   2,    4} : tous par conversion
- intersection {2, 4} => **ambiguité**

</details>

~~~cpp
fct('a', rdC);
~~~

<details>
<summary>Solution</summary>

- `const char`    {1, 2,    4} : 4 par conversion
- `const double&` {   2      } : type exact
- intersection {2} => **Fonction no 2**

</details>

~~~cpp
fct(2.0, 'a');	
~~~

<details>
<summary>Solution</summary>

- `const double` {1, 2,    4} : tous par conversion
- `const char`   {         4} : 4 par promotion
- intersection {4} => **Fonction no 4**

</details>

~~~cpp
fct('a', 2L);	
~~~

<details>
<summary>Solution</summary>

- `const char`   {1, 2      } : 1, 2 par promotion
- `const long`   {1, 2,    4} : tous par conversion
- intersection {1, 2} => **ambiguité**

</details>

~~~cpp
fct('a', 2.0L);	
~~~

<details>
<summary>Solution</summary>

- `const char`        {1, 2      } : par promotion
- `const long double` {1, 2,    4} : tous par conversion
- intersection {1, 2} => **ambiguité**

</details>
