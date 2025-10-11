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