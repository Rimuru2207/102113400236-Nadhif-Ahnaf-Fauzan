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
