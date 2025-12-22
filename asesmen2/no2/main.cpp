#include "mll.h"
#include <iostream>
using namespace std;

int main () {
    listParent P;
    createListParent(P);

    insertFirstParent(P, alokasiNodeParent({"G001", "Action"}));
    insertFirstParent(P, alokasiNodeParent({"G002", "Comedy"}));
    insertFirstParent(P, alokasiNodeParent({"G003", "Romance"}));
    insertFirstParent(P, alokasiNodeParent({"G004", "Horror"}));

    NodeParent G1 = P.first;   
    insertLastChild(G1->L_Child, alokasiNodeChild({"F001", "Fast & Furious", 130, 2009, 7.8}));

    NodeParent G2 = G1->next;
    insertLastChild(G2->L_Child, alokasiNodeChild({"F002", "The Bear", 100, 2022, 7.7}));
    insertLastChild(G2->L_Child, alokasiNodeChild({"F003", "Mr.Bean", 113, 1990, 7.6}));

    NodeParent G3 = G2->next;
    insertLastChild(G3->L_Child, alokasiNodeChild({"F004", "Your Name", 123, 2016, 7.8}));

    NodeParent G4 = G3->next;
    insertLastChild(G4->L_Child, alokasiNodeChild({"F005", "The Conjuring", 112, 2025, 7.5}));

    printStrukturMLL(P, P.first->L_Child);

    searchFilmByRating(P, 7.6);
}