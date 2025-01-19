# Supprimer un élément d'une position donnée dans un vector

Écrire une fonction C++ pour supprimer un élément d'une position donnée dans un tableau std::vector<int>. La fonction doit lever une(des) exception(s) en cas de problème(s) empêchant la suppression.

~~~cpp
void removeFromVector(std::vector<int>& vec, size_t pos);
~~~

_NB_ L'exercice doit être résolu en utilisant exclusivement une(des) exception(s) prédéfinie(s).

**Rappel** Hiérarchie des exceptions

~~~mermaid
graph TD
  exception(Exception)
  
  bad_alloc(Bad Alloc)
  logic_error(Logic Error)
  invalid_argument(Invalid Argument)
  out_of_range(Out of Range)

  runtime_error(Runtime Error)
  overflow_error(Overflow Error)
  range_error(Range Error)

  exception     --> bad_alloc
  exception     --> logic_error
  logic_error   --> invalid_argument
  logic_error   --> out_of_range
  exception     --> runtime_error
  runtime_error --> overflow_error
  runtime_error --> range_error
~~~

<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>
#include <vector>
#include <stdexcept>

void removeFromVector(std::vector<int>& vec, size_t pos) {
    if (vec.empty()) {
        throw std::runtime_error("Suppression impossible, le vecteur est vide");
    }

    if (pos >= vec.size()) {
        throw std::out_of_range("Position hors limites du vecteur");
    }

    vec.erase(vec.begin() + pos);
}

int main() {
    std::vector<int> monVecteur = {1, 2, 3, 4, 5};

    try {
        removeFromVector(monVecteur, 6); // Supprime l'élément à la position 2

        // Affichage du vecteur après suppression
        for (int val : monVecteur) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
~~~

</details>
