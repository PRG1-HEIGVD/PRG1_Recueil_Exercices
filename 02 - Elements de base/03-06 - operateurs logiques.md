# Les opérateurs logiques

On suppose disposer de deux entiers x et y.
Ecrire la condition permettant de tester :

1.	que nos deux entiers valent 0
2.	qu'au moins l'un de nos deux entiers vaut 0
3.	qu'un seul de nos deux entiers vaut 0
3.	qu'au moins un de nos deux entiers ne vaut pas 0




    

<details>
<summary>Solution</summary>

1. `x == 0 && y == 0`
2. `x == 0 || y == 0`
3. `(x == 0 && y != 0) || (x != 0 && y == 0)`
4. `x != 0 || y != 0`   `!(x == 0 && y == 0)`


</details>
