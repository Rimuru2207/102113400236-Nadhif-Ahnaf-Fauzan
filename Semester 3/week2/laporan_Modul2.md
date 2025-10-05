# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Bahasa C++ merupakan turunan dari bahasa C yang merupakan induk besar dari   banyak   bahasa pemrograman yang berkembang saat  ini, seperti PHP, Visual C, dan Java. Bahasa C++ memiliki kelebihan yaitu: Bahasa C++ merupakan bahasa pemrograman yang popular, Bahasa   C++   banyak   dibutuhkan   dalam   dunia   kerja, khususnya yang bergerak di bidang embedded system, Bahasa  C++  banyak  digunakan  untuk  membuat  aplikasi-aplikasi  canggih,  contoh  Google  Earth  dan  Skype  yang modul intinya menggunakan C++[1].

### A. Materi Minggu Kedua<br/>
Dalam pertemuan minggu kedua di mata kuliah Struktur Data, mahasiswa dikenalkan dengan bahasa C++, terutama dengan pengenalan array dalam C++ dan membuat sebuah codingan guided C++ dengan program program berikut:
#### 1. Array
Array adalah sebuah tipe data terstruktur yang terdiri dari sejumlah dengan tipe komponen yang sama[1].
#### 2. Array2d
Array dua dimensi adalah array yang terdiri dari (input 1) buah baris dan (input 2) buah kolom[2].
#### 3. Function
Fungsi adalah unit mandiri dari kode program yang dirancang untuk menyelesaikan tugas tertentu[3].
#### 4. Pointer
Pointer dalam C++ menunjuk ke lokasi memori variabel lain. Pointer memungkinkan kita mengakses lokasi mana pun di memori komputer, bertindak sebagai variabel[4].
#### 5. Reference
Reference adalah fitur yang berasal dari C++ memungkinkan kita untuk membuat variabel yang dapat memegang alamat memori dan berperan layaknya variabel tapi sebenarnya adalah alias dari suatu alamat memori, suatu obyek, atau suatu variabel[5].


## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main () {
    int arr[5];

    for (int i = 0; i < 5 ; i++) {
        cout << "masukan urutan angka ke- " << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke- " << j << " : " << arr[j] << endl;
        j++;
    }

    return 0;
}
```
penjelasan singkat guided 1
    Program ini meminta input angka sebanyak 5 angka, lalu program akan mengurutkan angka yang di inputkan dari indeks ke 0 sampai 4 (karena jumlah array hanya terbatas 5).
    
### 2. Array 2d

```C++
#include <iostream>
using namespace std;

void tampilkanMatriks(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <2; j++) {
            cout  << arr[i][j] << " ";
        }
    } 
}

int main() {
    int arrA[2][2] = {{1, 2}, {3, 4}};
    int arrB[2][2] = {{2, 3}, {4, 5}};
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }   
    }
    cout << "Hasil penjumlahan matriks A dan B : " << endl;
    tampilkanMatriks(arrC);
    return 0;
}
```
penjelasan singkat guided 2
    program ini menghitung array 2 dimensi (dalam contoh 2x2) lalu program akan menjumlahkan semua angka dalam array A dan array B.

### 3. Function

```C++
#include <iostream>
using namespace std;

int cariMaks(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0 ;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total Penjumlahan: " << totalJumlah << endl;

    int totalkali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalkali *= arr[i];
    }
    cout << "total Perkalian: " << totalkali << endl;

    
}

int main () {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran ; i++) {
        cout << "masukan urutan angka ke- " << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai Maksimum: " << cariMaks(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}
```
penjelasan singkat guided 3
    Program ini menjelaskan bagaimana fungsi bekerja, yaitu memisahkan program pencarian nilai max, penjumlahan, dan perkalian dengan program utama.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}   

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "nilai a : " << a << endl;
    cout << "alamat a : " << &a << endl;
    cout << "value stored in ptr : " << ptr << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "after swapping, nilai a : " << a << " and nilai b : " << b << endl;
    return 0;
}
```
penjelasan singkat guided 4
    Program ini menampilkan cara kerja pointer, yaitu menunjukan nilai dan alamat masing masing variabel, lalu menukar nilai variabel A dan Variabel B.

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}   

