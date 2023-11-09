# Coordonnées GPS (exercice long)

Nous avons besoin de convertir des coordonnées GPS dans les deux notations typiquement utilisées (DD <=> DMS)

- **DD** (Decimal Degrees)
- **DMS** (degrees, minutes, seconds)

|Yverdon | Latitude          | Longitude         |
|-------:|-------------------|-------------------|
|    DD  | 46.7785711        | 6.6409158         |
|   DMS  | N 46° 46' 42.856" | E 6° 38' 27.296"  |

Après avoir déclaré les types de données (*struct* et *enum*) de la manière la plus flexible possible en économisant la mémoire, écrire de manière décomposée (autres sous-programmes) les deux fonctions de conversion.<br>
Prévoir également deux fonctions d'affichage.

Aide : [GPS coordinates converter](https://www.gps-coordinates.net/gps-coordinates-converter)

Le code ci-après produit le résultat présenté

~~~cpp
Coord_DMS Yverdon_DMS = {Dir_NS::N, 46, 46, 42.856,
                         Dir_EW::E, 6, 38, 27.296};

Coord_DD Yverdon_DD = {46.7785711,
                       6.6409158};

afficher_DMS(Yverdon_DMS);
cout << endl;

afficher_DD (Yverdon_DD);
cout << endl;

afficher_DMS(coord_DD_to_DMS(Yverdon_DD));
cout << endl;

afficher_DD(coord_DMS_to_DD(Yverdon_DMS));
cout << endl;
~~~

~~~
Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.296"

Latitude  : 46.778571
Longitude : 6.640916

Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.297"

Latitude  : 46.778571
Longitude : 6.640916
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//-----------------------------------------------------------------------------

// degree - decimal
using DD = double;

struct Coord_DD {
   DD latitude;
   DD longitude;
};

using Degree =  int8_t;
using Minute = uint8_t;
using Second = double;

struct DMS {
   Degree degree;
   Minute minute;
   Second second;
};

enum class Dir_NS {N, S};
enum class Dir_EW {E, W};

struct DMS_Latitude {
   Dir_NS direction;
   DMS    dms;
};

struct DMS_Longitude {
   Dir_EW direction;
   DMS    dms;
};

struct Coord_DMS {
   DMS_Latitude  latitude;
   DMS_Longitude longitude;
};

//-----------------------------------------------------------------------------
// param volontairement par valeur
DMS DD_to_DMS(DD dd) {
   dd            = abs(dd);
   Degree degree = static_cast<Degree>(dd);
   Minute minute = static_cast<Minute>((dd - degree) * 60);
   Second second = ((dd - degree) * 60 - minute) * 60;

   return DMS{degree, minute, second};
}

//-----------------------------------------------------------------------------
DD DMS_to_DD (const DMS& dms) {
   return dms.degree + (dms.minute / 60.0) + (dms.second / 3600.0);
}

//-----------------------------------------------------------------------------
Coord_DD coord_DMS_to_DD (const Coord_DMS& dms) {
   Degree latitude_sign  = dms.latitude.direction  == Dir_NS::N ? 1.0 : -1.0;
   Degree longitude_sign = dms.longitude.direction == Dir_EW::E ? 1.0 : -1.0;
   return Coord_DD {
      latitude_sign  * DMS_to_DD(dms.latitude.dms),
      longitude_sign * DMS_to_DD(dms.longitude.dms)
   };
}

//-----------------------------------------------------------------------------
Coord_DMS coord_DD_to_DMS (const Coord_DD& deg) {
   return Coord_DMS {
      { deg.latitude  > 0.0 ? Dir_NS::N : Dir_NS::S, DD_to_DMS(deg.latitude) },
      { deg.longitude > 0.0 ? Dir_EW::E : Dir_EW::W, DD_to_DMS(deg.longitude)},
   };
}

//-----------------------------------------------------------------------------
void afficher_DMS(const Coord_DMS& dms) {
   cout << fixed << setprecision(3);
   cout << "Latitude  : ";
   cout << (dms.latitude.direction == Dir_NS::N ? 'N' : 'S') << " ";
   cout << (int)dms.latitude.dms.degree << "°"
        << (int)dms.latitude.dms.minute << "'"
        <<      dms.latitude.dms.second << "\"" << endl;

   cout << "Longitude : ";
   cout << (dms.longitude.direction == Dir_EW::E ? 'E' : 'W') << " ";
   cout << (int)dms.longitude.dms.degree << "°"
        << (int)dms.longitude.dms.minute << "'"
        <<      dms.longitude.dms.second << "\"" << endl;
};

//-----------------------------------------------------------------------------
void afficher_DD(const Coord_DD& dd) {
   cout << fixed << setprecision(6);
   cout << "Latitude  : " << dd.latitude  << endl;
   cout << "Longitude : " << dd.longitude << endl;
}

//-----------------------------------------------------------------------------
int main() {

   Coord_DMS Yverdon_DMS = {Dir_NS::N, 46, 46, 42.856,
                            Dir_EW::E, 6, 38, 27.296};

   Coord_DD Yverdon_DD = {46.7785711,
                          6.6409158};

   afficher_DMS(Yverdon_DMS);
   cout << endl;

   afficher_DD (Yverdon_DD);
   cout << endl;

   afficher_DMS(coord_DD_to_DMS(Yverdon_DD));
   cout << endl;

   afficher_DD(coord_DMS_to_DD(Yverdon_DMS));
   cout << endl;

   return EXIT_SUCCESS;
}
~~~
</details>

