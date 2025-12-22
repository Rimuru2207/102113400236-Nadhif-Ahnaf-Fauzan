#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef struct elmKota *adrKota;
typedef struct elmEdge *adrEdge;

struct elmKota {
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct elmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct graphKota {
    adrKota first;
};

void createGraph(graphKota &G);
adrKota alokasiNode(adrKota &K, string namaKota);
adrEdge alokasiEdge(adrEdge &E, adrKota kotaTujuan, int jarak);
void insertNode(graphKota &G, adrKota K);
adrKota findNode(graphKota G, string namaKota, adrKota &K);
void connectNode(adrKota K1, adrKota K2, int jarak);
void disconnectNode(adrKota K1, string namaKotaTujuan);
void deleteNode(graphKota &G, string namaKota);
void printGraph(graphKota G);
void resetVisited(graphKota G);
void printBFS(graphKota G, string startKota);
void printDFS(graphKota G, string startKota);

#endif