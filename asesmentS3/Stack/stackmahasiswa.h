#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string NIM;
    float nilaiTugas;
    float nilaiUTS;
    float nilaiUAS;
};

const int MAX = 6;

struct stackMahasiswa{
    mahasiswa dataMahasiswa[MAX];
    int top;
};

bool isEmpty(stackMahasiswa mhs);
bool isFull(stackMahasiswa mhs);
void createStack(stackMahasiswa &mhs);
void push(stackMahasiswa &mhs, mahasiswa m);
void pop(stackMahasiswa &mhs, mahasiswa &m);
void update(stackMahasiswa &mhs, int posisi);
void viewStack(stackMahasiswa mhs);
void searchNilaiAkhir(stackMahasiswa mhs, float minNilai, float maxNilai);

#endif