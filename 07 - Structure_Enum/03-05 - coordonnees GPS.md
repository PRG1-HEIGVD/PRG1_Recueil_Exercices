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
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>

using namespace std;

//-----------------------------------------------------------------------------

// degree - decimal
using DD = double;

struct Coord_DD {
   DD latitude;
   DD longitude;
};

using Degree = uint8_t;
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
}; // Note: gros gaspillage de place (sizeof(Coord_DMS) = 48 bytes)
   // 8 octets sont suffisant pour une précision centimétrique sur le globe

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
   DD latitude_sign  = dms.latitude.direction  == Dir_NS::N ? 1.0 : -1.0;
   DD longitude_sign = dms.longitude.direction == Dir_EW::E ? 1.0 : -1.0;
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
void test(const string& nom,
          const Coord_DMS& dms,
          const Coord_DD& dd) {

   cout << "------------------" << endl;
   cout << nom << endl;
   cout << "------------------" << endl;

   afficher_DMS(dms);
   cout << endl;

   afficher_DD (dd);
   cout << endl;

   afficher_DMS(coord_DD_to_DMS(dd));
   cout << endl;

   afficher_DD(coord_DMS_to_DD(dms));
   cout << endl;

}

//-----------------------------------------------------------------------------
int main() {

   Coord_DMS Yverdon_DMS   = {{Dir_NS::N, {46, 46, 42.856}},
                              {Dir_EW::E, {6, 38, 27.296}}};
   Coord_DD Yverdon_DD     = {46.7785711, 6.6409158};


   Coord_DMS Montreal_DMS  = {{Dir_NS::N, {45, 30, 11.457}},
                              {Dir_EW::W, {73, 34, 11.303}}};
   Coord_DD Montreal_DD    = {45.5031824, -73.5698065};

   Coord_DMS Le_Cap_DMS    = {{Dir_NS::S, {33, 55, 44.371}},
                              {Dir_EW::E, {18, 25, 2.625}}};
   Coord_DD Le_Cap_DD      = {-33.928992, 18.417396};

   Coord_DMS Lima_DMS      = {{Dir_NS::S, {12,  3, 43.583}},
                              {Dir_EW::W, {77,  2, 11.492}}};
   Coord_DD Lima_DD        = {-12.0621065, -77.0365256};
   
   Coord_DMS Tokyo_DMS     = {{Dir_NS::N,  {35, 41, 22.0}},
                              {Dir_EW::E, {139, 41, 30.0}}};
                             
   Coord_DD Tokyo_DD       = {35.6894444, 139.6916667};

   test("Yverdon",   Yverdon_DMS,   Yverdon_DD);
   test("Montreal",  Montreal_DMS,  Montreal_DD);
   test("Le Cap",    Le_Cap_DMS,    Le_Cap_DD);
   test("Lima",      Lima_DMS,      Lima_DD);
   test("Tokyo",     Tokyo_DMS,     Tokyo_DD);
}
~~~

~~~
------------------
Yverdon
------------------
Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.296"

Latitude  : 46.778571
Longitude : 6.640916

Latitude  : N 46°46'42.856"
Longitude : E 6°38'27.297"

Latitude  : 46.778571
Longitude : 6.640916

------------------
Montreal
------------------
Latitude  : N 45°30'11.457"
Longitude : W 73°34'11.303"

Latitude  : 45.503182
Longitude : -73.569806

Latitude  : N 45°30'11.457"
Longitude : W 73°34'11.303"

Latitude  : 45.503183
Longitude : -73.569806

------------------
Le Cap
------------------
Latitude  : S 33°55'44.371"
Longitude : E 18°25'2.625"

Latitude  : -33.928992
Longitude : 18.417396

Latitude  : S 33°55'44.371"
Longitude : E 18°25'2.626"

Latitude  : -33.928992
Longitude : 18.417396

------------------
Lima
------------------
Latitude  : S 12°3'43.583"
Longitude : W 77°2'11.492"

Latitude  : -12.062107
Longitude : -77.036526

Latitude  : S 12°3'43.583"
Longitude : W 77°2'11.492"

Latitude  : -12.062106
Longitude : -77.036526

------------------
Tokyo
------------------
Latitude  : N 35°41'22.000"
Longitude : E 139°41'30.000"

Latitude  : 35.689444
Longitude : 139.691667

Latitude  : N 35°41'22.000"
Longitude : E 139°41'30.000"

Latitude  : 35.689444
Longitude : 139.691667

~~~
</details>

