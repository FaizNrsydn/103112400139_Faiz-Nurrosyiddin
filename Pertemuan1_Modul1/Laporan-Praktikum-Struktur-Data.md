# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori

Bahasa pemrograman C dan C++ merupakan bahasa yang banyak digunakan baik dalam bidang akademik maupun industri karena memilikiperforma tinggi dan fleksibilitas yang luas. Bahasa C sendiri dikembangkan di Bell Labs pada awal 1970-an, diturunkan dari bahasa B dan BCL, serta awalnya dirancang untuk mendukung sistem operasi UNIX. Seiring perkembangan, versi ANSI C menjadi standar yang dominan dan banyak digunakan dalam pengembangan sistem maupun perangkat embedded [2].

Sementara itu, bahasa C++ dikembangkan oleh Bjarne Stroustrup pada awal 1980-an di Bell Labs sebagai pengembangan dari bahasa C. Tujuan utama pengembangan C++ adalah untuk menyediakan kemampuan pemrograman berorientasi objek tanpa menghilangkan efisiensi bahasa C. C++ menghadirkan konsep baru seperti class, inheritance, encapsulation, polymorphism, serta fitur overloading yang membuatnya lebih modular, terstruktur, dan mendukung pemrograman jangka panjang [1][2].

Selain itu, sejarah awal lahirnya bahasa C/C++ tidak dapat dilepaskan dari perkembangan sistem operasi UNIX yang dimulai sekitar tahun 1960-an. Pada saat itu, Massachusetts Institute of Technology, Bell Labs, dan General Electric mengembangkan sistem operasi Multics. Namun karena kompleksitasnya, beberapa peneliti Bell Labs seperti Ken Thompson dan Dennis Ritchie kemudian mengembangkan sistem operasi UNIX yang lebih sederhana. Dari sinilah bahasa C kemudian muncul sebagai bahasa pemrograman utama yang mendukung pengembangan UNIX, dan menjadi dasar lahirnya C++ [3].

Dalam konteks penggunaannya, bahasa C++ tidak hanya populer di dunia akademik, tetapi juga banyak diterapkan dalam industri perangkat lunak, seperti pengembangan sistem operasi, aplikasi desktop, perangkat lunak sistem tertanam, hingga game. Keunggulan utama C++ terletak pada kemampuannya dalam mengelola sumber daya sistem secara efisien serta memberikan kontrol tinggi terhadap memori. Hal ini membuat C++ sangat sesuai digunakan untuk pengembangan sistem yang membutuhkan performa tinggi [1].

isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

### B. ...<br/>

...

#### 1. ...

#### 2. ...

#### 3. ...

## Guided

### 1. ...

```C++
source code guided 1
```

penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```

penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```

penjelasan singkat guided 3

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float angka1, angka2;

    cout << "Masukkan angka 1: ";
    cin >> angka1;
    cout << "Masukkan angka 2: ";
    cin >> angka2;

    cout << "Penjumlahan angka1 + angka2 = " << angka1 + angka2 << endl;
    cout << "Pengurangan angka1 - angka2 = " << angka1 - angka2 << endl;
    cout << "Perkalian angka1 * angka2 = " << angka1 * angka2 << endl;
    cout << "Pembagian angka1 / angka2 = " << angka1 / angka2 << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided1-2.png)

