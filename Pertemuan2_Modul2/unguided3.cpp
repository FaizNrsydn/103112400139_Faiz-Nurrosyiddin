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
