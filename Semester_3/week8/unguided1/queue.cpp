#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

/* No. 1 : Linear Queue — head diam, tail bergerak
bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    int x = Q.info[Q.head];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << " - " << Q.tail << "\t| empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << "\t| ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
*/



bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << "\t| ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

/* No. 3 : Circular Queue 
bool isFull(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << "\t| ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
*/