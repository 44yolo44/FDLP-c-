#include <iostream>
#include <cstdlib> // Para srand() y rand()
#include <ctime>   // Para time()

using namespace std;

int main() {

    // Simular la carrera
    const int num_caballos = 4;
    int ganador = rand() % num_caballos + 1; // Genera un número entre 1 y 4

    // Mostrar los resultados
    cout << "Simulando una carrera de 4 caballos...\n";
    for (int i = 1; i <= num_caballos; i++) {
        cout << "Caballo " << i << " está corriendo...\n";
    }
    
    // Anunciar el ganador
    cout << "El caballo " << ganador << " es el ganador!\n";

    return 0;
}
