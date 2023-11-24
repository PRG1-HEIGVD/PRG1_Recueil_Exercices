# Instanciation

Soit la fonction générique fct suivante

~~~cpp
template <typename R, typename T, typename U>
R fct(const T& t, const U& u) {
   return R(t + u);
}
~~~

Indiquer si les instanciations, implicites ou explicites, sont correctes.
Si c’est le cas, préciser le type des arguments génériques R, T et U retenu.

<br>

~~~cpp
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
fct(f, d);
~~~

<details>
<summary>Solution</summary>

Incorrect

- R : -
- T : -
- U : -

------------------------------------------------
</details>

~~~cpp
fct<>(d, i);
~~~

<details>
<summary>Solution</summary>

Incorrect

- R : -
- T : -
- U : -

------------------------------------------------
</details>

~~~cpp
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
