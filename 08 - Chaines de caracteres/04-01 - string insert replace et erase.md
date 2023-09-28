# Insert replace et erase

Indiquer ce que va afficher chacune des séquences d'instructions suivantes : 

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_


~~~cpp
// #1
string s1 = "ABC";
string s2 = "123";
s1.insert(1, s2); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>

|A123BC|
</details>

	
~~~cpp
// #2
string s1 = "ABC";
string s2 = "123";
s1.insert(4, s2); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>

Erreur à l'exécution (NB s1.insert(3, s2) serait OK)

</details>


~~~cpp
// #3
string s1 = "ABC";
string s2 = "123";
s1.insert(2, s2, 1, 2); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>

|AB23C|
</details>


~~~cpp
// #4
string s1 = "ABC";
string s2 = "123";
s1.insert(2, s2, 0, string::npos); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|AB123C|

</details>


~~~cpp
// #5
string s = "ABC";
s.insert(3, "123", 2); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|ABC12|

</details>


~~~cpp
// #6
string s = "ABC";
s.insert(1, 2, '3'); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|A33BC|

</details>

~~~cpp
// #7
string s1 = "ABCDEF";
string s2 = "123";
s1.replace(1, 2, s2); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|A123DEF|

</details>


~~~cpp
// #8
string s1 = "ABCDEF";
string s2 = "123";
s1.replace(2, 4, s2); 
cout << '|' << s1 << '|' << endl;
~~~ 

<details>
<summary>Solution</summary>
|AB123|

</details>

~~~cpp
// #9
string s1 = "ABCDEF";
string s2 = "123";
s1.replace(1, 2, s2, 1, 2); 
cout << '|' << s1 << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|A23DEF|

</details>

	
~~~cpp
// #10
string s = "ABCDEF";
s.replace(2, 3, "123", 2); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|AB12F|

</details>


~~~cpp
// #11
string s = "ABCDEF";
s.erase(); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>
||

</details>

	
~~~cpp
// #12
string s = "ABCDEF";
s.erase(2); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>

|AB|
</details>


~~~cpp
// #13
string s = "ABCDEF";
s.erase(2, 2); 
cout << '|' << s << '|' << endl;
~~~

<details>
<summary>Solution</summary>
|ABEF|

</details>


