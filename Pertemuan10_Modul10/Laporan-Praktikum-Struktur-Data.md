# <h1 align="center">Laporan Praktikum Modul 10 - TREE</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Struktur data Tree (Pohon) adalah koleksi simpul (node) yang terhubung secara hirarkis, menjadikannya struktur non-linear. Setiap Tree memiliki satu simpul utama yang disebut Akar (Root), yang berfungsi sebagai titik awal. Setiap simpul hanya boleh memiliki satu simpul Induk (Parent) (kecuali Root), namun dapat memiliki beberapa simpul Anak (Child). Simpul yang tidak memiliki anak disebut Daun (Leaf). Dalam C++, Tree diimplementasikan menggunakan struktur (struct) atau kelas (class) untuk merepresentasikan node, di mana setiap node berisi data (infotype) dan satu atau lebih pointer yang menunjuk ke simpul anaknya.Jenis pohon yang paling dasar adalah Binary Tree, di mana setiap simpul maksimal hanya memiliki dua anak: kiri (left) dan kanan (right). Bentuk paling penting dari ini adalah Binary Search Tree (BST). Dalam BST, keterurutan data dijaga: untuk setiap simpul, semua nilai di sub-pohon kirinya lebih kecil dari nilai simpul tersebut, dan semua nilai di sub-pohon kanannya lebih besar. Aturan ini memungkinkan operasi dasar seperti pencarian (searching), penyisipan (insertion), dan penghapusan (deletion) dilakukan dengan sangat efisien, biasanya dalam kompleksitas waktu BigO (log n) pada kasus rata-rata.

## Guided

### 1. TREE
#### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; // alias pointer = node

struct BST // nama struct nya BST
{
    int angka;
    node left, right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree &tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

#### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angka){
    node nodeBaru = new BST;
    nodeBaru->angka = angka;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree &tree, int angka){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angka < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angka > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angka == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}

bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan program membuat struktur data binary search tree. Pada bst.h membuat struct BST dan poiter ke variabel node dengan struct yang berisi data angka integer dan pointer left, right.
Untuk function" yang terdapat di bst.cpp function dasar seperti isEmpty digunakan untuk mengecek tree tersebut kosong atau tidak, create tree untuk set tree = Nil, alokasi untuk mengalokasikan data baru ke dalam struct BST dan dealokasi untuk menghapus data dalam struct tersebut. adapun function insert node untuk menambahkan node/data baru kedalam tree, search by data untuk mencari data dalam tree dan menampilkan parent dan siblingnya, printOrder untuk menampilkan tree dengan urutan tengah - kiri - kanan atau root - child kiri - child kanan, preOrder untuk menampilkan tree dengan urutan kiri - tengah - kanan atau child kiri - root - child kanan, postOrder untuk menampilkan tree dengan urutan kiri - kanan - tengah atau child kiri - child kanan - root. Untuk delete node sama saja speerti sebelumnya, hanya saja setelah pengecakan digunakan case yang mau dihapus.
<br>
untuk mostRight : Tujuannya Mencari node dengan nilai terbesar (maksimum) dalam sub-pohon yang diberikan. Melakukan iterasi (perulangan) dari node akar tree yang diberikan, selalu mengikuti pointer right hingga pointer right tersebut menunjuk ke Nil (NULL).
<br>
untuk mostLeft : Tujuannya Mencari node dengan nilai terkecil (minimum) dalam sub-pohon yang diberikan. Melakukan iterasi (perulangan) dari node akar tree yang diberikan, selalu mengikuti pointer left hingga pointer left tersebut menunjuk ke Nil (NULL).
<br>
untuk deleteTree : jika data tidak koosong maka return dan hapus data kiri, data kanan dealokasi kan data = kosong.
<br>
untuk int size : untuk mengembalikan jumlah semua node, jika isEmpty == benar maka return 0, jika tidak return 1 + jumlah semua node kiri + jumlah semua node kanan.
<br>
untuk int height : untuk mengembalikan jumlah level tree, jika isEmpty == true, return -1, tetapi jika tidak buat variabel baru untuk kiir kanan, variabel max height nya dan pengecekan jika variabel pertma lebih dari variabel kedua maka max height nya varibael pertma, jika tidak masuk ke variabel kedua, return 1 + maxheight nya


## Unguided

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:
### Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
### - fungsi hitungJumlahNode( root:address ) : integer
### /* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
### - fungsi hitungTotalInfo( root:address, start:integer ) : integer
### /* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
### - fungsi hitungKedalaman( root:address, start:integer ) : integer
### 3. Print tree secara pre-order dan post-order.

#### bstree.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct node *address;

struct node
{
    infotype info;
    address left, right;
};

//no 1
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);

// no 2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// no 3
void preOrder(address root);
void postOrder(address root);

#endif
```

#### bstree.cpp
```C++
#include "bstree.h"
#include<iostream>
using namespace std;

// no 1
address alokasi(infotype x){
    address nodeBaru = new node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x){
    if (root == Nil){
        root = alokasi(x);
    }else if (x < root->info)
    {
        insertNode(root->left,x);
    }else if (x > root->info)
    {
        insertNode(root->right,x);
    }
}

