#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NULL;
    NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NULL;
    NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNode;
        LParent.last = newNode;
    } else {
        newNode->next = LParent.first;
        LParent.first->prev = newNode;
        LParent.first = newNode;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNode);
    } else {
        LParent.last->next = newNode;
        newNode->prev = LParent.last;
        LParent.last = newNode;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = NULL;
        } else {
            LParent.first = del->next;
            LParent.first->prev = NULL;
        }
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    NodeParent del = NPrev->next;
    if (del != NULL) {
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNode;
    } else {
        newNode->next = LChild.first;
        LChild.first->prev = newNode;
        LChild.first = newNode;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNode);
    } else {
        LChild.last->next = newNode;
        newNode->prev = LChild.last;
        LChild.last = newNode;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = NULL;
        } else {
            LChild.first = del->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    NodeChild del = NPrev->next;
    if (del != NULL) {
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int parentNum = 1;

    while (P != NULL) {
        cout << "== Parent " << parentNum << " ==\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        NodeChild C = P->L_Child.first;
        int childNum = 1;

        if (C == NULL) {
            cout << "(Tidak ada child)\n";
        } else {
            while (C != NULL) {
                cout << "   - Child " << childNum << " :\n";
                cout << "        ID Hewan   : " << C->isidata.idHewan << "\n";
                cout << "        Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "        Habitat    : " << C->isidata.habitat << "\n";
                cout << "        Ekor       : " << (C->isidata.ekor ? 1 : 0) << "\n";
                cout << "        Bobot      : " << C->isidata.bobot << "\n";

                C = C->next;
                childNum++;
            }
        }
        cout << "-----------------------------\n";
        P = P->next;
        parentNum++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int parentPos = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childPos = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << childPos << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "---------------------------\n\n";

                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "---------------------------\n\n";
            }

            C = C->next;
            childPos++;
        }

        P = P->next;
        parentPos++;
    }
}