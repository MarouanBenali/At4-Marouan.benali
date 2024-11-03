#include <iostream>
#include <vector>
#include <stdexcept> // Pour std::runtime_error

class Pile {
private:
    std::vector<int> elements; // Utilisation d'un vecteur pour stocker les éléments

public:
    // Constructeur
    Pile() {}

    // Fonction pour empiler un élément
    void push(int element) {
        elements.push_back(element); // Ajoute l'élément à la fin du vecteur
    }

    // Fonction pour dépiler un élément
    int pop() {
        if (elements.empty()) {
            throw std::runtime_error("Erreur : la pile est vide."); // Vérification si la pile est vide
        }
        int element = elements.back(); // Récupère le dernier élément
        elements.pop_back(); // Supprime le dernier élément
        return element; // Renvoie l'élément retiré
    }

    // Fonction pour vérifier si la pile est vide
    bool isEmpty() const {
        return elements.empty(); // Renvoie vrai si la pile est vide
    }
};

int main() {
    Pile p1; // Création de la première pile
    Pile p2; // Création de la deuxième pile

    // Empiler des éléments sur p1
    p1.push(10);
    p1.push(20);
    p1.push(30);

    // Empiler des éléments sur p2
    p2.push(40);
    p2.push(50);

    // Dépiler des éléments de p1
    std::cout << "Dépiler de p1 : " << p1.pop() << std::endl; // Doit afficher 30
    std::cout << "Dépiler de p1 : " << p1.pop() << std::endl; // Doit afficher 20

    // Dépiler des éléments de p2
    std::cout << "Dépiler de p2 : " << p2.pop() << std::endl; // Doit afficher 50

    // Vérifier si la pile p1 est vide
    if (!p1.isEmpty()) {
        std::cout << "Dépiler de p1 : " << p1.pop() << std::endl; // Doit afficher 10
    }

    // Vérification de la gestion des erreurs
    try {
        p1.pop(); // Devrait lever une erreur, car la pile est maintenant vide
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Afficher l'erreur
    }

    return 0;
}
