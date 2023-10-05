# Les opérateurs logiques

On suppose disposer de deux entiers x et y.
Ecrire la condition permettant de tester :

1.	que nos deux entiers valent 0
2.	qu'au moins l'un de nos deux entiers vaut 0
3.	qu'un seul de nos deux entiers vaut 0
4.	qu'au moins un de nos deux entiers ne vaut pas 0




    

<details>
<summary>Solution</summary>

1. `x == 0 && y == 0` ou `x == 0 and y == 0`
2. `x == 0 || y == 0` ou `x == 0 or y == 0`
3. `(x == 0) != (y == 0)` ou `(x == 0 && y != 0) || (x != 0 && y == 0)`. Notons que `(x == 0) xor (y == 0)` existe mais le `xor` n'est pas un opérateur booléen mais un opérateur bit à bit (vu en PRG2) et que la représentation binaire du type `bool` n'étant pas standardisée, son utilisation n'est pas correcte dans ce contexte
4. `x != 0 || y != 0` ou `!(x == 0 && y == 0)` en appliquant la loi de Morgan

</details>
