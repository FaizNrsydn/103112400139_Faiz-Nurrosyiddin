# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Queue atau antrian adalah salah satu struktur data linier yang beroperasi dengan prinsip FIFO (First In First Out), yang berarti elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Pada struktur data ini, elemen baru ditambahkan pada bagian belakang antrian, sementara elemen yang paling lama berada di depan antrian akan dihapus. Queue banyak digunakan dalam berbagai aplikasi, seperti pada manajemen proses dalam sistem operasi, antrian pada printer, serta dalam pemrograman jaringan untuk menangani data yang dikirimkan secara berurutan. Queue juga dapat diimplementasikan menggunakan array atau linked list, tergantung pada kebutuhan efisiensi dan ukuran antrian yang diinginkan.

Queue memiliki dua operasi utama, yaitu enqueue (penambahan elemen) dan dequeue (penghapusan elemen). Pada operasi enqueue, elemen ditambahkan ke belakang antrian, sementara pada operasi dequeue, elemen dikeluarkan dari bagian depan antrian. Struktur data ini juga dapat dikembangkan dalam varian yang lebih kompleks seperti double-ended queue (deque), di mana elemen bisa ditambahkan dan dihapus dari kedua ujung. Dalam implementasi antrian pada sistem komputer, konsep queue sering digunakan dalam penjadwalan proses, algoritma buffering, dan pengelolaan memori, sehingga mempermudah pengelolaan data secara efisien.

Terdapat 2 cara membuat queue yaitu:
- Menggunakan List/Pointer
<br> - Menggunakan Array

## Guided

### 1. QUEUE MENGGUNAKAN LIST
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nama;
    Node* next;
};

struct queue{
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

#### queue.cpp
```C++
#include "queue.h"
#include<iostream>
#include <string>
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

#### main.cpp
```C++
#include "queue.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);
    clearQueue(Q);
    viewQueue(Q);
    return 0;
}
```

### Penjelasan singkat guided 1:
program diatas merupakan program membuat queue menggunakan list, dimana konsepnya hampir sama seperti stack, queue memiliki head dan tail dimana untuk menambahkan datanya menggunakan konsep insert last dan hapus datanya delete first atau dinamakan First In First out kebalikannya stak.

### 2. QUEUE MENGGUNAKAN ARRAY
#### stack.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAKSIMAL = 5;

struct queue
{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

#### stack.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

### Penjelasan singkat guided 2:
program diatas merupakan queue menggunakan array tidak berbeda jauh juga dengan stack, head dan tail di set dengan nilai -1 artinya queue masih kosong, data pertama berada pada indeks ke-0. terdapat 3 implementasi dimana implementasi 1 yaitu head diam tail bergerak, implementasi 2 head bergerak tail bergerak, dan implementasi 3 head dan tail berputar. untuk penjelasan lebih lanjut di unguided. 

## Unguided

### 1.  Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
```C++
    Type infotype: integer
    Type Queue: <
    info : array [5] of infotype {index array dalam C++
    dimulai dari 0}
    head, tail : integer
    >
    procedure CreateQueue (input/output Q: Queue)
    function isEmptyQueue (Q: Queue) → boolean
    function isFullQueue (Q: Queue) → boolean
    procedure enqueue (input/output Q: Queue, input x: infotype)
    function dequeue (input/output Q: Queue) → infotype
    procedure printInfo (input Q: Queue)
