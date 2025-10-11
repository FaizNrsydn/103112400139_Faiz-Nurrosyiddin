#include <iostream>
#include "mhs.h"
using namespace std;

void inputData(dataMhs &mhs){
    cout << "Nama: ";
    cin >> mhs.nama;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Nilai Tugas: ";
    cin >> mhs.tugas;

    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

float hitungNilaiAkhir(float uts, float uas, float tugas){
    return 0.3*uts + 0.4*uas + 0.3*tugas;
}

void tampilkanData(dataMhs mhs[], int jumlah){
    for (int i = 0; i < jumlah; i++){
        cout << "Data Mahasiswa ke-" << i+1 << ":" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << endl;
    }
}
