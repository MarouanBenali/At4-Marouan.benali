#include <iostream>
using namespace std;

class Test {
private:
    static int count; // Variable statique pour compter les appels

public:
    // Méthode qui sera appelée plusieurs fois
    void call() {
        count++; // Incrémente le compteur à chaque appel
        cout << "La fonction call a été appelée " << count << " fois." << endl;
    }
};

// Initialisation de la variable statique à 0
int Test::count = 0;

int main() {
    Test t1, t2;

    // Appels multiples de la fonction call
    t1.call();
    t1.call();
    t2.call();
    t1.call();
    t2.call();

    return 0;
}
