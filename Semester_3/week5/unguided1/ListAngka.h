#ifndef LISTANGKA_H
#include <string>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &P);
void printList(const linkedList &L);
void insertFirst(linkedList &L, address P);
void insertLast(linkedList &L, address P);
void insertAfter(linkedList &L, address P, address Prec);
void delAfter(linkedList &L, address &P, address Prec);

void updateFirst(linkedList &L);
void updateAfter(linkedList &L, address Prec, string nodeLabel);
void updateLast(linkedList &L);

address SearchByData(const linkedList &L, int data);
bool SearchByAddress(const linkedList &L, address nodeCari);
void SearchByRange(const linkedList &L, int nilaiMin);

void operasiAritmatika(const linkedList &L);

#endif