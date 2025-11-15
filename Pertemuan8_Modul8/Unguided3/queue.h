#ifndef QUEUE_H
#define QUEUE_H

const int MAXIMAL = 5;

typedef int infotype;
struct Queue{
    infotype info[MAXIMAL];
    int head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif