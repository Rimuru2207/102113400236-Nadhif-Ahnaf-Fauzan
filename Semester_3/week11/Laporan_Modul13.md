# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Multi-Linked List adalah varian dari linked list di mana tiap node bisa memiliki lebih dari satu pointer ke node-node lain — tidak hanya “next” seperti singly linked list, atau “next + prev” seperti doubly linked list — melainkan bisa N pointer[1].

### A. Materi Minggu 13<br/>
Pada minggu 13 mahasiswa diajarkan lebih lanjut tentang Multi Linked List.

#### 1. Multi Linked List
Sebuah node pada multi-linked list umumnya terdiri dari: data + satu koleksi pointer/reference ke node-node lain. Contohnya bisa berupa array atau vector pointer. Dalam implementasi yang lebih spesifik, misalnya untuk representasi matriks jarang (sparse matrix), sebuah node bisa menyimpan data + pointer ke “next row” dan “next column” + informasi koordinat (row, column)[1].


## Guided 1
 
### 1. MLL 1

#### 1. mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan
{
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan
{
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild
{
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent
{
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk
{
    NodeParent first;
    NodeParent last;
};

// isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

// alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

// operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

// operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

// operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

// operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

#### 2. mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

// isEmpty & create list
bool isEmptyInduk(listInduk LInduk)
{
    if (LInduk.first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak)
{
    if (LAnak.first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListInduk(listInduk &LInduk)
{
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak)
{
    LAnak.first = LAnak.last = NULL;
}

// alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori)
{
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga)
{
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak)
{
    if (nodeAnak != NULL)
    {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk)
{
    if (nodeInduk != NULL)
    {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

// operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent)
{
    if (isEmptyInduk(LInduk) == true)
    {
        LInduk.first = LInduk.last = nodeBaruParent;
    }
    else
    {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent)
{
    if (isEmptyInduk(LInduk) == true)
    {
        LInduk.first = LInduk.last = nodeBaruParent;
    }
    else
    {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent)
{
    if (nodePrevParent == NULL)
    {
        cout << "Node Prev Parent tidak valid!" << endl;
    }
    else
    {
        if (nodePrevParent == LInduk.last)
        {
            insertLastParent(LInduk, nodeBaruParent);
            return;
        }
        else
        {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent " << nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last)
        { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        }
        else
        {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if (nodeHapus->L_Anak.first != NULL)
        {
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last)
        {
            LInduk.first = NULL;
            LInduk.last = NULL;
        }
        else
        {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if (nodeHapus->L_Anak.first != NULL)
        {
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        if (nodePrev != NULL && nodePrev->next != NULL)
        {
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL)
            {
                (nodeHapus->next)->prev = nodePrev;
            }
            else
            {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Anak.first != NULL)
            {
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        }
        else
        {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while (nodeBantu != NULL)
        {
            if (nodeBantu->isidata.idKategori == IDCari)
            {
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            }
            else
            {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if (!ketemu)
        {
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL)
        {
            if (nodeBantu->isidata.idKategori == IDCari)
            {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break;
            }
            else
            {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu)
        {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

// operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild)
{
    if (isEmptyAnak(LAnak))
    {
        LAnak.first = LAnak.last = nodeBaruChild;
    }
    else
    {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild)
{
    if (isEmptyAnak(LAnak))
    {
        LAnak.first = LAnak.last = nodeBaruChild;
    }
    else
    {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild)
{
    if (nodePrevChild == NULL)
    {
        cout << "Node Prev Parent tidak valid!" << endl;
    }
    else
    {
        if (nodePrevChild == LAnak.last)
        {
            insertLastChild(LAnak, nodeBaruChild);
            return;
        }
        else
        {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child " << nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List anak kosong!" << endl;
    }
    else
    {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last)
        { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        }
        else
        {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List anak kosong!" << endl;
    }
    else
    {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last)
        {
            LAnak.first = NULL;
            LAnak.last = NULL;
        }
        else
        {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        if (nodePrev != NULL && nodePrev->next != NULL)
        {
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL)
            {
                (nodeHapus->next)->prev = nodePrev;
            }
            else
            {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        }
        else
        {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while (nodeBantuParent != NULL)
        {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while (nodeBantuChild != NULL)
            {
                if (nodeBantuChild->isidata.idMakanan == IDCari)
                {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                }
                else
                {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if (ketemu)
            {
                break;
            }
            else
            {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if (!ketemu)
        {
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL)
        {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL)
            {
                if (nodeBantuChild->isidata.idMakanan == IDCari)
                {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                }
                else
                {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu)
            {
                break; // Break loop parent jika sudah ketemu di dalam
            }
            else
            {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu)
        {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

// operasi print
void printStrukturMLL(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk))
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while (nodeBantuParent != NULL)
        {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            // print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if (nodeBantuChild == NULL)
            {
                cout << "  (tidak ada child)" << endl;
            }
            else
            {
                int indexChild = 1;
                while (nodeBantuChild != NULL)
                {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk))
    {
        cout << "List induk Kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while (nodeBantuParent != NULL)
        {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk)
{
    if (isEmptyInduk(LInduk) == true || nodeInduk == NULL)
    {
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    }
    else
    {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if (nodeBantuChild == NULL)
        {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        }
        else
        {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while (nodeBantuChild != NULL)
            {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

// operasi hapus list
void hapusListInduk(listInduk &LInduk)
{
    NodeParent nodeBantu = LInduk.first;
    while (nodeBantu != NULL)
    {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        // panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak)
{
    NodeChild nodeBantu = LAnak.first;
    while (nodeBantu != NULL)
    {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

#### 3. main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main()
{
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl
         << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);

    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu

    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);

    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01"); // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99"); // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;

    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;

    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;

    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak);

    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L);

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
penjelasan singkat guided 1
    Program ini mengelola Multi Linked List yang terdiri dari parent (induk) dan child (anak), di mana setiap parent dapat memiliki banyak child. Program menyediakan fungsi untuk membuat list, mengecek apakah list kosong, serta alokasi dan dealokasi node. Terdapat operasi lengkap untuk parent dan child, seperti menambah, menghapus, mencari, dan mengubah data. Setiap penghapusan parent otomatis menghapus semua child di dalamnya. Program juga menyediakan fungsi untuk menampilkan struktur list, baik seluruh parent beserta anak-anaknya maupun list tertentu saja. Secara singkat, kode ini merupakan implementasi CRUD penuh untuk multi linked list berbasis doubly linked list.

## Unguided 

### Soal unguided no 1
1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
Type Struct golonganHewan <
idGolongan : String
namaGolongan : String
>
Type Struct dataHewan <
idHewan : String
namaHewan : String
habitat : String
ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
bobot : float //dalam kg
>
typedef struct nodeParent *NodeParent; //alias pointer ke struct
nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct
nodeChild

Type Struct nodeChild <
isidata : dataHewan
next : NodeChild
prev : NodeChild
>
Type Struct listChild <
first : NodeChild
last : NodeChild
>
Type Struct nodeParent <
isidata : golonganHewan
next : NodeParent
prev : NodeParent
L_Child : listChild
>
Type Struct listParent <
first : NodeParent
last : NodeParent
>
Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat :
String, tail : Boolean, weight : float) : NodeChild
Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)
Procedure insertFirstParent(input/output LParent : listParent, newNParent :
NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent :
NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev :
NodeParent)
Procedure insertFirstChild(input/output LChild : listChild, newNChild :
NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild :
NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)
Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)

Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk
dari multi linked listnya seperti ini :
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/soal1a.png)

Keterangan isi data setiap node :
❖ List Parent :
1) idGolongan : G001
namaGolongan : Aves
2) idGolongan : G002
namaGolongan : Mamalia
3) idGolongan : G003
namaGolongan : Pisces
4) idGolongan : G004
namaGolongan : Amfibi
5) idGolongan : G005
namaGolongan : Reptil
❖ List Child G001 :
1) idHewan : AV001
namaHewan : Cendrawasih
habitat : Hutan
ekor : True
bobot : 0,3
2) idHewan : AV002
namaHewan : Bebek
habitat : Air
ekor : True
bobot : 2
❖ List Child G002 :
1) idHewan : M001
namaHewan : Harimau
habitat : Hutan
ekor : True
bobot : 200
2) idHewan : M003
namaHewan : Gorila
habitat : Hutan
ekor : False
bobot : 160
3) idHewan : M002
namaHewan : Kucing
habitat : Darat
ekor : True
bobot : 4
❖ List Child G004 :
1) idHewan : AM001
namaHewan : Kodok
habitat : Sawah
ekor : False
bobot : 0,2

Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur
printMLLStructure().
(Lampirkan screenshot output hasil print pada laporan)
Ekspektasi output :
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/1b.png)

2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

Ekspektasi output :
![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/soal2.png)

3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :

![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/soal3a.png)

(Lampirkan screenshot output hasil print setelah dilakukan delete pada laporan).
Ekspektasi output :

![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/soal3b.png)


#### 1. MultiLL.h

```C++
#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNode);
void insertLastParent(listParent &LParent, NodeParent newNode);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNode);
void insertLastChild(listChild &LChild, NodeChild newNode);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);

void searchHewanByEkor(listParent LParent, bool tail);

#endif
```

#### 2. MultiLL.cpp

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NP = new nodeParent;
    NP->isidata.idGolongan = idGol;
    NP->isidata.namaGolongan = namaGol;
    NP->next = NULL;
    NP->prev = NULL;
    createListChild(NP->L_Child);
    return NP;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NC = new nodeChild;
    NC->isidata.idHewan = idHwn;
    NC->isidata.namaHewan = namaHwn;
    NC->isidata.habitat = habitat;
    NC->isidata.ekor = tail;
    NC->isidata.bobot = weight;
    NC->next = NULL;
    NC->prev = NULL;
    return NC;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNode;
        LParent.last = newNode;
    } else {
        newNode->next = LParent.first;
        LParent.first->prev = newNode;
        LParent.first = newNode;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNode);
    } else {
        LParent.last->next = newNode;
        newNode->prev = LParent.last;
        LParent.last = newNode;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = LParent.last = NULL;
        } else {
            LParent.first = del->next;
            LParent.first->prev = NULL;
        }
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    NodeParent del = NPrev->next;
    if (del != NULL) {
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNode;
    } else {
        newNode->next = LChild.first;
        LChild.first->prev = newNode;
        LChild.first = newNode;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNode);
    } else {
        LChild.last->next = newNode;
        newNode->prev = LChild.last;
        LChild.last = newNode;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = LChild.last = NULL;
        } else {
            LChild.first = del->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    NodeChild del = NPrev->next;
    if (del != NULL) {
        NPrev->next = del->next;
        if (del->next != NULL) {
            del->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent P = LParent.first;
    int parentNum = 1;

    while (P != NULL) {
        cout << "== Parent " << parentNum << " ==\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << P->isidata.namaGolongan << "\n";

        NodeChild C = P->L_Child.first;
        int childNum = 1;

        if (C == NULL) {
            cout << "(Tidak ada child)\n";
        } else {
            while (C != NULL) {
                cout << "   - Child " << childNum << " :\n";
                cout << "        ID Hewan   : " << C->isidata.idHewan << "\n";
                cout << "        Nama Hewan : " << C->isidata.namaHewan << "\n";
                cout << "        Habitat    : " << C->isidata.habitat << "\n";
                cout << "        Ekor       : " << (C->isidata.ekor ? 1 : 0) << "\n";
                cout << "        Bobot      : " << C->isidata.bobot << "\n";

                C = C->next;
                childNum++;
            }
        }
        cout << "-----------------------------\n";
        P = P->next;
        parentNum++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent P = LParent.first;
    int parentPos = 1;

    while (P != NULL) {
        NodeChild C = P->L_Child.first;
        int childPos = 1;

        while (C != NULL) {
            if (C->isidata.ekor == tail) {

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << childPos << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "---------------------------\n\n";

                cout << "--- Data Parent ---\n";
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "---------------------------\n\n";
            }

            C = C->next;
            childPos++;
        }

        P = P->next;
        parentPos++;
    }
}
```

#### 3. main.cpp

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/output1a.png)
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/output1b.png)

#### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/output2.png)

#### Output 3
![Screenshot Output Unguided 1_3](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/output3a.png)
![Screenshot Output Unguided 1_3](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week11/output3b.png)

penjelasan singkat unguided 1
    Kode ini mengimplementasikan Multi Linked List yang berisi parent (golongan hewan) dan child (hewan). Tersedia fungsi untuk mengecek list kosong, membuat list baru, mengalokasikan dan menghapus node parent maupun child. Operasi insert dan delete dibuat untuk menambah atau menghapus node di awal, akhir, atau setelah node tertentu, sambil menjaga pointer next dan prev agar struktur doubly linked list tetap benar. Fungsi printMLLStructure menampilkan seluruh parent beserta daftar child-nya dengan format terurut. Sementara itu, searchHewanByEkor mencari semua hewan berdasarkan nilai ekornya (TRUE/FALSE) lalu menampilkan detail child serta posisi parent dan child dalam list. Secara ringkas, kode ini menyediakan operasi dasar CRUD untuk multi linked list dua tingkat.

## Kesimpulan
Dari pertemuan minggu ke-13 ini, mahasiswa diajarkan tentang Multi Linked List, pengenalan contoh Multi Linked List dan cara membuatnya.

## Referensi
[1] geeksforgeeks (2025). "Introduction to Multi Linked List". diakses pada tanggal 6 Desember 2025 melalui https://www.geeksforgeeks.org/dsa/introduction-to-multi-linked-list/.  
<br>
