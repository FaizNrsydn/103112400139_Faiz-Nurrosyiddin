#include "doublylist.h"
#include<iostream>
using namespace std;

int main(){
    List L;
    createList(L);

    //no 1
    int count;
    string nopol, warna;
    int tahun;
    cout << "Masukkan Jumlah data yang ingin di tambahkan: ";
    cin >> count;
    cout << endl;
    cout << " --- MASUKKAN DATA KENDARAAN --- " << endl;
    for (int i = 0; i < count; i++){
        cout << "Masukkan nomor polisi      : ";
        cin >> nopol;
        cout << "Masukkan warna kendaraan   : ";
        cin >> warna;
        cout << "Masukkan tahun kendaraan   : ";
        cin >> tahun;
        
        infotype data;
        data = {nopol,warna,tahun};
        if (findElm(L, data) == NULL){
            insertLast(L,alokasi(data));
        }else{
            cout << " ---> Nomor polisi '" << data.nopol << "' sudah terdaftar!!! <--- " << endl;
        }
        cout << endl;
    }
    cout << endl;
    printInfo(L);

    //no 2
    infotype dataCari;
    cout << endl;
    cout << "Masukkan nomor polisi yang dicari: ";
    cin >> nopol;
    dataCari.nopol = nopol;
    address P = findElm(L, dataCari);
    if(P != NULL){
        cout << "+---------------------+" << endl;
        cout << "|      DITEMUKAN      |" << endl;
        cout << "+---------------------+" << endl;
        cout << "No polisi  : " << P->info.nopol << endl;
        cout << "Warna      : " << P->info.warna << endl;
        cout << "Tahun      : " << P->info.thnBuat << endl;
        cout << "+---------------------+" << endl;
    }else{
        cout << " ---> Data dengan nopol '" << P->info.nopol << "' tidak ditemukan <--- " << endl;
    }

    cout << endl;

    //no 3
    infotype dataDelete;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    cin >> nopol;
    dataDelete.nopol = nopol;
    deleteByNopol(L, dataDelete);
    cout << endl;
    printInfo(L);

    return 0;
}