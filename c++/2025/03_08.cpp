// ZIGZAG zadatak
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n = 3;  
    string niz[n];    
    string primjer = "PAYPALISHIRING";

    bool flag = true; 
    int i = 0, red = 0;

    while (i < primjer.length()) {
        niz[red] += primjer[i];

        if (red == 0) {
            flag = true;
            red++;
        } else if (red == n - 1) {
            flag = false;
            red--;
        } else {
            if (flag) {
                red++;
            } else {
                red--;
            }
        }
        i++;
    }

    cout << "\nZigZag ispis:\n";
    for (int i = 0; i < n; i++) {
        cout << niz[i] << endl;
    }

    return 0;
}