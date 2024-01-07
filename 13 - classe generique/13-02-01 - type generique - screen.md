# Type générique - screen

Déclarer un type de donnée permettant de définir un écran et sa résolution.

Un écran est composé de `width` x `height` `pixel`, chacun composé des trois couleurs `R` `G` `B`.<br>
Les couleurs peuvent être codées sur 8, 16 ou 32 bits. 

Sur la base de ces déclarations, déclarer les écrans suivants

| Screen   | Definition  | Depth   |
|----------|-------------|--------:|
| HD       | 1280 x 720  |  8 bits |
| Full HD  | 1920 x 1080 | 16 bits |
| UHD 4K   | 3840 x 2160 | 32 bits |
| UHD 8K   | 7680 x 4320 | 32 bits |

Ajouter le code afin d'afficher les détails d'un écran comme suit.

~~~cpp
HD      screen_HD;
cout << screen_HD; // (1280 x 720) / 8bits
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <array>
#include <cstdint>

using namespace std;

//------------------------------------------------------------
template <typename T>
struct Pixel {
   T R;
   T G;
   T B;
};

//------------------------------------------------------------
template <typename T, size_t width>
using Line = array<Pixel<T>, width>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
using Screen = array< Line<T, width>, height>;

//------------------------------------------------------------
using HD      = Screen<uint8_t,  1280,  720>;
using Full_HD = Screen<uint16_t, 1920, 1080>;
using UHD_4k  = Screen<uint32_t, 3840, 2160>;
using UHD_8k  = Screen<uint32_t, 7680, 4320>;

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
ostream& operator<< (ostream& os, const Screen<T, width, height>& s);

//------------------------------------------------------------
int main() {
   HD      screen_HD;
   Full_HD screen_Full_HD;
   UHD_4k  screen_UHD_4k;
   UHD_8k  screen_UHD_8k;

   cout << screen_HD << endl;
}

//------------------------------------------------------------
template <typename T, size_t width, size_t height>
ostream& operator<< (ostream& os, const Screen<T, width, height>& s) {
   if(s.empty()) return os;
   os << "(" << s[0].size() << " x " << s.size() << ") / "
      << sizeof(T) * 8 << "bits";
   return os;
}
~~~

</details>

Combien de mémoire faut-il pour ces structures ?

<details>
<summary>Solution</summary>

| Screen  | Definition  | Colors | Depth | Bits          | Bytes       | MB    |
|---------|-------------|:------:|:-----:|--------------:|------------:|------:|
| HD      | 1280 x 720  |   3    |   8   |    22,118,400 |   2,764,800 |   2.8 |
| Full HD | 1920 x 1080 |   3    |  16   |    99,532,800 |  12,441,600 |  12.4 |
| UHD 4K  | 3840 x 2160 |   3    |  32   |   796,262,400 |  99,532,800 |  99.5 |
| UHD 8K  | 7680 x 4320 |   3    |  32   | 3,185,049,600 | 398,131,200 | 398.1 |
</details>
