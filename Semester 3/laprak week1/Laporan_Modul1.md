# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Bahasa C++ merupakan turunan dari bahasa C yang merupakan induk besar dari   banyak   bahasa pemrograman yang berkembang saat  ini, seperti PHP, Visual C, dan Java. Bahasa C++ memiliki kelebihan yaitu: Bahasa C++ merupakan bahasa pemrograman yang popular, Bahasa   C++   banyak   dibutuhkan   dalam   dunia   kerja, khususnya yang bergerak di bidang embedded system, Bahasa  C++  banyak  digunakan  untuk  membuat  aplikasi-aplikasi  canggih,  contoh  Google  Earth  dan  Skype  yang modul intinya menggunakan C++[1].

### A. Materi Minggu Pertama<br/>
Dalam pertemuan minggu pertama di mata kuliah Struktur Data, mahasiswa dikenalkan dengan bahasa C++, cara menginstall C++, dan membuat sebuah codingan C++ dengan program program berikut:
#### 1. Aritmatika
Operasi aritmatika adalah bagian dasar dari matematika yang mempelajari operasi bilangan seperti penjumlahan, pengurangan, perkalian dan pembagian[2]
#### 2. Percabangan
Percabangan berfungsi untuk memecahkan persoalan dan mengambil satu keputusan dari beberapa pilihan sesuai kondisi yang sedang dialami program[3].
#### 3. Perulangan
Perulangan merupakan struktur dimana terdapat proses pengulangan perintah yang sama sebanyak n kali[1].
#### 4. Struct
Struktur (juga disebut struct) adalah cara untuk mengelompokkan beberapa variabel terkait ke dalam satu tempat. Setiap variabel dalam struktur dikenal sebagai anggota struktur. Tidak seperti array , suatu struktur dapat berisi banyak tipe data yang berbeda[4].


## Guided 

### 1. Aritmatika

```C++
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
```
penjelasan singkat guided 1
    Program ini berfungsi untuk melakukan operasi aritmatika (penjumlahan, pengurangan, perkalian, pembagian, modulus) dengan menginputkan 2 angka, progam akan otomatis melakukan operasi aritmatika dengan 2 angka tersebut.
    
### 2. Percabangan

```C++
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
```
penjelasan singkat guided 2
    program ini menapilkan hubungan lebih besar, lebih kecil, sama dengan, atau tidak sama antara dua buah angka yang di inputkan.

### 3. Perulangan for

```C++
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
```
penjelasan singkat guided 3
    Program ini menginput 2 angka lalu menampilkan deret bilangan dari 0 sampai angka yang kita inputkan, dan dari 20 turun hingga angka yang kita inputkan.

### 4. perulangan while

```C++
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

```
penjelasan singkat guided 4
    Program ini menginput dua angka, lalu menggunakan while untuk menampilkan deret dari 0 hingga kurang dari angka, dan menggunakan do-while untuk menampilkan deret mulai dari 11 sambil bertambah sampai kondisi perulangan tidak terpenuhi.

## Unguided 

### 1. Soal unguided no 1
Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float angka, angka2;
    cout << "masukan angka1: " << endl;
    cin >> angka;
    cout << "masukan angka2: " << endl;
    cin >> angka2;

    cout <<"penjumlahan : " << angka + angka2 << endl;
    cout << "pengurangan : " << angka - angka2 << endl;
    cout << "perkalian : " << angka * angka2 << endl;
    cout << "pembagian : " << angka / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester%203/laprak%20week1/Output-unguided1.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

penjelasan unguided 1 

### 2. Unguided 2
Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1] (https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester%203/laprak%20week1/Output-unguided2.png)


penjelasan unguided 2

### 3. Soal Unguided 3
(https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester%203/laprak%20week1/Soal-3.png)
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
Dari pertemuan minggu pertama ini, hanya diberikan tutorial install C++ dan berlatih menggunakan kode C++ saja.

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4. 
<br>[2] Wikipedia. (2025). Aritmetika. Diakses pada 25 September 2025, dari https://id.wikipedia.org/wiki/Aritmetika
<br>[3] Blog Rumah Coding. (2022). Percabangan C++. Diakses pada 25 September 2025, dari https://blog.rumahcoding.co.id/percabangan-c/
<br> [4] W3shcools. (2025). Struktur  C++ (struct). Diakses pada 25 September 2025, dari https://www.w3schools.com/cpp/cpp_structs.asp
