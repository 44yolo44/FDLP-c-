#include <iostream>
using namespace std;

int main() {
    // Datos
    int numero;         // Número ingresado por el usuario
    int contador = 0;   // Contador de números mayores que cero

    // Entrada y Proceso
    cout << "Introduce numeros (0 para terminar):" << endl;
    do {
        cin >> numero; // Leer número
        if (numero > 0) {
            contador++; // Incrementar contador si el número es mayor que cero
        }
    } while (numero != 0); // Repetir hasta que se ingrese 0

    // Salida
    cout << "Cantidad de numeros mayores que cero: " << contador << endl;

    return 0;
}
