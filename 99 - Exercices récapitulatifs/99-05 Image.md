# Image (tableau 2d)

On veut représenter une image avec un type `Image` qui est un alias
d'un vecteur de vecteurs de `PixelValue`, lui-même un alias du 
type `unsigned short`. 

La fonction `make_image` reçoit les dimensions (largeur, hauteur) 
d'une image à créer et la valeur commune de tous ses pixels en paramètres. 
Si cette dernière n'est pas spécifiée, elle prend la plus petite 
valeur possible pour un `Pixel_value`. 

La fonction `dilate` effectue une dilatation morphologique, une 
opération de traitement d'image qui consiste à remplacer chaque point
de l'image par le maximum d'un ensemble de points définis par un 
kernel, i.e. une liste de décalages par rapport au point considéré. 
Les décalages sont représentés par une structure `Pt` contenant deux entiers
signés `x` et `y`, tandis que le kernel est représenté par le type 
`Kernel`, un alias de type vecteur de `Pt`. 

Par exemple, si le noyau est `{Pt{-1,0}, Pt{1,2}}`, le point de coordonnées
`(x,y)` dans l'image retournée aura comme valeur le maximum des valeurs des points 
de coordonnées `(x-1,y)` et `(x+1,y+2)` dans l'image d'entrée. 

Définissez les différents types mentionnés ci-dessus et les fonctions 
`make_image` et `dilate`. Un exemple d'utilisation est disponible ci-dessous. 

~~~cpp
int main() {
   Pixel_value black = 0;
   Image image = make_image(1920,1080,black);

   for(size_t i = 0; i < 20; ++i)
      image[200 + i][300 - i] = 65535; // dessine une ligne oblique blanche
      
   Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
   Image dilated = dilate(image, kernel, black);
}
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <vector>

using namespace std;

using Pixel_value = unsigned short;
using Image = vector<vector<Pixel_value>>;

struct Pt {
   int x, y;
};

using Kernel = vector<Pt>;

Image make_image(size_t w, size_t h, Pixel_value v) {
   return Image(h,vector<Pixel_value>(w,v));
}

Image dilate(Image const& im,
             Kernel const& ker,
             Pixel_value default_value = numeric_limits<Pixel_value>::lowest()) {
   Image result(im);
   for(size_t y = 0; y < im.size(); ++y) {
      for(size_t x = 0; x < im[y].size(); ++x) {
         result[y][x] = numeric_limits<Pixel_value>::lowest();
         bool pas_de_voisin = true;
         for(size_t k = 0; k < ker.size(); ++k) {
            size_t nx = x + ker[k].x;
            size_t ny = y + ker[k].y;
            if( nx < im[y].size() and ny < im.size()) {
               result[y][x] = max(result[y][x], im[ny][nx]);
               pas_de_voisin = false;
            }
         }
         if (pas_de_voisin)
            result[y][x] = default_value;
      }
   }
   return result;
}


int main() {
   Pixel_value black = 0;
   Image image = make_image(1920,1080,black);

   for(size_t i = 0; i < 20; ++i)
      image[200 + i][300 - i] = 65535; // dessine une ligne oblique blanche

   Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
   Image dilated = dilate(image, kernel, black);
}
~~~
</details>

