#include <iostream>
#include <cstring> // Pour memcpy
#include <cstdlib> // Pour malloc et free

class Fichier {
private:
    char* P;      // Pointeur vers la zone mémoire
    size_t length; // Longueur du fichier en octets

public:
    // Constructeur
    Fichier(size_t len) : length(len), P(nullptr) {
        Creation(); // Appelle la méthode de création
    }

    // Destructeur
    ~Fichier() {
        delete[] P; // Libère la mémoire allouée
    }

    // Méthode pour créer un espace mémoire
    void Creation() {
        P = new char[length]; // Alloue l'espace mémoire
        std::cout << "Espace mémoire de " << length << " octets alloué." << std::endl;
    }

    // Méthode pour remplir l'espace mémoire
    void Remplit() {
        for (size_t i = 0; i < length; ++i) {
            P[i] = 'A' + (i % 26); // Remplit avec des lettres de A à Z
        }
        std::cout << "Espace mémoire rempli." << std::endl;
    }

    // Méthode pour afficher le contenu de l'espace mémoire
    void Affiche() {
        std::cout << "Contenu de la zone mémoire : ";
        for (size_t i = 0; i < length; ++i) {
            std::cout << P[i]; // Affiche chaque caractère
        }
        std::cout << std::endl;
    }
};

int main() {
    size_t taille = 100; // Taille de l'espace mémoire à allouer
    Fichier* fichier = new Fichier(taille); // Instanciation de la classe Fichier

    fichier->Remplit(); // Remplit la zone mémoire
    fichier->Affiche(); // Affiche le contenu de la zone mémoire

    delete fichier; // Détruit l'objet, appelant le destructeur
    return 0;
}