int main() {
    int a = 20, b = 30;
    int &ref = a;

    ref = a;

    cout << "nilai a : " << a << endl;
    cout << "alamat a : " << &a << endl;
    cout << "value stored in ref : " << ref << endl;
    cout << "value pointed to by ref : " << &ref << endl;

    ref = 50;
    cout << "\nsetelah ref = 50" << endl;
    cout << "nilai a : " << a << endl;
    cout << "nilai ref : " << ref << endl;

    tukar(&a, &b);
    cout << "after swapping, nilai a : " << a << " and nilai b : " << b << endl;
    return 0;
}
```
penjelasan singkat guided 5
    Program ini menunjukan penggunakan referensi dan pointer dengan menukar kedua variabel dengan pointer lalu menggunakan referensi kepada salah satu variabel.


## Unguided 

### 1. Soal unguided no 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
# include <iostream>
using namespace std;

void inputMatrix(int A[3][3]){
    cout << "Input matrix (3x3): " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> A[i][j];
        }
    }
}

void outputMatrix(int A[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void penjumlahanMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void penguranganMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalianMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = 0;
            for (int k = 0; k < 3; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];
    cout << "Input matriks A:" << endl;
    inputMatrix(A);
    cout << "Input matriks B:" << endl;
    inputMatrix(B);

    cout << "Hasil Penjumlahan:" << endl;
    penjumlahanMatrix(A, B, C);
    outputMatrix(C);

    cout << "Hasil Pengurangan:" << endl;
    penguranganMatrix(A, B, C);
    outputMatrix(C);

    cout << "Hasil Perkalian:" << endl;
    perkalianMatrix(A, B, C);
    outputMatrix(C);

    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](github image link)

penjelasan unguided 1 
    Program ini meminta input 2 buah matrix 2dimensi (Mat A dan Mat B) sepanjang 3x3, lalu program akan menghitung operasi dasar antar Matrix A dan Matrix B.

### 2. Unguided 2
Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 22, y = 7, z = 6;

    cout << "Sebelum tukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << endl;

    tukarPointer(&x, &y, &z);
    cout << "Setelah tukar (pointer): x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << endl;

    tukarReference(x, y, z);
    cout << "Setelah tukar (reference): x=" << x << ", y=" << y << ", z=" << z << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](github image link)

penjelasan unguided 2
    Program ini mempunyai 3 buah variabel XYZ, yang masing masing akan ditukar dengan pointer dan reference.

### 3. Soal Unguided 3
Diketahui sebuah array 1 dimensi sebagai berikut :
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMin(int arr[], int n) {
    int minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int cariMax(int arr[], int n) {
    int maximum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

void hitungRataRata(int arr[], int n) {
    float jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    cout << "Rata-rata: " << jumlah / n << endl;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanArray(arrA, n); break;
            case 2: cout << "Nilai maksimum: " << cariMax(arrA, n) << endl; break;
            case 3: cout << "Nilai minimum: " << cariMin(arrA, n) << endl; break;
            case 4: hitungRataRata(arrA, n); break;
            case 5: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
Menu 1-2:

![Screenshot Output Unguided 3_1](github image link)

Menu 3-5:

![Screenshot Output Unguided 3_1](github image link)

penjelasan unguided 3
    Program ini membuat sebuah program kecil dengan menu tertentu, program ini sudah mempunyai array, user tinggal memilih mau diapakan array tersebut dengan menu yang tersedia (cari max, cari min, hitung rata-rata, atau langsung keluar dari program).

## Kesimpulan
Dari pertemuan minggu kedua ini, mahasiswa di ajari tentang materi Array dan pointer pada bahasa pemrograman C++

## Referensi
[1] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 8 Oktober 2025 melalui https://doi.org/10.21070/2020/978-623-6833-67-4. 
<br> [2] Medium. (2025). Penjelasan Array 2 dimensi beserta contohnya. Diakses pada 8 Oktober 2025 melalui https://akbartaufik.medium.com/penjelasan-array-2-dimensi-beserta-contohnya-ca8062a6125f.
<br> [3] S. Anam, et.al. (2021). Cara Mudah Belajar Bahasa Pemrograman C++. Malang: Universitas Brawijaya Press. Diakses pada 8 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=4UJTEAAAQBAJ&oi=fnd&pg=PA11&dq=fungsi+c%2B%2B+definitions&ots=LFyt914Q-Q&sig=z80EG2j2wRZDAxGBTyrNyadOUJA&redir_esc=y#v=onepage&q&f=false.
<br> [4] ScholarHat. (2025). Pointer dalam C++: Deklarasi, Inisialisasi, dan Keuntungan. Diakses pada 8 Oktober 2025 melalui https://www.scholarhat.com/tutorial/cpp/pointers-in-cpp.
<br> [5] Belajarcpp. (2025). Reference. Diakses pada 8 Oktober 2025 melalui https://www.belajarcpp.com/tutorial/cpp/reference/.
