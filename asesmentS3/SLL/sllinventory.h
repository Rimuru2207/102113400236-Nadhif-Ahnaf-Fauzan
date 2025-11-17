#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <iostream>
using namespace std;

struct produk{
    string nama;
    string SKU;
    int jumlah;
    float HargaSatuan;
    float DiskonPersen;  
};
typedef produk dataProduk;
typedef struct node *address;

struct node{
    dataProduk info;
    address next;
};

struct list{
    address head;
};

bool isEmpty(list &L);
void createList(list &L);
address alokasi(string nama, string SKU, int jumlah, float HargaSatuan, float DiskonPersen);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address P, address Q);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address &P, address Q);
void updateAtPosition(list &L, address P, int posisi);
void viewList(list L);
void searchByFinalPriceRange(list L, float minPrice, float maxPrice);

#endif