# <h1 align="center">Laporan Praktikum Modul 5 - Single Linked List (bagian kedua)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Single linked list adalah jenis paling dasar dari linked list di mana setiap node terhubung ke node berikutnya dalam urutan linear. Setiap node memiliki dua bagian: data yang disimpan dan referensi ke node berikutnya dalam urutan.[1].

### A. Materi Minggu Ketiga<br/>
Dalam pertemuan minggu ketiga di mata kuliah Struktur Data, mahasiswa dijelaskan tentang Linked List, terutama Single Linked List, menambahkan list dan menghapus list tertentu, lalu membuat program berikut:
#### 1. Single Linked List (Update List)
Penyisipan dan penghapusan di tengah linked list merupakan operasi yang penting dalam manajemen linked list karena memungkinkan kita untuk menambah atau menghapus elemen pada posisi yang ditentukan di antara elemen-elemen yang ada. Saat melakukan operasi ini, kita perlu memastikan untuk menyesuaikan referensi antar node sehingga linked list tetap terhubung secara konsisten[1].


## Guided 
 
### 1. SLL (Update)

#### 1. listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

#### 2. list.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

#### 3. main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan singkat guided 2
    program ini adalah ADT (menggunakan 3 program), program akan membuat list buah, program akan meminta input nama, jumlah, dan harga buah untuk di update, lalu program akan menampilkan list yang sudah du update, program akan mencari node dan menampilkan jika ketemu ada di posisi berapa dan alamatnya apa, program akan menampilkan list yang mempunya range harga tertentu, program akan menghapus list tertentu sesuai program main lalu menampilkan list seteleah melakukan perubahan tersebut.

## Unguided 
Diberikan pseudo ADT SLL (ListAngka.h, ListAngka.cpp, main.cpp) terdapat 3 soal yang akan langsung menjadi 1 
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week5/outputsoal1.png)

### Soal unguided no 1
1. Buatlah procedure updateFirst, updateLast, dan updateAfter, pada "main.cpp" lakukan:
➢ Update data 40 menjadi 50
➢ Update data 8 menjadi 29
➢ Update data 33 menjadi 45
➢ Update data 18 menjadi 20
➢ Tampilkan seluruh list setelah diupdate
Outputnya:
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week5/outputsoal2.png)

2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange, pada "main.cpp" lakukan:
➢ Mencari data nilai 20
➢ Mencari data nilai 55
➢ Mencari data alamat nodeB
➢ Mencari data alamat nodeA
➢ Mencari data dengan nilai minimal 40
Outputnya:
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week5/outputsoal3.png)

3. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.
Outputnya: 
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week5/outputsoal4.png)

#### 1. ListAngka.h

```C++
#ifndef LISTANGKA_H
#include <string>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &P);
void printList(const linkedList &L);
void insertFirst(linkedList &L, address P);
void insertLast(linkedList &L, address P);
void insertAfter(linkedList &L, address P, address Prec);
void delAfter(linkedList &L, address &P, address Prec);

void updateFirst(linkedList &L);
void updateAfter(linkedList &L, address Prec, string nodeLabel);
void updateLast(linkedList &L);

address SearchByData(const linkedList &L, int data);
bool SearchByAddress(const linkedList &L, address nodeCari);
void SearchByRange(const linkedList &L, int nilaiMin);

void operasiAritmatika(const linkedList &L);

#endif
```

#### 2. ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

void createList(linkedList &L) {
    L.first = nullptr;
}

