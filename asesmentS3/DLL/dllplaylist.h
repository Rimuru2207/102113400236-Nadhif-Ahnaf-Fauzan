#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
using namespace std;

struct song{
    string title;
    string artist;
    int DurationSec;
    int PlayCount;
    float rating;
};

typedef song listSong;
typedef struct node *address;

struct node{
    song info;
    address prev;
    address next;
};

struct list{
    address head;
    address tail;
};

bool isEmpty(list L);
void createList(list &L);
address alokasi(string title, string artist, int DurationSec, int PlayCount, float rating);
void dealokasi(address &S);
void insertFirst(list &L, address S);
void insertLast(list &L, address S);
void insertAfter(list &L, address Q, address S);
void insertBefore(list &L, address Q, address S);
void deleteFirst(list &L, address &S);
void deleteLast(list &L, address &S);
void deleteAfter(list &L, address Q, address &S);
void deleteBefore(list &L, address Q, address &S);
void updateAtPosition(list L, address S, int posisi);
void updateBefore(list L, address Q);
void viewList(list L);
void searchByPopularityRange(list L, int minScore, int maxScore);

#endif