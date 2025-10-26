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