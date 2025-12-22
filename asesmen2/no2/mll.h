#ifndef MLL_H
#define MLL_H
#include <iostream>
using namespace std;

struct dataGenre{
    string idGenre;
    string namaGenre;
};

struct dataFilm{
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahumTayang;
    float ratingFilm;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataFilm film;
    NodeChild next;
    NodeParent parent;
};

struct listChild{
    NodeChild first;
    NodeChild last;  
};

struct nodeParent{
    dataGenre genre;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent alokasiNodeParent(dataGenre genre);
NodeChild alokasiNodeChild(dataFilm film);
void dealokasiNodeParent(NodeParent &P);
void dealokasiNodeChild(NodeChild &C);
void insertFirstParent(listParent &LParent, NodeParent P);
void insertLastChild(listChild &LChild, NodeChild C);
void deleteAfterParent(listParent &LParent, NodeParent prev);
void hapusListChild(listChild &LChild, NodeParent P);
void searchFilmByRating(listParent LParent, float rating);
void printStrukturMLL(listParent LParent, listChild LChild);

#endif