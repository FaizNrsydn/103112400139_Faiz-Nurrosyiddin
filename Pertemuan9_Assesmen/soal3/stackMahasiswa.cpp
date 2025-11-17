#include "stackMahasiswa.h"

bool isEmpty(StackMahasiswa StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa &StackMHS, Mahasiswa dataMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh! Tidak dapat menambahkan data." << endl;
    } else {
        StackMHS.Top++;
        StackMHS.dataMahasiswa[StackMHS.Top] = dataMHS;
    }
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data yang bisa di-Pop." << endl;
    } else {
        StackMHS.Top--;
    }
}

void Update(StackMahasiswa &StackMHS, int posisi, Mahasiswa dataMHS) {
    int indeks = posisi - 1;
    if (indeks < 0 || indeks > StackMHS.Top) {
        cout << "Posisi " << posisi << " tidak valid untuk diupdate." << endl;
    } else {
        StackMHS.dataMahasiswa[indeks] = dataMHS;
        cout << "Data Mahasiswa pada posisi ke-" << posisi << " berhasil diupdate." << endl;
    }
}

void View(StackMahasiswa StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "\nStack kosong. Tidak ada data yang ditampilkan." << endl;
    } else {
        for (int i = 0; i <= StackMHS.Top; i++) {
            float nilaiAkhir = 
                0.20 * StackMHS.dataMahasiswa[i].NilaiTugas + 
                0.40 * StackMHS.dataMahasiswa[i].NilaiUTS + 
                0.40 * StackMHS.dataMahasiswa[i].NilaiUAS;

            cout << "[" << i + 1 << "] (NIM: " << StackMHS.dataMahasiswa[i].NIM << ", Nama: " << StackMHS.dataMahasiswa[i].Nama 
                << ", Nilai Akhir: " << nilaiAkhir << ")" << endl;
        }
        cout << endl;
    }
}

float hitungNilaiAkhir(const Mahasiswa &M) {
    return 0.20 * M.NilaiTugas + 0.40 * M.NilaiUTS + 0.40 * M.NilaiUAS;
}

void SearchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong. Tidak dapat melakukan pencarian." << endl;
        return;
    }
    
    bool found = false;
    
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = hitungNilaiAkhir(StackMHS.dataMahasiswa[i]);
        
        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Posisi ke-" << i + 1 << ": Nama: " << StackMHS.dataMahasiswa[i].Nama 
                << ", NIM: " << StackMHS.dataMahasiswa[i].NIM << ", Nilai Akhir: " << nilaiAkhir << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Tidak ditemukan mahasiswa dengan Nilai Akhir dalam rentang tersebut." << endl;
    }
}