# Type generique - screen

Déclarer un type de donnée permettant de définir un écran et sa résolution.

Un écran est composé de `width` x `height` `pixel`, chacun composé des trois couleurs `R` `G` `B`.<br>
Les couleurs peuvent être codées sur 8, 16 ou 32 bits. 

Sur la base de ces déclarations, déclarer les écrans suivants

| Screen   | Definition  |
|----------|-------------|
| HD       | 1280 x 720  |
| Full HD  | 1920 x 1080 |
| UHD 4K   | 3840 x 2160 |
| UHD 8K   | 7680 x 4320 |

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <vector>
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
template <typename T, int width>
using Line = std::array<Pixel<T>, width>;

//------------------------------------------------------------
template <typename T, int width, int height>
using Screen = std::array< Line<Pixel<T>, width>, height>;

//------------------------------------------------------------
int main() {
   Screen<::uint32_t, 1920, 1080> fullHD;
}
~~~

</details>
