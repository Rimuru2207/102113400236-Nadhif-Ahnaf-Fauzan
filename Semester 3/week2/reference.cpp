#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}   

int main() {
    int a = 20, b = 30;
    int &ref = a;

    ref = a;

    cout << "nilai a : " << a << endl;
    cout << "alamat a : " << &a << endl;
    cout << "value stored in ref : " << ref << endl;
    cout << "value pointed to by ref : " << &ref << endl;

    ref = 50;
    cout << "\nsetelah ref = 50" << endl;
    cout << "nilai a : " << a << endl;
    cout << "nilai ref : " << ref << endl;

    tukar(&a, &b);
    cout << "after swapping, nilai a : " << a << " and nilai b : " << b << endl;
    return 0;
}