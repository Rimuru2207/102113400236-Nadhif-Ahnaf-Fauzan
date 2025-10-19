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
