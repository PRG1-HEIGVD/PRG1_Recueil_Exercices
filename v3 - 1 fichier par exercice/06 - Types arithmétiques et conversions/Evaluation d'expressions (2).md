# Evaluations d'expressions (2)

Soient les déclarations suivantes :
~~~cpp
int i = 5, j = 11; 

double x1 = (double) j / i;
double x2 = double(j / i);
double x3 = j / i + .5;
double x4 = (double) j / i + .5;
double x5 = (int)( j + .5) / i;
~~~

Que valent les variables x1 à x5 ? 

<details><summary>Solution</summary>

~~~cpp
x1 = 2.2;  // division réelle
x2 = 2.0;  // division entière
x3 = 2.5;
x4 = 2.7;  // division réelle
x5 = 2.0;  // division entière 
~~~

</details>