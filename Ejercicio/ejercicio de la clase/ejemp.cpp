#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(15) << "Izquierda" << "Columna 1" << endl;
    
    cout << right << setw(15) << "Derecha" << "Columna 2" << endl;
    return 0;
}
