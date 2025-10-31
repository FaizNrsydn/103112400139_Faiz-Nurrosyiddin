# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Double Linked List (DLL) atau Daftar Berantai Ganda adalah struktur data linier yang merupakan variasi dari Single Linked List. Perbedaan utamanya adalah setiap simpul (node) pada DLL memiliki dua penunjuk (pointer): satu menunjuk ke simpul berikutnya (next) dan satu lagi menunjuk ke simpul sebelumnya (previous).
1. Konsep Dasar
- Simpul (Node): Unit dasar dari DLL. Setiap simpul terdiri dari tiga komponen:
  + Data (Data Field): Tempat menyimpan informasi yang sebenarnya.
  + Penunjuk Berikutnya (Next Pointer): Menyimpan alamat memori dari simpul yang berada tepat setelahnya.
  + Penunjuk Sebelumnya (Previous Pointer): Menyimpan alamat memori dari simpul yang berada tepat sebelumya.
- Arah Traversal: Tidak seperti Single Linked List yang hanya dapat dilalui satu arah (maju), DLL memungkinkan traversal dua arah (maju dan mundur).
- Header dan Tail: DLL biasanya memiliki penunjuk khusus:
  + Header/Head: Menunjuk ke simpul pertama dalam daftar.
  + Tail: Menunjuk ke simpul terakhir dalam daftar.
- Kondisi Akhir:
  + Penunjuk previous dari simpul pertama (Head) adalah NULL.
  + Penunjuk next dari simpul terakhir (Tail) adalah NULL.
2. Representasi StrukturSecara konseptual, struktur satu simpul (node) dapat diwakili sebagai berikut:
<br>Node = [Previous Pointer, Data, Next Pointer]

## Guided

### 1. Insert & Update Double Linked List
#### listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev; //beda nya dengan singly linked list
};

struct linkedlist{
    address first;
    address last; //ini juga
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

#### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan program membuat double linked list, dimana isi dari list nya yaitu nama, jenis, harga dan rating. Dan seperti biasa program akan menambah list menggunakan function insertFirst, insertLast, insertAfter dan insertBefore.
Dalam program main.cpp insert list dilakukan seperti ini:
```C++
    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
```
Maka list yang akan terbentuk adalah: D - A - C - E - B.
Lalu program main.cpp melakukan update list:
```C++
    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);
```
Maka list akan terupdate sesuai dengan inputan usernya. Dan list yang akan terupdate adalah D, B, A, dan E.

### 2. Search & Delete Double Linked List
#### listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

#### listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

#### main.cpp
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

### Penjelasan singkat guided 2:
Program diatas merupakan lanjutan dari program guided 1 hanya menambahkan function pencarian yaitu findByName mencari berdasarkan nama, findByJenis mencari berdasarkan jenis, dan findByRating mencari berdasarkan rating. dan juga function penghapusan yaitu deleteByname menghapus berdasarkan nama, deleteFirst menghapus list pertama, deleteAfter dan before menghapus elemen setelah dan sebelum elemen tertentu, dan deleteNode menghapus node.

## Unguided

### 1.  Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:
### Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.
### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address
### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
### - procedure deleteFirst( input/output L : List,P : address )
### - procedure deleteLast( input/output L : List,P : address )
### - procedure deleteAfter( input Prec : address,input/output P : address )

#### doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include<iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);

void insertLast(List &L, address P);

address findElm(List L, infotype x);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address prec, address &P);
void deleteByNopol(List &L, infotype x);

#endif
```

#### doublylist.cpp
```C++
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
```

##### main.cpp
```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan6_Modul6/Output-Unguided1-1.png)
![Screenshot Output Unguided 1_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan6_Modul6/Output-Unguided1-2.png)
![Screenshot Output Unguided 1_3](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan6_Modul6/Output-Unguided1-3.png)

