# Pointeurs et const

Soient les déclarations suivantes :

~~~cpp
int i = 5;
const int j = 10;

int* ptr_i = &i;
const int* ptr_j = &j;

const int* ptr_i_1 = &i;
int* const ptr_i_2 = &i;
~~~

- Indiquez si les instructions suivantes sont correctes ou pas (génère une erreur) ? 
- Expliquez votre réponse, 
- Quelle serait la valeur de i et j si l'instruction est exécutée.


| # | Instruction         | Correcte ? (oui/non) | Explication |  i  |  j  |
|---| ------------------- | -------------------- | ----------- | ---:| ---:|
| 1 | `*ptr_i = 15;`      |                      |             |     |     |
| 2 | `int *ptr_j_1 = &j;`|                      |             |     |     |
| 3 | `ptr_j = ptr_i;`    |                      |             |     |     |
| 4 | `*ptr_i_1 = 25;`    |                      |             |     |     |
| 5 | `*ptr_i_2 = 30;`    |                      |             |     |     |
| 6 | `ptr_i_1 = &j;`     |                      |             |     |     |
| 7 | `ptr_i_2 = &j;`     |                      |             |     |     |



    

<details>
<summary>Solution</summary>

| # | Instruction           | Correcte | Explication                                                                    |  i  |  j  |
|---| --------------------- | ---------| ------------------------------------------------------------------------------ | ---:| ---:|
| 1 | `*ptr_i = 15;`        |   oui    | `i` est modifiable                                                             |  15 |  10 |
| 2 | `int *ptr_j_1 = &j;`  |   non    | on ne peux pas initialiser un pointeur `int` avec un rvalue de type `const int`|     |     |
| 3 | `ptr_j = ptr_i;`      |   oui    | `ptr_j` est modifiable                                                         |   5 |  10 |
| 4 | `*ptr_i_1 = 25;`      |   non    | un pointeur vers une valeur constante                                          |     |     |
| 5 | `*ptr_i_2 = 30;`      |   oui    | const pointer vers non const lvalue                                            |  30 |  10 |
| 6 | `ptr_i_1 = &j;`       |   oui    | `ptr_i_1` est modifiable (non const)                                          |   5 |  10 |
| 7 | `ptr_i_2 = &j;`       |   non    | `ptr_i_2` est un pointeur constant et serait lié à une constante               |     |     |


</details>
