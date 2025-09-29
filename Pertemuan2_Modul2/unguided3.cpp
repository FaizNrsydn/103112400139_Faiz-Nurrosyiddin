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
    int hasil;

    for (int i = 0;i < ukuran;i++){
        total += arr[i];
    }

    hasil = total / ukuran;
    cout << "Rata-rata: " << hasil << endl; 
}

int main(){
    const int ukuran = 10;
    int arrA[ukuran] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMaximum(arrA,ukuran) << endl;
    cout << "Nilai terkecil dalam array: " << cariMinimum(arrA,ukuran) << endl;
    hitungRataRata(arrA, ukuran);
    return 0;
}
