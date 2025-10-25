# <h1 align="center">Laporan Praktikum Modul 5 - Single Linked List (Bagian Kedua)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Single Linked List adalah struktur data linier dinamis yang terdiri dari serangkaian simpul (node), di mana setiap simpul memiliki dua bagian utama: data yang menyimpan nilai atau informasi, dan pointer yang menunjuk ke simpul berikutnya dalam daftar. Dalam implementasi menggunakan bahasa C++, simpul direpresentasikan menggunakan struct atau class dengan anggota data dan pointer ke tipe simpul itu sendiri.

Struktur ini bersifat satu arah, artinya penelusuran node hanya dapat dilakukan dari node pertama (head) menuju node terakhir (tail). Single Linked List memungkinkan operasi dinamis, seperti penambahan atau penghapusan elemen tanpa perlu pengalokasian ruang secara statis seperti pada array. Namun, akses elemen dilakukan secara berurutan sehingga membutuhkan waktu yang linear untuk mencari atau memanipulasi data di posisi tertentu.

Operasi dasar yang umum dilakukan pada Single Linked List antara lain:
- Inisialisasi: Membuat list kosong dengan pointer head yang bernilai NULL.
- Penambahan node: Dapat dilakukan di awal (insert first), akhir (insert last), atau posisi tertentu.
- Penghapusan node: Berdasarkan nilai data atau posisi.
- Traversal: Menelusuri list dari head ke tail untuk mengakses atau memproses data.
- Update: Mengupdate data dalam list bisa dilakukan di awal(Update First), akhir(update last), atau posisi tertentu.
- Searching: Mencari data dalam list bisa dilakukan berdasarkan nilai data, address dan range.

Konsep linked list sangat fundamental dalam pemrograman dan ilmu komputer sebagai dasar memahami struktur data yang lebih kompleks serta manajemen memori dinamis.

## Guided

### 1. Update & Find Single Linked List

##### listBuah.h
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

##### list.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

##### main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan program single linked list dimana isi datanya merupakan nama buah, jumlah, dan harganya. Lalu pada program main kita menambahkan elemen nodeA - nodeF:
```C++
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
```
maka list yang akan terbentuk akan seperti ini:
```C++
Nama Buah : Jeruk, Jumlah : 100, Harga : 3000
Nama Buah : Pir, Jumlah : 87, Harga : 5000
Nama Buah : Semangka, Jumlah : 43, Harga : 11500
Nama Buah : Apel, Jumlah : 75, Harga : 4000
Nama Buah : Durian, Jumlah : 15, Harga : 31450
jumlah node : 5
```
selanjutnya program tersebut mamanggil fungsi update:
```C++
    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);
```
dimana update first berfungsi untuk melakukan update pada list pertama, update last untuk update pada list terakhir dan update after untuk update list tertentu.
selanjutnya program tersebut memanggil fungsi find/search:
```C++
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
```
dimana find node by data mencari elemen dengan nama buah dan menampilkan datanya jika ditemukan, selanjutnya find node by address yaitu mencari elemen dengan alamat memorinya lalu menampilkan datanya jika ditemukan, dan find node by range yaitu mencari elemen dengan range harga seperti di contoh yaitu harga 5000 - 10000.

## Unguided

### 1.  Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L: List, x: infotype ) : address
###  Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infoType;
typedef struct ElmList *address; 

struct ElmList{
    infoType info;
    address next;
};

struct List{
    address first;
};

