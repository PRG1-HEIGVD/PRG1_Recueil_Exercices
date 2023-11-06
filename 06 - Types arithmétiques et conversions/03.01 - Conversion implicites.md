# Conversions implicites

Soient les déclarations suivantes :
~~~cpp
char c = 'A';
int n = 7;
int a = -2;
unsigned b = 1;
long p = 10;
float x = 1.25f;
double z = 5.5;

auto r1 = n + c + p;
auto r2 = 2 * x + c;
auto r3 = (char) n + c;
auto r4 = (float) z + n / 2;
auto r5 = a + b;
~~~

Pour chacune des variables `r1` à `r5`, indiquez :
- combien de conversions implicites sont mises en œuvre et lesquelles
- ce qu'elle vaut et quel est son type


<details><summary>Solution</summary>

Rappel Les promotions numériques : `bool → int`, `char → int` et `short → int`

~~~cpp
long r1 = 82; 

/* r1 = n + c + p
 * 
 * 2 conversions implicites : c est tout d'abord converti en int, 
 * avant d'être ajouté à n. Le résultat (72), de type int, est 
 * ensuite converti en long, avant d'être ajouté à p. Au final, 
 * on obtient la valeur 82 de type long.
 */

float r2 = 67.5;

/* r2 = 2*x + c
 * 
 * 3 conversions implicites : c (de type char) est tout d'abord 
 * converti en int (promotion numérique), ce qui donne 65. On 
 * évalue ensuite 2 * x en convertissant 2 (de type int) en float, 
 * ce qui donne 2.5 de type float. Pour effectuer l'addition, on
 * convertit la valeur entière 65 en float, avant de l'ajouter au 
 * résultat précédent (2.5).
*/

int r3 = 72;

/* r3 = (char)n + c
 * 
 * 2 conversions implicites : n est converti explicitement en char (cast)
 * c et (char)n sont tous les deux convertis implicitement en int 
 * (promotion numérique) avant d'etre additionnés.
 */

float r4 = 8.5;

/* r4 = (float) z + n / 2
 * 
 * 1 conversion implicite : z est tout d'abord converti en float
 * (cast), ce qui donne 5.5. La division entière n / 2 est ensuite 
 * effectuée; on obtient la valeur 3. Cette valeur (3) est ensuite 
 * convertie en float, avant d'être ajoutée à 5.5. 
*/

unsigned int r5 = numeric_limits<unsigned>::max(); // probablement 4'294'967'295

/* r5 = a + b;
 * 
 * 1 conversion implicite (de type ajustement de type) de int en unsigned int. 
 */
~~~

</details>
