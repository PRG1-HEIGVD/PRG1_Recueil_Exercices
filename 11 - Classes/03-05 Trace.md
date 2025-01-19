# Trace

Soient la classe suivante et les fonctions

~~~cpp
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t) {
      return os << t.id << t.data;
   }

public:
   Trace()                   : id(nextId++), data('a')  { cout << "C0(" << *this << ") "; }
   Trace(char data)          : id(nextId++), data(data) { cout << "Ci(" << *this << ") "; }
   Trace(const Trace& other) : id(nextId++)             { this->data = other.data;
                                                          cout << "CC("  << other << "->" << *this << ") "; }
   ~Trace()                                             { cout << "D("  << *this << ") "; }
   Trace& operator= (const Trace& other)                { this->data = other.data;
                                                          cout << "=C("  << other << "->" << *this << ") ";
                                                          return *this; }
private:
   static int  nextId;
          int  id;
          char data;
};

int Trace::nextId = 1;

Trace f1 (char i)         { cout << "f1 : "; return Trace(i); }
Trace f2 (Trace t)        { cout << "f2 : "; return t;        }
Trace f3 (const Trace& t) { cout << "f3 : "; return t;        }
~~~

Que produisent les déclarations ou instructions suivantes ?

<br>

~~~cpp
// no 1
Trace trace1a;
~~~

<details>
<summary>Solution</summary>

~~~
C0(1a)
~~~

------------------------------------------------------------

</details>

~~~cpp
// no 2
Trace trace1b('a');
~~~

<details>
<summary>Solution</summary>

~~~
Ci(2a)
~~~

------------------------------------------------------------

</details>

~~~cpp
// no 3
Trace trace1c(trace1a);
~~~

<details>
<summary>Solution</summary>

~~~
CC(1a->3a)
~~~

------------------------------------------------------------

</details>

~~~cpp
// no 4
Trace trace1d(Trace('b'));
~~~

<details>
<summary>Solution</summary>

~~~
Ci(4b)
~~~

------------------------------------------------------------

</details>

~~~cpp
// no 5
Trace trace1e(f1('c'));
~~~

<details>
<summary>Solution</summary>

~~~
f1 : Ci(5c)
~~~

**Note**

- `f1('c')` crée un objet `Trace` avec le caractère `c` en utilisant le constructeur `Trace(char data)`, affichant "Ci(5c)".
- L'objet `Trace` temporaire retourné par `f1('c')` est directement utilisé pour initialiser `trace1e` sans nécessiter de copie explicite grâce à l'optimisation du compilateur RVO (Return Value Optimization).

------------------------------------------------------------

</details>

~~~cpp
// no 6
Trace trace1f(f2(trace1a));
~~~

<details>
<summary>Solution</summary>

~~~
CC(1a->6a) f2 : CC(6a->7a) D(6a)
~~~

- passage de `trace1a` par valeur (copie) à `f2` => `CC(1a->6a))`
- utilisation du retour de `f2` pour contructruire `trace1f` => `CC(6a->7a)`
- fin de `f2` et destruction du paramètre => `D(6a)`

------------------------------------------------------------

</details>

~~~cpp
// no 7
Trace trace1g(f3(trace1a));
~~~

<details>
<summary>Solution</summary>

~~~
f3 : CC(1a->8a)
~~~

- le parmètre `trace1a` est directement utilisé pour construire `trace1g` => `CC(1a->8a)`

------------------------------------------------------------

</details>

~~~cpp
// no 8
vector<Trace> vect(3, Trace('b'));
~~~

<details>
<summary>Solution</summary>

~~~
Ci(9b) CC(9b->10b) CC(9b->11b) CC(9b->12b) D(9b)   3 / 3
~~~

- création de `Trace(2)` => `Ci(9b)`
- 3 copies dans le vecteur => `CC(9b->10b) CC(9b->11b) CC(9b->12b)`
- suppression de l'objet temporaire => `Ci(9b)`

Note

~~~
vect.size()     => 3
vect.capacity() => 3
~~~

GMB

------------------------------------------------------------

</details>

~~~cpp
// no 9
vect.push_back(trace1a);
~~~

<details>
<summary>Solution</summary>

~~~
CC(1a->13a) CC(12b->14b) CC(11b->15b) CC(10b->16b) D(12b) D(11b) D(10b)   4 / 6
~~~

