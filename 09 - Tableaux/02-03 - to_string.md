# vector to_string

Ecrire la fonction *to_string* permettant de traiter un *vector* d'entiers et de retourner sa représentation *string* au format [v1, v2, .., vn]

~~~cpp
const vector<int> v = {1, 2, 3, 4, 5, 6};
cout << to_string(v); // [1, 2, 3, 4, 5, 6]
~~~

<details>
<summary>Solution 1 : avec to_string(int)</summary>

~~~cpp
string to_string (const vector<int>& v) {
   string result = "[";
   for (size_t i = 0; i < v.size(); ++i) {
      if (i)
         result += ", ";
      result += to_string(v[i]);
   }
   return result += "]";
}
~~~
</details>

<details>
<summary>Solution 2 : avec stringstream</summary>

~~~cpp
string to_string (const vector<int>& v) {
   if (v.empty()) return "[]";
   stringstream out;
   out << '[' << v.front();
   for (size_t i = 1; i < v.size(); ++i)
      out << ", " << v[i];
   out << ']';
   return out.str();
}
~~~
</details>