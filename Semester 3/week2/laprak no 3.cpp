#include <iostream>
using namespace std;

int cariMin(int arr[], int n) {
    int minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int cariMax(int arr[], int n) {
    int maximum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

void hitungRataRata(int arr[], int n) {
    float jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    cout << "Rata-rata: " << jumlah / n << endl;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanArray(arrA, n); break;
            case 2: cout << "Nilai maksimum: " << cariMax(arrA, n) << endl; break;
            case 3: cout << "Nilai minimum: " << cariMin(arrA, n) << endl; break;
            case 4: hitungRataRata(arrA, n); break;
            case 5: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);
    return 0;
}