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
        cout << endl;
    }
}

void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L){
    address P;
    if (L.first == Nil){
        cout << "List Kosong." << endl;
    }else{
        P = L.first;
        L.first = L.first->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L){
    address P, Q;
    if (L.first == Nil){
        cout << "List Kosong" << endl;
    }else{
        P = L.first;
        if (P->next == Nil){
            L.first->next = Nil;
            dealokasi(P);
        }else{
            while (P->next != Nil)
            {
                Q = P;
                P = P->next;
            }
            Q->next = Nil;
            dealokasi(P);
        }
    }
}

void deleteAfter(List &L, address P, address Q){
    if (L.first == Nil){
        cout << "List Kosong" << endl;
    }else{
        if (Q != Nil && Q->next != Nil)
        {
            P = Q->next;
            Q->next = P->next;
            P->next = Nil;
            dealokasi(P);
        }else{
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(List L){
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(List &L){
    address nodeBantu, P;
    nodeBantu = L.first;
    while (nodeBantu != Nil){
        P = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(P);
    }
    L.first = Nil;
    cout << "- List Sudah Terhapus -" << endl;
}