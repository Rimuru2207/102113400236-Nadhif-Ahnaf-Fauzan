#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;


typedef char infoGraph;


typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;


struct ElmEdge {
adrNode to;
adrEdge next;
};


struct ElmNode {
infoGraph info;
int visited;
adrEdge firstEdge;
adrNode next;
};


struct Graph {
adrNode first;
};

void CreateGraph(Graph &G);
adrNode NewNode(infoGraph x);
void InsertNode(Graph &G, infoGraph x);
adrNode FindNode(Graph G, infoGraph x);
void Connect(Graph &G, adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);


void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);
void ResetVisit(Graph &G);

#endif