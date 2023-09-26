# switch -> if ... else 
 
Réécrivez les extraits de code suivants en replaçant le `switch` par des instructions `if else`. Notez que 
la variable `a` est de type `int`. 

~~~cpp 
switch (a) {
    case 0 : cout << "A"; break;
    case 1 : cout << "Z"; break;
    case 2 : cout << "a"; break; 
    default : cout << "b"; break;
}
~~~

<textarea style="font-size: 15pt" cols="80" rows="10"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a == 0) {
   cout << "A";
} else if (a == 1) {
   cout << "Z";
} else if (a == 2) {
   cout << "a";
} else {
   cout << "b";
}          
~~~
</details>

~~~cpp 
switch (a) {
   case 0 : cout << "0"; 
   default : cout << "D"; break;
}
~~~

<textarea style="font-size: 15pt" cols="80" rows="5"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a == 0) {
   cout << "0";
}
cout << "D";    
~~~
</details>

~~~cpp 
switch (a) {
   case 0 : 
   case 1 : 
   case 2 : 
   case 3 : 
   case 4 : 
   case 5 : cout << "A"; break;
   case 6 : cout << "3"; 
   case 7 : cout << "4"; break; 
   default : cout << "D"; 
}
~~~

<textarea style="font-size: 15pt" cols="80" rows="10"> // Ecrivez votre réponse ici avant de lire la solution
</textarea>

<details>
<summary>Solution</summary>

~~~cpp 
if (a >= 0 and a <= 5) {
   cout << "A";
} else if (a == 6) {
   cout << "34";
} else if (a == 7) {
   cout << "4";
} else {
   cout << "D";
}             
~~~
</details>