address alokasi(dataAngka x) {
    address P = new node;
    P->angka = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printList(const linkedList &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->angka << " - ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address P) {
    if (P != nullptr) {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedList &L, address P) {
    if (P == nullptr) return;
    if (L.first == nullptr) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address P, address Prec) {
    if (Prec != nullptr && P != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void delAfter(linkedList &L, address &P, address Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

void updateFirst(linkedList &L) {
    if (L.first != nullptr) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address Prec, string nodeLabel) {
    if (Prec != nullptr && Prec->next != nullptr) {
        cout << "masukkan update data node setelah node " << nodeLabel << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> Prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != nullptr) {
        address P = L.first;
        while (P->next != nullptr) {
            P = P->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> P->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

address SearchByData(const linkedList &L, int data) {
    address P = L.first;
    while (P != nullptr) {
        if (P->angka == data)
            return P;
        P = P->next;
    }
    return nullptr;
}

bool SearchByAddress(const linkedList &L, address nodeCari) {
    address P = L.first;
    while (P != nullptr) {
        if (P == nodeCari)
            return true;
        P = P->next;
    }
    return false;
}

void SearchByRange(const linkedList &L, int nilaiMin) {
    address P = L.first;
    int posisi = 1;
    bool found = false;

    cout << "Data > " << nilaiMin << ": ";

    while (P != nullptr) {
        if (P->angka > nilaiMin) {
            if (found) cout << ", ";
            cout << P->angka << " (posisi ke-" << posisi << ")";
            found = true;
        }
        P = P->next;
        posisi++;
    }

    if (!found)
        cout << "(tidak ada data lebih besar dari " << nilaiMin << ")";
    cout << endl;
}

void operasiAritmatika(const linkedList &L) {
    if (L.first == nullptr) {
        cout << "List kosong. Tidak dapat melakukan operasi aritmetika." << endl;
        return;
    }

    address P = L.first;
    int jumlah = 0;
    int kali = 1;
    int kurang = P->angka;

    bool firstNode = true;
    while (P != nullptr) {
        jumlah += P->angka;
        kali *= P->angka;
        if (!firstNode)
            kurang -= P->angka;
        firstNode = false;
        P = P->next;
    }

    cout << "Hasil Penjumlahan = " << jumlah << endl;
    cout << "Hasil Pengurangan = " << kurang << endl;
    cout << "Hasil Perkalian   = " << kali << endl;
}
```

#### 3. main.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA); 
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC); 
    insertLast(L, nodeE); 
    insertFirst(L, nodeF); 

    address nodeHapus = nullptr;
    delAfter(L, nodeHapus, nodeC);

    printList(L);

    updateFirst(L);
    updateAfter(L, nodeD, "25");
    updateLast(L);
    updateAfter(L, L.first, "50");

    printList(L);

    cout << endl << "Search Data: " << endl;

    address hasil = SearchByData(L, 20);
    if (hasil != nullptr)
        cout << "Data 20 ditemukan di alamat " << hasil << endl;
    else
        cout << "Data 20 tidak ditemukan" << endl;
    cout << endl;

    hasil = SearchByData(L, 55);
    if (hasil != nullptr)
        cout << "Node data 55 ditemukan di alamat " << hasil << endl;
    else
        cout << "Node dengan data 55 tidak ditemukan" << endl;
    cout << endl;

    cout << "Mencari data alamat " << nodeB << endl;
    if (SearchByAddress(L, nodeB))
        cout << "Alamat " << nodeB << " ditemukan dengan data " << nodeB->angka << endl;
    else
        cout << "Alamat " << nodeB << " tidak ditemukan" << endl;
    cout << endl;

    cout << "Mencari data alamat " << nodeA << endl;
    if (SearchByAddress(L, nodeA))
        cout << "Alamat " << nodeA << " ditemukan dengan data " << nodeA->angka << endl;
    else
        cout << "Alamat " << nodeA << " tidak ditemukan" << endl;
    cout << endl;

    cout << "Mencari data diatas nilai 40" << endl;
    SearchByRange(L, 40);
    cout << endl;

    cout << "OPERASI ARITMETIKA" << endl;
    operasiAritmatika(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](Github file)

penjelasan unguided 1 
Program ini akan memasukan list angka program akan meminta input angka untuk di update, lalu program akan menampilkan list yang sudah di update, program akan mencari node dan menampilkan jika ketemu alamatnya apa, program akan menampilkan list yang mempunya range angka lebih besar dari 40, program akan melakukan operasi aritmatika pada list tersebut.

## Kesimpulan
Dari pertemuan minggu ketiga ini, mahasiswa diajarkan tentang Single Linked List (lanjutan), melanjutkan modul 4, mahasiswa diajarkan cara update data pada list dan melakukan sesuatu pada list tersebut.

## Referensi
[1] Rumah Coding (2025). "Linked List: Pengertian dan Implementasi Dasar". Diakses pada 18 Oktober 2025 melalui https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/. 
<br>
