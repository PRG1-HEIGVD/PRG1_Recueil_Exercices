# Affichage d'un fichier .csv

Ecrivez les fichiers `display_csv.h` et `display_csv.cpp` qui déclarent et 
définissent la fonction `display_csv` qui affiche le contenu d'un fichier
.csv (comma separated values). Elle prend en paramètres 
- le nom du fichier à lire
- le caractère de séparation des colonnes
- la largeur des colonnes à afficher 

S'il est impossible d'ouvrir le fichier, signalez-le en levant une exception
de type `File_not_found`, type que vous déclarez vous-même. 

Exemple d'utilisation : le code suivant 

~~~cpp
#include "display_csv.h"
#include <iostream>

using namespace std;

int main() {
   try {
      display_csv("data.txt", ',', 10);
   } catch (File_not_found& e) {
      cerr << "File not found \n";
      exit(-1);
   }
}
~~~

avec `data.txt` qui contient 

~~~text
hello,world,x,y,z
1,2,,4,5
,b,c,,d
~~~

affiche 

~~~text
     hello     world         x         y         z
         1         2                   4         5
                   b         c                   d
~~~

<details>
<summary>Solution</summary>

### display_csv.h

~~~cpp
#ifndef DISPLAY_CSV_H
#define DISPLAY_CSV_H

#include <string_view>

class File_not_found { };

void display_csv(std::string_view filename, char separator, int col_size);

#endif
~~~

### display_csv.cpp

~~~cpp
#include "display_csv.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

void display_csv(string_view filename, char separator, int col_size) {
   ifstream file(filename);
   if (not file)
      throw File_not_found{};

   string line;
   while(getline(file,line)) {
      stringstream s(line);
      string element;
      while(getline(s,element,separator))
         cout << setw(col_size) << element;
      cout << endl;
   }
}
~~~
</details>