- mise à jour de la capacité (3 => 6) et de la taille (3 => 4) du vecteur 
- construction par copie du nouvelle élément => `CC(1a->13a)`
- construction par copie des éléments dans le nouvel emplacement mémoire => `CC(12b->14b) CC(11b->15b) CC(10b->16b)`
- suppression des éléments dans l'ancien emplacement mémoire => `D(12b) D(11b) D(10b)`

------------------------------------------------------------

</details>

~~~cpp
// no 10
Trace trace2a('b');
trace2a = trace1a;
~~~

<details>
<summary>Solution</summary>

~~~
Ci(17b) =C(1a->17a)
~~~

- construction de `trace2a(2)` => `Ci(17b)`
- affectation dans `trace2a` => `=C(1a->17a)`

------------------------------------------------------------

</details>

~~~cpp
// no 11
trace2a = f1('c');
~~~

<details>
<summary>Solution</summary>

~~~
f1 : Ci(18c) =C(18c->17c) D(18c)
~~~

- appel de `f1` avec `3` comme paramètre
- construction dans la fonction de l'objet => `Ci(18c)`
- affectation dans `trace2a` du retour de `f1` => `=C(18c->17c)`
- desctruction de l'objet au terme de la fonction => `D(18c)`

------------------------------------------------------------

</details>

~~~cpp
// no 12
trace2a = f2(trace1a);
~~~

<details>
<summary>Solution</summary>

~~~
CC(1a->19a) f2 : CC(19a->20a) =C(20a->17a) D(20a) D(19a)
~~~

- appel de `f2` et passage par valeur (copie) de `trace1a` => `CC(1a->19a)`
- retour du paramètre `t` à `Trace` => `CC(19a->20a)`
- affectation dans `trace2a` => `=C(20a->17a)`
- suppression du paramètre et de l'objet utilisé pour le retour => `D(20a) D(19a)`

------------------------------------------------------------

</details>

~~~cpp
// no 13
trace2a = f3(trace1a);
~~~

<details>
<summary>Solution</summary>

~~~
f3 : CC(1a->21a) =C(21a->17a) D(21a)
~~~

- passage du paramètre par ref constante `const Trace& t`
- retour du paramètre `t` à `Trace` => `CC(1a->21a)`
- affectation dans `trace2a` => `=C(21a->17a)`
- suppression de l'objet utilisé pour le retour => `D(21a)`

------------------------------------------------------------

</details>

~~~cpp
// no 14
{
   Trace trace1b('a');
}
~~~

<details>
<summary>Solution</summary>

~~~
Ci(22a) D(22a)
~~~

- construction avec `trace1b(1)` => `Ci(22a)`
- sortie du bloc `{..}`, donc destruction de l'objet => `D(22a)`

------------------------------------------------------------

</details>

~~~cpp
// no 15
{
   vector<Trace> v(3);
}
~~~

<details>
<summary>Solution</summary>

~~~
C0(23a) C0(24a) C0(25a) D(25a) D(24a) D(23a)
~~~

- construction de 3 objets pour le vecteur => `C0(23a) C0(24a) C0(25a)`
- sortie du bloc `{..}`, donc destruction des 3 objets => `D(25a) D(24a) D(23a)`

------------------------------------------------------------

</details>

~~~cpp
// no 16
{
   vector<Trace> v(2, Trace('a'));
}
~~~

<details>
<summary>Solution</summary>

~~~
Ci(26a) CC(26a->27a) CC(26a->28a) D(26a) D(28a) D(27a)
~~~

- construction de 1 objet connu `Ci(26a)`
- ... copie de cet objets dans les éléments du vecteur => `CC(26a->27a) CC(26a->28a)`
- destruction de l'objet temporaire `D(26a)`
- sortie du bloc `{..}`, donc destruction des objets du vecteur => `D(28a) D(27a)`


------------------------------------------------------------

</details>

~~~cpp
// no 17
{
   vector<Trace> v(2, trace1a);
}
~~~

<details>
<summary>Solution</summary>

~~~
CC(1a->29a) CC(1a->30a) D(30a) D(29a)
~~~

- copie de `trace1a` dans les éléments du vecteur => `CC(1a->29a) CC(1a->30a)`
- sortie du bloc `{..}`, donc destruction des objets du vecteur => `D(30a) D(29a)`

------------------------------------------------------------

</details>

------------------------------------------------------------
<details>
<summary>code complet</summary>

~~~cpp
#include <iostream>
#include <vector>

using namespace std;

class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t) {
      return os << t.id << t.data;
   }

