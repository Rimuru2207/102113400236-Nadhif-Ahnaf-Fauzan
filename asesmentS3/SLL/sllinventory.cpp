#include "sllinventory.h"

#include <iostream>
using namespace std;

bool isEmpty(list &L){
    if(L.head == NULL){
        return true; 
    } else {
        return false;
    }
}

void createList(list &L){
    L.head = NULL;
}

address alokasi(string nama, string SKU, int jumlah, float HargaSatuan, float DiskonPersen){
    address P = new node;
    P->info.nama = nama;
    P->info.SKU = SKU;
    P->info.jumlah = jumlah;
    P->info.HargaSatuan = HargaSatuan;
    P->info.DiskonPersen = DiskonPersen;
    P->next = NULL;
    return P;
}

void dealokasi(address &P){
    P->next = NULL;
    delete P;
}

void insertFirst(list &L, address P){
    if(isEmpty(L)) {
        L.head = P;
    } else {
        P->next = L.head;
        L.head = P;
    }
}

void insertLast(list &L, address P){
    if(isEmpty(L) == true) {
        L.head = P;
    } else {
        address nodeBantu = L.head;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu -> next;
        }
        nodeBantu->next = P;
    }
}

void insertAfter(list &L, address P, address Q){
    if(Q != NULL){
        P->next = Q->next;
        Q->next = P;
    }
}

void deleteFirst(list &L, address &P){
    address nodeHapus;
    if(isEmpty(L) == false){
        nodeHapus = L.head;
        L.head = L.head->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil dihapus." << endl;
    } else {}
        cout << "List kosong" << endl;
}

void deleteLast(list &L, address &P){
    address nodeHapus;
    if(isEmpty(L) == false){
        if(L.head->next == NULL){
            nodeHapus = L.head;
            L.head = NULL;
        } else {
            address nodeBantu = L.head;
            while (nodeBantu->next->next != NULL) {
                nodeBantu = nodeBantu -> next;
            }
            nodeHapus = nodeBantu->next;
            nodeBantu->next = NULL;
        }
        dealokasi(nodeHapus);
        cout << "Node terakhir berhasil dihapus." << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

void deleteAfter(list &L, address &P, address Q){
    address nodeHapus;
    if(isEmpty(L) == false && Q != NULL && Q->next != NULL){
        nodeHapus = Q->next;
        Q->next = nodeHapus->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
        cout << "Node setelah node " << Q->info.nama << " berhasil dihapus." << endl;
    } else {
        cout << "List kosong" << endl;
    }
}

void updateAtPosition(list &L, address P, int posisi){
    if(isEmpty(L) == true){

    cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update : " << endl;
        cout << "Nama : ";
        cin >> L.head->info.nama;
        cout << "SKU : ";
        cin >> L.head->info.SKU;
        cout << "Jumlah : ";
        cin >> L.head->info.jumlah;
        cout << "Harga : ";
        cin >> L.head->info.HargaSatuan;
        cout << "Diskon Persen : ";
        cin >> L.head->info.DiskonPersen;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void viewList(list L){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.head;
        int nomor = 1;
        while (nodeBantu != NULL) {
            cout << "Nama: " << nodeBantu->info.nama << endl;
            cout << "SKU: " << nodeBantu->info.SKU << endl;
            cout << "Jumlah: " << nodeBantu->info.jumlah << endl;
            cout << "Harga Satuan: " << nodeBantu->info.HargaSatuan << endl;
            cout << "Diskon Persen: " << nodeBantu->info.DiskonPersen << "%" << endl;
            nodeBantu = nodeBantu->next;
            nomor++;
        }
    }
}

void searchByFinalPriceRange(list L, float minPrice, float maxPrice){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.head;
        bool found = false;
        while (nodeBantu != NULL) {
            float finalPrice = nodeBantu->info.HargaSatuan * (1 - nodeBantu->info.DiskonPersen / 100);
            if(finalPrice >= minPrice && finalPrice <= maxPrice){
                cout << "Nama: " << nodeBantu->info.nama << endl;
                cout << "SKU: " << nodeBantu->info.SKU << endl;
                cout << "Jumlah: " << nodeBantu->info.jumlah << endl;
                cout << "Harga Satuan: " << nodeBantu->info.HargaSatuan << endl;
                cout << "Diskon Persen: " << nodeBantu->info.DiskonPersen << "%" << endl;
                cout << "Harga Akhir: " << finalPrice << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
    }
}