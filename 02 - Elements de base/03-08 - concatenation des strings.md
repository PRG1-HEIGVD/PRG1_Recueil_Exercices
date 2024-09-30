# Concaténation 

Indiquer la valeur de la variable `s` après chacune des séquences d'instructions suivantes : (si erreur, indiquez la)


1.
~~~cpp
string s = string("A") + "BC";
~~~

2.
~~~cpp
string s = string("AB") + 'C';
~~~

3.
~~~cpp
string s = "A" + "BC";
~~~

4.
~~~cpp
string s = "AB";
s += 'C';
~~~

5.
~~~cpp
string s = "AB";
string ss = s + 5;
~~~
    
6.
~~~cpp
string s = "PRG";
string s1 = "2023-01-01";
s += s1[4]; 
s += s1[6];
~~~

7.
~~~cpp
string s = "PRG";
s += to_string(1);
~~~

<details>
<summary>Solution</summary>

1. ABC
2. ABC
3. erreur
4. ABC
5. erreur
6. PRG-1
7. PRG1

</details>
