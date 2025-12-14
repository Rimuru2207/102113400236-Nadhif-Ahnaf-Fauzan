#include "graph.h"


int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');


    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');


    Connect(G, A, B);
    Connect(G, A, C);
    Connect(G, B, D);
    Connect(G, B, E);
    Connect(G, C, F);
    Connect(G, C, Gg);
    Connect(G, D, H);
    Connect(G, E, H);
    Connect(G, F, H);
    Connect(G, Gg, H);

    cout << "Representasi Adjacency List:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, A);

    ResetVisit(G);

    cout << "\nBFS dari A: ";
    PrintBFS(G, A);
    return 0;
}