# Opérateurs

Que va afficher le programme C++ suivant ?


~~~cpp
int i, j, k;

i = 0; k = i++;
cout << "A : i = " << i << " k = " << k << endl;

i = 1; k = ++i;
cout << "B : i = " << i << " k = " << k << endl;

i = 2; j = 3;
k = i++ * ++j;
cout << "C : i = " << i << " j = " << j << " k = " << k << endl;

i = 3; j = 4;
k = i *= --j;
cout << "D : i = " << i << " j = " << j << " k = " << k << endl;

~~~


<details>
<summary>Solution</summary>

- A : i = 1 k = 0
- B : i = 2 k = 2
- C : i = 3 j = 4 k = 8
- D : i = 9 j = 3 k = 9


</details>