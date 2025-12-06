# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
1. Pengertian Multi Linked List
Multi linked list merupakan struktur data yang mengembangkan linked list biasa dengan setiap node memiliki lebih dari satu pointer, memungkinkan hubungan kompleks antar elemen seperti relasi parent-child atau multiple akses. Struktur ini cocok untuk menyimpan data dengan relasi banyak-ke-banyak, seperti penjualan sales atau pegawai dengan anak-anaknya.​

2. Karakteristik Utama
Setiap node berisi data dan multiple pointer, berbeda dari single linked list yang hanya satu pointer next. Multi linked list mendukung akses simultan ke beberapa kumpulan list terpisah, menjaga organisasi data tanpa duplikasi. Keunggulannya termasuk fleksibilitas penyisipan/penghapusan tanpa geser elemen, meski traversal lebih lambat O(n).

## Guided

### 1. MULTI LINKED LIST
#### mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

#### mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

#### main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan source code dalam membuat struktur data multi linked list, tidak jauh berbeda dengan double linked list dimana multi linked list terdapat list anak seperti contoh diatas dimana Kategori makanan merupakan induk list dan Nama makanan yang menjadi anak nya, untuk function dan prosedure nya sama seperti linked list biasa:
[1] terdapat fungsi isEmpty dan createList untuk induk dan anak.
<br>
[2] terdapat fungsi alokasi dan dealokasi untuk induk dan anak.
<br>
[3] terdapat fungsi insert first, last, after, delete first, last, after, find, dan update untuk induk.
<br>
[4] terdapat fungsi insert first, last, after, delete first, last, after, find, dan update untuk anak.
<br>
[5] terdapat fungsi print struktur multi linked list, print list induk dan anak.
<br>
[6] terdapat hapus list induk dan anak.

## Unguided

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
### Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.
### Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini :
### Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur printMLLStructure().

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :

#### multi.h
```C++
#ifndef MULTI_H
#define MULTI_H

#include<iostream>
using namespace std;

struct golonganHewan
{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan
{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild
{
    dataHewan isidata;
    NodeChild next, prev;
};

struct listChild
{
    NodeChild first, last;
};

struct nodeParent
{
    golonganHewan isidata;
    NodeParent next, prev;
    listChild L_Child;
};

struct listParent
{
    NodeParent first, last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent &LParent, bool tail);
#endif
```

#### bstree.cpp
```C++
#include "multi.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent){
    if(LParent.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyChild(listChild &LChild){
    if(LChild.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = weight;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void deallocNodeParent(NodeParent &NParent){
    if(NParent != NULL) {
        NParent->next = NParent->prev = NULL;
        delete NParent;
        NParent = NULL;
    }
}

void deallocNodeChild(NodeChild &NChild){
    if(NChild != NULL) {
        NChild->next = NChild->prev = NULL;
        delete NChild;
        NChild = NULL;
    }
}

void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent) == true) {
        LParent.first = LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent){
    if(isEmptyParent(LParent) == true){
        cout << "List parent kosong!" << endl;
    } else {
        NodeParent nodeHapus = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Child.first != NULL){
            deleteListChild(nodeHapus->L_Child);
        }
        deallocNodeParent(nodeHapus);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(isEmptyParent(LParent) == true){
        cout << "List parent kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeParent nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LParent.last = NPrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Child.first != NULL){
                deleteListChild(nodeHapus->L_Child);
            }
            deallocNodeParent(nodeHapus);
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)) {
        LChild.first = LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild){
    if(isEmptyChild(LChild) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        deallocNodeChild(nodeHapus);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(isEmptyChild(LChild) == true){
        cout << "List parent kosong!" << endl;
    } else {
        if(NPrev != NULL && NPrev->next != NULL){
            NodeChild nodeHapus = NPrev->next;
            NPrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = NPrev;
            } else {
                LChild.last = NPrev;
            }
            nodeHapus->next = NULL;
            deallocNodeChild(nodeHapus);
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void printMLLStructure(listParent &LParent){
    if(isEmptyParent(LParent)) {
        cout << "List parent kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Golongan    : " << nodeBantuParent->isidata.idGolongan << endl;
            cout << "Nama Golongan  : " << nodeBantuParent->isidata.namaGolongan << endl;
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Hewan     : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "      Nama Hewan   : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "      Habitat      : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "      Ekor         : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "      Bobot        : " << nodeBantuChild->isidata.bobot << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void deleteListChild(listChild &LChild){
    NodeChild nodeBantu = LChild.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        deallocNodeChild(nodeHapus);
    }
    LChild.first = LChild.last = NULL;
}

void searchHewanByEkor(listParent &LParent, bool tail){
    if(isEmptyParent(LParent) == true){
        cout << "List parent kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LParent.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.ekor == tail) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaGolongan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child   : " << nodeBantuChild->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                    cout << "Habitat    : " << nodeBantuChild->isidata.habitat << endl;
                    cout << "Ekor       : " << nodeBantuChild->isidata.ekor << endl;
                    cout << "Bobot      : " << nodeBantuChild->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent      : " << nodeBantuParent->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Golongan  : " << nodeBantuParent->isidata.namaGolongan << endl;
                    cout << "---------------------------" << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                nodeBantuParent = nodeBantuParent->next;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}
```

