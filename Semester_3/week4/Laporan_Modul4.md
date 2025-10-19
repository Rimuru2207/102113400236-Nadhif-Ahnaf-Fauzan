# <h1 align="center">Laporan Praktikum Modul 4 - Single Linked List (bagian Pertama)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Single linked list adalah jenis paling dasar dari linked list di mana setiap node terhubung ke node berikutnya dalam urutan linear. Setiap node memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan.[1].

### A. Materi Minggu Ketiga<br/>
Dalam pertemuan minggu ketiga di mata kuliah Struktur Data, mahasiswa dijelaskan tentang Linked List, terutama Single Linked List, menambahkan list dan menghapus list tertentu, lalu membuat program berikut:
#### 1. Single Linked List (Add list)
Pembuatan linked list kosong merupakan langkah pertama yang penting dalam implementasi single linked list. Saat membuat linked list kosong, kita harus menginisialisasi variabel atau objek yang menunjuk ke node pertama dalam linked list sebagai nilai yang menunjukkan bahwa linked list tersebut tidak memiliki elemen. Langkah ini penting karena menentukan status awal linked list sebelum elemen-elemen ditambahkan.[1].
#### 2. Delete List
Penghapusan di tengah linked list merupakan operasi yang penting dalam manajemen linked list karena memungkinkan kita untuk menambah atau menghapus elemen pada posisi yang ditentukan di antara elemen-elemen yang ada. Saat melakukan operasi ini, kita perlu memastikan untuk menyesuaikan referensi antar node sehingga linked list tetap terhubung secara konsisten.[1].


## Guided 
 
### 1. SLL (add)

#### 1. list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool listEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

#### 2. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
     if (Prev != Nil) {
         nodeBaru->next = Prev->next;
         Prev->next = nodeBaru;
     } else {
         cout << "Node sebelumnya tidak valid!" << endl;
     }
 }

 void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
     if (isEmpty(List)) {
         List.first = nodeBaru;
     } else {
         address nodeBantu = List.first;
         while (nodeBantu->next != Nil) {
             nodeBantu = nodeBantu->next;
         }
         nodeBantu->next = nodeBaru;
     }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

#### 3. main.cpp
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 2
    program ini adalah ADT (menggunakan 3 program), program akan membuat list mahasiswa terdiri dari Nama Nim dan usia.

### 2. SLL (Delete List)

#### 1. list.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool listEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address &nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

#### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
     if (Prev != Nil) {
         nodeBaru->next = Prev->next;
         Prev->next = nodeBaru;
     } else {
         cout << "Node sebelumnya tidak valid!" << endl;
     }
 }

 void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
     if (isEmpty(List)) {
         List.first = nodeBaru;
     } else {
         address nodeBantu = List.first;
         while (nodeBantu->next != Nil) {
             nodeBantu = nodeBantu->next;
         }
         nodeBantu->next = nodeBaru;
     }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

#### 3. main.cpp

```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 2
    Hamppir sama seperti program guided 1, hanya saja program kedua menambahkan fungsi delete list.

## Unguided 

### 1. Soal unguided no 1
![] (https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week4/soal1p1.png)
![] (https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week4/soal1p2.png)

#### 1. singlylist.h

```C++
#ifndef SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

#### 2. singlylist.cpp

```C++
#include "singlylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address p = new ElmList;
    p->info = x;
    p->next = NULL;
    return p;
}

void dealokasi(address p) {
    delete p;
}

void printInfo(List L) {
    address p = L.First;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(List &L, address p) {
    p->next = L.First;
    L.First = p;
}
```

#### 3. main.cpp

```C++
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address p1, p2, p3, p4, p5 = NULL;

    CreateList(L);

    p1 = alokasi(2);
    insertFirst(L, p1);

    p2 = alokasi(0);
    insertFirst(L, p2);

    p3 = alokasi(8);
    insertFirst(L, p3);

    p4 = alokasi(12);
    insertFirst(L, p4);

    p5 = alokasi(9);
    insertFirst(L, p5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week4/outputno1.png)

penjelasan unguided 1 
Program ini akan memasukan list angka kedalam list sesuai dengan pointer masing masing angka.

### 2. Unguided 2
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week4/soal2.png)

#### 1. singlylist.h

```C++
#ifndef SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;
struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```
#### 2. singlylist.cpp

```C++
#include "singlylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First != NULL) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First != NULL) {
        if (L.First->next == NULL) {
            deleteFirst(L);
        } else {
            address Q = L.First;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            address P = Q->next;
            Q->next = NULL;
            dealokasi(P);
        }
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.First != NULL) {
        deleteFirst(L);
    }
}
```
#### 3. main.cpp

```C++
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address p1, p2, p3, p4, p5 = NULL;
    CreateList(L);

    p1 = alokasi(2);
    insertFirst(L, p1);

    p2 = alokasi(0);
    insertFirst(L, p2);

    p3 = alokasi(8);
    insertFirst(L, p3);

    p4 = alokasi(12);
    insertFirst(L, p4);

    p5 = alokasi(9);
    insertFirst(L, p5);

    cout << "Isi list: ";
    printInfo(L);

    deleteFirst(L);
    deleteLast(L);

    address Prec = L.First;
    deleteAfter(L, Prec);

    cout << "Setelah hapus list: ";
    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week4/outputuno2.png)


penjelasan unguided 2
Program ini kurang lebih sama seperti program sebelumnya, tetapi program ini akan menambah fungsi delete list dalam kasus ini program akan menghapus list awal, akhir, dan kondisi tertentu.

## Kesimpulan
Dari pertemuan minggu ketiga ini, mahasiswa diajarkan tentang Single Linked List, penambahan list dan penghapusan list.

## Referensi
[1] Rumah Coding (2025). "Linked List: Pengertian dan Implementasi Dasar". Diakses pada 18 Oktober 2025 melalui https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/. 
<br>
