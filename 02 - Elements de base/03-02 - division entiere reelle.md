# Division entière et réelle

Soient les déclarations suivantes :

~~~cpp
int i = 5, j = 11;
double x = 5, y = 11;

double m = 0;
~~~

Que vaut la variable m dans chacun des cas ci-dessous ?

| # | Expréssion           |  m  |
|---| ---------------------|-----|
| 1 | `m = j / i;`         |     |
| 2 | `m = y / x;`         |     |
| 3 | `m = j / i + 1.0;`   |     |
| 4 | `m = y / x + 1;`     |     |
| 5 | `m = y / x + j / i;` |     |
| 6 | `m = i + y / x;`     |     |
| 7 | `m = x + j / i;`     |     |


    

<details>
<summary>Solution</summary>

| # | Expréssion           |  m  |
|---| ---------------------|-----|
| 1 | `m = j / i;`         | 2.0 |
| 2 | `m = y / x;`         | 2.2 |
| 3 | `m = j / i + 1.0;`   | 3.0 |
| 4 | `m = y / x + 1;`     | 3.2 |
| 5 | `m = y / x + j / i;` | 4.2 |
| 6 | `m = i + y / x;`     | 7.2 |
| 7 | `m = x + j / i;`     | 7.0 |


</details>
