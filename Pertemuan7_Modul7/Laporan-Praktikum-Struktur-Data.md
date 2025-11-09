# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Stack dalam C++ adalah struktur data linier yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan adalah elemen pertama yang dikeluarkan. Stack dapat diimplementasikan menggunakan array atau linked list. Operasi dasar pada stack meliputi push (menambah elemen ke atas stack) dan pop (menghapus elemen paling atas). Dalam implementasi array di C++, biasanya digunakan variabel "top" untuk menandai elemen posisi teratas, dengan "top" dimulai dari -1 saat stack kosong. Stack memiliki keterbatasan seperti stack overflow saat kapasitas penuh dan stack underflow saat stack kosong dan elemen ingin dihapus. Stack banyak digunakan dalam kasus seperti evaluasi ekspresi matematika, manajemen memori, dan undo/redo.

#### Operasi Dasar
Push        : Menambahkan elemen ke bagian atas tumpukan.
Pop         : Menghapus elemen teratas.
Atas/Intip  : Mengakses elemen atas tanpa menghapusnya.
isEmpty     : Memeriksa apakah tumpukan kosong.

## Guided

### 1. STACK MENGGUNAKAN LIST
#### stack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan program membuat stak menggunakan list, mirip seperti linked list, hanya beda pada first nya menggunakan top, semua function juga mirip, hanya saja stack hanya bisa memasukkan elemen menjadi elemen pertama atau kalau di linked list isdertFirst, bisa dilihat pada prosedur push:
```C++
void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}
```
dimana elemen akan disisipkan dipaling atas atau paling pertama.
juga berbeda pada delete nya stak hanya bisa mendelete elemen paling atas atau pertamanya, bisa dilihat pada prosedur pop:
```C++
void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}
```
bisa dilihat bahwa prosedur diatas akan menghapus elemen paling atas.
kita juga dapat mengupdate data dan mencari data pada stack, algoritma nya sama seperti linked list.

### 2. STACK MENGGUNAKAN ARRAY
#### stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if (isFull(s)){
        cout << "Stak Penuh!" << endl;
    }else{
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if (isEmpty(s)){
        cout << "Stak Kosong!" << endl;
    }else{
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if (isEmpty(s))
    {
        cout << "Stack Kosong!" << endl;
        return;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top - (posisi - 1)
    int idx = s.top - (posisi -1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    }else{
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;
    
    pop(s);
    pop(s);
    cout << endl;
    
    cout << "--- Stack setelah pop ---" << endl;
    view(s);
    cout << endl;
    
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;
    
    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

### Penjelasan singkat guided 2:
Program diatas merupakan program stack menggunakan array, dimana untuk tipe bentukannya hanya berisi:
```C++
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};
```
hanya berisi data array dan top, dimana ketika top nya = -1 maka isi dari stack kosong, dan max digunakan untuk jumlah maksimum datanya, untuk function dan prosedur nya masih sama seperti stack menggunakan list
```C++
bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX;
}

void createStack(stackTable &s){
    s.top = -1;
}
```
untuk function isEmpty akan bernilai true ketika staknya masih kosong atau top nya bernilai -1 dan untuk function isFull akan bernilai true ketika top nya sudah menyentuh nilai MAX. Prosedur createStack untuk membuat stack kosong dan mengisi top = -1.
```C++
void push(stackTable &s, int angka){
    if (isFull(s)){
        cout << "Stak Penuh!" << endl;
    }else{
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if (isEmpty(s)){
        cout << "Stak Kosong!" << endl;
    }else{
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}
```
untuk prosedur push nilai top akan ditambah satu ketika push terjadi, dan data akan dimasukkan kedalam variabel yang menampung data array dengan indeks nilai top saat ini. untuk prosedur pop, data paling atas atau data dengan indeks paling atas/akhir akan disimpan di variabel val dan nilai top dikurangi 1 agar indeks dari array berkurang/ indeks terakhir dihapus.
```C++
    int idx = s.top - (posisi -1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "data berhasil diupdate!" << endl;
    cout << endl;
```
pada prosedur update akan menggunakan index pada array yang diupdate dimana mencari index dengan cara mengurangi nilai top dengan nilai posisi - 1 misal tersapat 3 data dan ingin mengupdate data ke-2 maka nilai top adalah 2 (0,1,2) - nilai posisi 2-1 maka 2 - 1 = 1, maka yang akan diubah data ke-2 yang berada di indeks ke-1.
```C++
    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }
```
untuk prosedur search menggunakan for dari nilai top sampai akhir dan menggunakan if untuk membandikan data dengan data yang ingin dicari.

## Unguided

### 1.  Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
```C++
    Type infotype : integer
    Type Stack <
        info : array [20] of integer
        top : integer
    >
    procedure CreateStack( input/output S : Stack )
    procedure push(input/output S : Stack, input x : infotype)
    function pop(input/output t S : Stack ) → infotype
    procedure printInfo( input S : Stack )
    procedure balikStack(input/output S : Stack )
```
### Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
```C++
    int main(){
        cout << "Hello world!" <<
        endl;
        Stack S;
        createStack(S);
        Push(S,3);
        Push(S,4);
        Push(S,8);
        pop(S)
        Push(S,2);
        Push(S,3);
        pop(S);
        Push(S,9);
        printInfo(S);
        cout<<"balik stack"<<endl;
        balikStack(S);
        printInfo(S);
        return 0;
    }
```

#### stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;
struct Stack
{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 20;
}

void createStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stak Penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }    
}

infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stak Kosong!" << endl;
        return 0;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i)
        {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S){
    if (isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        Stack tampung1;
        Stack tampung2;
        createStack(tampung1);
        createStack(tampung2);
        while (!isEmpty(S))
        {
            push(tampung1, pop(S));
        }
        while (!isEmpty(tampung1))
        {
            push(tampung2, pop(tampung1));
        }
        while (!isEmpty(tampung2))
        {
            push(S, pop(tampung2));
        }
    }
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);

    cout<<"balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout <<"------------" << endl;
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan7_Modul7/Output-Unguided1.png)

