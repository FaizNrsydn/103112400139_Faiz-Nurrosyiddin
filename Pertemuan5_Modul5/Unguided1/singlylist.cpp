#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L){
    L.first = Nil;
}

address alokasi(infoType x){
    address nodeBaru = new ElmList;
    nodeBaru->info = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &P){
    P->next = Nil;
    delete P;
}

void printInfo(List L){
    if (L.first == Nil)
    {
        cout << "List kosong." << endl;
    }else{
        address nodeBantu = L.first;
        cout << " - ISI DARI LIST - " << endl;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->info << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
    cout << endl;
}

void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}

void findElm(List L, infoType x){
    address nodeBantu = L.first;
    int posisi = 0;
    bool found = false;
    cout << " - MENCARI DATA '" << x << "' PADA LIST - " << endl;
    while(nodeBantu != Nil){
        posisi++;
        if(nodeBantu->info == x){
            cout << "Data " << x << " ditemukan dalam list pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
    }
    if(found == false){
        cout << "Node dengan data " << x << " tidak ditemukan dalam list!" << endl;
    }
    cout << endl;
}

void sumElm(List L){
    address nodeBantu = L.first;
    int total = 0;
    cout << " - MENJUMLAHKAN TOTAL INFO SELURUH ELEMEN - " << endl;
    while (nodeBantu != Nil){
        total += nodeBantu->info;
        nodeBantu = nodeBantu->next;
    }
    cout << "Total Info dari kelima elemen adalah " << total << endl; 
}