public:
   Trace()           : id(nextId++), data('a')     { cout << "C0(" << *this << ") ";   }
   Trace(char data)  : id(nextId++), data(data)    { cout << "Ci(" << *this << ") ";   }
   Trace(const Trace& other)     :id(nextId++)     { this->data = other.data;
                                                     cout << "CC("  << other << "->" << *this << ") "; }
   ~Trace()                                        { cout << "D(" << *this << ") ";   }
   Trace& operator=(const Trace& other)            { this->data = other.data;
                                                     cout << "=C("  << other << "->" << *this << ") ";
                                                     return *this; }
private:
   static int  nextId;
          int  id;
          char data;
};

int Trace::nextId = 1;

Trace f1(char i)         { cout << "f1 : "; return Trace(i); }
Trace f2(Trace t)        { cout << "f2 : "; return t;        }
Trace f3(const Trace& t) { cout << "f3 : "; return t;        }

int main() {

   // no 1
   cout << "no  1 : ";
   Trace trace1a;
   cout << endl;

   // no 2
   cout << "no  2 : ";
   Trace trace1b('a');
   cout << endl;

   // no 3
   cout << "no  3 : ";
   Trace trace1c(trace1a);
   cout << endl;

   // no 4
   cout << "no  4 : ";
   Trace trace1d(Trace('b'));
   cout << endl;

   // no 5
   cout << "no  5 : ";
   Trace trace1e(f1('c'));
   cout << endl;

   // no 6
   cout << "no  6 : ";
   Trace trace1f(f2(trace1a));
   cout << endl;

   // no 7
   cout << "no  7 : ";
   Trace trace1g(f3(trace1a));
   cout << endl;

   // no 8
   cout << "no  8 : ";
   vector<Trace> vect(3, Trace('b'));
   cout << "\t" << vect.size() << " / " << vect.capacity();
   cout << endl;

   // no 9
   cout << "no  9 : ";
   vect.push_back(trace1a);
   cout << "\t" << vect.size() << " / " << vect.capacity();
   cout << endl;

   // no 10
   cout << "no 10 : ";
   Trace trace2a('b');
   trace2a = trace1a;
   cout << endl;

   // no 11
   cout << "no 11 : ";
   trace2a = f1('c');
   cout << endl;

   // no 12
   cout << "no 12 : ";
   trace2a = f2(trace1a);
   cout << endl;

   // no 13
   cout << "no 13 : ";
   trace2a = f3(trace1a);
   cout << endl;

   // no 14
   cout << "no 14 : ";
   {
      Trace trace1b('a');
   }
   cout << endl;

   // no 15
   cout << "no 15 : ";
   {
      vector<Trace> v(3);
   }
   cout << endl;

   // no 16
   cout << "no 16 : ";
   {
      vector<Trace> v(2, Trace('a'));
   }
   cout << endl;

   // no 17
   cout << "no 17 : ";
   {
      vector<Trace> v(2, trace1a);
   }
   cout << endl;

   cout << endl;
   cout << "fin de programme" << endl;
}
~~~

~~~
no  1 : C0(1a) 
no  2 : Ci(2a) 
no  3 : CC(1a->3a) 
no  4 : Ci(4b) 
no  5 : f1 : Ci(5c) 
no  6 : CC(1a->6a) f2 : CC(6a->7a) D(6a) 
no  7 : f3 : CC(1a->8a) 
no  8 : Ci(9b) CC(9b->10b) CC(9b->11b) CC(9b->12b) D(9b) 	3 / 3
no  9 : CC(1a->13a) CC(12b->14b) CC(11b->15b) CC(10b->16b) D(12b) D(11b) D(10b) 	4 / 6
no 10 : Ci(17b) =C(1a->17a) 
no 11 : f1 : Ci(18c) =C(18c->17c) D(18c) 
no 12 : CC(1a->19a) f2 : CC(19a->20a) =C(20a->17a) D(20a) D(19a) 
no 13 : f3 : CC(1a->21a) =C(21a->17a) D(21a) 
no 14 : Ci(22a) D(22a) 
no 15 : C0(23a) C0(24a) C0(25a) D(25a) D(24a) D(23a) 
no 16 : Ci(26a) CC(26a->27a) CC(26a->28a) D(26a) D(28a) D(27a) 
no 17 : CC(1a->29a) CC(1a->30a) D(30a) D(29a) 

fin de programme
D(17a) D(13a) D(14b) D(15b) D(16b) D(8a) D(7a) D(5c) D(4b) D(3a) D(2a) D(1a) 
~~~

</details>

