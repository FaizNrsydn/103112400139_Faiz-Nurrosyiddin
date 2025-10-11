# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
ADT adalah tipe data tertentu yang didefinisikan oleh pemrogram untuk kemudahan pemrograman serta untuk mengakomodasi tipe-tipe data yang tidak secara spesifik diakomodasi oleh bahasa pemrograman yang digunakan. Maka, secara informal dapat dinyatakan bahwa ADT adalah :
1. Tipe data abstrak ADT pertama kali ditemukan oleh para ilmuan komputer utuk memisahkan struktur penyimpanan dari perilaku tipe data yang abstrak seperti misalnya, Tumpukan (Stack) serta antrian (Queue). Seperti kita duga, pemrogram tidak perlu tahu bagaimana Tumpukan(Stack) perubahan inplementasi ADT tidak mengubah program yang menggunakannya secara keseluruhan, dengan catatan bahwa interface ADT tersebut dengan ‘dunia luar’ tetap dipertahankan.
2. Pemakaian dan pembuatan ADT dapat dilakukan secara terpisah, yang perlu dibicarakan antara pembuat dan pengguna ADT adalah interface ADT yang bersangkutan.
3. ADT merupakan sarana pengembangan sistem yang bersifat modular, memungkinkan suatu sistem dikembangkan oleh beberapa orang anggota tim kerja dimana masing-masing anggota tim bisa melakukan bagiannya sendiri-sendiri dengan tetap mempertahankan keterpaduannya dengan anggota tim yang lain.

## Guided

### 1. Rata-rata

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "masukkan nama mahasiswa: ";
    cin >> m.nama;
    cout << "masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2)/2;
}


int main(){
    mahasiswa mhs;

    inputMhs(mhs);
    cout << "Rata-rata: " << rata2(mhs);
    return 0;
}
```

### Penjelasan singkat guided 2:
Program diatas merupakan program untuk menghitung rata-rata nilai.

### 2. ADT

##### pelajaran.h
```C++
//header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```

##### pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

// implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Mapel: " << pel.kodeMapel << endl; 
}
```

##### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Penjelasan singkat guided 2:
Program diatas merupakan program sederhana untuk menyimpan dan menampilkan nama pelajaran dan kode pelajaran menggunakan ADT

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

##### mhs.h
```C++
#ifndef MHS_H
#define MHS_H

#include <iostream>
using namespace std;

const int MAX_MHS = 10;

struct dataMhs{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputData(dataMhs &mhs);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanData(dataMhs mhs[], int jumlah);

#endif
```

##### mhs.cpp
```C++
#include <iostream>
#include "mhs.h"
using namespace std;

void inputData(dataMhs &mhs){
    cout << "Nama: ";
    cin >> mhs.nama;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Nilai Tugas: ";
    cin >> mhs.tugas;

    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

float hitungNilaiAkhir(float uts, float uas, float tugas){
    return 0.3*uts + 0.4*uas + 0.3*tugas;
}

void tampilkanData(dataMhs mhs[], int jumlah){
    for (int i = 0; i < jumlah; i++){
        cout << "Data Mahasiswa ke-" << i+1 << ":" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << endl;
    }
}
```

##### main.cpp
```C++
#include <iostream>
#include "mhs.h"
using namespace std;

int main(){
    dataMhs mhs[MAX_MHS];
    int jumlah = 0;

    while (jumlah < MAX_MHS){
        cout << "Masukkan Data Mahasiswa ke-" << jumlah+1 << endl;
        inputData(mhs[jumlah]);
        jumlah++;

        char tambah;
        cout << "Apakah ingin tambah data mahasiswa lagi?(y/n): ";
        cin >> tambah;
        if (tambah == 'n'){
            break;
        }
    }

    tampilkanData(mhs, jumlah);
    return 0;    
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan3_Modul3/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan3_Modul3/Output-Unguided1-2.png)

### Penjelasan unguided 1:
Program diatas merupakan program menyimpan data nama, nim, nilai uts, nilai uas, nilai tugas dan nilai akhir menggunakan ADT
data disimpan pada struct di file mhs.h:
```C++
struct dataMhs{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};
```
dan juga membuat 3 function pada file mhs.h:
```C++
void inputData(dataMhs &mhs);
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanData(dataMhs mhs[], int jumlah);
```
Pada file mhs.cpp kita masukkan isi dari 3 function yang sudah dibuat di file mhs.h:
```C++
void inputData(dataMhs &mhs){
    cout << "Nama: ";
    cin >> mhs.nama;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Nilai Tugas: ";
    cin >> mhs.tugas;

    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}
```
function pertama berfungsi untuk menginput data mahasiswa yaitu nama, nim, nilai uts, nilai uas, nilai tugas. dan memasukan data tersebut ke function hitung nilai akhir
```C++
float hitungNilaiAkhir(float uts, float uas, float tugas){
    return 0.3*uts + 0.4*uas + 0.3*tugas;
}
```
function ini berfungsi untuk menghitung nilai akhir dengan rumus 0.3 * nilai uts + 0.4 * nilai uas + 0.3 * nilai tugas
```C++
void tampilkanData(dataMhs mhs[], int jumlah){
    for (int i = 0; i < jumlah; i++){
        cout << "Data Mahasiswa ke-" << i+1 << ":" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << endl;
    }
}
```
function ini berfungsi untuk menampilkan data yang sudah diinputkan dan nilai akhir yang sudah dihitung.
```C++
    while (jumlah < MAX_MHS){
        cout << "Masukkan Data Mahasiswa ke-" << jumlah+1 << endl;
        inputData(mhs[jumlah]);
        jumlah++;

        char tambah;
        cout << "Apakah ingin tambah data mahasiswa lagi?(y/n): ";
        cin >> tambah;
        if (tambah == 'n'){
            break;
        }
    }
```
pada file main.cpp, terdapat while untuk berfungsi agar user dapat menginput data sebanyak 10x setiap selesai menginputkan data user akan ditanya ingin tambah data lagi atau tidak jika user menginputkan y maka user bisa input lagi dan jika user menginputkan n maka program akan langsung menampilkan data yang sudah diinputkan.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel
### Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
```C++
Type pelajaran <
namaMapel : string kodeMapel : string
function create_pelajaran( namapel : string, kodepel: string ) → pelajaran
procedure tampil_pelajaran( input pel: pelajaran )
```
### Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
### Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
using namespace std;
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran (namapel,kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

##### pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

##### pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Mapel: " << pel.kodeMapel << endl; 
}
```

##### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2:

##### Output 1

![Screenshot Output Unguided 2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan3_Modul3/Output-Unguided2.png)

### Penjelasan unguided 2:
Program diatas kurang lebih sama dengan program guided ADT dimana berfungsi untuk menyimpan data pada struct di file pelajaran.h dan membuat function untuk memasukan datanya dan menampilkannya di file pelajaran.cpp dan mengeksekusi programnya di main.cpp.

### 3.  Buatlah program dengan ketentuan :
### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

##### array.h
```C++
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

const int SIZE = 3;

void tampilArray(int arr[SIZE][SIZE]);
void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]);
void tukar(int *x, int *y);

