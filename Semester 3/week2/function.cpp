#include <iostream>
using namespace std;

int cariMaks(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0 ;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total Penjumlahan: " << totalJumlah << endl;

    int totalkali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalkali *= arr[i];
    }
    cout << "total Perkalian: " << totalkali << endl;

    
}

int main () {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran ; i++) {
        cout << "masukan urutan angka ke- " << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai Maksimum: " << cariMaks(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}