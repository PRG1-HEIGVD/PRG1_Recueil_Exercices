# Passage par valeur vs par référence
Le programme ci-dessous contient plusieurs erreurs.
1) Pour chaque ligne fautive, indiquez son numéro et précisez la nature de l'erreur
2) En admettant maintenant que les lignes fautives ont été supprimées du programme ci- dessous, déterminer "à la main" ce qu'il va afficher à l'exécution ?

~~~cpp
1  #include <cstdlib>
2  #include <iostream>

3  using namespace std;
4
5  void f(double x);
6  void g(double& x);
7  void h(const double& x); 
9  int main() {
10
11    const int C = 1;
12    int n = C;
13    double x = C;
14   
15    f(C);
16    f(n);
17    f(x);
18    g(C);
19    g(n);
20    g(x);
21    h(C);
22    h(n);
23    h(x);
24   
25    return EXIT_SUCCESS;
26 }
27   
28 void f(double x) {
29    x = x + 1;
30    cout << "x = " << x <<endl;
31 }
32 
33 void g(double& x) {
34    x = x + 1;
35    cout << "x = "<< x <<endl;
36 }
37 
38 void h(const double& x) {
39    x = x + 1;
40    cout << "x = " << x <<endl;
41 }
~~~

<details>
<summary>Solution</summary>

1) Erreurs
- Ligne 18 : Le paramètre effectif de g ne peut être qu'une variable
- Ligne 19 : Le paramètre effectif de g doit être du même type que le paramètre formel
(pas de conversion implicite possible dans ce cas !)
- Ligne 39 : Le mot clé const précise que le paramètre ne peut pas être modifié dans le corps de la fonction

2) Après corrections

- x=2
- x=2
- x=2
- x=2
- x=1
- x=1
- x=2 (2 car le paramètre effectif x a été préalablement modifié lors de l'appel g(x))
</details>