void CreateList(List &L);
address alokasi(infoType x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void findElm(List L, infoType x);
void sumElm(List L);

#endif
```

##### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infoType;
typedef struct ElmList *address; 

struct ElmList
{
    infoType info;
    address next;
};

struct List
{
    address first;
};

void CreateList(List &L);
address alokasi(infoType x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

##### Singlylist.cpp
```C++
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
```

##### main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    findElm(L, 8);
    sumElm(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan5_Modul5/Output-Unguided1.png)

### Penjelasan unguided 1:
Program diatas merupakan linked list dengan isi data berupa angka, pada program main data sudah dimasukkan menggunakan fungsi insertFirst(), lalu menambahkan fungsi baru yaitu fungsi findElm() dimana berfungsi untuk mencari elemen.
```C++
while(nodeBantu != Nil){
        posisi++;
        if(nodeBantu->info == x){
            cout << "Data " << x << " ditemukan dalam list pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
    }
```
code diatas merupakan inti dari pencariannya dimana program akan berulang selama pointer nodeBantu yang diisi oleh L.first tidak sama dengan Nil atau terus berulang sampai list terakhir lalu didalam while nya terdapat kondisi dimana jika nodebantu.info atau isi dari data node bantu tersebut sama dengan angka yang dicari yaitu x maka program akan mencetak:
```C++
    cout << "Data " << x << " ditemukan dalam list pada posisi ke-" << posisi << "!" << endl;
```
dimana posisi digunakan untuk data tersebut ditemukan di posisi ke berapa, posisi terus bertambah dan while terus berulang saat kondisi tidak terpenuhi.
Selanjutnya menambahkan fungsi sumElm() yang berfungsi untuk menjumlahkan semua elemen yang ada di list tersebut.
```C++
while (nodeBantu != Nil){
        total += nodeBantu->info;
        nodeBantu = nodeBantu->next;
    }
```
code diaatas merupakan inti dari penjumlahan pada function sumElm() dimana total diset 0 lalu selama perulangan terus ditambahkan dengan nodeBantu.info atau isi dari datanya. dan total akan menampung data list yang sudah dijumlahkan.

### 2. Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h”
### kemudian buatlah implementasi function & procedure tersebut pada file “listAngka.cpp”
### kemudian lakukan hal berikut pada file “main.cpp”
### a. Buatlah procedure updateFirst, updateLast, dan updateAfter
### b. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange
### c. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.

##### listAngka.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

typedef int dataAngka;
typedef struct node *address;

struct node{
    dataAngka angka;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst (linkedlist &L);
void updateLast (linkedlist &L);
void updateAfter (linkedlist &L, address nodePrev);

void SearchByData(linkedlist list, int data);
void SearchByAddress(linkedlist list, address node);
void SearchByRange(linkedlist list, int nilaiMin);

void penjumlahElm(linkedlist List);
void penguranganElm(linkedlist List);
void perkalianElm(linkedlist List);
#endif
```

##### listAngka.cpp
```C++
#include "listAngka.h"
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
}

address alokasi(dataAngka x) { 
    address nodeBaru = new node; 
    nodeBaru->angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->angka << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->angka << " - ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
    cout << endl;
}

void updateFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan Angka: ";
        cin >> List.first->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist &List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan Angka: ";
        cin >> nodeBantu->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist &List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
            cout << "Masukkan Angka: ";
            cin >> nodeBantu->angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void SearchByData(linkedlist list, int data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->angka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(linkedlist list, address node){
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void SearchByRange(linkedlist List, int nilaiMin){
    if(isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << "---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            int nilai = nodeBantu->angka;
            if(nilai >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", Nilai : " << nilai << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dalam range tersebut!" << endl;
            cout << "------------------------------------" << endl;
        }
    }
    cout << endl;
}

void penjumlahElm(linkedlist List){
    address nodeBantu = List.first;
    int total = 0;
    while (nodeBantu != Nil){
        total += nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    cout << "Total penjumlahan : " << total << endl; 
}

void penguranganElm(linkedlist List){
    address nodeBantu = List.first;
    int total = List.first->angka;
    while (nodeBantu != Nil){
        total -= nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    cout << "Total pengurangan : " << total << endl; 
}

void perkalianElm(linkedlist List){
    address nodeBantu = List.first;
    int total = 1;
    while (nodeBantu != Nil){
        total *= nodeBantu->angka;
        nodeBantu = nodeBantu->next;
    }
    cout << "Total perkalian : " << total << endl; 
}
```

##### main.cpp
```C++
#include <iostream>
#include "listAngka.h"
using namespace std;

int main(){
    linkedlist L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT & DELETE AFTER ---" << endl;
    printList(L);

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(L);

    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    penjumlahElm(L);
    penguranganElm(L);
    perkalianElm(L);
    return 0;
}
```

### Output Unguided 2:

##### Output 1

![Screenshot Output Unguided 2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan5_Modul5/Output-Unguided2.png)

### Penjelasan unguided 2:
Program diatas merupakan linked list yang berisi data angka integer lalu program diatas bertujuan untuk mengupdate, mencari, menjumlahkan, mengurangkan dan mengalikan isi dari list tersebut.
#### Pada update terdapat 3 fungsi:
Yang pertama, update first untuk mengupdate data list pertama.
```C++
void updateFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan Angka: ";
        cin >> List.first->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}
```
kode diatas berfungsi untuk mengupdate nilai first bisa kita lihat nilai yang di inputkan user akan masuk ke List.first.angka atau isi data angka nya diubah/update.

Kedua, update after untuk mengupdate data pada posisi tertentu.
pada fungsi update after, parameternya berisi list dan nodePrev sebagai tanda untuk posisi data sebelumnya. yang akan dicari adalah data setelahnya.
```C++
if (nodePrev != Nil && nodePrev->next != Nil){
    address nodeBantu = nodePrev->next;
    cout << "Masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
    cout << "Masukkan Angka: ";
    cin >> nodeBantu->angka;
    cout << "Data Berhasil Diupdate!" << endl;
    cout << endl;
```
Kode diatas merupakan inti dari update after dimana program akan mengecek terlebih dahulu apakah node prev nya Nil dan node prev next nya Nil atau yang berarti node prev tersebut tidak berada di akhir list, lalu membuat variabel node bantu yang diisi node prev.next lalu variabel tersebut digunakan untuk menampung inputan user yang nnt nya untuk mengupdate nilai terbaru.

Ketiga, update last yaitu mengupdate data list paling akhir.
```C++
    address nodeBantu = List.first;
    while (nodeBantu->next != Nil) {
        nodeBantu = nodeBantu->next;
    }
```
Kode diatas merupakan inti dari fungsi update last dimana program terus berulang sampai node terakhir lalu mengupdate list terakhit tersebut.

#### Pada pencarian terdapat 3 fungsi yaitu:
Pertama search by data yang berfungsi untuk mencari berdasarkan datanya.
```C++
address nodeBantu = list.first;
    int posisi = 0;
    bool found = false;
    while(nodeBantu != Nil){
        posisi++;
        if(nodeBantu->angka == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
```
Kode diatas merupakan inti dari pencariannya dimana program akan berulang dari list pertama sampai terakhir lalu membandingkan data listnya dengan angka yang dicari jika ketemu maka program akan mengeluarkan output seperti pada kode diatas lalu berhenti melakukan perulangan.

Kedua, search by address, yaitu mencari data berdasarkan address nya.
```C++
address nodeBantu = list.first;
    int posisi = 0;
    bool found = false;
    while (nodeBantu != Nil) {
        posisi++;
        if(nodeBantu == node) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << nodeBantu << endl;
        }
        nodeBantu = nodeBantu->next;
    }
```
Kode diatas mirip seperti sebelumnya yaitu search by data bedanya kita membandingkannya dengan addressnya.

Ketiga, search by range yaitu mencari data dalam range tertentu seperti program diatas kita mencari data dengan range diatas 40.
```C++
while (nodeBantu != Nil) {
    posisi++;
    int nilai = nodeBantu->angka;
    if(nilai >= nilaiMin) {
        cout << "Data ditemukan pada posisi ke-" << posisi << ", Nilai : " << nilai << endl;
        cout << "-------------------------------------------" << endl;
        found = true;
    }
    nodeBantu = nodeBantu->next;
}
```
Kode diatas juga mirip dengan pencarian sebelumnya bedanya perbandingan dilakukan dengan membandingkan nilai range nya dengan angkanya ketika angka tersebut lebih dari range nya maka data tersebut yang dicari.

#### Selanjutnya penjumlahan, pengurangan dan perkalian
```C++
while (nodeBantu != Nil){
    total += nodeBantu->angka;
    nodeBantu = nodeBantu->next;
}
```
Di ketiga fungsi kode intinya hanya seperti kode diatas yang membedakannya untuk penjumlahan += pengurangan -= dan perkalian *= untuk di bagian pengurangan total awalnya/ nilai awalnya yaitu data list pertama, lalu untuk perkalian nilai total awalnya di set = 1.

## Kesimpulan
Single Linked List pada C++ merupakan struktur data yang efisien untuk pengelolaan elemen secara dinamis dengan alokasi memori yang fleksibel. Dengan karakteristik node yang saling terhubung melalui pointer satu arah, linked list mempermudah operasi seperti insert dan delete secara dinamis dibandingkan dengan array statis. Namun, kelemahannya adalah akses langsung ke elemen tertentu tidak memungkinkan, sehingga traversal diperlukan untuk mencapai elemen tersebut.

## Referensi
[1] Dharmayanti, R. (2011). Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++. Jurnal Informatika, 9(2), 123-131.
<br>[2] Modul Pembelajaran Struktur Data (2025). Linked List Dasar dengan C++. Fakultas Ilmu Komputer, Universitas X.
<br>[3] Sedgewick, R., & Wayne, K. (2011). Algorithms, 4th Edition. Addison-Wesley.