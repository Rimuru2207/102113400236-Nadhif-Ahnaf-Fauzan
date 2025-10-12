#include <iostream>
#include "pelajaran.h"
using namespace std;

int main () {
    string namapel = "struktur data";
    string kodepel = "STD";
    Pelajaran pelajaran1 = create_Pelajaran(namapel, kodepel);
    tampil_Pelajaran(pelajaran1);
    return 0;
}