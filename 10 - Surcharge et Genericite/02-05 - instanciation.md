# Instanciation

Soit la fonction générique `fct` suivante

~~~cpp
template <typename R, typename T, typename U>
R fct(const T& t, const U& u) {
   return R(t + u);
}
~~~

et les déclarations de variables 

~~~cpp
double d;
float  f;
int    i;
~~~

Indiquer si les instanciations, implicites ou explicites, sont correctes.<br>
Si correcte, préciser le type des arguments génériques R, T et U retenus.

<br>

~~~cpp
// no 1
template
int fct(const float& t, const double& u);
~~~

<details>
<summary>Solution</summary>

Correct

Instanciation explicite de la fonction `fct`.

- R : ne sera pas déductible, à passer lors de l'appel
- T : `float` par déduction
- U : `double` par déduction

exemple d'appel : `fct<int>(f, d);`

------------------------------------------------
</details>

~~~cpp
// no 2
template
int fct<>(const int& t, const double& u);
~~~

<details>
<summary>Solution</summary>

Correct

Instanciation explicite de la fonction `fct`.

- R : ne sera pas déductible, à passer lors de l'appel
- T : `int` par déduction
- U : `double` par déduction

exemple d'appel : `fct<int>(i, d);`

------------------------------------------------
</details>

~~~cpp
// no 3
fct(f, d);
~~~

<details>
<summary>Solution</summary>

Incorrect. R n'est pas déductible. 

------------------------------------------------
</details>

~~~cpp
// no 4
fct<>(d, i);
~~~

<details>
<summary>Solution</summary>

Incorrect. R n'est pas déductible. 

------------------------------------------------
</details>

~~~cpp
// no 5
fct<int>(i, d);
~~~

<details>
<summary>Solution</summary>

Correct

- R : `int` explicitement choisi par `<int>`
- T : `int` par déduction
- U : `double` par déduction

------------------------------------------------
</details>

~~~cpp
// no 6
fct<int, double>(i, d);
~~~

<details>
<summary>Solution</summary>

Correct

- R : `int` explicitement choisi par `<int>`
- T : `double` explicitement choisi par `<double>`
- U : `double` par déduction

------------------------------------------------
</details>
  