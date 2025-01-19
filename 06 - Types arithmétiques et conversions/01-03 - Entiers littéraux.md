# Littéraux constants

Pour chacune des lignes de code suivantes, indiquez 
- si elle compile
- si oui
  - quel est le type de la variable
  - ce que la ligne affiche; 

On suppose que le compilateur utilise le modèle de donnée LLP64, i.e, avec `int` et `long` codés sur 32 bits et `long long` sur 64. 

~~~
  auto v1 = 12u;        cout << v1 << endl;
~~~
<details>
<summary>Solution</summary>

~~~cpp
unsigned int v1 = 12; 
~~~
</details>
  
~~~
  auto v2 = 1L;         cout << v2 << endl;
~~~
<details>
<summary>Solution</summary>

~~~cpp
long int v2 = 1;     
~~~
</details>

~~~  
  auto v3 = 100'000'000'000; cout << v3 << endl;
~~~
<details>
<summary>Solution</summary>

~~~cpp
long long v3 = 100'000'000'000;  
   // ou long en LP64, voir int dans un modèle de donnée plus
   // exotique. Dans tous les cas, le plus petit type entier capable 
   // de stocker la valeur 100000000000
~~~
</details>

~~~  
  auto v4 = 0x33;      cout << v4 << endl;
~~~
<details>
<summary>Solution</summary>

~~~cpp                            
int v4 = 51; // 33 en hexadécimal : 3 * 16 + 3 * 1
~~~
</details>

~~~  
  auto v5 = 0xefg;     cout << v5 << endl;
~~~
<details>
<summary>Solution</summary>
Ne compile pas. `g` n'est pas un chiffre hexadécimal
</details>

~~~  
  auto v6 = 0xef;      cout << v6 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
int v6 = 239; // ef en hexadécimal : 14 * 16 + 15
~~~
</details>

~~~  
  auto v7 = 0xEF;      cout << v7 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
int v7 = 239; // EF en hexadécimal : 14 * 16 + 15
~~~
</details>

~~~  
  auto v8 = 08;        cout << v8 << endl;
~~~

<details>
<summary>Solution</summary>
Ne compile pas. `8` n'est pas un chiffre octal
</details>

~~~  
  auto v9 = 027;       cout << v9 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
int v9= 23; // 027 en octal : 2*8+7 
~~~
</details>

~~~  
  auto v10 = 0xffull;       cout << v10 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
unsigned long long v10 = 255; // ff en hexadécimal : 15*16+15
~~~
</details>


~~~  
  auto v11 = 0xffffffff;       cout << v11 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
unsigned int v11 = 4294967295; // 2^32-1, valeur qui n'est pas représentable en signed int
~~~
</details>

~~~  
  auto v12 = 0x7fffffff;       cout << v12 << endl;
~~~

<details>
<summary>Solution</summary>

~~~cpp
int v12 = 2147483647; // 2^31-1, le plus grand int représentable
~~~
</details>

~~~
   auto v13 = 0b010101; cout << v13;
~~~
<details>
<summary>Solution</summary>

~~~cpp
int v13 = 21; // 010101 en binaire : 0*32 + 1*16 + 0*8 + 1*4 + 0*2 + 1*1
~~~
</details>

~~~
   auto v14 = 0b101ul; cout << v14;
~~~

<details>
<summary>Solution</summary>

~~~cpp
unsigned long v14 = 5; // 101 en binaire : 1*4 + 0*2 + 1*1
~~~
</details>