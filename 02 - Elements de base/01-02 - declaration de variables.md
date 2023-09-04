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
 5. 
    ~~~cpp
    int n = 5, m = 0;
    const int nb_produit = 10;
    m = n * nb_produit - 1;    
    ~~~
 6. 
    ~~~cpp
    int n = 5, m = 0;
    const int nb_produit = 10;
    m = n * nb_produit--;    
    ~~~

<details>
<summary>Solution</summary>

1. `n = 0`
2. Non ce n'est pas correcte. La variable `n` est déclarée deux fois.
3. Non ce n'est pas correcte. La variable `k` n'est psa déclarée.
4. Non ce n'est pas correcte. La variable `n` n'est pas initialisé (donc indéfini)
5. `m = 49`
6. Non ce n'est pas correcte. La variable `nb_produit` est défini comme const et ne peux pas être modifiée `nb_produit--`.

</details>