# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Nadhif Ahnaf Fauzan - 103112400236</p>

## Dasar Teori
Binary Search Tree (BST) adalah salah satu struktur data berbasis pohon yang paling umum digunakan untuk melakukan penyimpanan dan pencarian data secara efisien. BST termasuk dalam kategori binary tree, yaitu struktur pohon yang setiap nodenya memiliki maksimal dua child: left dan right[1].

### A. Materi Minggu 10<br/>
pada minggu 10 ini mahasiswa diajarkan tentang BST(binary search tree).

#### 1. Tree
Tree termasuk dalam kategori binary tree, yaitu struktur pohon yang setiap nodenya memiliki maksimal dua child: left dan right[1]. Keunikan utama BST adalah aturan penyimpanan datanya. Pada setiap node, data yang berada di subtree kiri selalu bernilai lebih kecil dari nilai nodenya, sedangkan data di subtree kanan bernilai lebih besar. Sifat inilah yang menjadikan proses pencarian, penyisipan, maupun penghapusan pada BST dapat dilakukan lebih cepat bila dibandingkan dengan struktur data linear seperti array atau linked list[2]. BST banyak digunakan pada implementasi nyata seperti pengelolaan data penduduk, penyimpanan data berurutan, pembuatan indeks, serta komponen penting dalam struktur data yang lebih kompleks seperti AVL Tree dan Red-Black Tree. Traversal seperti InOrder, PreOrder, dan PostOrder digunakan untuk membaca isi tree dalam pola tertentu; traversal InOrder khususnya menghasilkan urutan data yang terurut naik[3].


## Guided 1
 
### 1. queue 1

#### 1. queue.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

#### 2. queue.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

#### 3. main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
penjelasan singkat guided 1
    program ini  mengimplementasikan struktur data Binary Search Tree (BST) lengkap dengan operasi dasar seperti insert, delete, search, traversal (preorder, inorder, postorder), penghitungan ukuran (size), tinggi tree (height), pencarian node paling kiri/kanan, serta menghapus seluruh tree. File bst.h mendefinisikan struktur node BST dan fungsi-fungsinya, sedangkan bst.cpp berisi implementasi detail setiap operasi, termasuk cara memasukkan node baru sesuai aturan BST, mencari data beserta parent dan sibling-nya, menghapus node dengan empat kemungkinan kasus (leaf, satu anak kiri, satu anak kanan, dua anak), traversal rekursif, menghitung jumlah node, dan tinggi tree secara rekursif. Pada main.cpp, program menyediakan menu interaktif yang memungkinkan pengguna melakukan semua operasi tersebut secara langsung, mulai dari menambahkan node, menghapus node, mencari data, menampilkan traversal, hingga menghapus seluruh tree. Program berjalan dalam loop sampai pengguna memilih opsi keluar.

## Unguided 

### Soal unguided no 1
1. ![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/soal1.png)

2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/soal2.png)

3. ![](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/soal3.png)

#### 1. bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

void preOrder(address root);
void postOrder(address root);

#endif
```

#### 2. bstree.cpp

```C++
#include "bstree.h"

#include <iostream>
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL) return NULL;
    if (x == root->info) return root;
    if (x < root->info) return findNode(x, root->left);
    return findNode(x, root->right);
}

void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

//nomor 2

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info +
           hitungTotalInfo(root->left) +
           hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL) return 0;
    int L = hitungKedalaman(root->left);
    int R = hitungKedalaman(root->right);
    return 1 + max(L, R);
}

//nomor 3

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}
```

#### 3. main.cpp

```C++
#include "bstree.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);

    cout << "\n" << endl;

    cout << "kedalaman : " << hitungKedalaman(root) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    cout << "\nPreOrder : ";
    preOrder(root);

    cout << "\nPostOrder: ";
    postOrder(root);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/output1.png)

#### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/output2.png)

#### Output 3
![Screenshot Output Unguided 1_3](https://github.com/Rimuru2207/102113400236-Nadhif-Ahnaf-Fauzan/blob/main/Semester_3/week10/output3.png)

penjelasan singkat unguided 1
    Program ini membuat Binary Search Tree (BST), memasukkan beberapa angka ke dalamnya, lalu menampilkan hasilnya dengan berbagai traversal (InOrder, PreOrder, PostOrder). Program juga menghitung kedalaman tree, jumlah node, dan total nilai semua node. Semua fungsi untuk mengolah BST—seperti insert, cari, hitung, dan traversal—diimplementasikan di bstree.cpp, sedangkan main.cpp hanya memanggil fungsi-fungsi tersebut untuk menunjukkan cara kerja BST.

## Kesimpulan
Dari pertemuan minggu ke-10 ini, mahasiswa diajarkan tentang tree, pengenalan contoh tree dan cara membuatnya.

## Referensi
[1] Malau, et al. "Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk". 3(2), 87. diambil dari https://doi.org/10.54367/kakifikom.v3i2.1794. diakses pada 29 November 2025.
<br> [2] Agung Wijoyo, et al. "Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien". 2(2), 144-145. diambil dari https://jurnalmahasiswa.com/index.php/jriin/article/view/1264. diakses pada 29 November 2025.
