# Instanciation

Soit la fonction générique fct suivante

~~~cpp
template <typename R, typename T, typename U>
R fct(const T& t, const U& u) {
   return R(t + u);
}
~~~

et les déclarations de variables suivantes 

~~~cpp
double d;
float f;
int i;
~~~

Indiquer si les instanciations, implicites ou explicites, sont correctes.<br>
Si c’est le cas, préciser le type des arguments génériques R, T et U retenus.

<br>

~~~cpp
// no 1
template
int fct(const float& t, const double& u);
~~~

<details>
<summary>Solution</summary>

Correct

- R : `int`
- T : `float`
- U : `double`

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

- R : `int`
- T : `int `
- U : `double`

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

- R : `int`
- T : `int`
- U : `double`

------------------------------------------------
</details>

~~~cpp
// no 6
fct<int, double>(i, d);
~~~

<details>
<summary>Solution</summary>

Correct

- R : `int`
- T : `double`
- U : `double`

------------------------------------------------
</details>
  