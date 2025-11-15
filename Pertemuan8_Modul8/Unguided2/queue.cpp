#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return Q.tail == 5-1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue Penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    }else{
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
        return value;
    }
}

void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)){
        cout << "empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}