# Messages
Implémenter une classe Message permettant de modéliser un message (email).
Un message se caractérise par un expéditeur, un destinataire, une date-heure de création ainsi qu'un contenu (le texte du message).
La classe doit mettre à disposition :
- un constructeur qui prend en paramètres l'expéditeur et le destinataire et qui fixe automatiquement la date-heure courante. 
Considérer qu'une fois celle-ci fixée, elle ne doit plus pouvoir être modifiée (champ avec attribut const).
- une fonction membre qui permet d'ajouter une ligne de texte au contenu du message
- une fonction membre toString qui convertit l'objet message en une unique chaîne de caractères comme suit "From : xxx\nTo : yyy\nDate : zzz\n…"
- une fonction membre qui permet d'afficher à l'écran le message.

__Note :__
- Résoudre le problème ci-dessus en exploitant la compilation séparée
- Pour la question de la date-heure de création et de sa mise en forme, consulter la librairie <ctime> et, en particulier, la fonction strftime.

Exemple de <ctime>
~~~cpp
std::time_t dateNow = time(NULL);
const string FORMAT = "%d.%m.%Y %X"; // Exemple : 24.11.2023 16:10:25
char buffer[256];
strftime(buffer, sizeof (buffer), FORMAT.c_str(), localtime(&dateNow)); // ex. buffer == "24.11.2023 16:10:25"
~~~


Le code ci-dessous doit s'exécuter correctement et affiche le résultat ci-après.

~~~cpp
#include <cstdlib>
#include "message.h"

using namespace std;

int main() {
   Message msg("Pierre Burki", "Alfred Strohmeier");
   msg.ajouter("Cher ami,");
   msg.ajouter("RDV demain a 9h.");
   msg.ajouter("Meilleures salutations.");

   msg.ajouter("\nPierre");
   msg.afficher(); // ou cout << msg.toString();
   return EXIT_SUCCESS;
}

~~~

~~~text
From : Pierre Burki       
To   : Alfred Strohmeier  
Date : 29.11.2023 09:43:25

Cher ami,
RDV demain a 9h.
Meilleures salutations.   

Pierre
~~~


<details>
<summary>message.h</summary>

~~~cpp
#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <string>
#include <vector>

using TexteMessage = std::vector<std::string>;

class Message {
public:

   // Constructeur
   Message(const std::string& expediteur, const std::string& destinataire);
      
   // Permet d'ajouter une ligne de texte au message
   void ajouter(const std::string& ligneTexte);
      
   // Convertit l'objet courant en chaîne de caractères
   std::string toString() const;

   // Affiche le contenu intégral de l'objet courant
   void afficher() const;
   
   // Les accesseurs viendraient s'insérer ici
   
private:
   const std::time_t dateCreation; // date-heure de création du message
   std::string expediteur;         // expéditeur du message 
   std::string destinataire;       // destinataire du message
   TexteMessage texteMessage;      // l'ensemble des lignes constituant le message
};

#endif

~~~



</details>

<details>
<summary>message.cpp</summary>

~~~cpp
#include <iostream>
#include "message.h"

using namespace std;

Message::Message(const string& expediteur, const string& destinataire)
: dateCreation(time(NULL)), expediteur(expediteur), destinataire(destinataire) {
}

void Message::ajouter(const string& ligneTexte) {
   texteMessage.push_back(ligneTexte);
}

string Message::toString() const {
   const string FORMAT = "%d.%m.%Y %X"; // Exemple : 24.07.2021 16:10:25
//    const string FORMAT = "%d.%m.%Y %H:%M"; // Exemple : 24.07.2021 16:10
   char buffer[256];
   strftime(buffer, sizeof (buffer), FORMAT.c_str(), localtime(&dateCreation));
   string str = "From : " + expediteur + '\n' +
                "To   : " + destinataire + '\n' +
                "Date : " + buffer + '\n';
   str += '\n';
   for (const string& s : texteMessage)
      str += s + '\n';
   return str;
}

void Message::afficher() const {
   cout << toString();
}

~~~



</details>


