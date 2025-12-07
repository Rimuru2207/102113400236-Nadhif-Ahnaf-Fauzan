#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    NodeParent G1 = LP.first;
    insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent G2 = G1->next;
    insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent G4 = G2->next->next;
    insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);

    searchHewanByEkor(LP, false);

    cout << "\nDELETE G004\n";
    NodeParent cursor = LP.first;
    while (cursor != NULL && cursor->isidata.idGolongan != "G004") {
        cursor = cursor->next;
    }

    if (cursor != NULL) {
        if (cursor == LP.first)
            deleteFirstParent(LP);
        else
            deleteAfterParent(LP, cursor->prev);
    }

    cout << "\n=== SETELAH DELETE ===\n";
    printMLLStructure(LP);

    return 0;
}