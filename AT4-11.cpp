#include <iostream>
#include <vector>
#include <algorithm> // Pour std::sort
#include <stdexcept> // Pour std::invalid_argument

class Traitement {
private:
    std::vector<int> entiers; // Vecteur pour stocker les entiers

public:
    // Méthode pour initialiser le vecteur
    void Initialise() {
        int input;
        while (entiers.size() < 15) {
            std::cout << "Entrez un entier pair non nul : ";
            std::cin >> input;

            // Vérification de l'entrée
            if (std::cin.fail() || input == 0 || input % 2 != 0) {
                std::cin.clear(); // Réinitialiser l'état de l'entrée
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer la ligne
                std::cout << "Erreur : Veuillez entrer un entier pair non nul." << std::endl;
            } else {
                entiers.push_back(input); // Ajouter l'entier au vecteur
            }
        }
    }

    // Méthode récursive pour afficher les éléments du vecteur
    void show(int index = 0) {
        if (index < entiers.size()) {
            std::cout << entiers[index] << " ";
            show(index + 1); // Appel récursif
        } else {
            std::cout << std::endl; // Nouvelle ligne à la fin
        }
    }

    // Méthode amie pour calculer la moyenne
    friend double moyenne(const Traitement& t);

    // Méthode amie pour calculer la médiane
    friend double median(const Traitement& t);
};

// Fonction amie pour calculer la moyenne
double moyenne(const Traitement& t) {
    if (t.entiers.empty()) return 0.0;

    double sum = 0;
    for (int num : t.entiers) {
        sum += num;
    }
    return sum / t.entiers.size();
}

// Fonction amie pour calculer la médiane
double median(const Traitement& t) {
    if (t.entiers.empty()) return 0.0;

    std::vector<int> sorted = t.entiers; // Copier le vecteur pour trier
    std::sort(sorted.begin(), sorted.end()); // Trier les éléments

    size_t size = sorted.size();
    if (size % 2 == 0) {
        return (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0; // Moyenne des deux du milieu
    } else {
        return sorted[size / 2]; // Élément du milieu
    }
}

int main() {
    Traitement t;
    t.Initialise(); // Initialisation du vecteur
    std::cout << "Les entiers saisis sont : ";
    t.show(); // Affichage des entiers

    std::cout << "Moyenne : " << moyenne(t) << std::endl; // Affichage de la moyenne
    std::cout << "Médiane : " << median(t) << std::endl; // Affichage de la médiane

    return 0;
}
