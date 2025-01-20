#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) 
    {
        cout << "7 x " << setw(2) << i << " = " << setw(3) << 7 * i << "   ";
        cout << "9 x " << setw(2) << i << " = " << setw(3) << 9 * i << endl;
    }

    return 0;
}