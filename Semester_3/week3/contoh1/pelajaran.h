#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_Pelajaran(string namaMapel, string kodeMapel);

void tampil_Pelajaran(Pelajaran pel);

#endif