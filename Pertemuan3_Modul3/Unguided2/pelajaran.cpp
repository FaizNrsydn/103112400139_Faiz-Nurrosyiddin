#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Mapel: " << pel.kodeMapel << endl; 
}