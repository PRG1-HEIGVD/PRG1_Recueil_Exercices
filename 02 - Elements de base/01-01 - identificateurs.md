# Identificateurs (noms des variables) en c++
Pour chacun des cas ci-dessous, indiquez s'il s'agit d'un identificateur C++ légal ou non. Justifiez votre réponse si celle-ci est "Non"

|  #  | Identificateur | Oui / Non | Explication | 
| --- | -------------- | --------- | ----------- |
| 1 | `007` | | |
| 2 | `james_bond_007`  | | |
| 3 | `james_bond__007`  | | |
| 4 | `james bond` | | |
| 5 | `sOs` | | |
| 6 | `SOS` | | |
| 7 | `_007` | | |
| 8 | `__007` | | |
| 9 | `_007_` | | |
| 10 | `bond-007` | | |
| 11 | `tom&jerry` | | |
| 12 | `int` | | |
| 13 | `INT` | | |
| 14 | `André` | | |
| 15 | `_` | | |



<details>
<summary>Solution</summary>

|  #  | Identificateur | Oui / Non | Explication | 
| --- | -------------- | --------- | ----------- |
|1 | `7` | Non | Un identificateur ne peut pas commencer par un chiffre |
|2 | `james_bond_007` | Oui |  |
|3 | `james_bond__007` | Oui | Plusieurs _ peuvent se suivre |
|4 | `james bond` | Non | Pas d'espace dans un identificateur |
|5 | `sOs` | Oui |  |
|6 | `SOS` | Oui | Vu que C++ tient compte de la casse, 5) est un identificateur différent de 6) |
|7 | `_007` | Oui | Un identificateur peut commencer par _ |
|8 | `__007` | Oui |  |
|9 | `_007_` | Oui |  |
|10 | `bond-007` | Non | Le caractère '-' n'est pas autorisé |
|11 | `tom&jerry` | Non | Le caractère '&' n'est pas autorisé |
|12 | `int` | Non | Mot réservé |
|13 | `INT` | Oui | Déconseillé toutefois ! |
|14 | `André` | Non | Les lettres accentuées ne sont pas autorisées |
|15 | `_` | Oui | … mais pas des plus parlants (!) |


</details>