### Penjelasan unguided 1:
Program diatas merupakan program double linked list dan berisi data kendaraan nomor polisi, warna kendaraan dan tahun kendaraan. <br> 1. Membuat file header .h dan implementasi fungsi di cpp juga hasilnya di main.cpp
pada main.cpp, input data kedaraan didapat dari input user dimana pertama kali program dijalankan user akan memeasukkan jumlah data yang mau di input:
```C++
    cout << "Masukkan Jumlah data yang ingin di tambahkan: ";
    cin >> count;
```
lalu menggunakan for untuk melakukan perulangan sebanyak jumlah data yang diinputkan user:
```C++
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
```
pada code diatas didalam for terdapat kondisi dimana sebelum data kendaraan diinputkan data nomor polisi akan dicek terlebih dahulu, apabila nomor polisi tersebut sudah ada atau sudah terdaftar maka data tersebut tidak akan dimasukkan kedalam list, program menggunakan fungsi findElm(), dimana fungsi tersebut akan mengembalikan address dari nomor yang dicari ketika ditemukan lalu ketika tidak ditemukan maka akan mengembalikan nilai NULL, artinya ketika nilai yang dikembalikan di function findElm() NULL maka nomor polisi belum terdaftar dan bisa masuk kedalam list.

2. membuat fungsi pencarian elemen berdasarkan nomor polisi:
```C++
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
```
untuk mencari elemen berdasarkan nomor polisi, memanggil fungsi findElm kembali seperti sebelumnya, fungsi findElm() akan mengembalikan nilai address nya ketika nomor polisi yang dicari ditemukan. Lalu pada program main:
```C++
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
```
nahh pada program main ketika address P nya tidak NULL maka elemen yang dicari ditemukan dan program akan menampilkan elemen yang dicari.

3. Menghapus elemen nomor polisi D003
Pada hapus elemen kita biasanya membuat 3 fungsi delete saja, namun pada kasus ini karena kita tidak tahu posisi nomor polisi D003 nya berada di list pertama, terakhir atau ditengah-tengah maka kita perlu menambah fungsi baru yaitu deleteByNopol.
```C++
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
```
Dimana didalam fungsi deleteByNopol terdapat fungsi findElm() yang digunakan untuk mengetahui dimana letak nomor polisi D003 tersebut lalu dimasukkan ke dalam variabel P sebagai address.
Lalu program akan mengecek menggunakan kondisi, kondisi yang pertama yaitu ketika P = NULL artinya nomor polisi D003 tidak ditemukan dalam list, kondisi selanjutnya ketika P = L.first yang artinya nomor polisi D003 berada di elemen pertama dalam list maka program akan menghapus menggukana function deleteFirst, kondisi selanjutnya ketika P = L.last maka nomor polisi berada di elemen terakhir dalam list dan menggunakan deleteLast, kondisi terakhir yaitu nomor polisi berada ditengah-tengah maka, kita akan mengisi variabel address prec dengan P->prev atau elemen sebelumnya dan menggukana deleteAfter.
Lalu setelah itu List yang telah dihapus dialokasi agar terhapus.

## Kesimpulan
Double Linked List (DLL) adalah struktur data linier yang ditingkatkan dari Single Linked List, di mana setiap simpul (node) memiliki dua penunjuk: satu ke simpul berikutnya (next) dan satu lagi ke simpul sebelumnya (previous), memungkinkan traversal dua arah yang unik. Keunggulan utamanya adalah efisiensi tinggi dalam operasi penghapusan dan kemudahan akses ke simpul sebelumnya, namun kekurangan utamanya terletak pada pemanfaatan memori yang lebih besar karena kebutuhan penyimpanan penunjuk tambahan, serta peningkatan kompleksitas dalam implementasi operasi penyisipan dan penghapusan karena harus memperbarui dua penunjuk secara simultan.

## Referensi
[1] Kurniawan, A., & Budi, M. (2020). Analisis Perbandingan Kinerja Struktur Data Double Linked List dan Array untuk Operasi Sisip dan Hapus. Jurnal Ilmu Komputer dan Informasi, 15(2), 45-56.
<br>[2] Smith, J., & Johnson, L. (2018). Improving Memory Utilization in Double Linked Lists using Pointer Compression. Proceedings of the International Conference on Data Structures. IEEE Press.