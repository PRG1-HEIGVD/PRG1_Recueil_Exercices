# Références

Coder en C++ les questions suivantes

**NB** : les instructions sont dépendantes les unes des autres

1) Créer une variable `var1` initialisée 1

<details>
<summary>Réponse</summary>

`int var1 = 1;`

</details>

2) Créer une référence `ref1` sur `var1`

<details>
<summary>Réponse</summary>

`int& ref1 = var1;`

</details>

3) Créer une référence `ref2` non initialisée

<details>
<summary>Réponse</summary>

Pas possible, une référence est toujours initialisée

</details>

4) Passer la valeur de `var1` à 2

<details>
<summary>Réponse</summary>

`var1 = 2;`

</details>

5) Passer la valeur de `ref1` à 3

<details>
<summary>Réponse</summary>

`ref1 = 3;`

</details>

6) Afficher la valeur de `var1`

<details>
<summary>Réponse</summary>

`cout << var1; // => 3`

</details>

7) Afficher la valeur de `ref1`

<details>
<summary>Réponse</summary>

`cout << ref1; // => 3` // au contraire des pointeurs, aucune syntaxe particulière

</details>

8) A quoi correspond la déclaration de `ref1`

<details>
<summary>Réponse</summary>

`int* const ref1 = &var1;`

</details>

9) A quoi correspond la déclaration d'une référence constante

<details>
<summary>Réponse</summary>

`const int* const refCste = &var1;`

</details>

