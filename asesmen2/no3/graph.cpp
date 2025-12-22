#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void createGraph(graphKota &G){
    G.first = NULL;
}

adrKota alokasiNode(adrKota &K, string namaKota){
    adrKota newKota = new elmKota;
    newKota->namaKota = namaKota;
    newKota->visited = 0;
    newKota->firstEdge = NULL;
    newKota->next = NULL;
    K = newKota;
    return newKota;
}

adrEdge alokasiEdge(adrEdge &E, adrKota kotaTujuan, int jarak){
    adrEdge newEdge = new elmEdge;
    newEdge->kotaTujuan = kotaTujuan;
    newEdge->jarak = jarak;
    newEdge->next = NULL;
    E = newEdge;
    return newEdge;
}

void insertNode(graphKota &G, adrKota K){
    if(G.first == NULL){
        G.first = K;
    } else {
        adrKota temp = G.first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = K;
    }
}

adrKota findNode(graphKota G, string namaKota, adrKota &K){
    adrKota temp = G.first;
    while(temp != NULL){
        if(temp->namaKota == namaKota){
            K = temp;
            return temp;
        }
        temp = temp->next;
    }
    K = NULL;
    return NULL;
}

void connectNode(adrKota K1, adrKota K2, int jarak){
    adrEdge newEdge;
    alokasiEdge(newEdge, K2, jarak);
    if(K1->firstEdge == NULL){
        K1->firstEdge = newEdge;
    } else {
        adrEdge temp = K1->firstEdge;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newEdge;
    }
}

void disconnectNode(adrKota K1, string namaKotaTujuan){
    adrEdge temp = K1->firstEdge;
    adrEdge prev = NULL;
    while(temp != NULL){
        if(temp->kotaTujuan->namaKota == namaKotaTujuan){
            if(prev == NULL){
                K1->firstEdge = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void deleteNode(graphKota &G, string namaKota){
    adrKota temp = G.first;
    adrKota prev = NULL;
    while(temp != NULL){
        if(temp->namaKota == namaKota){
            if(prev == NULL){
                G.first = temp->next;
            } else {
                prev->next = temp->next;
            }
            adrKota curr = G.first;
            while(curr != NULL){
                disconnectNode(curr, namaKota);
                curr = curr->next;
            }
            adrEdge edgeTemp = temp->firstEdge;
            while(edgeTemp != NULL){
                adrEdge toDelete = edgeTemp;
                edgeTemp = edgeTemp->next;
                delete toDelete;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printGraph(graphKota G){
    adrKota tempKota = G.first;
    while(tempKota != NULL){
        cout << "Kota: " << tempKota->namaKota << endl;
        adrEdge tempEdge = tempKota->firstEdge;
        while(tempEdge != NULL){
            cout << "Terhubung ke: " << tempEdge->kotaTujuan->namaKota << endl;
            cout << "dengan jarak " << tempEdge->jarak << endl;
            tempEdge = tempEdge->next;
        }
        tempKota = tempKota->next;
    }
}

void printBFS(graphKota G, string startKota){
    adrKota startNode;
    if(findNode(G, startKota, startNode) == NULL){
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }

    queue<adrKota> q;
    startNode->visited = 1;
    q.push(startNode);

    while(!q.empty()){
        adrKota current = q.front();
        q.pop();
        cout << "Mengunjungi Kota: " << current->namaKota << endl;

        adrEdge tempEdge = current->firstEdge;
        while(tempEdge != NULL){
            if(tempEdge->kotaTujuan->visited == 0){
                tempEdge->kotaTujuan->visited = 1;
                q.push(tempEdge->kotaTujuan);
            }
            tempEdge = tempEdge->next;
        }
    }

    adrKota resetNode = G.first;
    while(resetNode != NULL){
        resetNode->visited = 0;
        resetNode = resetNode->next;
    }
}

void printDFS(graphKota G, string startKota){
    adrKota startNode;
    if(findNode(G, startKota, startNode) == NULL){
        cout << "Kota tidak ditemukan!" << endl;
        return;
    }

    stack<adrKota> s;
    startNode->visited = 1;
    s.push(startNode);

    while(!s.empty()){
        adrKota current = s.top();
        s.pop();
        cout << "Mengunjungi Kota: " << current->namaKota << endl;

        adrEdge tempEdge = current->firstEdge;
        while(tempEdge != NULL){
            if(tempEdge->kotaTujuan->visited == 0){
                tempEdge->kotaTujuan->visited = 1;
                s.push(tempEdge->kotaTujuan);
            }
            tempEdge = tempEdge->next;
        }
    }

    adrKota resetNode = G.first;
    while(resetNode != NULL){
        resetNode->visited = 0;
        resetNode = resetNode->next;
    }
}

void resetVisited(graphKota G){
    adrKota temp = G.first;
    while(temp != NULL){
        temp->visited = 0;
        temp = temp->next;
    }
}