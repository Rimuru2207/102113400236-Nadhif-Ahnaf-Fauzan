#include "dllplaylist.h"
#include <iostream>
using namespace std;

bool isEmpty(list L){
    if (L.head == NULL && L.tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void createList(list &L){
    L.head = NULL;
    L.tail = NULL;
}

address alokasi(string title, string artist, int DurationSec, int PlayCount, float rating){
    address S = new node;
    S->info.title = title;
    S->info.artist = artist;
    S->info.DurationSec = DurationSec;
    S->info.PlayCount = PlayCount;
    S->info.rating = rating;
    S->prev = NULL;
    S->next = NULL;
    return S;
}

void delokasi(address &S){
    S->next = NULL;
    S->prev = NULL;
    delete S;
}

void insertFirst(list &L, address S){
    if (isEmpty(L)) {
        L.head = L.tail = S;
    } else {
        S->next = L.head;
        L.head->prev = S;
        L.head = S;
    }
}

void insertLast(list &L, address S){
    if (isEmpty(L) == true) {
        L.head = L.tail = S;
    } else {
        S->prev = L.tail;
        L.tail->next = S;
        L.tail = S;
    }
}

void insertAfter(list &L, address Q, address S){
    if (Q != NULL) {
        S->next = Q->next;
        S->prev = Q;
        if (Q->next != NULL) {
            Q->next->prev = S;
        } else {
            L.tail = S;
        }
        Q->next = S;
    }
}

void insertBefore(list &L, address Q, address S){
    if (Q != NULL) {
        S->prev = Q->prev;
        S->next = Q;
        if (Q->prev != NULL) {
            Q->prev->next = S;
        } else {
            L.head = S;
        }
        Q->prev = S;
    }
}

void deleteFirst(list &L, address &S){
    if (!isEmpty(L)) {
        S = L.head;
        if (L.head == L.tail) {
            L.head = L.tail = NULL;
        } else {
            L.head = L.head->next;
            L.head->prev = NULL;
        }
        S->next = NULL;
        S->prev = NULL;
    }
}

void deleteLast(list &L, address &S){
    if (!isEmpty(L)) {
        S = L.tail;
        if (L.head == L.tail) {
            L.head = L.tail = NULL;
        } else {
            L.tail = L.tail->prev;
            L.tail->next = NULL;
        }
        S->next = NULL;
        S->prev = NULL;
    }
}

void deleteAfter(list &L, address Q, address &S){
    if (Q != NULL && Q->next != NULL) {
        S = Q->next;
        Q->next = S->next;
        if (S->next != NULL) {
            S->next->prev = Q;
        } else {
            L.tail = Q;
        }
        S->next = NULL;
        S->prev = NULL;
    }
}

void deleteBefore(list &L, address Q, address &S){
    if (Q != NULL && Q->prev != NULL) {
        S = Q->prev;
        Q->prev = S->prev;
        if (S->prev != NULL) {
            S->prev->next = Q;
        } else {
            L.head = Q;
        }
        S->next = NULL;
        S->prev = NULL;
    }
}

void updateAtPosition(list L, address S, int posisi){
    address nodeBantu = L.head;
    int index = 0;
    while (nodeBantu != NULL && index < posisi) {
        nodeBantu = nodeBantu->next;
        index++;
    }
    if (nodeBantu != NULL) {
        cout << "Update Node " << posisi << ": " << endl;
        cout << "Title: ";
        cin >> nodeBantu->info.title;
        cout << "Artist: ";
        cin >> nodeBantu->info.artist;
        cout << "Durasi: ";
        cin >> nodeBantu->info.DurationSec;
        cout << "Play Count: ";
        cin >> nodeBantu->info.PlayCount;
        cout << "Rating: ";
        cin >> nodeBantu->info.rating;
    } else {
        cout << "Gak Valid" << endl;
    }
}

void updateBefore(list L, address Q){
    if (Q != NULL && Q->prev != NULL) {
        address S = Q->prev;
        cout << "Update Node Sebelum " << Q->info.title << ": " << endl;
        cout << "Title: ";
        cin >> S->info.title;
        cout << "Artist: ";
        cin >> S->info.artist;
        cout << "Durasi: ";
        cin >> S->info.DurationSec;
        cout << "Play Count: ";
        cin >> S->info.PlayCount;
        cout << "Rating: ";
        cin >> S->info.rating;
    } else {
        cout << "Gak Valid" << endl;
    }
}

void viewList(list L){
    address nodeBantu = L.head;
    while (nodeBantu != NULL) {
        cout << nodeBantu->info.title << "Dari " << nodeBantu->info.artist << endl;
        cout << "Durasi: " << nodeBantu->info.DurationSec << "Detik" << endl;
        cout << "Play Count: " << nodeBantu->info.PlayCount << endl;
        cout << "Rating: " << nodeBantu->info.rating << endl;
        nodeBantu = nodeBantu->next; 
    }
}

void searchByPopularityRange(list L, int minScore, int maxScore){
    address nodeBantu = L.head;
    bool found = false;
    while (nodeBantu != NULL) {
        if (nodeBantu->info.PlayCount >= minScore && nodeBantu->info.PlayCount <= maxScore) {
            cout << "Title: " << nodeBantu->info.title << ", Artist: " << nodeBantu->info.artist << ", Play Count: " << nodeBantu->info.PlayCount << endl;
            found = true;
        }
        nodeBantu = nodeBantu->next;
    }
}