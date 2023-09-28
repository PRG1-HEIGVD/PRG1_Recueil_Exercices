# struct - définition
Indiquer si les définitions proposées sont correctes ou non

1.

~~~cpp
struct Date {
   int jour, mois, annee;
}
~~~

<details>
<summary> Solution </summary>
> **faux** : manque un `;` après `}`
</details>

2.

~~~cpp
struct Date {
   int jour;
   int mois;
   int annee;
};
~~~

<details>
<summary> Solution </summary>
correct : chaque type est spécifié 
</details>

3.

~~~cpp
struct Date {
   int jour, mois, annee;
};
~~~

<details>
<summary> Solution </summary>
correct : le type est commun à tous les membres
</details>

4.

~~~cpp
struct Date {
   int jour; mois; annee;
};
~~~

<details>
<summary> Solution </summary>
faux : les identifications sont séparés par des `;`
</details>

5.

~~~cpp
struct {
   int valeur;
} date;
~~~

<details>
<summary> Solution </summary>
correct : type *anonyme* et une variable `date`est créée
</details>

6.

~~~cpp
struct Vide {
} date;
~~~

<details>
<summary> Solution </summary>
faux : un `struct` doit avoir au moins un membre 
</details>

7.

~~~cpp
struct Struct {
   int  valeur;
   int* ptr = nullptr;
};
~~~

<details>
<summary> Solution </summary>
correct : le `ptr`est initialisé ce qui est une bonne chose
</details>

8.

~~~cpp
struct Struct {
   string text;
};
~~~

<details>
<summary> Solution </summary>
correct : un `struc` peut contenir un `string`
</details>

9.

~~~cpp
struct Details {
   int valeur;
};

struct Struct {
   char    car;
   Details details;
};
~~~

<details>
<summary> Solution </summary>
correct : un `struc` peut contenir un autre `struct`
</details>

10.

~~~cpp
struct const Struct {
   int  valeur;
};
~~~

<details>
<summary> Solution </summary>
faux : un `struc` n'est pas constant globalement
</details>

11.

~~~cpp
struct Struct {
   const char car 'A';
};
~~~

<details>
<summary>Solutions</summary>
correct : un membre d'un `struc` peut être constant
</details>
