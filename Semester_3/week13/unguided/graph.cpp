#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
G.first = NULL;
}

adrNode NewNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}


void InsertNode(Graph &G, infoGraph x) {
    adrNode P = NewNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}


adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return NULL;
}


void Connect(Graph &G, adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->to = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;


    adrEdge E2 = new ElmEdge;
    E2->to = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->to->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) {
        return;
    }
    cout << N->info << " ";
    N->visited = 1;


    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->to);
        E = E->next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);


    while (!Q.empty()) {
        adrNode P = Q.front(); Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->to->visited == 0) {
                E->to->visited = 1;
                Q.push(E->to);
            }
            E = E->next;
        }
    }
}

void ResetVisit(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}