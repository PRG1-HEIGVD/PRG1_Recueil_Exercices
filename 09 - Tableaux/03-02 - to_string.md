# to_string

Ecrire la fonction *to_string* permettant de traiter un *tableau* d'entiers et de retourner sa représentation *string* au format [v1, v2, .., vn].

Sans faire de surcharge, la fonction *to_string* doit pouvoir traiter les tableaux ci-dessous

~~~cpp
   int t[10]               = {1, 2, 3, 4, 5, 6};
   const array<int, 10> a  = {1, 2, 3, 4, 5, 6};
   vector<int> v           = {1, 2, 3, 4, 5, 6};
~~~

Que produisent ces appels

~~~cpp
   cout << to_string(t) << endl;
   cout << to_string(a) << endl;
   cout << to_string(v) << endl;
~~~


<details>
<summary>Solution</summary>

~~~cpp
string to_string (span<const int> v) {
   string result = "[";
   for (size_t i = 0; i < v.size(); ++i) {
      if (i)
         result += ", ";
      result += to_string(v[i]);
   }
   return result += "]";
}
~~~

~~~
[1, 2, 3, 4, 5, 6, 0, 0, 0, 0]
[1, 2, 3, 4, 5, 6, 0, 0, 0, 0]
[1, 2, 3, 4, 5, 6]
~~~

</details>

