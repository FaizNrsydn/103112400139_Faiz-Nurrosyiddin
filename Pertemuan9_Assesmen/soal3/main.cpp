#include "stackMahasiswa.h"
#include <iostream>
#include <string>

using namespace std;

Mahasiswa createMahasiswa(string nama, string nim, float tugas, float uts, float uas) {
    Mahasiswa M;
    M.Nama = nama;
    M.NIM = nim;
    M.NilaiTugas = tugas;
    M.NilaiUTS = uts;
    M.NilaiUAS = uas;
    return M;
}

int main() {
    StackMahasiswa S;
    // 1
    createStack(S);

    // 2
    Push(S, createMahasiswa("Venti", "11111", 75.7, 82.1, 65.5));
    Push(S, createMahasiswa("Xiao", "22222", 87.4, 88.9, 81.9));
    Push(S, createMahasiswa("Kazuha", "33333", 92.3, 88.8, 82.4));
    Push(S, createMahasiswa("Wanderer", "44444", 95.5, 85.5, 90.5));
    Push(S, createMahasiswa("Lynette", "55555", 77.7, 65.4, 79.9));
    Push(S, createMahasiswa("Chasca", "66666", 99.9, 93.6, 87.3));

    // 3
    View(S);

    // 4
    Pop(S);

    // 5
    View(S);

    // 6
    Mahasiswa M_update = createMahasiswa("Heizou", "77777", 99.9, 88.8, 77.7);
    Update(S, 3, M_update);

    // 7
    View(S);

    // 8
    SearchNilaiAkhir(S, 85.5, 95.5);

    return 0;
}