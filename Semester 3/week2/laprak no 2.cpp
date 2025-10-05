#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 22, y = 7, z = 6;

    cout << "Sebelum tukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << endl;

    tukarPointer(&x, &y, &z);
    cout << "Setelah tukar (pointer): x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << endl;
    tukarReference(x, y, z);
    cout << "Setelah tukar (reference): x=" << x << ", y=" << y << ", z=" << z << endl;

    return 0;
}