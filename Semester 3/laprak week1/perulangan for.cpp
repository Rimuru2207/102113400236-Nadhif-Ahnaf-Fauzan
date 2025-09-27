#include <iostream>
using namespace std;

int main () {
    int angka, angka2;
    cout << "masukan angka : " <<endl;
    cin >> angka;
    cout << "masukan angka2 : " <<endl;
    cin >> angka2;

    for (int i = 0; i <= angka; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    for (int i = 20; i > angka; i--) { //decrement
        cout << i << " - ";
    }

    return 0;
}