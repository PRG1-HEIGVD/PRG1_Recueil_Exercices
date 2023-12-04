# Carnet d'adresses

Soit la déclaration et l'instruction

~~~cpp
array carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
              Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
              Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
              Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

cout << carnet << endl;
~~~

Ecrire le code nécessaire afin d'afficher le carnet d'adresse comme suit :

~~~
prenom : Jean
nom    : Veuxplus
date   : 7.4.1975

prenom : Alain
nom    : Verse
date   : 21.12.2018

prenom : Justin
nom    : Ptipeu
date   : 1.8.2023

prenom : Rémi
nom    : Fasol
date   : 17.5.1957
~~~

<details>
<summary>Solution</summary>

~~~cpp
struct Date {
   uint8_t  jour;
   uint8_t  mois;
   uint16_t annee;
};

struct Personne {
   string prenom;
   string nom;
   Date   date;
};

ostream& operator<< (ostream& os, const Date& d) {
   os << (int)d.jour << "." << (int)d.mois << "." << d.annee;
// os << +d.jour << "." << +d.mois << "." << d.annee;
   return os;
}

ostream& operator<< (ostream& os, const Personne& p) {
   os << "prenom : " << p.prenom  << endl;
   os << "nom    : " << p.nom     << endl;
   os << "date   : " << p.date    << endl;
   return os;
}

template <typename T, size_t taille>
ostream& operator<< (ostream& os, const array<T, taille> tab) {
   for(const T& t : tab)
      os << t << endl;
   return os;
}
~~~

-----------------------------------------------------

</details>
