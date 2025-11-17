#include "queuePengiriman.h"
#include <iostream>

using namespace std;

bool isEmpty(queueEkspedisi Q){
    return Q.head == -1;
}

bool isFull(queueEkspedisi Q){
    return Q.tail == MAX - 1;
}

void CreateQueue(queueEkspedisi &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(queueEkspedisi &Q){
    Paket P;
    cout << "Kode Resi: ";
    cin >> P.kodeResi;
    cout << "Nama Pengirim: ";
    cin >> P.NamaPengirim;
    cout << "Berat Barang: ";
    cin >> P.beratBarang;
    cout << "Tujuan: ";
    cin >> P.tujuan;

    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = 0;
        }
        Q.tail++;
        Q.dataPaket[Q.tail] = P;
        cout << "Paket Resi " << P.kodeResi << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

void deQueue(queueEkspedisi &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        Paket P_out = Q.dataPaket[Q.head];
        cout << "Mengahapus data Resi " << P_out.kodeResi << "..." << endl;

        for(int i = Q.head; i < Q.tail; i++){
            Q.dataPaket[i] = Q.dataPaket[i+1];
        }

        Q.tail--;
        
        if(Q.tail < Q.head){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void viewQueue(queueEkspedisi Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "\n--- Daftar Paket dalam Queue ---" << endl;
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i - Q.head + 1 << ". Kode Resi: " << Q.dataPaket[i].kodeResi 
                << " (Pengirim: " << Q.dataPaket[i].NamaPengirim 
                << ", Berat: " << Q.dataPaket[i].beratBarang << " kg, Tujuan: " 
                << Q.dataPaket[i].tujuan << ")" << endl;
        }
        cout << "--------------------------------" << endl;
    }
    cout << endl;
}