### Penjelasan unguided 1:
program diatas merupakan program stack menggunakan array sama seperti pada guided 2 memiliki fungsi push dan pop untuk menambah dan menghapus data, print info untuk menampilkan isi dari stak nya dan ada 1 prosedur tambahan yaitu balikStack yang digunakan untuk membalik urutan data dari stak dimana yang tadinya berada diatas menjadi dipaling bawah/akhir.
```C++
    Stack tampung1;
    Stack tampung2;
    createStack(tampung1);
    createStack(tampung2);
    while (!isEmpty(S))
    {
        push(tampung1, pop(S));
    }
    while (!isEmpty(tampung1))
    {
        push(tampung2, pop(tampung1));
    }
    while (!isEmpty(tampung2))
    {
        push(S, pop(tampung2));
    }
```
algoritmanya terdapat pada code diatas dimana kita membuat stack kosong sebanyak 2 untuk bisa membalik stak dari S, yang pertama stak kosong pertama atau tampung1 menampung setiap pop dari stak S dimana pop akan mengembalikan data dari top sampai akhir dan dipush kedalam stak tampung1, saat data berada di stak tampung1 sebenarnya sudah terbalik tetapi karena yang diminta adalah isi dari stak S maka kita buat push lagi ke dalam stak kosong yang kedua yaitu tampung2, dimana akan mengambil data dari tampung1, lalu kita lakukan push kembali pada stak S yang mengambil data dari stak tampung 2. Ilustrasinya seperti berikut:
misal stak S saat ini -> 9 2 4 3
```C++
    push(tampung1, pop(S));
```
maka stak tampung1 -> 3 4 2 9
jika kita langsung push ke stak S nnt nya akan kembali ke ke urutan yang semula yaitu 9 2 4 3
maka dari itu kita perlu buat stak kosong lagi
```C++
    push(tampung2, pop(tampung1));
```
stak tampung2 -> 9 2 4 3
lalu karena saat ini stak S kosong maka kita bisa push S dari pop tampung2
```C++
    push(S, pop(tampung2));
```
maka stak S saat ini -> 3 4 2 9
stak S berhasil di balik