address findNode(address root, infotype x){
    address nodeBantu = root;
    bool ketemu = false;
    while(nodeBantu != Nil){
        if(x < nodeBantu->info){
            nodeBantu = nodeBantu->left;
        } else if(x > nodeBantu->info){
            nodeBantu = nodeBantu->right;
        } else if(x == nodeBantu->info){
            ketemu = true;
            break;
        }
    }
    if (ketemu){
        return nodeBantu;
    }else{
        return Nil;
    }
}

void printInorder(address root){
    if(root == Nil){
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

// no 2
int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
}

int hitungTotalInfo(address root, int start){
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return -1;
    } else {
        int hl = hitungKedalaman(root->left, start + 1);
        int hr = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

// no 3
void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}
```

##### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    // no 1
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    cout << "In-Order: ";
    printInorder(root);
    cout << endl;

    // no 2
    cout<<"\n";
    cout<<"kedalaman : "<< hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<< hitungJumlahNode(root)<<endl;
    cout<<"total : "<< hitungTotalInfo(root,0)<<endl;
    return 0;
}

// no 3
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);

    // no 3
    cout << "Pre-Order: ";
    preOrder(root);
    cout << endl;
    cout << "Post-Order: ";
    postOrder(root);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1&2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan10_Modul10/Output-Unguided1-1&2.png)
![Screenshot Output Unguided 1_3](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan10_Modul10/Output-Unguided1-3.png)

### Penjelasan unguided 1:
#### Nomor 1
Pada function insert Node:
```C++
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
```
pada kondisi pertama yaitu ketika tree masih kosong maka data baru yang akan masuk disimpan pada tree/root nya, kondisi kedua ketika data angka tersebut lebih kecil dari root/parent nya maka data akan disimppan dinode sebelah kiri, dan kondisi ketiga yaitu ketika data angka tersebut lebih besar dari root/parent nya maka data akan disimpan dinode sebelah kanan.
<br>
Selanjutnya pada function search:
```C++
    while(nodeBantu != Nil){
        if(x < nodeBantu->info){
            nodeBantu = nodeBantu->left;
        } else if(x > nodeBantu->info){
            nodeBantu = nodeBantu->right;
        } else if(x == nodeBantu->info){
            ketemu = true;
            break;
        }
    if (ketemu){
        return nodeBantu;
    }else{
        return Nil;
    }
    }
```
menggunakan while dengan nodeBantu merupakan root dan akan mengecek terdapat 3 kondisi jika data kurang dari root/parentnya maka nodeBantu akan mencari di node sebelah kiri dan ketika data lebih dari root/parentnya maka nodeBantu akan mencari di node sebelah kanan dan yang terakhir ketika data ditemukan nilai ketemu = true dan akan mengemblikan nodeBantu atau node yang ditemukan, jika tidak akan mengembalikan nilai Nil.
<br>
lalu fungsi printInOrder:
```C++
    if(root == Nil){
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
```
akan mengecek root tersebut bernilai Nil atau kosong atau tidak, lalu untuk urutannya tengah - kiri - kanan atau root - child kiri - child kanan

#### Nomor 2
```C++
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
```
hitung jumlahNode mengecek root kosong atau tidak, jika tidak mengembalikan nilai 1 + jumlah semua node kiri + jumlah semua node kanan. 
```C++
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
```
hitungTotalInfo mengecek root kosong atau tidak jika tidak isi data nya + hitungTotalInfo kiri, start + hitungTotalInfo kanan, start. start = 0.
```C++
    if(root == Nil){
        return -1;
    } else {
        int hl = hitungKedalaman(root->left, start + 1);
        int hr = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
```
hitung kedalaman mengecek root kosong atau tidak, jika tidak buat variabel baru untuk kiri kanan, variabel max height nya dan pengecekan jika variabel pertma lebih dari variabel kedua maka max height nya varibael pertma, start + 1, jika tidak masuk ke variabel kedua, return 1 + maxheight nya, start +1. start = 0.

### Nomor 3
```C++
void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}
```
preOrder (Tengah- kiri-kanan atauu root-child kiri-child kanan) : jika data nya == kosong return , ter-output data nya, ter-output preorder kiri preorder kanan. 
<br>
postOrder (kiri - kanan - tengah atau child kiri - child kanan - root) : jika data nya == kosong maka akan teroutput data kiri - data kanan.

## Kesimpulan
Struktur data Tree (Pohon) adalah metode penyimpanan data non-linear yang tersusun hirarkis, dimulai dari Akar (Root). Di C++, Tree direpresentasikan oleh node yang saling terhubung melalui pointer. Jenis utamanya, Binary Search Tree (BST), menerapkan aturan keterurutan (nilai left < Nilai root < Nilai right) yang memastikan semua operasi dasar (searching, insertion, deletion) berjalan sangat efisien dengan kompleksitas waktu BigO(log n).

## Referensi
[1] Chevalier, F., Auber, D., & Telea, A. (2007, September). Structural analysis and visualization of c++ code evolution using syntax trees. In Ninth international workshop on Principles of software evolution: in conjunction with the 6th ESEC/FSE joint meeting (pp. 90-97).
<br> [2] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA