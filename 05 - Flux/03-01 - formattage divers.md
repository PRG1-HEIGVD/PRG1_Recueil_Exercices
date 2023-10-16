# Formattage cout, effet des fonctions de formatage

Quel sera le résultat de l'exécution de la fonction suivante :

~~~cpp
void test_formatage(){
    int num = -15;

    // 1
    std::cout << std::setfill(':') << std::setw(5) << std::left << num << "*\n";
    // 2
    std::cout << std::setfill(':') << std::setw(5) << std::right << num << "*\n";
    // 3
    std::cout << std::setfill(':') << std::setw(5) << std::internal << num << "*\n";

    // 4
    std::cout << std::setfill(':') << std::setw(5) << std::boolalpha << std::left << (num < 0) << "*\n";
    // 5
    std::cout << std::setfill(':') << std::setw(5) << std::boolalpha << std::left << (num > 0) << "*\n";

    // 6
    std::cout << std::setfill(':') << std::setw(5) << std::noboolalpha << std::left << (num < 0) << "*\n";
    // 7
    std::cout << std::setfill(':') << std::setw(5) << std::noboolalpha << std::left << (num > 0) << "*\n";
}
~~~

<details>
<summary>Solution</summary>

~~~
-15::*
::-15*
-::15*
true:*
false*
1::::*
0::::*
~~~



</details>