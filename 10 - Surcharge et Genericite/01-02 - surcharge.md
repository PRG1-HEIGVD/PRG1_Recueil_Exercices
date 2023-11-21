# fonctions surchargées

Soient les déclarations

~~~cpp
void fct (      int,        float ) {cout << "Fonction 1" << endl;}
void fct (      int,       double ) {cout << "Fonction 2" << endl;}
void fct (      float&,       int&) {cout << "Fonction 3" << endl;}
void fct (const float&, const int&) {cout << "Fonction 4" << endl;}

int    i =   1;
int&  ri =   i;
char   c = 'A';
float  f = 2.f;
double d = 3.0;
const double& rdC = d;
~~~

Indiquer par un « X » la fonction appelée, ambigu le cas échéant.

| Appel					| Ambigu | fct1 | fct2 | fct3 | fct4 |
|---						|---     |---   |---   |---   |---   |
| fct(i, c);			|        |      |      |      |      |
| fct(2.0, 1);		|        |      |      |      |      |
| fct(i, f);			|        |      |      |      |      |
| fct(ri, f);		|        |      |      |      |      |
| fct(f, 1);			|        |      |      |      |      |
| fct(i, d);			|        |      |      |      |      |
| fct(f, i);			|        |      |      |      |      |
| fct(2.0, i);		|        |      |      |      |      |
| fct(2, c);			|        |      |      |      |      |
| fct(c, 2);			|        |      |      |      |      |
| fct(rdC, i);		|        |      |      |      |      |
| fct(f, rdC);		|        |      |      |      |      |
| fct(‘a’ rdC);		|        |      |      |      |      |
| fct(2.0, ‘a’);	|        |      |      |      |      |
| fct(‘a’, 2L);		|        |      |      |      |      |
| fct(‘a’, 2.0L);	|        |      |      |      |      |

<details>
<summary>Solution</summary>

| Appel					| Ambigu | fct1 | fct2 | fct3 | fct4 |
|---						|---     |---   |---   |---   |---   |
| fct(i, c);			| {1,2,4}|      |      |      |      |
| fct(2.0, 1);		|        |      |      |      |  X   |
| fct(i, f);			|        |  X   |      |      |      |
| fct(ri, f);		|        |  X   |      |      |      |
| fct(f, 1);			|        |      |      |      |  X   |
| fct(i, d);			|        |      |  X   |      |      |
| fct(f, i);			|        |      |      |  X   |      |
| fct(2.0, i);		|        |      |      |      |  X   |
| fct(2, c);			| {1,2}  |      |      |      |      |
| fct(c, 2);			| {1,2,4}|      |      |      |      |
| fct(rdC, i);		|        |      |      |      |  X   |
| fct(f, rdC);		| {2,4}  |      |      |      |      |
| fct(‘a’ rdC);		|        |      | X    |      |      |
| fct(2.0, ‘a’);	|        |      |      |      |  X   |
| fct(‘a’, 2L);		| {1,2}  |      |      |      |      |
| fct(‘a’, 2.0L);	| {1,2}  |      |      |      |      |

</details>

