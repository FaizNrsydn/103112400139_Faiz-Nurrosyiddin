#include <iostream>
using namespace std;

int main(){
    string satuan[] = {" ", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    int angka;
    cout << "Masukkan angka (0-99): ";
    cin >> angka;

    if (angka < 0 || angka > 99){
        cout << "angka harus 0-99";
    }else if (angka < 10){
        cout << satuan[angka];
    }else if (angka == 10){
        cout << "sepuluh";
    }else if (angka == 11){
        cout << "sebelas";
    }else if (angka < 20){
        cout << satuan[angka%10] << " belas";
    }else{
        int puluh = angka / 10;
        int sisa = angka % 10;

        cout << satuan[puluh] << " puluh";
        if (sisa != 0){
            cout << " " << satuan[sisa];
        }
    }
}