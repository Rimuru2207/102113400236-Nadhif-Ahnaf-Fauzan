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
    int *ptr;

    ptr = &a;

    cout << "nilai a : " << a << endl;
    cout << "alamat a : " << &a << endl;
    cout << "value stored in ptr : " << ptr << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "after swapping, nilai a : " << a << " and nilai b : " << b << endl;
    return 0;
}