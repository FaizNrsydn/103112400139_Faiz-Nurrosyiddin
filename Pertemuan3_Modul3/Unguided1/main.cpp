#include <iostream>
#include "mhs.h"
using namespace std;

int main(){
    dataMhs mhs[MAX_MHS];
    int jumlah = 0;

    while (jumlah < MAX_MHS){
        cout << "Masukkan Data Mahasiswa ke-" << jumlah+1 << endl;
        inputData(mhs[jumlah]);
        jumlah++;

        char tambah;
        cout << "Apakah ingin tambah data mahasiswa lagi?(y/n): ";
        cin >> tambah;
        if (tambah == 'n'){
            break;
        }
    }

    tampilkanData(mhs, jumlah);
    return 0;    
}