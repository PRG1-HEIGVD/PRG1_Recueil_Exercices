# Que produisent ces codes

<!-- ----------------------------- -->
1)

~~~cpp
void f1(int n) {
   cout << 'A' << n << ' ';
   if (n) {
      f1(n-1);
   }
}

f1(2);
~~~

<details>
<summary>Solution</summary>

~~~
A2 A1 A0
~~~
</details>

<!-- ----------------------------- -->
2)

~~~cpp
void f2(int n) {
   if (n) {
      f2(n-1);
   }
   cout << 'A' << n << ' ';
}

f2(2);
~~~

<details>
<summary>Solution</summary>

~~~
A0 A1 A2
~~~
</details>

<!-- ----------------------------- -->
3)

~~~cpp
void f3(int n) {
   cout << 'A' << n << ' ';
   if (n) {
      f3(n-1);
   }
   cout << 'B' << n << ' ';
}

f3(2);
~~~

<details>
<summary>Solution</summary>

~~~
A2 A1 A0 B0 B1 B2
~~~
</details>

<!-- ----------------------------- -->
4)

~~~cpp
void f4(int n) {
   if (n) {
      cout << n << ' ';
      f4(n-1);
      f4(n/2);
   }
}

f4(4);
~~~

<details>
<summary>Solution</summary>

~~~
4 3 2 1 1 1 2 1 1
~~~
</details>

<!-- ----------------------------- -->
5)

~~~cpp
void f5(int n) {
   if (n) {
      f5(n-1);
      if (n>1)
         f5(n-2);
      cout << n << ' ';
   }
}

f5(4);
~~~

<details>
<summary>Solution</summary>

~~~
1 2 1 3 1 2 4
~~~
</details>

<!-- ----------------------------- -->
6)

~~~cpp
int f6(int a, int b) {
   cout << '(' << a << ", " << b << ')';
   if (b == 0)
      return a;
   return f6(b, a%b);
}

f6(8, 5);
~~~

<details>
<summary>Solution</summary>

~~~
(8, 5)(5, 3)(3, 2)(2, 1)(1, 0)
~~~
</details>