### Penjelasan unguided 1:
Program diatas merupakan program kalkulator yang sangat sederhana dimana program menerima 2 input-an dari user bertipe data float dan menghasilkan outpu-an berupa penjumlahan, pengurangan, perkalian, dan pembagian dari kedua input-an tersebut. proses perhitungan terjadi pada kode berikut:
```C++   
    cout << "Penjumlahan angka1 + angka2 = " << angka1 + angka2 << endl; //program menjumlahkan kedua angka
    cout << "Pengurangan angka1 - angka2 = " << angka1 - angka2 << endl; //program mengurangkan kedua angka
    cout << "Perkalian angka1 * angka2 = " << angka1 * angka2 << endl;   //program mengalikan kedua angka
    cout << "Pembagian angka1 / angka2 = " << angka1 / angka2 << endl;   //program membagi kedua angka
```

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main(){
    string satuan[] = {"Nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100){
        cout << "angka harus 0-100";
    }else if (angka < 10){
        cout << satuan[angka];
    }else if (angka == 10){
        cout << "sepuluh";
    }else if (angka == 11){
        cout << "sebelas";
    }else if (angka < 20){
        cout << satuan[angka%10] << " belas";
    }else if (angka < 100){
        int puluh = angka / 10;
        int sisa = angka % 10;

        cout << satuan[puluh] << " puluh";
        if (sisa != 0){
            cout << " " << satuan[sisa];
        }
    }else{
        cout << "seratus";
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided2-2.png)

### Penjelasan unguided 2:
Program diatas merupakan program yang mengubah angka menjadi tulisan dan angka yang diinputkan user harus 0-100.
```C++
    string satuan[] = {"Nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
```
Menggunakan array bertipe data string untuk menampung tulisan angka satuan.
```C++
    if (angka < 0 || angka > 100){
        cout << "angka harus 0-100";
    }
```
kondisi pertama yaitu mengecek apakah input-an dari user memenuhi angkanya yaitu range 0-100.
```C++
    else if (angka < 10){
        cout << satuan[angka];
    }
```
kondisi ke 2 yaitu ketika user menginputkan angka yang kurang dari 10 maka outputnya akan mengambil array satuan index ke sesuai angka yang diinputkan user misal inputnya 5 maka akan mengambil array satuan index ke-5 yaitu lima
```C++
    else if (angka == 10){
        cout << "sepuluh";
    }else if (angka == 11){
        cout << "sebelas";
    }
```
kedua kondisi tersebut dibuat karena angka 10 dan 11 tidak dapat diambil dari array satuan jadi ketika user menginput 10 atau 11 maka program langsung mencetak "sepuluh" atau "sebelas". 
```C++
    else if (angka < 20){
        cout << satuan[angka%10] << " belas";
    }
```
kondisi selanjutnya jika user menginputkan angka belasan yaitu 12-19 maka angka tersebut akan dimodulus 10 yang bertujuan untuk mengambil angka belakangnya misal 12%10 maka hasilnya 2 dan langsung mengarah ke array index ke-2 yaitu dua dilanjut dengan output " belas" yang akan menghasilkan output "dua belas".
```C++
    else if (angka < 100){
        int puluh = angka / 10;  //untuk mengambil angka pertama
        int sisa = angka % 10;   //untuk mengambil angka terakhir

        cout << satuan[puluh] << " puluh";
        if (sisa != 0){
            cout << " " << satuan[sisa];
        }
    }
```
kondisi selanjutnya jika user menginputkan angka 20-99 atau puluhan. pertama tama program akan menghitung angka yang diinputkan user dibagi dengan 10 bertujuan untuk mengambil angka pertamanya dan angka yang diinputkan user dimodulus dengan 10 untuk mengambil angka terakhir atau sisanya, misal user menginputkan 79 pertama tama akan dibagi 10 menghasilkan 7.9, tetapi karena tipe data integer jadi hanya mengambil angka 7 nya saja lalu 79 % 10 hasilnya 9 selanjutnya outputnya akan mengambil dari array satuan dengan index hasil dari pembagian dengan 10 dan diikuti " puluh", selanjutnya ada kondisi lagi untuk mengecek jika sisa dari modulus 10 tidak 0 maka output sisanya seperti yang dimisalkan tadi yaitu sisanya 9 maka akan mengambil array satuan index ke-9 jadi hasil akhirnya "tujuh puluh sembilan".

### 3. Buatlah program yang dapat memberikan input dan output sbb.

### input: 3

### output:

### 321\*123

###  21\*12

###   1\*1

###    \*

```C++
#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Input: ";
    cin >> n;
    cout << "output: " << endl;

    for (int i = 0; i <= n; i++){
        for (int j = 0;j<i;j++){
            cout << " ";
        }

        for (int j = n-i;j>=1;j--){
            cout << j;
        }

        cout << "*";

        for (int j = 1; j <= n-i;j++){
            cout << j;
        }
        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan1_Modul1/Output-Unguided3-2.png)

### Penjelasan unguided 3
Program diatas merupakan program nested loop (perulangan bersarang) dimana kita akan membuat segitiga terbalik dimana didalamnya terdapat angka yang mengulang.
```C++
    for (int i = 0; i <= n; i++){
```
pada perulangan pertama berfungsi untuk banyak baris yang ingin kita buat misal 3 artinya i akan mengulang sebanyak 4x karena i dimulai dari 0-3.
```C++
    for (int j = 0;j<i;j++){
            cout << " ";
        }
```
pada perulangan ini berfungsi untuk spasi pada awal baris jadi setiap i baris akan mencetak sebanyak i spasi didepan kecuali pada baris awal karena i = 0.
```C++
    for (int j = n-i;j>=1;j--){
            cout << j;
        }
```
pada perulangan ini untuk mencetak angka dari n-i sampai 1, jadi di baris awal karena i=0 maka n,n-1,n-2.... sampai 1 semakin kebawah maka akan semakin berkurang angkanya. misal n=3 maka pada baris awal akan menghasilkan "321".
```C++
    cout << "*";
```
ini bertujuan untuk mencetak bintang di tengah setiap baris.
```C++
    for (int j = 1; j <= n-i;j++){
            cout << j;
        }
```
perulangan terakhir yaitu setelah bintang ada angka yang dicetak dari 1 sampai n-i jadi kebalikan dari yang sebelumnya. misal n=3 maka pada baris awal akan menghasilkan 123 dan sama seperti sebelumnya semakin kebawah semakin berkurang angkanya.
```C++
    cout << endl;
```
kode tersebut untuk membuat baris baru setelah semua perulangan didalamnya selesai dijalankan.
## Kesimpulan

...

## Referensi

[1] Al Fatta, H. (2006). Dasar Pemrograman C++ Disertai dengan Pengenalan Pemrograman Berorientasi Objek. Penerbit Andi. Diakses pada 27 September 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=H20EMvS2EmQC&oi=fnd&pg=PA1&dq=pengenalan+c%2B%2B&ots=tY4pt6w9M6&sig=9ZBtgg8RaXBNnK4agosxsFrk4O0&redir_esc=y#v=onepage&q=pengenalan%20c%2B%2B&f=false
<br>[2] Huda, A., Ardi, N., & Muabi, A. (2021). Pengantar coding berbasis C/C++. UNP PRESS. Diakses pada 27 September 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=G9dbEAAAQBAJ&oi=fnd&pg=PA129&dq=pengenalan+c%2B%2B&ots=6eHR6Mcsae&sig=vbXmnbHDS9giglrNppsPkTw4XMQ&redir_esc=y#v=onepage&q=pengenalan%20c%2B%2B&f=false
<br>[3] Trianiza, I., Khirdany, E. N., Wahyudi, E., Vandika, A. Y., & Sofyan, S. (2025). Pengenalan Pemrograman Dasar Dunia Koding dengan C++. YPAD Penerbit. Diakses pada 27 September 2025 melalui https://journal.yayasanpad.org/index.php/ypadbook/article/view/434/319
