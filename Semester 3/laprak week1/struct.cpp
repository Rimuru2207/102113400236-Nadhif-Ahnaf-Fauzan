#include <iostream>
using namespace std;

int main () {
    const int jumlah = 5;
    struct rapot{
        char nama[5];
        int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++){
        cout <<"masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout <<"masukan nilai siswa : ";
        cin >> siswa[i].nilai;
    }
    int i = 0;
    while (i < jumlah){
        cout << "nama : " << siswa[i].nama << "nilai : " << siswa[i].nilai << endl;
        i++;
    }
    return 0;
}