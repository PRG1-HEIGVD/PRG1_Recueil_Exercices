# Comparer des chaines de caracatères

Soient les déclarations suivantes :

~~~cpp
string s1 = "prg1";
string s2 = "prg2";
string s3 = "pdl";
string s4 = "prg";
string s5 = "pdg23";
string s6 = "Prg1";
~~~

Quel est le résultat d'évaluation des expressions suivantes ? Expliquez votre réponse.

Pour rappel, `' ' < '0' < '9' < 'A' < 'Z' < 'a' < 'z'`

| # | Expréssion | Résultat (true/false) | Explication |
|---| ---------- | --------------------- | ----------- |
| 1 | `s1 < s2` | | |
| 2 | `s1 > s3`  | | |
| 3 | `s1 < s4`  | | |
| 4 | `s3 > s5` | | |
| 5 | `s1 > s6` | | |



    

<details>
<summary>Solution</summary>

| # | Expréssion | Résultat (true/false) | Explication |
|---| ---------- | --------------------- | ----------- |
| 1 | `s1 < s2` | true | premier caractère différent '1' < '2' |
| 2 | `s1 > s3`  | true | premier caractère différent 'r' > 'd' |
| 3 | `s1 < s4`  | false | on atteint la fin de s4 sans trouver de caractères différents et s4 est plus courte que s1 |
| 4 | `s3 > s5` | true | premier caractère différent 'l' > 'g' |
| 5 | `s1 > s6` | true | premier caractère différent 'p' > 'P' |


</details>