```
### Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
struct Queue{
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return Q.tail == 5-1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue Penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    }else{
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    infotype value;
    if (isEmptyQueue(Q)) {
        cout << "empty queue!" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
        return value;
    }
}

void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan8_Modul8/Output-Unguided1.png)

### Penjelasan unguided 1:
program diatas merupakan queue dengan implementasi 1: head diam dan tail bergerak.
```C++
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue Penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    }else{
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}
```
pada prosedur enqueue saat queue masih kosong head dan tail akan di set nilainya menjadi 0 dan data x dimasukkan kedalam array pada indeks yang sama seperti Q.tail, dan saat queue sudah ada datanya maka tail akan ditambah 1 artinya data akan dimasukkan setelah data yang ada misalnya ada data dan head dan tail berada pada indeks ke-0 maka data baru yang ingin di masukkan kedalam queue akan berada pada indeks setelahnya yaitu indeks ke-1.
```C++
infotype dequeue(Queue &Q) {
    infotype value;
    if (isEmptyQueue(Q)) {
        cout << "empty queue!" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
        return value;
    }
}
```
pada prosedur dequeue program akan mengganti nilai indeks Q.head saat ini dengan nilai indeks setelahnya dimana pada kode diatas menggunakan perulangan dengan i = Q.head dan mengulang sampai indeks sebelum Q.tailnya. setelah itu nilai indeks Q.tail akan dikurangi 1 sesuai dengan isi arraynya yang berkurang 1. dan saat Q.tai < 0 atau sudah mencapai -1 yang artinya queue sudah kosong, maka Q.head dan Q.tail akan diset -1 atau queue kosong.
```C++
void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```
selanjutnya prosedur printInfo dimana program akan print isi dari array menggunakan perulangan, indeks akan dimulai dari head sampai tail.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
struct Queue{
    infotype info[5];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return Q.tail == 5-1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue Penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    }else{
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
        return value;
    }
}

void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan8_Modul8/Output-Unguided2.png)

### Penjelasan unguided 2:
program diatas merupakan queue dengan implementasi 2 yaitu head dan tail bergerak, perbedaannya terdapat pada prosedur dequeue.
```C++
infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
        return value;
    }
}
```
perbedaannya tidak menggunakan perulangan karena bukan mengubah nilai indeks dari array tetapi hanya memindahkan indeks head ke indeks setelahnya misal array memiliki data 5 2 7 dan head dan tail berada pada indeks ke 0 dan 2 ketika melakukan dequeue indeks head akan ditambah 1 berati head saat ini bernnilai 1 saat diprint info maka yang ter print hanya angka 2 dan 7 dan ketika kita menambah data atau enqueue maka head tetap pada indeks 1 dan tail akan bertambah 1 jadi head 1 dan tail 3.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAXIMAL = 5;

typedef int infotype;
struct Queue{
    infotype info[MAXIMAL];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q){
    if((Q.tail + 1) % MAXIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAXIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "empty queue" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAXIMAL;
        }
        return value;
    }
}

void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if(isEmptyQueue(Q) == true){
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << Q.info[i] << " ";
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAXIMAL;
            count++;
        }
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan8_Modul8/Output-Unguided3.png)

### Penjelasan unguided 3:
program diatas merupakan queue implementasi 3, perbedaannya terdapat pada prosedur isFull, enqueue, dequeue dan printInfo
```C++
bool isFull(Queue Q){
    if((Q.tail + 1) % MAXIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}
```
pada prosedur isFull, queue penuh jika penunjuk tail berikutnya ((Q.tail + 1) % MAXIMAL) = head. artinya hanya tersisa satu array kosong (saat tail berada tepat di belakang head).
```C++
void enqueue(Queue &Q, infotype x){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAXIMAL;
        }
        Q.info[Q.tail] = x;
    }
}
```
pada enqueue tail digeser maju satu posisi menggunakan operasi modulo: Q.tail = (Q.tail + 1) % MAXIMAL
```C++
infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "empty queue" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAXIMAL;
        }
        return value;
    }
}
```
pada prosedur dequeue Jika elemen yang di-dequeue adalah elemen terakhir (Q.head == Q.tail), antrian menjadi kosong, sehingga head dan tail direset ke -1.Jika masih ada elemen lain, penunjuk head digeser maju satu posisi menggunakan operasi modulo: Q.head = (Q.head + 1) % MAXIMAL.

## Kesimpulan
Queue adalah struktur data yang sangat efisien dalam pengelolaan data secara urut dengan prinsip FIFO. Dengan dua operasi dasar yakni enqueue dan dequeue, struktur ini memungkinkan pemrosesan data secara berurutan dan teratur. Penggunaan queue sangat relevan dalam berbagai bidang, seperti sistem operasi dan jaringan komputer, untuk memastikan pengelolaan antrian data berjalan lancar dan terorganisir. Implementasi yang tepat dari queue dapat meningkatkan efisiensi dalam pemrosesan data dalam aplikasi yang memerlukan pengaturan antrian yang jelas.

## Referensi
[1] Wirth, N. (1976). Algorithms + Data Structures = Programs. Prentice-Hall.
<br> [2] Knuth, D. E. (1997). The Art of Computer Programming: Volume 1, Fundamental Algorithms (3rd ed.). Addison-Wesley.
<br> [3] Aho, A. V., Ullman, J. D., & Hopcroft, J. E. (1983). Data Structures and Algorithms. Addison-Wesley.