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

bool isFull(Queue Q){
    if((Q.tail + 1) % MAXIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAXIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    infotype value;
    if(isEmptyQueue(Q) == true){
        cout << "empty queue" << endl;
        return -1;
    } else {
        value = Q.info[Q.head];
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAXIMAL;
        }
        return value;
    }
}

void printInfo(Queue Q){
    cout<< Q.head << " - " << Q.tail << "\t | ";
    if(isEmptyQueue(Q) == true){
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << Q.info[i] << " ";
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAXIMAL;
            count++;
        }
        cout << endl;
    }
}