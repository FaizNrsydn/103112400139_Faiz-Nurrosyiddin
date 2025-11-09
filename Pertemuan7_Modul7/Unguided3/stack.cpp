#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 20;
}

void createStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stak Penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stak Kosong!" << endl;
        return 0;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i)
        {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S){
    if (isEmpty(S)){
        cout << "Stack Kosong!" << endl;
    }else{
        Stack tampung1;
        Stack tampung2;
        createStack(tampung1);
        createStack(tampung2);
        while (!isEmpty(S))
        {
            push(tampung1, pop(S));
        }
        while (!isEmpty(tampung1))
        {
            push(tampung2, pop(tampung1));
        }
        while (!isEmpty(tampung2))
        {
            push(S, pop(tampung2));
        }      
    }
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack penuh!" << endl;
    }

    Stack tempstack;
    createStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);
    

    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
}

void getInputStream(Stack &S){
    int input ;

    while((input = cin.get()) != '\n') {
        if ((input >= '0' && input <= '9')){
            infotype data = input -'0';
            push(S, data);
        }
    }
}