##### main.cpp
```C++
#include "multi.h"
#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    // NO 1 
    NodeParent Kat1 = allocNodeParent("G001", "Aves");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, Kat2);

    NodeParent Kat3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, Kat3);

    NodeParent Kat4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, Kat4);

    NodeParent Kat5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, Kat5);

    // --> Isi Kategori AVES (G001)
    NodeChild avs1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(Kat1->L_Child, avs1);

    NodeChild avs2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(Kat1->L_Child, avs2);

    // --> Isi Kategori MAMALIA (G002)
    NodeChild mml1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(Kat2->L_Child, mml1);

    NodeChild mml2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(Kat2->L_Child, mml2);

    NodeChild mml3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(Kat2->L_Child, mml3);

    // --> Isi Kategori AMFIBI (G004)
    NodeChild amf1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(Kat4->L_Child, amf1);

    cout << "   ### NOMOR 1 ###" << endl;
    printMLLStructure(L);
    cout << endl;

    // NO 2
    // 4. Test Pencarian (SEARCH)
    cout << "   ### NOMOR 2 ###" << endl;
    searchHewanByEkor(L, false);
    cout << endl;

    // NO 3
    cout << "   ### NOMOR 3 ###" << endl;
    cout << "> Menghapus G004" << endl;
    deleteAfterParent(L, Kat3);

    cout << "\n=== TAMPILAN AKHIR SETELAH DELETE ===" << endl;
    printMLLStructure(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan10_Modul10/Output-Unguided1-1.png)
![Screenshot Output Unguided 1_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan10_Modul10/Output-Unguided1-2.png)
![Screenshot Output Unguided 1_3](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan10_Modul10/Output-Unguided1-3.png)

### Penjelasan unguided 1:
#### Nomor 1
membuat ADT Multi linked list dalam file "multiLL.h" berisi struct golongan hewan yang menampung string id golongan dan nama golongan ini merupakan isi data untuk node parentnya, selanjutnya struct dataHewan yang menampung id hewan, nama hewan, habitat, ekor dan bobot, ini merupakan isi data untuk node childnya. terdapat type terdefinisi nodeParent pointer ke NodeParent dan nodeChild pointer NodeChild. Kemudian ada struct nodeChild, listChild dan nodeParent, listParent.

pada multiLL.cpp terdapat fungsi dan prosedur sebagai berikut: 
[1] fungsi isEmptyParent dan isEmptyChild untuk mengecek list parent dan child nya kosong atau tidak, fungsi mengembalikan nilai true jika list kosong dan false jika list ada.
<br>[2] prosedur createListParent dan createListChild untuk membuat list baru yang dimana nilai dari listParent dan listchild first nya NULL.
<br>[3] fungsi allocNodeParent dan allocNodeChild untuk mengalokasi data parent dan child, fungsi mengembalikan nilai node nya.
<br>[4] prosedur deallocNodeParent dan deallocNodeChild untuk menghapus node parent dan node child.
<br>[5] prosedure insertFirstParent dan insertLastParent untuk menambahkan node baru pada list parent pada list pertama dan terakhir.
<br>[6] prosedur insertFirstChild dan insertLastChild untuk menambahkan node baru pada list child pada list pertama dan terakhir.
<br>[7] prosedur printMLLStructure untuk mencetak list parent dan childnya.

#### Nomor 2
menambahkan prosedur searchHewanByEkor untuk mencari nama hewan berdasarkan hewan yang tidak memiliki ekor (ekor = false), program menggunakan while untuk menelusuri list parentnya lalu menggunakan while lagi untuk menulusuri list child nya dan mengecek jika hewan tersebut tidak memiliki ekor (ekor = false) maka program akan mencetak data hewan tersebut.

### Nomor 3
memanggil prosedur deleteFirstParent atau deleteAfterParent, karena kita ingin menghapus G004 maka kita panggil deleteAfterParent dimana G004 merupakan list Parent setelah G003, maka program akan menghapus list parent dengan id G004.

## Kesimpulan
Multi Linked List adalah pengembangan dari Linked List tradisional, di mana setiap node tidak hanya menyimpan data, tetapi juga lebih dari satu pointer. Struktur data ini memungkinkan pembuatan hubungan yang kompleks antar elemen, seperti relasi banyak-ke-banyak atau parent-child.

## Referensi
[1] Jurnal Modul 10 - Multi Linked List. (2025). Diakses dari https://id.scribd.com/document/618400689/Jurnal-Modul-10-Multi-Linked-List​
<br> [2] Detail Multi Linked List 1-N. (2025). Diakses dari https://www.scribd.com/document/733120041/Detail-Multi-Linked-List-1-N​
<br> [3] Makalah Struktur Data Variasi Linked List. (2025). Diakses dari https://id.scribd.com/document/362244036/MAKALAH-STRUKTUR-DATA-VARIASI-LINKED-LIST​
<br> [4] Implementasi Struktur Data Array Dan Linked List. Diakses dari https://padangjurnal.web.id/index.php/menulis/article/download/417/433/586​
<br> [5] Pengertian Linked List: Struktur Data. (2023). Diakses dari https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/