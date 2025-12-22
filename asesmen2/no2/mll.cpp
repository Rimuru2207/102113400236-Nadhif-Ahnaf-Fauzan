#include "mll.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent){
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild){
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent){
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent alokasiNodeParent(dataGenre genre){
    NodeParent P = new nodeParent;
    P->genre = genre;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild alokasiNodeChild(dataFilm film){
    NodeChild C = new nodeChild;
    C->film = film;
    C->next = NULL;
    C->parent = NULL;
    return C;
}

void dealokasiNodeParent(NodeParent &P){
    delete P;
    P = NULL;
}

void dealokasiNodeChild(NodeChild &C){
    delete C;
    C = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent P){
    if(isEmptyParent(LParent)){
        LParent.first = P;
        LParent.last = P;
    } else {
        P->next = LParent.first;
        LParent.first = P;
    }
}

void insertLastChild(listChild &LChild, NodeChild C){
    if(isEmptyChild(LChild)){
        LChild.first = C;
        LChild.last = C;
    } else {
        LChild.last->next = C;
        LChild.last = C;
    }
}

void deleteAfterParent(listParent &LParent, NodeParent prev){
    if(prev != nullptr && prev->next != nullptr){
        NodeParent P = prev->next;
        prev->next = P->next;
        dealokasiNodeParent(P);
    }
}

void hapusListChild(listChild &LChild, NodeParent P){
    NodeChild C = LChild.first;
    NodeChild prevC = NULL;
    while(C != NULL){
        if(C->parent == P){
            if(prevC == NULL){
                LChild.first = C->next;
            } else {
                prevC->next = C->next;
            }
            NodeChild temp = C;
            C = C->next;
            dealokasiNodeChild(temp);
        } else {
            prevC = C;
            C = C->next;
        }
    }
}

void searchFilmByRating(listParent LParent, float rating){
    NodeParent P = LParent.first;
    while(P != NULL){
        NodeChild C = P->L_Child.first;
        while(C != NULL){
            if(C->film.ratingFilm >= rating){
                cout << "ID: " << C->film.idFilm << endl;
                cout << "Judul: " << C->film.judulFilm <<endl;
                cout << "Rating: " << C->film.ratingFilm << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}

void printStrukturMLL(listParent LParent, listChild LChild){
    NodeParent P = LParent.first;
    int parentNum = 1;

    while(P != NULL){
        cout << "Parent - " << parentNum << "\n";
        cout << "Genre ID: " << P->genre.idGenre << "\n";
        cout << "Genre Name: " << P->genre.namaGenre << "\n";
        
        NodeChild C = P->L_Child.first;
        int childNum = 1;
        
        if (C != NULL){
                
            cout << "Child - " << childNum << "\n";
            cout << "Film ID: " << C->film.idFilm << "\n";
            cout << "Judul: " << C->film.judulFilm << "\n";
            cout << "Durasi: " << C->film.durasiFilm << "\n";
            cout << "Tahun Tayang: " << C->film.tahumTayang << "\n";
            cout << "Rating: " << C->film.ratingFilm << "\n";

            C = C->next;
            childNum++;
        }
        P = P->next;
        parentNum++;
    }
}
