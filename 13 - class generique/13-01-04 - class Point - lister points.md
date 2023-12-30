# classe générique Point - déplacer 

Reprendre l'exercice précédant [13-01-03 - class Point - quadrant](13-01-03%20-%20class%20Point%20-%20quadrant.md)

Ajouter une fonction ordinaire `listerPoint<T>` qui liste l'ensemble des points.

~~~
p1(1, 2)
p2(4, 2)
p3(9, 8)
p4(-1, 5)
p5(3, -1)
p6(7, 0)
~~~

<details>
<summary>Solution - listerPoints</summary>

~~~cpp
template <typename T>
void listerPoints(const vector<Point<T>>& v) {
   for (const Point<T>& p : v) {
      p.afficher();
      cout << endl;
   }
}
~~~

</details>
