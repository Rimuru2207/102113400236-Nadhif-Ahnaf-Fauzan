# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Graph merupakan satu bentuk graph yang dapat digunakan dalam membentuk sebuah struktur data yang saling berelasi namun memiliki karakteristik dengan dua jenis node yang berbeda seperti data hubungan keluarga atau data pohon keluarga.[1].

### A. Materi Minggu 13<br/>
pada minggu ke-13 kami diajarkan tentang Graph

#### 1. Graph
Struktur data graph adalah bentuk penyimpanan data yang digunakan untuk merepresentasikan hubungan antar elemen dalam bentuk grafis. Setiap elemen disebut simpul atau vertex, dan koneksi antara elemen disebut sisi atau edge[2].


## Guided 

### 1. Graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge
{
    adrNode Node;
    adrEdge Next;
};

struct Graph
{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode alokasiNode(infoGraph data);
adrEdge alokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode Node1, adrNode Node2);
void DeleteNode(Graph &G, infoGraph X);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```
    
### 2. Graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

// prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G)
{
    G.First = NULL;
}

// alokasi Node baru
adrNode AlokasiNode(infoGraph data)
{
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; // isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

// alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan)
{
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

// Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data)
{
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL)
    {
        G.First = nodeBaru;
    }
    else
    {
        // konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

// function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        if (nodeBantu->info == data)
        {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

// prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2)
{
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL)
    {
        // Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        // Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

// prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2)
{
    if (node1 != NULL && node2 != NULL)
    {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        // Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2)
        {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL)
        { // jika Edge ditemukan
            if (PrevE == NULL)
            {
                // Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            }
            else
            {
                // Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

// prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X)
{
    // 1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    // 2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    // cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL)
    {
        DisconnectNode(nodeLainnya, nodeHapus); // putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    // 3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    // Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL)
    {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    // 4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus)
    {
        // jika nodeHapus di awal
        G.First = nodeHapus->Next;
    }
    else
    {
        // jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    // 5. delete nodeHapus
    delete nodeHapus;
}

// Menampilkan isi Graph (Adjacency List)
void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            cout << edgeBantu->Node->info << " "; // Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

// Reset status visited sebelum traversal
void ResetVisited(Graph &G)
{
    adrNode nodeReset = G.First;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

// traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    queue<adrNode> Qyu;

    // Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty())
    {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        // Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            if (edgeBantu->Node->visited == 0)
            {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

// Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    stack<adrNode> Stak;

    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty())
    {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0)
        {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            // masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL)
            {
                if (edgeBantu->Node->visited == 0)
                {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // Hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ==" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL)
    {
        cout << "Node E berhasil terhapus" << endl;
    }
    else
    {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    return 0;
}
```
penjelasan singkat guided 1
    Program ini mengimplementasikan struktur data graph tak berarah (undirected graph) menggunakan adjacency list dalam bahasa C++. Graph direpresentasikan sebagai linked list node, di mana setiap node menyimpan data (info), penanda kunjungan (visited), pointer ke node berikutnya, dan pointer ke daftar edge yang menunjukkan hubungan dengan node lain. Program menyediakan fungsi untuk membuat graph, menambah dan mencari node, menghubungkan serta memutus hubungan antar node, menghapus node beserta seluruh edge yang terkait, dan menampilkan isi graph. Selain itu, program juga mengimplementasikan algoritma traversal BFS menggunakan queue dan DFS menggunakan stack, dengan mekanisme reset visited sebelum traversal untuk memastikan penelusuran berjalan dengan benar.


## Unguided 

### 1. Unguided 1
1. Soal no 1:

![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week13/soal1.png)
2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur: PrintDFS (Graph G, adrNode N);
3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur: PrintBFS (Graph G, adrNode N);

### 1. Graph.h

```C++
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
```

### 2. Graph.cpp

```C++
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
```

### 3. main.cpp
```C++
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
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week13/output1.png)


penjelasan unguided 1
    Program ini implementasi struktur data graph menggunakan adjacency list. Graph disusun sebagai linked list node, di mana setiap node menyimpan data (info), penanda kunjungan (visited), pointer ke node berikutnya, serta daftar edge yang menunjukkan hubungan ke node lain. Program menyediakan operasi dasar seperti membuat graph, menambah node, mencari node, menghubungkan dua node secara dua arah, dan menampilkan isi graph. Selain itu, program juga mengimplementasikan traversal DFS secara rekursif dan BFS menggunakan queue, dengan fungsi ResetVisit untuk mengatur ulang status kunjungan node agar traversal dapat dilakukan kembali dengan benar.

## Kesimpulan
Dari pertemuan minggu 13 mahasiswa diajarkan tentang Graph, contoh graph dan implementasinya.

## Referensi
[1] Ardiansyah (2020). "Traversal Struktur Data Bipartite Graph dalam Graph Database menggunakan Depth-First Search" 5(2). 141-144. diakses pada 14 Desember 2025 melalui https://doi.org/10.21831/elinvo.v5i2.28326
<br> [2] Telkom University (2025). "Mengenal Struktur Data Graph: Definisi dan Manfaat". diakses pada 14 Desember 2025 melalui https://bif.telkomuniversity.ac.id/mengenal-struktur-data-graph-definisi-dan-manfaat.
