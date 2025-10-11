#ifndef MHS_H
#define MHS_H

#include <iostream>
using namespace std;

const int MAX_MHS = 10;

struct dataMhs{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputData(dataMhs &mhs);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanData(dataMhs mhs[], int jumlah);

#endif