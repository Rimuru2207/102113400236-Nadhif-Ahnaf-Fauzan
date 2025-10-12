#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    float nilai, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mhasiswa: ";
    cin >> m.nama;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rataRata(mahasiswa m) {
    return (m.nilai + m.nilai2) / 2;
}

int main() {
    mahasiswa m;
    inputMhs(m);
    cout << "Rata-rata nilai " << rataRata(m);
    return 0;
}