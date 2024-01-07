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
template <typename T, int width>
using Line = std::array<Pixel<T>, width>;

//------------------------------------------------------------
template <typename T, int width, int height>
using Screen = std::array< Line<Pixel<T>, width>, height>;

//------------------------------------------------------------
int main() {
   Screen<::uint8_t,  1280,  720> HD;
   Screen<::uint16_t, 1920, 1080> FullHD;
   Screen<::uint32_t, 3840, 2160> UHD_4k;
   Screen<::uint32_t, 7680, 4320> UHD_8k;
}
~~~

</details>
