# Operateurs sur hh:mm 🕔

Soient la déclaration et le code suivant

~~~cpp
struct HeureMinute {
   int8_t heure;
   int8_t minute;
};

HeureMinute saisie(const string& msg) {
   HeureMinute hm;
   bool erreur;
   do {
      cout << msg;
      cin >> hm;
      erreur = cin.fail();
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (erreur);
   return hm;
}

HeureMinute hm1 = {12, 34};
HeureMinute hm2 = {21, 43};

cout << boolalpha;
cout << hm1 << " <  " << hm2 << "  : " << (hm1 <  hm2) << endl;
cout << hm1 << " >  " << hm2 << "  : " << (hm1 >  hm2) << endl;
cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;

cout << hm1 << " +  " << hm2 << "  : " << (hm1 +  hm2) << endl;
cout << hm1 << " +  " << 44  << "     : " << (hm1 +  44 ) << endl;
cout << 44  << "    +  " << hm1 << "  : " << (44  +  hm1) << endl;
cout << hm1 << " += "  << 2 << "      : " << (hm1+=2 )    << endl;

cout << "++" << hm1  << "\t\t: " << ++hm1 << endl;
cout << hm1  << "++" << "\t\t: " << hm1++ << endl;
cout << hm1 << endl;

cout << endl;
HeureMinute hm3 = saisie("heure [hh:mm]: ");
cout << "votre saisie : " << hm3 << endl;
~~~

Ecrire le code nécessaire afin que le code produise ceci.

~~~
12:34 <  21:43  : true
12:34 >  21:43  : false
12:34 <= 21:43  : true
12:34 >= 21:43  : false
12:34 == 21:43  : false
12:34 != 21:43  : true
12:34 +  21:43  : 34:17
12:34 +  44     : 13:18
44    +  12:34  : 13:18
12:34 += 2      : 12:36
++12:36         : 12:37
12:37++         : 12:37
12:38

heure [hh:mm]: 12 34
heure [hh:mm]: 12:34
votre saisie : 12:34

~~~

<details>
<summary>Solution</summary>

~~~cpp
bool operator< (const HeureMinute& lhs, const HeureMinute& rhs) {
   if (lhs.heure != rhs.heure)
      return lhs.heure < rhs.heure;
   return lhs.minute < rhs.minute;
}

bool operator> (const HeureMinute& lhs, const HeureMinute& rhs) {
   return rhs < lhs;
}

bool operator<= (const HeureMinute& lhs, const HeureMinute& rhs) {
   return !(rhs < lhs);
}

bool operator>= (const HeureMinute& lhs, const HeureMinute& rhs) {
   return !(lhs < rhs);
}

bool operator== (const HeureMinute& lhs, const HeureMinute& rhs) {
   return lhs.heure   == rhs.heure
      and lhs.minute  == rhs.minute;
}

bool operator!= (const HeureMinute& lhs, const HeureMinute& rhs) {
   return !(lhs == rhs);
}

HeureMinute operator+ (const HeureMinute& lhs, const HeureMinute& rhs) {
   return { int8_t(lhs.heure + rhs.heure + (lhs.minute + rhs.minute) / 60),
            int8_t((lhs.minute + rhs.minute) % 60)};
}

HeureMinute& operator+= (HeureMinute& hm, int8_t minute) {
   hm = {int8_t(hm.heure + (hm.minute + minute) / 60),
          int8_t((hm.minute + minute) % 60)};
   return hm;
}

HeureMinute operator+ (HeureMinute hm, int8_t minute) {
   return hm += minute;
}

HeureMinute operator+ (int8_t minute, HeureMinute hm) {
   return hm += minute;
}

HeureMinute& operator++ (HeureMinute& hm) {
   return hm += 1;
}

HeureMinute operator++ (HeureMinute& hm, int) {
   HeureMinute tmp = hm;
   ++hm;
   return tmp;
}

ostream& operator<< (ostream& os, const HeureMinute& h) {
   return os << +h.heure << ":" << +h.minute;
}

istream& operator>> (istream& is, HeureMinute& h) {
   char c;
   int  valeur; // sinon lecture d'un char avec int8_t
   is >> valeur;
   h.heure = valeur;

   is >> c;
   if (c != ':') {
      is.setstate(ios::failbit);
   }

   is >> valeur;
   h.minute = valeur;

   if (h.minute >= 60) {
      cout << h.minute << endl;
      cout << "fail 60" << endl;
      is.setstate(ios::failbit);
   }

   return is;
}
~~~

------------------------------------------------------------

</details>

🤔 Pourrions-nous *simplifier* l'algorithme des opérateurs < et ==

<details>
<summary>Solution</summary>

En profitant de la comparaison lexicographique des structures comme 
*vector*, *array*, *pair*, etc ... 👍

Choisir toutefois la structure la plus économe en mémoire (compléxité spatiale).

~~~cpp
bool operator< (const HeureMinute& lhs, const HeureMinute& rhs) {
   return pair{lhs.heure, lhs.minute} < pair{rhs.heure, rhs.minute};
}

bool operator== (const HeureMinute& lhs, const HeureMinute& rhs) {
   return pair{lhs.heure, lhs.minute} == pair{rhs.heure, rhs.minute};
}
~~~

Nous verrons dans le chapitre consacré aux classes que l'on peut encore plus simplifier l'écriture des opérateurs de comparaison par l'utilisation de l'opérateur à 3 voies:

~~~cpp
struct HeureMinute {
   int8_t heure;
   int8_t minute;
   auto operator<=>(const HeureMinute& rhs) const = default;
};
~~~


</details>
