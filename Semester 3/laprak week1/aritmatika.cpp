#include <iostream>
using namespace std;

int main () {
    int angka, angka2;
    cout << "masukan angka : " <<endl;
    cin >> angka;
    cout << "masukan angka2 : " <<endl;
    cin >> angka2;

    //operasi penjumlahan
    cout <<"penjumlahan : " << angka + angka2 << endl;
    //operasi pengurangan
    cout << "pengurangan : " << angka - angka2 << endl;
    //perkalian
    cout << "perkalian : " << angka * angka2 << endl;
    //pembagian
    cout << "pembagian : " << angka / angka2 << endl;
    //modulus
    cout << "modulus : " << angka % angka2 << endl;
    return 0;
}