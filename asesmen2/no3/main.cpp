#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main () {
    graphKota G;
    createGraph(G);

    adrKota K1, K2, K3, K4, K5;
    alokasiNode(K1, "Jakarta");
    alokasiNode(K2, "Bogor");
    alokasiNode(K3, "Bekasi");
    alokasiNode(K4, "Depok");
    alokasiNode(K5, "Tangerang");

    insertNode(G, K1);
    connectNode(K1, K5, 24);
    connectNode(K1, K4, 21);
    connectNode(K1, K3, 16);
    connectNode(K1, K2, 42);

    insertNode(G, K2);
    
    connectNode(K2, K3, 60);
    connectNode(K2, K4, 22);
    connectNode(K2, K1, 42);

    
    insertNode(G, K4);
    connectNode(K4, K3, 25);
    connectNode(K4, K5, 30);
    connectNode(K4, K2, 22);
    connectNode(K4, K1, 21);

  
    insertNode(G, K5);
    connectNode(K5, K4, 25);
    connectNode(K5, K3, 45);
    connectNode(K5, K1, 24);

    insertNode(G, K3);
    connectNode(K3, K4, 25);
    connectNode(K3, K5, 45);
    connectNode(K3, K2, 60);
    connectNode(K3, K1, 16);

    printGraph(G);

    deleteNode(G, "Depok");

    printGraph(G);

    cout << "BFS Traversal starting from Jakarta:" << endl;
    printBFS(G, "Jakarta");

    cout << "\nDFS Traversal starting from Jakarta:" << endl;
    printDFS(G, "Jakarta");

    return 0;
}