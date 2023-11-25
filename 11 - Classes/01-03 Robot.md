# Robot
Implémenter une classe Robot permettant de modéliser un robot se déplaçant le long d'un axe horizontal gradué. Le robot se déplace soit vers la droite, soit vers la gauche. 

Initialement le robot se déplace vers la droite, mais il peut, en tout temps, faire demi-tour pour ensuite se déplacer dans la direction opposée.

La classe doit mettre à disposition :
- un constructeur permettant de définir la position initiale (de type int) du robot
<br> __Important__  Si l'utilisateur ne fournit pas de valeur pour la position initiale du robot, on considérera que cette dernière vaut 0.
- une fonction membre deplacer permettant au robot de se déplacer de n unités dans la direction courante
<br> __Important__  Si l'utilisateur ne fournit pas de valeur pour n, le robot se déplacera par défaut d'une unité. Si la valeur fournie est <= 0, le robot ne bougera pas.
- une fonction membre faireDemiTour permettant au robot de faire demi-tour
- une méthode getPosition  retournant la position courante du robot

Le programme suivant permet de vérifier le bon fonctionnement de la classe Robot

~~~cpp
int main() {
    Robot r1, r2(10);
    cout << "position courante de r2: " << r2.getPosition() << endl;
    r1.deplacer();
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(-1);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(2);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.faireDemiTour();
    r1.deplacer(4);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    return EXIT_SUCCESS;
}
~~~

Résultats :

~~~text
position courante de r2: 10
position courante de r1: 1
position courante de r1: 1
position courante de r1: 3
position courante de r1: -1
~~~


<details>
<summary>Solution</summary>

~~~cpp
#include <cstdlib>
#include <iostream>
using namespace std;

enum class Dir {GAUCHE = -1, DROITE = 1}; // +1 = vers la droite, -1 = vers la gauche

class Robot {
public:
    Robot(int positionInitiale = 0);
    void faireDemiTour();
    void deplacer(int nbUnites = 1);
    int getPosition() const;
private:
    Dir direction; 
    int position;  // la position courante du robot
};

Robot::Robot(int positionInitiale)
        : direction(Dir::DROITE), position(positionInitiale) {
}

void Robot::faireDemiTour() {
    direction == Dir::GAUCHE ? direction = Dir::DROITE : direction = Dir::GAUCHE;
}

void Robot::deplacer(int nbUnites) {
    if(nbUnites > 0)
        position += int(direction) * nbUnites;
}

int Robot::getPosition() const {
    return position;
}

int main() {
    Robot r1, r2(10);
    cout << "position courante de r2: " << r2.getPosition() << endl;
    r1.deplacer();
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(-1);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(2);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.faireDemiTour();
    r1.deplacer(4);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    return EXIT_SUCCESS;
}

~~~



</details>