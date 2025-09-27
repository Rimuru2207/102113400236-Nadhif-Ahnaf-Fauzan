#include <iostream>
using namespace std;

int main () {
    int angka, angka2;
    cout << "masukan angka : " <<endl;
    cin >> angka;
    cout << "masukan angka2 : " <<endl;
    cin >> angka2;

    if (angka > angka2) {
        cout << angka << "lebih besar dari " << angka2 << endl;
    } else if (angka == angka2) {
        cout << angka << "sama dengan " << angka2 << endl;
    } else if (angka < angka2) {
        cout << angka << "lebih kecil dari " << angka2 << endl;
    }

    if (angka != angka2) {
        cout << angka << "tidak sama dengan " << angka2 << endl;
    }

    return 0;
}