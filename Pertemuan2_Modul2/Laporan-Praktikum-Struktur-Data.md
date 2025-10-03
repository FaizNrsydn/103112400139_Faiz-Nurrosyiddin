# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori

Struktur data merupakan suatu konsep yang memberikan penjelasan mengenai koleksi atau kelompok data yang dapat dikarakteristikan oleh organisasi dan operasi yang dapat dilakukan terhadapnya. Pemilihan struktur data yang tepat dalam proses pemrograman dapat menghasilkan algoritma yang lebih jelas dan tepat, sehingga program secara keseluruhan menjadi lebih sederhana [1].

Salah satu jenis struktur data yang sederhana adalah array. Array, atau dalam beberapa literatur disebut larik, merupakan koleksi data yang elemen-elemennya memiliki nama yang sama dan bertipe data yang sama. Setiap elemen dalam array dapat diakses melalui indeks yang sesuai, memudahkan pengolahan data dalam jumlah besar secara efisien [1][2].

Selain itu, variabel dalam pemrograman memiliki fungsi untuk menyimpan nilai tertentu yang dapat berubah-ubah. Setiap variabel memiliki nama dan tipe yang spesifik, dan hanya data dengan tipe yang sesuai dengan tipe variabel yang dapat disimpan di dalamnya. Hal ini menjadikan variabel sebagai tempat penyimpanan data yang terorganisir dan mudah diakses selama proses eksekusi program [2].

### A. Array <br/>
#### 1. Array satu dimensi
Array merupakan struktur data yang dapat digunakan untuk menyimpan sekumpulan data dalam satu tempat memori yang berurutan serta dapat diakses menggunakan indeks. Perintah array memungkinkan penyimpanan dan pengelolaan data secara efisien dalam sebuah pemrograman.

#### 2. Array dua dimensi
Array berdimensi merupakan struktur data yang dapat menyimpan data dalam bentuk matriks atau tabel dua di- mensi atau dimensi yang lebih tinggi. Array berdimensi ini sangat memungkinkan untuk mengorganisir data da- lam bentuk grid dengan baris dan kolom. Array dengan dua dimensi sering digunakan untuk merepresentasikan matriks yang setiap elemennya memiliki baris dan kolom. Sementara array tiga dimensi paling banyak digunakan untuk mempresentasikan struktur. data yang lebih kom- pleks, seperti bangun ruang dan volume.

### B. Pointer <br/>
Merupakan variabel yang menyimpan alarat me- mori dari suatu nilai atau objek. Hal ini akan mernudah- kan programmer untuk memanipulasi suatu nilai atau objek. Pointer memiliki tujuan, di antaranya menerus- kan fungsi kepada fungsi lain, nengalokasikan objek baru kepada timbunan, dan melakukan iterasi atas ele- men dalam array atau kepada struktur data lainnya. Pointer dalam bahasa C++ dideklarasikan dengan ope- raror*. Apabila telah dideklarasikan, pointer diinisiali- sasikan dengan alamat memori yang valid sebelum di- gunakan. Pointer juga memiliki beberapa operasi, yaitu:
1. Operator dereference (*) digunakan untuk meng- akses sebuah nilai yang ditunjuk oleh pointer.
2. Operator address-of (&) digunakan untuk menda- patkan alamat memori dari suatu variabel.
3. Operator increment dan decrement (++ dan -) di- gunakan untuk menggeser pointer ke alamat me- mori berikutnya ataupun sebelumnya.

### C. Fungsi <br/>
Fungsi adalah suatu segmen kode yang mengerjakan tugas tertentu. Fungsi dapat diartikan juga sebagai suatu blok kode yang terpisah dari bagian program utarnanya dan di- gunakan untuk melakukan ugas-tugas tertentu. Kegunaan dari fungsi ialah untuk merangkum operasi urum dalamn satu blok yang nantinya dapat digunakan kembali. Dalam sebuah pemrograman. Terdapat pula kondisi.
### B. Prosedure <br/>

## Guided

