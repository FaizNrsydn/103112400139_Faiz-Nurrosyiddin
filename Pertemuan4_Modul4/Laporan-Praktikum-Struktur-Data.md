# <h1 align="center">Laporan Praktikum Modul 4 - Single Linked List (Bagian Pertama)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Single Linked List adalah struktur data linier dinamis yang terdiri dari serangkaian simpul (node), di mana setiap simpul memiliki dua bagian utama: data yang menyimpan nilai atau informasi, dan pointer yang menunjuk ke simpul berikutnya dalam daftar. Dalam implementasi menggunakan bahasa C++, simpul direpresentasikan menggunakan struct atau class dengan anggota data dan pointer ke tipe simpul itu sendiri.

Struktur ini bersifat satu arah, artinya penelusuran node hanya dapat dilakukan dari node pertama (head) menuju node terakhir (tail). Single Linked List memungkinkan operasi dinamis, seperti penambahan atau penghapusan elemen tanpa perlu pengalokasian ruang secara statis seperti pada array. Namun, akses elemen dilakukan secara berurutan sehingga membutuhkan waktu yang linear untuk mencari atau memanipulasi data di posisi tertentu.

Operasi dasar yang umum dilakukan pada Single Linked List antara lain:
- Inisialisasi: Membuat list kosong dengan pointer head yang bernilai NULL.
- Penambahan node: Dapat dilakukan di awal (insert first), akhir (insert last), atau posisi tertentu.
- Penghapusan node: Berdasarkan nilai data atau posisi.
- Traversal: Menelusuri list dari head ke tail untuk mengakses atau memproses data.

Konsep linked list sangat fundamental dalam pemrograman dan ilmu komputer sebagai dasar memahami struktur data yang lebih kompleks serta manajemen memori dinamis.

## Guided

### 1. Insert Single Linked List

##### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa
{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; // mendefinisikan alias address sebagai pointer ke struct node

struct node //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist //ini linked listnya
{
    address first;
};

//semua function dan prosedur yang akan digunakan
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

#endif
```

##### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

##### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan program single linked list dimana isi datanya merupakan nama,nim dan umur yang ditampung pada struct mahasiswa dalam file list.h, data tersebut dimasukan kedalam list dengan menggunakan prosedur insertFirst yaitu berfungsi untuk menyisipkan data di elemen pertama dalam sebuah list, insertAfter yang berfungsi untuk menyisipkan data pada elemen setelahnya atau ditengah-tengah, dan insertLast untuk menyisipkan elemen diakhir dalam list, lalu program akan mencetak datanya.

### 2. Delete Single Linked List

##### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa
{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; // mendefinisikan alias address sebagai pointer ke struct node

struct node //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist //ini linked listnya
{
    address first;
};

//semua function dan prosedur yang akan digunakan
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &List);
void dellast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

##### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void dellast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
    F.S. menampilkan jumlah node didalam list*/
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
    /* I.S. list sudah ada
    F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

##### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    dellast(List);
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

### Penjelasan singkat guided 2:
Program diatas merupakan program yang sama dengan guided 2 namun ada tambahan yaitu fungsi delete, sama seperti insert, delete juga memiliki 3 prosedure deleteFirst untuk menghapus elemen pertama dalam list, deleteAfter untuk menghapus elemen yang berada di tengah, deleteLast untuk menghapus elemen terkhir dalam lsit. adapun function dealokasi untuk melepas node elemen dari list nya, nbList untuk mennghitung sisa jumlah node yang ada dilist setelah didelete dan deleteList untuk menghapus semua list/node.

## Unguided

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype: int
Type address : pointer to ElmList
Type ElmList <
info: infotype
next address
>
Type List <First address>
procedure CreateList(input/output L: List)
function alokasi (x: infotype) → address
procedure dealokasi (input/output P address)
procedure printInfo(input L: List)
procedure insertFirst (input/output L List, input P : address)
```
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”
### Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
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
    return 0;
}
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
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan4_Modul4/Output-Unguided1.png)

### Penjelasan unguided 1:
Progeram diatas berfungsi untuk membuat single linked list dimana program dapat menyisipkan data diawal pada list tersebut, bisa dilihat pada prosedur insertFirst():
```C++
void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}
```
dimana P merupakan node baru yang akan ditambahkan dalam list, sebelumnya node baru dibuat di function alokasi():
```C++
address alokasi(infoType x){
    address nodeBaru = new ElmList;
    nodeBaru->info = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}
```
dimana variabel node baru diisi dengan data yang akan dimasukan yaitu x dan node baru->next nya diset menjadi Nil lalu disambung di prosedur insertFirst(). Lalu program akan menampilkan isi dari list menggunakan prosedur printInfo():
```C++
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
```
program akan mengecek terlebih dahulu apakah list tersebut kosong atau tidak. jika iya maka program akan menampilkan "list kosong", jika tidak maka akan menampilkan list dengan menggunakan while loop.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

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
void deleteFirst(List &L);
void deleteAfter(List &L, address P, address Q);
void deleteLast(List &L);
int nbList(List L);
void deleteList(List &L);

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

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,P3,P4);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2:

##### Output 1

![Screenshot Output Unguided 2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan4_Modul4/Output-Unguided2.png)

### Penjelasan unguided 2:
Program diatas hanya menambahkan fungsi delete atau menghapus list, dimana ada 3 cara menghapusnya yaitu deleteFirst():
```C++
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
```
program tersebut berfungsi untuk menghapus elemen/node pertama dari list, pertama program akan mengecek apakah list tersebut kosong atau tidak jika tidak program akan menghapus elemen/node pertama yang didefinisikan sebagai P. selanjutnya ada deleteLast():
```C++
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
```
program tersebut berfungsi untuk menghapus elemen/node terakhir dari list, pertama program akan mengecek apakah list tersebut kosong atau tidak jika tidak program akan menghapus elemen/node terakhir dengan cara menggunakan while untuk mencari elemen/node terakhir. selanjutnya deleteAfter():
```C++
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
```
program tersebut berfungsi untuk menghapus elemen/node yang berada ditengah dari list, pertama program akan mengecek apakah list tersebut kosong atau tidak jika tidak program akan menghapus elemen/node yang berada ditengah dengan cara program akan mengecek terlebih dahulu node sebelumnya yaitu Q apakah ada atau tidak ada jika sudah ketemu, program akan menghapus elemen setelah Q. penghapusan elemen/node berjalan di prosedur dealokasi. function nbList() berfungsi untuk menampilkan jumlah node setelah dihapus dan prosedur deleteList berfungsi untuk menghapus List.

## Kesimpulan
Single Linked List pada C++ merupakan struktur data yang efisien untuk pengelolaan elemen secara dinamis dengan alokasi memori yang fleksibel. Dengan karakteristik node yang saling terhubung melalui pointer satu arah, linked list mempermudah operasi seperti insert dan delete secara dinamis dibandingkan dengan array statis. Namun, kelemahannya adalah akses langsung ke elemen tertentu tidak memungkinkan, sehingga traversal diperlukan untuk mencapai elemen tersebut.

## Referensi
[1] Dharmayanti, R. (2011). Implementasi Struktur Data Linked List pada Bahasa Pemrograman C++. Jurnal Informatika, 9(2), 123-131.
<br>[2] Modul Pembelajaran Struktur Data (2025). Linked List Dasar dengan C++. Fakultas Ilmu Komputer, Universitas X.
<br>[3] Sedgewick, R., & Wayne, K. (2011). Algorithms, 4th Edition. Addison-Wesley.