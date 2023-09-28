# if ... else -> switch
 
Réécrivez les extraits de code suivants en utilisant exclusivement la structure de contrôle `switch`. La variable `a` est de type `int`. 

~~~cpp 
if (a == 1) {
   cout << "A";
} else if (a == 4) {
   cout << "C"; 
} else if (a == 2) {
   cout << "E";
} else {
   cout << "BA";
}        
~~~

<details>
<summary>Solution</summary>

~~~cpp 
switch (a) {
   default : cout << "B"; 
   case 1 : cout << "A"; break;
   case 4 : cout << "C"; break;
   case 2 : cout << "E"; break;
}   
~~~

</details>

~~~cpp 
if (a < 0 or a >= 5) {
   cout << "D";
} else if (a < 3) {
   cout << "A";
} else {
   cout << "B";
}  
~~~

<details>
<summary>Solution</summary>

~~~cpp 
switch (a) {
   case 0:
   case 1:
   case 2: cout << "A"; break;
   case 3:
   case 4: cout << "B"; break;
   default: cout << "D"; break; 
}   
~~~
</details>