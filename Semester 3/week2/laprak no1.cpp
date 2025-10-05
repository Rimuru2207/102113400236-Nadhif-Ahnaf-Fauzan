# include <iostream>
using namespace std;

void inputMatrix(int A[3][3]){
    cout << "Input matrix (3x3): " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> A[i][j];
        }
    }
}

void outputMatrix(int A[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void penjumlahanMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void penguranganMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalianMatrix(int A[3][3], int B[3][3], int C[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = 0;
            for (int k = 0; k < 3; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3];
    cout << "Input matriks A:" << endl;
    inputMatrix(A);
    cout << "Input matriks B:" << endl;
    inputMatrix(B);

    cout << "Hasil Penjumlahan:" << endl;
    penjumlahanMatrix(A, B, C);
    outputMatrix(C);

    cout << "Hasil Pengurangan:" << endl;
    penguranganMatrix(A, B, C);
    outputMatrix(C);

    cout << "Hasil Perkalian:" << endl;
    perkalianMatrix(A, B, C);
    outputMatrix(C);

    return 0;

}