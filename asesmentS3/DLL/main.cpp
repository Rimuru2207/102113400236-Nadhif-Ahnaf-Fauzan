#include "dllplaylist.h"
#include <iostream>
using namespace std;

int main () {

    list L;
    address S1, S2, S3, S4;
    createList(L);

    S1 = alokasi("Senja di kota", "Nona Band", 210, 150, 4.2);
    S2 = alokasi("Langkahmu", "Delta", 185, 320, 4.8);
    S3 = alokasi("Hujan Minggu", "Arka", 240, 90, 3.9);
    S4 =alokasi("Senandung", "Mira", 175, 120, 4.0);

    insertLast(L, S1);
    insertLast(L, S2);
    insertLast(L, S3);

    viewList(L);

    deleteLast(L, S3);

    updateAtPosition(L, S2, 1);

    viewList(L);

    insertBefore(L, S2, S4);

    viewList(L);

    updateBefore(L, S2);

    deleteBefore(L, S2, S3);

    searchByPopularityRange(L, 150.0, 300.0);
    
    return 0;
}