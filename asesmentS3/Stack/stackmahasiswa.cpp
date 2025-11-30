#include "stackmahasiswa.h"

#include <iostream>
using namespace std;

bool isEmpty(stackMahasiswa mhs){
    return mhs.top == -1;
}

bool isFull(stackMahasiswa mhs){
    return mhs.top == MAX - 1;
}

void createStack(stackMahasiswa &mhs){
    mhs.top = -1;
}

void push(stackMahasiswa &mhs, mahasiswa m){
    if(isFull(mhs)){
        cout << "Data Penuh" << endl;
    } else {
        mhs.top++;
        mhs.dataMahasiswa[mhs.top] = m;
    }
}

void pop(stackMahasiswa &mhs, mahasiswa &m){
    if(isEmpty(mhs)){
        cout << "Data Kosong" << endl;
    } else {
        m = mhs.dataMahasiswa[mhs.top];
        mhs.top--;  
    }
}

void update(stackMahasiswa &mhs, int posisi){
    if(posisi < 0 || posisi > mhs.top){
        cout << "Posisi tidak valid" << endl;
    } else if (isEmpty(mhs)){
        cout << "Data Kosong" << endl;
    } else {
        cout << "Masukkan data baru : " << endl;
        cout << "Nama: ";
        cin >> mhs.dataMahasiswa[posisi].nama;
        cout << "NIM: ";
        cin >> mhs.dataMahasiswa[posisi].NIM;
        cout << "Nilai Tugas: ";
        cin >> mhs.dataMahasiswa[posisi].nilaiTugas;
        cout << "Nilai UTS: ";
        cin >> mhs.dataMahasiswa[posisi].nilaiUTS;
        cout << "Nilai UAS: ";
        cin >> mhs.dataMahasiswa[posisi].nilaiUAS;
    }
}

void viewStack(stackMahasiswa mhs){
    if(isEmpty(mhs)){
        cout << "Data Kosong" << endl;
    } else {
        for(int i = mhs.top; i >= 0; i--){
            cout << "Nama: " << mhs.dataMahasiswa[i].nama << endl;
            cout << "NIM: " << mhs.dataMahasiswa[i].NIM << endl;
            cout << "Nilai Tugas: " << mhs.dataMahasiswa[i].nilaiTugas << endl;
            cout << "Nilai UTS: " << mhs.dataMahasiswa[i].nilaiUTS << endl;
            cout << "Nilai UAS: " << mhs.dataMahasiswa[i].nilaiUAS << endl;
        }
    }
}

void searchNilaiAkhir(stackMahasiswa mhs, float minNilai, float maxNilai){
    if(isEmpty(mhs)){
        cout << "Data Kosong" << endl;
    } else {
        for(int i = 0; i <= mhs.top; i++){
            float nilaiAkhir = (mhs.dataMahasiswa[i].nilaiTugas * 0.20) + (mhs.dataMahasiswa[i].nilaiUTS * 0.40) + (mhs.dataMahasiswa[i].nilaiUAS * 0.40);
            if(nilaiAkhir >= minNilai && nilaiAkhir <= maxNilai){
                cout << "Nama: " << mhs.dataMahasiswa[i].nama << endl;
                cout << "NIM: " << mhs.dataMahasiswa[i].NIM << endl;
                cout << "Nilai Akhir: " << nilaiAkhir << endl;
            }
        }
    }
}