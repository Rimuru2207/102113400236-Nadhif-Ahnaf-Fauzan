#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore();
    cout << endl;

    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "Masukkan nomor polisi : ";
        getline(cin, x.nopol);

        if (isExist(L, x.nopol)) {
            cout << "Nomor polisi sudah terdaftar " << endl;
            i--;
            continue;
        }

        cout << "Masukkan warna kendaraan : ";
        getline(cin, x.warna);
        cout << "Masukkan tahun kendaraan : ";
        cin >> x.thnBuat;
        cin.ignore();
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);

    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    getline(cin, cariNopol);
    address Q = cariElm(L, cariNopol);

    if (Q != nullptr) {
        cout << "Nomor Polisi : " << Q->info.nopol << endl;
        cout << "Warna        : " << Q->info.warna << endl;
        cout << "Tahun        : " << Q->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    string hapusNopol;
    cout << " Masukkan Nomor Polisi yang akan dihapus : ";
    getline(cin, hapusNopol);
    address H = cariElm(L, hapusNopol);

    if (H != nullptr) {
        if (H == L.first) {
            deleteFirst(L, H);
        } else if (H == L.last) {
            deleteLast(L, H);
        } else {
            deleteAfter(H->prev, H);
        }
        dealokasi(H);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl;
    }

    printInfo(L);

    return 0;
}