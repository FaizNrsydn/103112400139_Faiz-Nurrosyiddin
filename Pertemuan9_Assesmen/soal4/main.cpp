#include "queuePengiriman.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    queueEkspedisi Q;
    CreateQueue(Q);
    int pilih;
    bool running = true;

    while (running) { 
        cout << "\n--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan data Paket" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 0:
                running = false;
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia." << endl;
                break;
        }
    }
    return 0;
}