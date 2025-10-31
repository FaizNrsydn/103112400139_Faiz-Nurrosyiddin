#include "doublylist.h"
#include<iostream>
using namespace std;

bool isEmpty(List L){
    return L.first == NULL;
}

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) { 
    address nodeBaru = new ElmList;
    nodeBaru->info.nopol = x.nopol;
    nodeBaru->info.warna = x.warna;
    nodeBaru->info.thnBuat = x.thnBuat;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = NULL;
    P->prev = NULL;
    delete P;
}

void insertLast(List &L, address P){
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

address findElm(List L, infotype x){
    address nodeBantu = L.first;
    while (nodeBantu != NULL){
        if (nodeBantu->info.nopol == x.nopol){
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }
    return NULL;
}

void printInfo(List L) {
    if (isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        cout << "+---------------------+" << endl;
        cout << "|     DATA LIST 1     |" << endl;
        cout << "+---------------------+" << endl;
        // cout << endl;
        while (nodeBantu != NULL) {
            cout << "No polisi  : " << nodeBantu->info.nopol << endl;
            cout << "Warna      : " << nodeBantu->info.warna << endl;
            cout << "Tahun      : " << nodeBantu->info.thnBuat << endl;
            cout << "+---------------------+" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void deleteFirst(List &L, address P){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.first;
    if(L.first == L.last){
        L.first = L.last = NULL;
    } else {
        L.first = pDel->next;
        L.first->prev = NULL;
        pDel->next = NULL;
    }
    pDel->prev = NULL;
}

void deleteLast(List &L, address P){
    if(isEmpty(L) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = L.last;
    if(L.first == L.last){
        L.first = L.last = NULL;
    } else {
        L.last = pDel->prev;
        L.last->next = NULL;
        pDel->prev = NULL;
    }
    pDel->next = NULL;
}

void deleteAfter(address Prec, address &P){
    P = Prec->next;

    if (P != NULL) {
        Prec->next = P->next; 
        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            Prec->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteByNopol(List &L, infotype x) {
    address P = findElm(L, x);
    address Prec;

    if (P == NULL) {
        cout << "Nomor Polisi " << x.nopol << " tidak ditemukan." << endl;
        return;
    }
    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
        Prec = P->prev;
        deleteAfter(Prec, P); 
    }
    cout << " --- Data dengan nomor polisi " << x.nopol << " berhasil dihapus --- " << endl;
    dealokasi(P); 
}