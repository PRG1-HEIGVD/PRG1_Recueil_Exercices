# Tableaux et structures

Soient les déclarations

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

array carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
              Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
              Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
              Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

Personne* ptr_personne;
Personne& ref_personne = carnet.at(0);

ostream& operator<< (ostream& os, const Date& date) {
   return os << (int)date.jour << "." << (int)date.mois << "." << date.annee;
}
~~~

Ecrire les instructions demandées
<br>

1) En utilisant `ref_personne`, afficher la date de Jean

<details>
<summary>Solution</summary>

~~~cpp
cout << ref_personne.date;
~~~

----------------------------------------

</details>

2) En utilisant `ptr_personne`, afficher la date de Jean

<details>
<summary>Solution</summary>

~~~cpp
// ces 3 affectations sont identiques
ptr_personne = &carnet.at(0);
ptr_personne = &carnet[0];
ptr_personne = carnet.data();

cout << ptr_personne->date;
~~~

----------------------------------------

</details>

3) En utilisant `ref_personne`, remplacer l'année de la date de Jean par 1976

<details>
<summary>Solution</summary>

~~~cpp
ref_personne.date.annee = 1976;
~~~

----------------------------------------

</details>

4) En utilisant `ptr_personne`, remplacer l'année de la date de Jean par 1976

<details>
<summary>Solution</summary>

~~~cpp
ptr_personne->date.annee = 1976;
~~~

----------------------------------------

</details>

5) En utilisant `ref_personne`, afficher les initiales de Alain => "VA"

<details>
<summary>Solution</summary>

~~~cpp
// difficile, une référence ne peut pas être ré-affectée
cout << (&ref_personne + 1)->prenom[0] << (&ref_personne + 1)->nom[0] << endl;
~~~

----------------------------------------

</details>

6) En utilisant `ptr_personne`, afficher les initiales de Alain => "VA"

<details>
<summary>Solution</summary>

~~~cpp
// ces 4 affectations sont identiques
++ptr_personne;
ptr_personne = &carnet.at(1);
ptr_personne = &carnet[1];
ptr_personne = carnet.data() + 1;

cout << ptr_personne->prenom[0] << ptr_personne->nom[0] << endl;
~~~

----------------------------------------

</details>

7) Combien de bypes occupe un string dans le tableau

<details>
<summary>Solution</summary>

**Invariablement 8 bytes**.<br>
Un tableau contient des éléments de même taille,
alors qu'un string peut stocker un nombre différent de caractères.<br>
La partie `string.data` n'est pas dans le tableau, seule la structure du string s'y trouve

~~~cpp
// Pour s'en convaincre
carnet.at(0).nom = "Un nom plus long pour agrandir le str";


cout << "sizeof(Personne)     : " << sizeof(Personne)                   << endl;
cout << "sizeof(Personne) x 4 : " << sizeof(Personne) * 4               << endl;
cout << "sizeof(Carnet)       : " << sizeof(carnet)                     << endl;

cout << "carnet.data - debut  : " << carnet.data()                      << endl;
cout << "carnet.data - fin    : " << carnet.data() + carnet.size()      << endl;
cout << "jean.nom.data        : " << (void*)(carnet.at(0).nom.data())   << endl;

// sizeof(Personne)     : 56
// sizeof(Personne) x 4 : 224
// sizeof(Carnet)       : 224
// carnet.data - debut  : 0x16cf2f4d8
// carnet.data - fin    : 0x16cf2f5b8
// jean.nom.data        : 0x600002eec270
~~~

----------------------------------------

</details>
