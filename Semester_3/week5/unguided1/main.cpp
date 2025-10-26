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