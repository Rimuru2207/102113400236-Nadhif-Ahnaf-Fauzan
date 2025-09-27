#include <iostream>
using namespace std;

int main () {
    int angka, angka2;
    cout << "masukan angka : " <<endl;
    cin >> angka;
    cout << "masukan angka2 : " <<endl;
    cin >> angka2;

    int i = 0 ;
    int j = 11;
    //perulangan while
    while (i < angka) {
        cout << i << " - ";
        i++;
    }

    cout << endl;

    //perulangan do-while
    do {
        cout << j << " - ";
        j++; //decrement
    } while (j > angka2);

    return 0;
}