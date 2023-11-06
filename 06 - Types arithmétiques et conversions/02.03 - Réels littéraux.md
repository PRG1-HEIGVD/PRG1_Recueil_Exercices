# Littéraux constants

Pour chacune des lignes de code suivante, indiquez 
- si elle compile
- si oui
  - quel est le type de la variable
  - ce que la ligne affiche; 
  
  ~~~
  auto v1 = 1.5;        cout << v1 << endl;
  
  auto v2 = 1E3;        cout << v2 << endl;

  auto v4 = 12.0u;      cout << v4 << endl;
  
  auto v6 = 1.0L;       cout << v6 << endl;
  
  auto v7 = .5;         cout << v7 << endl;
  
  auto v8 = 5.;         cout << v8 << endl;

  auto v14 = 0x0.2;     cout << v14 << endl;
  
  auto v17 = 0x1.p0;    cout << v17 << endl;
    
  auto v18 = 0x1.8p+0f; cout << v18 << endl;
    
  auto v19 = 0x1.p-2L;  cout << v19 << endl;
    
  auto v20 = 0x1.1p+2;  cout << v20 << endl; 
  ~~~

<details>
<summary>Solution</summary>

~~~cpp
double v1 = 1.5;            // 1.5

double v2 = 1E3;            // 1000

// auto v4 = 12.0u;         un réel ne peut être non signé

long double v6 = 1.0L;      // 1

double v7 = .5;             // 0.5

double v8 = 5.;             // 5

//  auto v14 = 0x0.2;         pas le bon format hexfloat

double v17 = 0x1.p0;        // 1

float v18 = 0x1.8p+0f;      // 1.5

long double v19 = 0x1.p-2L; // 0.25

double v20 = 0x1.1p+2;      // 4.25
~~~

</details>