#endif
```

##### array.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp; 
        }
    }
}

void tukar(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
```

##### main.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

int main(){
    int arrA[SIZE][SIZE] = {
        {3,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrB[SIZE][SIZE] = {
        {2,3,4},
        {5,6,7},
        {8,9,1}
    };

    cout << "TUKAR ARRAY 2D" << endl;
    cout << "Sebelum Ditukar: " << endl;
    cout << "Array A: " << endl;
    tampilArray(arrA);
    cout << "Array B: " << endl;
    tampilArray(arrB);

    tukarArray(arrA, arrB);

    cout << "Setelah Ditukar: " << endl;
    cout << "Array A: " << endl;
    tampilArray(arrA);
    cout << "Array B: " << endl;
    tampilArray(arrB);

    cout << endl;

    int a = 20, b = 30;
    cout << "TUKAR 2 VARIABEL" << endl;
    cout << "Sebelum Ditukar: " << endl;
    cout << "var a: " << a << endl;
    cout << "var b: " << b << endl;
    cout << "Setelah Ditukar: " << endl;
    tukar(&a,&b);
    cout << "var a: " << a << endl;
    cout << "var b: " << b << endl;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan3_Modul3/Output-Unguided3.png)

### Penjelasan unguided 3
Program diatas merupakan program array 2D 3x3 dan program berfungsi untuk menampilkan, menukar array 2D tersebut dan juga ada 2 buah variabel pointer untuk ditukar juga
```C++
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

const int SIZE = 3;

void tampilArray(int arr[SIZE][SIZE]);
void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]);
void tukar(int *x, int *y);

#endif
```
pada array.h hanya membuat function saja dan mendeklarasi variabel global untuk size arraynya
```C++
void tampilArray(int arr[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
```
function pada array.cpp diatas berfungsi untuk menampilkan array
```C++
void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp; 
        }
    }
}
```
function selanjutnya berfungsi untuk menukar array menggunakan temporary variabel
```C++
void tukar(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
```
function terakhir digunakan untuk menukar 2 variabel dengan pointer
pada file main.cpp berisi deklarasi variabel untuk array 2D dan mengisi arraynya
```C++
    int arrA[SIZE][SIZE] = {
        {3,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrB[SIZE][SIZE] = {
        {2,3,4},
        {5,6,7},
        {8,9,1}
    };
```
dan selebihnya hanya code eksekusi programnya

## Kesimpulan
ADT (Abstract Data Type) secara informal dapat dinyatakan sebagai kontrak logis dan sarana modularitas dalam pemrograman. ADT diciptakan untuk memisahkan perilaku tipe data abstrak (seperti Stack atau Queue) dari detail struktur penyimpanan atau implementasi internalnya.  Pemrogram hanya perlu mengetahui antarmuka (interface) ADT—yaitu, operasi yang dapat dilakukan—tanpa perlu tahu bagaimana operasi tersebut diimplementasikan. Pemisahan ini memungkinkan penggunaan dan pembuatan ADT dapat dilakukan secara terpisah, serta menjadikan ADT sebagai sarana pengembangan sistem yang modular, di mana perubahan pada implementasi internal tidak memengaruhi program pengguna, selama antarmuka eksternal tetap dipertahankan.

## Referensi
[1] TRIASE, (2020). DIKLAT EDISI REVISI STRUKTUR DATA. diakses pada 11 oktober 2025 melalui http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf