# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Queue adalah struktur data yang mengakses data secara FIFO (yang awal datang, yang awal diproses)[1].

### A. Materi Minggu Ketiga<br/>
Pada minggu ke-8 ini mahasiswa diajarkan tentang queue

#### 1. queue
Queue ini hampir sama seperti stack tetapi queue menggunakan prinsip FIFO(First In First Out), queue bisa menggunakan linked list dan Array, queue memiliki 2 operasi yaitu enqueue dan dequeue, enqueue adalah proses menambah sebuah data kedalam list queue, lalu dequeue adalah proses untuk menghapus sebuah data dari list queue tersebut.


## Guided 1
 
### 1. queue 1

#### 1. queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

#### 2. queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q)
{
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q)
{
    return Q.head == nullptr;
}

bool isFull(queue)
{
    return false;
}

void enQueue(queue &Q, const string &nama)
{
    Node *baru = new Node{nama, nullptr};
    if (isEmpty(Q))
    {
        Q.head = Q.tail = baru;
    }
    else
    {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node *hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr)
    {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node *p = Q.head; p != nullptr; p = p->next)
    {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q)
{
    while (!isEmpty(Q))
    {
        deQueue(Q);
    }
}
```

#### 3. main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    
    return 0;
}
```
penjelasan singkat guided 1
    program ini akan menambah beberapa anak kedalam queue, lalu menampilkan isi queue setelah selesai, program akan menghapus beberapa anak lalu menampilkan queue setelah di update, lalu program akan menghapus sisa queue tersebut.

## Guided 2
 
### 2. queue 2

#### 1. queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

#### 2. queue.cpp
```C++
#include "queue.h"

#include <iostream>
using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

#### 3. main.cpp
```C++
#include "queue.h"

#include <iostream>
using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
    
}
```
penjelasan singkat guided 2
    program ini hampir mirip dengan program sebelumnya, tetapi program ini memiliki beberapa kondisi khusus, yaitu ada alternatif 1 2 dan 3. Alternatif 1: head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam), Alternatif 2: head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak), Alternatif 3 : head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head).

## Unguided 

### Soal unguided no 1
1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “queue.h”:

![](Github file)

Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”

Pseudo dan Outputnya:
![](File Gambar)

2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).


3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);

void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);

void printInfo(Queue Q);

#endif
```

#### 2. queue.cpp

```C++
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

/* No 2 : Linear Queue — head & tail bergerak

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

*/

/* No. 3 : Circular Queue — head & tail berputar

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
```

#### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T\t| Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](Github file)

#### Output 2
![Screenshot Output Unguided 1_2](Github file)

#### Output 3
![Screenshot Output Unguided 1_3](Github file)

penjelasan unguided 1 
Program ini mengimplementasikan struktur data Queue berbasis array berukuran 5 menggunakan indeks head dan tail untuk menandai elemen pertama dan terakhir. Pada awalnya kedua indeks bernilai –1 sebagai penanda queue kosong. File queue.h mendefinisikan struktur dan fungsi, sedangkan queue.cpp berisi implementasi operasi seperti enqueue yang menambahkan data ke posisi tail, dequeue yang mengambil data dari head lalu menggeser elemen ke kiri, serta fungsi pengecekan kondisi kosong/penuh dan printInfo untuk menampilkan isi queue. File main.cpp menjalankan beberapa operasi enqueue dan dequeue, kemudian menampilkan perubahan head, tail, dan isi queue setelah setiap langkah sehingga menunjukkan bagaimana queue bekerja mengikuti prinsip FIFO (First In First Out).

## Kesimpulan
Dari pertemuan minggu ke-8 ini, mahasiswa diajarkan tentang queue, pengenalan contoh queue dan cara membuatnya.

## Referensi
[1] Rachmat Selamet. (2016). IMPLEMENTASI STRUKTUR DATA LIST, QUEUE DAN STACK DALAM JAVA. 15(3), 18-20. melalui https://www.academia.edu/download/87054128/112016_03_Rachmat.pdf pada 15 November 2025.
<br>
