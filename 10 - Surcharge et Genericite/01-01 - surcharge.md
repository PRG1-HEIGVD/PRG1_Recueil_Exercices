# Fonctions surchargées

Les fonctions proposées peuvent-elles être surcharges et utilisées correctement ?

<br>

~~~cpp
// no 1
void f(int)      { /* no 1 */ }
void f(int, int) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, le nombre de paramètres est différent<br>

`f(1);    // appel no 1`<br>
`f(1, 2); // appel no 2`

-------------------------------------

</details>


~~~cpp
// no 2
void f(int)    { /* no 1 */ }
void f(double) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, le type des paramètres est différent

`f(1);   // appel no 1`<br>
`f(1.2); // appel no 2`

-------------------------------------

</details>

~~~cpp
// no 3
void f(int) { /* no 1 */ }
int  f(int) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**NON**, le type de retour est différent mais peut être ignoré<br>
exemple `sin(x);`<br>
=> Les fonctions ne peuvent pas être surchargées.

-------------------------------------

</details>

~~~cpp
// no 4
void f(int i=0) { /* no 1 */ }
void f(int    ) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**NON**, ces fonctions **ne sont pas** disctinctes.<br>
Si le paramètre effectif renseigne le paramètre formel avec valeur pas défaut, quelle fonction utiliser ?

=> mais le compilateur ne permet pas cette surcharge

-------------------------------------

</details>

~~~cpp
// no 5
void f(int&) { /* no 1 */ }
void f(int ) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, ces fonctions sont disctinctes mais **peuvent poser des problèmes** selon les paramètres utilisés.<br>

~~~cpp
const int CSTE = 2;
int i;

f(CSTE); // appel de la no 2
f(2);    // appel de la no 2
f(i);    // ambiguité
~~~

-------------------------------------

</details>

~~~cpp
// no 6
void f(const int&) { /* no 1 */ }
void f(int )       { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, ces fonctions sont disctinctes mais **ne peuvent pas être utilisées**.<br>

~~~cpp
const int CSTE = 2;
int i;
const int& r = i;

f(CSTE); // ambiguité
f(2);    // ambiguité
f(i);    // ambiguité
f(r);    // ambiguité
~~~

-------------------------------------

</details>

~~~cpp
// no 7
void f(int ) { /* no 1 */ }
void f(int*) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, ces fonctions sont disctinctes avec des types différents.<br>

~~~cpp
const int CSTE = 2;
int i;
int*       ptr1 = &i;
const int* ptr2 = &i;

f(CSTE); // appel de la no 1
f(2);    // appel de la no 1
f(i);    // appel de la no 1
f(&i);   // appel de la no 2
f(ptr1); // appel de la no 2
f(ptr2); // aucune fonction compatible
~~~

-------------------------------------

</details>

~~~cpp
// no 8
void f(const int*) { /* no 1 */ }
void f(      int*) { /* no 2 */ }
~~~

<details>
<summary>Solution</summary>

**OUI**, ces fonctions sont disctinctes avec des types différents<br>
... mais pas compatibles avec n'importe quel type.<br>

~~~cpp
const int CSTE = 2;
int    i;
double d;

f(&CSTE); // appel de la no 1
f(2);     // aucune fonction compatible
f(i);     // aucune fonction compatible
f(&i);    // appel de la no 2
f(&d);    // aucune fonction compatible
~~~

-------------------------------------

</details>
