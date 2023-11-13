# assign, '+', '+=' et append

Indiquer ce que va afficher chacune des séquences d'instructions suivantes : 

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_




1.
~~~cpp
string s1 = "ABC";
string s2;
s2.assign(s1, 2, 3);
cout << '|' << s2 << '|' << endl;
~~~

2.
~~~cpp
string s1 = "ABC";
string s2;
s2.assign(s1, 3, 2);
cout << '|' << s2 << '|' << endl;
~~~

3.	
~~~cpp
string s;
s.assign("ABC", 2);
cout << '|' << s << '|' << endl;
~~~

4.	
~~~cpp
string s;
s.assign(2, 65);
cout << '|' << s << '|' << endl;
~~~

5.	
~~~cpp
string s;
s.assign(4, '\101');
cout << '|' << s << '|' << endl;
~~~

6.	
~~~cpp
string s;
s.assign(4, '\x42');
cout << '|' << s << '|' << endl;
~~~

7.	
~~~cpp
string s = string("A") + string("BC");
cout << '|' << s << '|' << endl;
~~~

8.	
~~~cpp
string s = string("A") + "BC";
cout << '|' << s << '|' << endl;
~~~

9.	
~~~cpp
string s = 'A' + string("BC");
cout << '|' << s << '|' << endl;
~~~

10.	
~~~cpp
string s = "A" + "BC";
cout << '|' << s << '|' << endl;
~~~

11.	
~~~cpp
string s = "AB";
s += 'C';
cout << '|' << s << '|' << endl;
~~~

12.	
~~~cpp
string s1 = "";
string s2 = "123";
s1.append(s2);
cout << '|' << s1 << '|' << endl;
~~~

13.	
~~~cpp
string s1 = "";
string s2 = "123";
s1.append(s2, 1, 3);
cout << '|' << s1 << '|' << endl;
~~~

14.	
~~~cpp
string s;
s.append("123", 2);
cout << '|' << s << '|' << endl;
~~~

15.	
~~~cpp
string s;
s.append(2, '2');
cout << '|' << s << '|' << endl;
~~~


<details>
<summary>Solution</summary>

1.	|C|
2.	||
3.	|AB|
4.	|AA|
5.	|AAAA|
6.	|BBBB|
7.	|ABC|
8.	|ABC|
9.	|ABC|
10.	Erreur à la compilation
11.	|ABC|
12.	|123|
13.	|23|
14.	|12|
15.	|22|


</details>
