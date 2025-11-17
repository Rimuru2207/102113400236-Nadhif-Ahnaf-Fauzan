#include "sllinventory.h"

#include <iostream>
using namespace std;

int main () {

    list L;
    address P1, P2, P3;
    createList(L);

    P1 = alokasi("Pulpen", "A001", 20, 2500, 0);
    P2 = alokasi("Buku Tulis", "A002", 15, 5000, 10);
    P3 = alokasi("Penghapus", "A003", 30, 1500, 0);

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    viewList(L);

    deleteFirst(L,P1);

    viewList(L);

    updateAtPosition(L, P2, 1);
    viewList(L);

    searchByFinalPriceRange(L, 2000, 7000);
    return 0;
}