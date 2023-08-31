# Déclaration de variables

Pour chaque séquence d'instructions suivante, déterminez si elle est correcte ou pas : 
- Si oui, donnez la valeur de la variable au terme de la séquence.
- Sinon, expliquez pourquoi la séquence n'est pas correcte.

1. 
   ~~~cpp
    int n = 1;
    n = 1 – 2 * n;
    n = n + 1;
   ~~~

2.  
    ~~~cpp
    int n = 1;
    n = n + 1;
    int n = 1 – 2 * n;
    ~~~
3. 
    ~~~cpp
    int n = 1, p = 2;
    n = (n + 1) * (n - k);
    ~~~
4. 
    ~~~cpp
    int n, m = 0;
    n = 2 * n - 1;
    m = n + 1;
    ~~~
<details>
<summary>Solution</summary>

1. `n = 0`
2. Non ce n'est pas correcte. La variable `n` est déclarée deux fois.
3. Non ce n'est pas correcte. La variable `k` n'est psa déclarée.
4. Non ce n'est pas correcte. La variable `n` n'est pas initialisé (donc indéfini)

</details>