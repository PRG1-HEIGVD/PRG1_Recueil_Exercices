# [ ], at, length, size, resize et substr

Indiquer ce que va afficher chacune des séquences d'instructions suivantes : 

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

1.	
~~~cpp
string s = "ABC";
cout << '|' << s[1] << '|' << endl;
~~~

2.	
~~~cpp
string s1 = "ABC";
string s2 = s1[1];
cout << '|' << s2 << '|' << endl;
~~~
3.	
~~~cpp
string s1 = "ABC";
string s2;
s2 = s1[1];
cout << '|' << s2 << '|' << endl;
~~~
4.	
~~~cpp
string s = "ABC";
cout << '|' << s[3] << '|' << endl;
~~~
5.	
~~~cpp
string s = "ABC";
cout << '|' << s[4] << '|' << endl;
~~~
6.	
~~~cpp
string s = "ABC";
cout << '|' << s.at(3) << '|' << endl;
~~~
7.	
~~~cpp
string s;
cout << s.length() << endl;
~~~
8.	
~~~cpp
string s = "ABC";
cout << s.length() << endl;
~~~
9.	
~~~cpp
string s = "ABC";
cout << s.size() << endl;
~~~
10.	
~~~cpp
string s = "ABC";
s.resize(5);
cout << '|' << s << '|' << endl;
~~~
11.	
~~~cpp
string s = "ABC";
s.resize(2, 'x');
cout << '|' << s << '|' << endl;
~~~
12.	
~~~cpp
string s = "ABC";
s.resize(4, 'x');
cout << '|' << s << '|' << endl;
~~~
13.	
~~~cpp
string s = "ABCDE";
cout << '|' << s.substr(1, 2) << '|' << endl;
~~~
14.	
~~~cpp
string s = "ABCDE";
cout << '|' << s.substr(0, 10) << '|' << endl;
~~~
15.	
~~~cpp
string s = "ABCDE";
cout << '|' << s.substr(3) << '|' << endl;
~~~
16.	
~~~cpp
string s = "ABCDE";
cout << '|' << s.substr() << '|' << endl;
~~~



<details>
<summary>Solution</summary>

1.	|B|
2.	Erreur à la compilation (pas de constructeur string(char))
3.	|B|
4.	|\0| 
5.	Comportement indéfini
6.	Erreur à l'exécution
7.	0
8.	3
9.	3
10.	|ABC\0\0|
11.	|AB|
12.	|ABCx|
13.	|BC|
14.	|ABCDE|
15.	|DE|
16.	|ABCDE|



</details>
