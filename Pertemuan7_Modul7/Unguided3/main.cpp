#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<< endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;
}