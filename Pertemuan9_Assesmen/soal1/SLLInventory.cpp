#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    if(L.head == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(List &L) {
    L.head = Nil;
}

address allocate(Product P) { 
    address nodeBaru = new Node;
    nodeBaru->info.nama =  P.nama;
    nodeBaru->info.SKU = P.SKU;
    nodeBaru->info.jumlah = P.jumlah;
    nodeBaru->info.hargaSatuan = P.hargaSatuan;
    nodeBaru->info.diskonPersen =P.diskonPersen;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void deallocate(address &addr) {
    addr->next = Nil;
    delete addr;
}

void insertFirst(List &L, Product P) {
    address nodeBaru = allocate(P);
    nodeBaru->next = L.head; 
    L.head= nodeBaru;
}

void insertLast(List &L, Product P){
    address nodeBaru = allocate(P);
    if (isEmpty(L)) {
        L.head = nodeBaru;
    } else {
        address nodeBantu = L.head;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void insertAfter(List &L, address Q, Product P){
    address nodeBaru = allocate(P);
    if (Q != Nil) {
        nodeBaru->next = Q->next;
        Q->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void deleteFirst(List &L, Product &P){
    address nodeHapus;
    if (isEmpty(L) == false) {
        nodeHapus = L.head;
        L.head = L.head->next;
        nodeHapus->next = Nil;
        deallocate(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}
void deletelast(List &L, Product &P){
    address nodeHapus, nodePrev;
    if(isEmpty(L) == false){
        nodeHapus = L.head;
        if(nodeHapus->next == Nil){
            L.head->next = Nil;
            deallocate(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            deallocate(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}
void deleteAfter(List &L, address Q, address nodeHapus){
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (Q != Nil && Q->next != Nil) { 
            nodeHapus = Q->next;       
            Q->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            deallocate(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updatePosition(List L, int posisi){
    int idx = 1;
    address nodeBantu = L.head;
    while (nodeBantu != Nil)
    {
        if (idx == posisi)
        {
            cout << "Masukkan update data pada posisi ke- : "<< idx << endl;
            cout << "Nama : ";
            cin >> nodeBantu->info.nama;
            cout << "SKU : ";
            cin >> nodeBantu->info.SKU;
            cout << "Jumlah : ";
            cin >> nodeBantu->info.jumlah;
            cout << "Harga Satuan : ";
            cin >> nodeBantu->info.hargaSatuan;
            cout << "Diskon Persen : ";
            cin >> nodeBantu->info.diskonPersen;
            cout << endl;
            break;
        }else{
            // break;
            idx++;        
        }
        nodeBantu = nodeBantu->next;
    }
    
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice){
        if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.head;
        int posisi = 0;
        bool found = false;
        cout << "--- Data dalam range harga " << minPrice << " - " << maxPrice << " ---" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->info.hargaSatuan;
            if(harga >= minPrice && harga <= maxPrice) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "[" << posisi << "]" << endl;
                cout << "Nama : " << nodeBantu->info.nama << endl;
                cout << "SKU : " << nodeBantu->info.SKU << endl;
                cout << "Jumlah : " << nodeBantu->info.jumlah << endl;
                cout << "Harga Satuan : " << nodeBantu->info.hargaSatuan << endl;
                cout << "Diskon Persen : " << nodeBantu->info.diskonPersen << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dalam range harga tersebut!" << endl;
        }
    }
    cout << endl;
}

void viewList(List L){
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.head;
        int idx = 0;
        while (nodeBantu != Nil) {
            idx++;
            cout << "[" << idx << "]" << endl;
            cout << "Nama : " << nodeBantu->info.nama << endl;
            cout << "SKU : " << nodeBantu->info.SKU << endl;
            cout << "Jumlah : " << nodeBantu->info.jumlah << endl;
            cout << "Harga Satuan : " << nodeBantu->info.hargaSatuan << endl;
            cout << "Diskon Persen : " << nodeBantu->info.diskonPersen << endl;
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

// bagian B
float hitungHargaAkhir(float hargaSatuan, float diskonPersen) {
    return hargaSatuan * (1.0 - (diskonPersen / 100.0));
}

void maxHargaAkhir(List L){
    if (isEmpty(L)) {
        cout << "List kosong. Tidak dapat mencari Harga Akhir maksimum." << endl;
        return;
    }

    address nodeBantu = L.head;
    float maxHarga = -1.0;
    
    while (nodeBantu != Nil) {
        float hargaAkhirSaatIni = hitungHargaAkhir(nodeBantu->info.hargaSatuan, nodeBantu->info.diskonPersen);
        if (hargaAkhirSaatIni > maxHarga) {
            maxHarga = hargaAkhirSaatIni;
        }
        nodeBantu = nodeBantu->next;
    }

    cout << "--- Produk dengan Harga Akhir Maksimum (Rp" << maxHarga << ") ---" << endl;
    nodeBantu = L.head; 
    int posisi = 0;
    bool found = false;

    while (nodeBantu != Nil) {
        posisi++;
        float hargaAkhirSaatIni = hitungHargaAkhir(nodeBantu->info.hargaSatuan, nodeBantu->info.diskonPersen);
        
        if (hargaAkhirSaatIni == maxHarga) {
            cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
            cout << "[" << posisi << "]" << endl;
            cout << "Nama : " << nodeBantu->info.nama << endl;
            cout << "SKU : " << nodeBantu->info.SKU << endl;
            cout << "Jumlah : " << nodeBantu->info.jumlah << endl;
            cout << "Harga Satuan : " << nodeBantu->info.hargaSatuan << endl;
            cout << "Diskon Persen : " << nodeBantu->info.diskonPersen << endl;
            cout << "Harga Akhir : " << hargaAkhirSaatIni << endl;
            found = true;
        }
        nodeBantu = nodeBantu->next;
    }
    
    if (!found) {
        cout << "Terjadi kesalahan saat mencari produk dengan harga akhir maksimum." << endl;
    }
    cout << endl;
}