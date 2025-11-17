#include "stackmahasiswa.h"

#include <iostream>
using namespace std;

int main () {
    stackMahasiswa mhs;
    createStack(mhs);

    mahasiswa m1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    mahasiswa m2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    mahasiswa m3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    mahasiswa m4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    mahasiswa m5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    mahasiswa m6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    push(mhs, m1);
    push(mhs, m2);
    push(mhs, m3);
    push(mhs, m4);
    push(mhs, m5);
    push(mhs, m6);

    viewStack(mhs);

    pop(mhs, m1);

    viewStack(mhs);

    update(mhs, 3);
    viewStack(mhs);

    searchNilaiAkhir(mhs, 85.5, 95.5);  

    return 0;
}