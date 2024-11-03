#include <iostream>
using namespace std;

class NbrComplex {
private:
    int Re, Im;

public:
    // Constructeur
    NbrComplex(int PR = 0, int PI = 0) : Re(PR), Im(PI) {}

    // Surcharge de l'opérateur +
    NbrComplex operator+(NbrComplex other) {
        return NbrComplex(Re + other.Re, Im + other.Im);
    }

    // Surcharge de l'opérateur -
    NbrComplex operator-(NbrComplex other) {
        return NbrComplex(Re - other.Re, Im - other.Im);
    }

    // Surcharge de l'opérateur *
    NbrComplex operator*(NbrComplex other) {
        return NbrComplex(Re * other.Re - Im * other.Im, Re * other.Im + Im * other.Re);
    }

    // Surcharge de l'opérateur /
    NbrComplex operator/(NbrComplex other) {
        int denom = other.Re * other.Re + other.Im * other.Im;
        if (denom == 0) {
            cout << "Erreur : division par zéro" << endl;
            return NbrComplex(0, 0);
        }
        int realPart = (Re * other.Re + Im * other.Im) / denom;
        int imagPart = (Im * other.Re - Re * other.Im) / denom;
        return NbrComplex(realPart, imagPart);
    }

    // Surcharge de l'opérateur ==
    bool operator==(NbrComplex other) {
        return (Re == other.Re && Im == other.Im);
    }

    // Fonction d'affichage
    void affichage() {
        if (Im >= 0)
            cout << Re << " + " << Im << "i" << endl;
        else
            cout << Re << " - " << -Im << "i" << endl;
    }
};

int main() {
    int real1, imag1, real2, imag2;
    cout << "Entrez la partie réelle et imaginaire du premier nombre complexe: ";
    cin >> real1 >> imag1;
    cout << "Entrez la partie réelle et imaginaire du deuxième nombre complexe: ";
    cin >> real2 >> imag2;

    NbrComplex c1(real1, imag1);
    NbrComplex c2(real2, imag2);
    NbrComplex result;
    int choix;

    do{
        cout << "Choisissez une opération :\n";
        cout << "1 - Addition\n";
        cout << "2 - Soustraction\n";
        cout << "3 - Multiplication\n";
        cout << "4 - Division\n";
        cout << "5 - Egalité\n";
        cout << "Votre choix : ";
        cin >> choix;
    }while(choix<1 || choix>5);

    switch (choix) {
        case 1:
            result = c1 + c2;
            cout << "Résultat de l'addition: ";
            result.affichage();
            break;
        case 2:
            result = c1 - c2;
            cout << "Résultat de la soustraction: ";
            result.affichage();
            break;
        case 3:
            result = c1 * c2;
            cout << "Résultat de la multiplication: ";
            result.affichage();
            break;
        case 4:
            result = c1 / c2;
            cout << "Résultat de la division: ";
            result.affichage();
            break;
        case 5:
            if (c1 == c2)
                cout << "Les deux nombres complexes sont égaux." << endl;
            else
                cout << "Les deux nombres complexes ne sont pas égaux." << endl;
            break;
        default:
            cout << "Choix invalide." << endl;
            break;
    }

    return 0;
}
