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