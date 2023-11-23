# fonctions surchargées

Les fonctions proposées peuvent-elles être surcharges et utilisées correctement ?

<br>

~~~cpp
void f(int)      { // no 1 }
void f(int, int) { // no 2 }
~~~

<details>
<summary>Solution</summary>

**OUI**, le nombre de paramètres est différent<br>

`f(1);		// appel no 1`<br>
`f(1, 2);	// appel no 2`

</details>

~~~cpp
void f(int)    { // no 1 }
void f(double) { // no 2 }
~~~

<details>
<summary>Solution</summary>

**OUI**, le type des paramètres est différent

`f(1);		// appel no 1`<br>
`f(1.2);	// appel no 2`

</details>

~~~cpp
void f(int) { // no 1 }
int  f(int) { // no 2 }
~~~

<details>
<summary>Solution</summary>

**NON**, le type de retour est différent mais peut être ignoré<br>
exemple `sin(x);`<br>
=> Les fonctions ne peuvent pas être surchargées.

</details>

~~~cpp
void f(int i=0) { // no 1  }
void f(int    ) { // no 2  }
~~~

<details>
<summary>Solution</summary>

**NON**, ces fonctions **ne sont pas** disctinctes.<br>
Si le paramètre effectif renseigne le paramètre formel avec valeur par défaut, quelle fonction utiliser ?

=> mais le compilateur ne permet pas cette surcharge

</details>

~~~cpp
void f(int&) { // no 1  }
void f(int ) { // no 2  }
~~~

<details>
<summary>Solution</summary>

**OUI**, ces fonctions sont disctinctes mais **peuvent poser des problèmes** selon les paramètres utilisés.<br>

~~~cpp
const int CSTE = 2;
int i;

f(CSTE); // ne peut appeler que la no 2
f(2);    // ne peut appeler que la no 2
f(i);    // quelle fonction appeler => AMBIGUITE
~~~

</details>