### 2.  Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
```C++
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;
struct Stack
{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 20;
}

void createStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stak Penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }    
}

infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stak Kosong!" << endl;
        return 0;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i)
        {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S){
    if (isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        Stack tampung1;
        Stack tampung2;
        createStack(tampung1);
        createStack(tampung2);
        while (!isEmpty(S))
        {
            push(tampung1, pop(S));
        }
        while (!isEmpty(tampung1))
        {
            push(tampung2, pop(tampung1));
        }
        while (!isEmpty(tampung2))
        {
            push(S, pop(tampung2));
        }      
    }
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack penuh!" << endl;
    }

    Stack tempstack;
    createStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);

    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan7_Modul7/Output-Unguided2.png)

### Penjelasan unguided 2:
pada program diatas ditambahkan prosedur pushAscending yang berfungsi untuk mengurutkan data yang di push. 
```C++
    Stack tempstack;
    createStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);
```
disini kita membutuhkan stak sementara untuk menampung data yang lebih besar dimana ketika data top atau data paling atas lebih besar dari data yang ingin di push stak S akan di pop selama data didalam stak S masih lebih besar dari data yang ingin di push, nah setelah kondisi while tidak terpenuhi data yang ingin dipush akan dimasukkan kedalam stak S,
```C++
    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
```
lalu lakukan while kembali dengan kondisi stak sementara tersebut tidak kosong maka pop stak sementara tersebut dan push ke dalam stak S kembali.

### 3.  Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
```C++
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### stack.h
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;
struct Stack
{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);

void getInputStream(Stack &S);

#endif
```

#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 20;
}

void createStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stak Penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stak Kosong!" << endl;
        return 0;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i)
        {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S){
    if (isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        Stack tampung1;
        Stack tampung2;
        createStack(tampung1);
        createStack(tampung2);
        while (!isEmpty(S))
        {
            push(tampung1, pop(S));
        }
        while (!isEmpty(tampung1))
        {
            push(tampung2, pop(tampung1));
        }
        while (!isEmpty(tampung2))
        {
            push(S, pop(tampung2));
        }      
    }
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack penuh!" << endl;
    }

    Stack tempstack;
    createStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);

    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
}

void getInputStream(Stack &S){
    int input ;

    while((input = cin.get()) != '\n') {
        if ((input >= '0' && input <= '9')){
            infotype data = input -'0';
            push(S, data);
        }
    }
}
```

##### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<< endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;
}
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan7_Modul7/Output-Unguided3.png)

### Penjelasan unguided 3:
pada program diatas ditambahkan prosedur getInputStream yang berfungsi untuk mengambil data dari inpur user
```C++
    while((input = cin.get()) != '\n') {
            if ((input >= '0' && input <= '9')){
                infotype data = input -'0';
                push(S, data);
            }
        }
```
menggunakan while untuk user bisa menginput sampai menekan enter menggunakan cin.get() lalu mengecek kondisi input harus berupa angka 0-9 karena cin.get() akan terkonversi ke char ASCII jadi input user - '0', misal '1' ASCII nya adalah 49 => maka ketika dikurangi '0' akan menjadi 49-48 = 1. lalu data akan dipush kedalam stak S.

## Kesimpulan
pemilihan metode implementasi Stack—baik menggunakan Array maupun Linked List—sepenuhnya bergantung pada kebutuhan spesifik aplikasi dan preferensi desain. Pendekatan Array direkomendasikan jika aplikasi memerlukan kecepatan akses elemen yang cepat (O(1)) dan beroperasi dengan ukuran Stack yang statis, sebab Array lebih efisien dalam hal pemakaian memori dan akses langsung melalui indeks. Sebaliknya, Linked List merupakan pilihan yang lebih baik jika aplikasi memprioritaskan fleksibilitas ukuran yang dinamis dan sering melakukan operasi penyisipan/penghapusan (push/pop) yang cepat. Dengan demikian, pemahaman mendalam mengenai trade-off antara kecepatan, penggunaan memori, dan fleksibilitas keduanya adalah kunci dalam pengambilan keputusan implementasi yang tepat.

## Referensi
[1] Rishabh Singh. (2024). https://medium.com/@RobuRishabh/understanding-how-to-use-stack-queues-c-9f1fc06d1c5e
<br> [2]Risky Dwi Setiyawan.(2024) PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST https://journal.uii.ac.id/Snati/article/download/2208/2031