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