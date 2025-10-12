# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type(ADT)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Abstract Data Type (ADT) adalah sekumpulan objek dan sekumpulan operasi terkait pada objek tersebut[1].

### A. Materi Minggu Ketiga<br/>
Dalam pertemuan minggu ketiga di mata kuliah Struktur Data, mahasiswa dijelaskan tentang Abstract Data Type (ADT), lalu membuat program berikut:
#### 1. Struct
Struktur (juga disebut struct) adalah cara untuk mengelompokkan beberapa variabel terkait ke dalam satu tempat. Setiap variabel dalam struktur dikenal sebagai anggota struktur. Tidak seperti array , suatu struktur dapat berisi banyak tipe data yang berbeda[2].
#### 2. Abstract Data Type (ADT)
ADT Mendukung abstraksi, enkapulasi dan penyembunyian informasi (Pada dasarnya meningkatkan indeendensi representasional)[1].


## Guided 

### 1. Struct

```C++
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
```
penjelasan singkat guided 1
    Program ini meminta input Nama, dan dua buah nilaim otomatis program akan menghitung rata-rata nilai.
    
### 2. ADT (Pelajaran)

#### 1. pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_Pelajaran(string namaMapel, string kodeMapel);

void tampil_Pelajaran(Pelajaran pel);

#endif
```
#### 2. pelajaran.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

Pelajaran create_Pelajaran(string namaMapel, string kodeMapel) {
    Pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
};

void tampil_Pelajaran(Pelajaran pel) {
    cout << "Nama Mata Pelajaran: " << pel.namaMapel << endl;
    cout << "Nilai: " << pel.kodeMapel << endl;
}
```
#### 3. main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main () {
    string namapel = "struktur data";
    string kodepel = "STD";
    Pelajaran pelajaran1 = create_Pelajaran(namapel, kodepel);
    tampil_Pelajaran(pelajaran1);
    return 0;
}
```
penjelasan singkat guided 2
    program ini adalah ADT (menggunakan 3 program), inputannya adalah nama pelajaran dan kode pelajaran maka program akan langsung menampilkan outpu berupa nama pelajaran dan nilainya.



## Unguided 

### 1. Soal unguided no 1
Buat program yang dapat menyimpan data mahasiswa (max 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diproses dari fungsi dengan rumus 0.3*uts+0.4*uas+0.3*tugas

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "NILAI AKHIR" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](Github file)

penjelasan unguided 1 
Program ini akan meminta jumlah mahasiswa, user akan menginputkan Nama, NIM, Nilai-Nilai sebanyak jumlah mahasiswa yang di masukan oleh user, program akan mengeluarkan nilai akhir yaitu hasil dari operasi antar 3 nilai.

### 2. Unguided 2
!(github file)

#### pelajaran.h

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);

void tampil_pelajaran(pelajaran pel);

#endif
```
#### pelajaran.cpp

```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
#### main.cpp

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](File Github)


penjelasan unguided 2
Program ini menggunakan sebuah ADT atau 3 program dalam 1 projek, program akan menampilkan nama pelajaran dan kode pelajaran sesuai dengan yang ada di dalam kode.

### 3. Soal Unguided 3
...

```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[N][N], int arr2[N][N], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *p1 = &A[0][0];
    int *p2 = &B[2][2];

    cout << "Array A sebelum ditukar: ";
    tampilArray(A);
    cout << "Array B sebelum ditukar: ";
    tampilArray(B);

    tukarElemen(A, B, 1, 1);

    cout << "Array A sesudah tukar elemen [1][1]: ";
    tampilArray(A);
    cout << "Array B sesudah tukar elemen [1][1]: ";
    tampilArray(B);

    cout << "Nilai sebelum tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Nilai sesudah tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](File Github)

penjelasan unguided 3
Program ini menampilkan 2 buah array 3x3, masing masing array akan ditukar nilainya, program akan menampilkan array sebelum di tukar nilai (default) menukar elemen [1][1], dan menukar pointer.

## Kesimpulan
Dari pertemuan minggu ketiga, mahasiswa diajarkan tentang Abstract Data Type atau ADT.

## Referensi
[1] DC. Schmidt (2025). "Object-Oriented Design and Programming C++ Language Support for Abstract Data Types". Washington: Vanderbilt University. Diakses pada 25 September 2025 melalui https://www.dre.vanderbilt.edu/~schmidt/PDF/C++-adts.pdf. 
<br>[2] W3shcools. (2025). Struktur  C++ (struct). Diakses pada 10 Oktober 2025, dari https://www.w3schools.com/cpp/cpp_structs.asp.
