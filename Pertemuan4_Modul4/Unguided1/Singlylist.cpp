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
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->info << " ";
            nodeBantu = nodeBantu->next;
        }
    }
}

void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}