### 1. Array satu dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i<5;i++){
        cout << "masukkan value index ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j<5)
    {
        cout << "isi index ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
    
}
```

### Penjelasan singkat guided 1:
Program diatas merupakan cara untuk menerima input dari user dan memasukkannya kedalam array 1 dimensi lalu adapun program untuk menampilkan isi ararynya, dimana kedua program tersebut menggunakan perulangan (for).

### 2. Array 2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1,2},
        {3,4}
    };
    int arrB[2][2] = {
        {2,3},
        {4,5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matrix 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);

    //perkalian matrix 2x2
    for (int i = 0; i < 2; i++){           //perulangan baris
        for (int j = 0; j < 2; j++){       //perulangan kolom
            for (int k = 0; k < 2; k++){   //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```

### Penjelasan singkat guided 2:
Program diatas merupakan program untuk menghitung penjumlahan dan perkalian matrix 2x2 menggunakan array 2 dimensi 

### 3. Function dan Prosedur

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX =arr[0];
    for (int i = 1;i < ukuran;i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i<ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan: " << totalJumlah <<endl;

    int totalKali = 1;
    for (int i = 0; i<ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian: " << totalKali <<endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0;i<ukuran;i++){
        cout << "masukkan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```

### Penjelasan singkat guided 3
program diatas merupakan implementasi dari function dan prosedur dimana ada function cariMax() untuk mencari nilai tertinggi yang ada di dalam array dan prosedur operasiAritmatika() untuk menjumlahkan dan mengalikan isi dalam array.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "value of a: " << a << endl;
    cout << "address of a: " << &a << endl;
    cout << "value stored in ptr: " << ptr << endl;
    cout << "value pointed to by ptr: " << *ptr << endl;

    tukar(&a,&b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```

### Penjelasan singkat guided 4
program diatas merupakan implementasi dari pointer untuk menukar dua variabel seperti kode diatas yaitu menukar variabel a dengan variabel b

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: (&a)" << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "alamat ref (&ref): " << &ref << endl;

    //mengubah nilai a lewat refence
    ref = 50;
    cout << "\nSetelah ref = 50;"<<endl;
    cout << "Nilai a: "<< a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```

### Penjelasan singkat guided 5
program diatas merupakan implementasi dari reference yang hampir mirip dengan pointer program diatas juga menukar variabel a dengan b.

## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {3,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrB[3][3] = {
        {2,3,4},
        {5,6,7},
        {8,9,1}
    };

    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(arrC);

    cout << "Hasil Pengurangan: " << endl;
    tampilkanHasil(arrD);

    for (int i = 0; i < 3; i++){           
        for (int j = 0; j < 3; j++){      
            for (int k = 0; k < 3; k++){   
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrE);
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided1.png)

### Penjelasan unguided 1:
Program diatas merupakan program operasi penjumlahan, pengurangan, dan perkalian matriks 3x3, dimana program tersebut menggunakan array 2 dimensi
```C++
    int arrA[3][3] = {
        {3,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrB[3][3] = {
        {2,3,4},
        {5,6,7},
        {8,9,1}
    };

    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};   
```
kode diatas merupakan deklarasi variabel array 2 dimensi dengan tipe data integer dimana arrA merupakan matriks 3x3 ke-1 dan arrB merupakan matriks 3x3 ke-2 dan arrC, arrD, arrE untuk menampung hasil dari penjumlahan, pengurangan, dan perkalian.
```C++ 
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
```
kode diatas merupakan proses untuk menjumlahkan dan mengurangkan kedua matriks dimana perulangan pertama berfungsi untuk mengulang baris dan perulangan kedua untuk kolom lalu hasil penjumlahan akan disimpan di variabel arrC dan pengurangan di variabel arrD.
```C++
    for (int i = 0; i < 3; i++){           
        for (int j = 0; j < 3; j++){      
            for (int k = 0; k < 3; k++){   
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }   
```
kode diatas merupakan proses untuk mengalikan kedua matriks 3x3 dimana perulangan pertama berfungsi untuk mengulang baris, perulangan kedua untuk kolom dan perulangan ketiga merupakan proses perkalian sesuai dengan aturan perkalian matriks 3x3 lalu hasilnya akan ditampung di variabel arrE
```C++
void tampilkanHasil(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}   
```
kode diatas merupakan prosedur untuk menampilkan hasil dari penjumlahan, pengurangan dan perkalian yang sudah ditampung di variabel arrC, arrD, dan arrE kita tinggal panggil prosedur dan masukkan variabel" yang menampung hasil dan akan ditampilkan.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

### POINTER
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int *ptr;

    ptr = &a;

    cout << "value of a: " << a << endl;
    cout << "address of a: " << &a << endl;
    cout << "value stored in ptr: " << ptr << endl;
    cout << "value pointed to by ptr: " << *ptr << endl;

    tukar(&a,&b,&c);
    cout << "After swapping, value of a = " << a << ", b = " << b <<" dan c = " << c << endl;

    return 0;
}
```

### REFERENCE
```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z){
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main(){
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: (&a)" << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "alamat ref (&ref): " << &ref << endl;

    //mengubah nilai a lewat refence
    ref = 50;
    cout << "\nSetelah ref = 50;"<<endl;
    cout << "Nilai a: "<< a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "After swapping, value of a = " << a << ", b = " << b <<" dan c = " << c << endl;

    return 0;
}
```

### Output Unguided 2 (pointer) :

##### Output 1 (pointer)

![Screenshot Output Unguided 2_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided2-1.png)

##### Output 2 (reference)

![Screenshot Output Unguided 2_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided2-2.png)

### Penjelasan unguided 2 (pointer & reference):
Program diatas kurang lebih sama dengan program guided pointer dan reference dimana hanya menambah 1 variabel yaitu z untuk ditukar-tukar isi dari ketiga variabel tersebut menggunakan pointer dan reference.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
### Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
### --- Menu Program Array ---
### 1. Tampilkan isi array
### 2. cari nilai maksimum
### 3. cari nilai minimum
### 4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran){
    int MIN =arr[0];
    for (int i = 1;i < ukuran;i++){
        if (arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

int cariMaximum(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1;i < ukuran;i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void hitungRataRata(int arr[], int ukuran){
    int total;
    for (int i = 0;i < ukuran;i++){
        total += arr[i];
    }
    cout << "Rata-rata: " << total << "/" << ukuran << " = " << total/ukuran << endl; 
}

int main(){
    const int ukuran = 10;
    int arrA[ukuran] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    cout << "-- Menu Program Array --" << endl;
    cout << "1. Tampilkan Isi Array" << endl;
    cout << "2. Cari Nilai Maksimum" << endl;
    cout << "3. Cari Nilai Minimum" << endl;
    cout << "4. Hitung Nilai Rata-rata" << endl;

    cout << "Pilih (1-4): ";
    cin >> pilihan;
    cout << endl;

    switch (pilihan)
    {
    case 1:
        cout << "Isi dari Array: ";
        for (int i = 0; i < ukuran; i++){
            cout << arrA[i] << " ";
        }
        cout << endl;
        break;
    case 2:
        cout << "Nilai terbesar dalam array: " << cariMaximum(arrA,ukuran) << endl;
        break;
    case 3:
        cout << "Nilai terkecil dalam array: " << cariMinimum(arrA,ukuran) << endl;
        break;
    case 4:
        hitungRataRata(arrA, ukuran);
        break;
    default:
        cout << "Input salah!!!" << endl;
        break;
    }
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided3-2.png)

##### Output 3

![Screenshot Output Unguided 3_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided3-3.png)

##### Output 4

![Screenshot Output Unguided 3_2](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan2_Modul2/Output-Unguided3-4.png)

### Penjelasan unguided 3
Program diatas merupakan program mencari nilai maksimum, minimum, dan menghitung rata-rata.
```C++
int cariMinimum(int arr[], int ukuran){
    int MIN =arr[0];
    for (int i = 1;i < ukuran;i++){
        if (arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}
```
kode diatas merupakan function untuk mencari nilai minimum menggunakan for dimana program akan membandingkan satu persatu dimulai dari indeks ke-1 sampai akhir mana yang paling kecil nilainya.

```C++
int cariMaximum(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1;i < ukuran;i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}
```
kode diatas merupakan function untuk mencari nilai maksimum menggunakan for dimana program akan membandingkan satu persatu dimulai dari indeks ke-1 sampai akhir mana yang paling besar nilainya.

```C++
void hitungRataRata(int arr[], int ukuran){
    int total;
    for (int i = 0;i < ukuran;i++){
        total += arr[i];
    }
    cout << "Rata-rata: " << total << "/" << ukuran << " = " << total/ukuran << endl; 
}
```
kode diatas merupakan prosedur untuk menghitung rata-rata dimana menggunakan perulangan dan menjumlahkan isi array dari indeks pertama sampai terakhir lalu dibagi dengan ukuran atau panjang array nya.

```C++
int main(){
    switch (pilihan)
    {
    case 1:
        cout << "Isi dari Array: ";
        for (int i = 0; i < ukuran; i++){
            cout << arrA[i] << " ";
        }
        cout << endl;
        break;
    case 2:
        cout << "Nilai terbesar dalam array: " << cariMaximum(arrA,ukuran) << endl;
        break;
    case 3:
        cout << "Nilai terkecil dalam array: " << cariMinimum(arrA,ukuran) << endl;
        break;
    case 4:
        hitungRataRata(arrA, ukuran);
        break;
    default:
        cout << "Input salah!!!" << endl;
        break;
    }
    return 0;
}
```
kode diatas merupakan pilihan user menggunakan switch dimana ketika user pilih 1 maka akan tampil isi array, 2 akan tampil nilai maksimum, 3 akan tampil nilai minimum dan 4 akan tampil hasil rata-rata, jika user menginputkan selain 1-4 maka akan tampil "Input salah!!!".

## Kesimpulan
Bahasa pemrograman C dan C++ merupakan fondasi penting dalam dunia akademik maupun industri karena memiliki performa tinggi, fleksibilitas, serta kontrol penuh terhadap sistem. C yang dikembangkan di Bell Labs pada awal 1970-an menjadi dasar lahirnya sistem operasi UNIX dan kemudian distandardisasi menjadi ANSI C yang banyak digunakan pada pengembangan sistem maupun perangkat embedded [2]. Perkembangan selanjutnya melahirkan C++ pada awal 1980-an oleh Bjarne Stroustrup, dengan membawa paradigma pemrograman berorientasi objek tanpa menghilangkan efisiensi bahasa C melalui fitur-fitur seperti class, inheritance, encapsulation, polymorphism, serta overloading [1][2].

C++ kemudian berkembang menjadi bahasa pemrograman tingkat tinggi yang mendukung paradigma prosedural maupun OOP, dengan struktur program sederhana, dukungan tipe data beragam, serta mekanisme input-output yang mudah digunakan [4]. Berkat kemampuannya dalam mengelola sumber daya sistem secara efisien dan memberikan kontrol tinggi terhadap memori, C++ banyak diterapkan dalam berbagai bidang seperti pengembangan sistem operasi, aplikasi desktop, sistem tertanam, hingga game, menjadikannya bahasa yang relevan untuk kebutuhan jangka panjang [1][3].

## Referensi

[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++. diakses pada 3 oktober 2025 melalui https://osf.io/preprints/osf/vyech_v1
<br>[2] Utami, E., Kom, M., Dhuhita, W. M. P., Kom, S., & Kom, M. (2017). Langkah Mudah Belajar Struktur Data Menggunakan C/C++. Elex Media Komputindo. diakses pada 3 oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=rURGDwAAQBAJ&oi=fnd&pg=PP1&dq=array+c%2B%2B+indonesia&ots=4Vjuxcpw5l&sig=fjIrURRcgTgCTZKEe1bA607sFS0&redir_esc=y#v=onepage&q&f=false
<br>[3] Nabila Chairunnisa,S.Kom (2024). "Langkah mudah belajar pemrograman C++". Penerbit ANAK HEBAT INDONESIA