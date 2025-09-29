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