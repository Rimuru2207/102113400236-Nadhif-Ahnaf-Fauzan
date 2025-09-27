#include <iostream>
using namespace std;

string angkaTulisan (int angka) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka < 10) return satuan[angka];
    else if (angka < 20) return belasan[angka - 10];
    else if (angka < 100) {
        int puluh = angka / 10;
        int satu = angka % 10;
        if (satu == 0) return puluhan[puluh];
        else return puluhan[puluh] + " " + satuan[satu];
    } else if (angka == 100) {
        return "seratus";
    } else {
        return "tidak valid";
    }
}

int main () {
    int angka2;
    cout << "masukan angka (0-100): " << endl;
    cin >> angka2;
    cout << angka2 << " : "  << angkaTulisan(angka2) << endl;
    return 0;
}
