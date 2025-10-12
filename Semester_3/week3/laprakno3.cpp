#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[N][N], int arr2[N][N], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *p1 = &A[0][0];
    int *p2 = &B[2][2];

    cout << "Array A sebelum ditukar: ";
    tampilArray(A);
    cout << "Array B sebelum ditukar: ";
    tampilArray(B);

    tukarElemen(A, B, 1, 1);

    cout << "Array A sesudah tukar elemen [1][1]: ";
    tampilArray(A);
    cout << "Array B sesudah tukar elemen [1][1]: ";
    tampilArray(B);

    cout << "Nilai sebelum tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Nilai sesudah tukar pointer: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}
