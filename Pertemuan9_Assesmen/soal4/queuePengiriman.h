#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Paket
{
    string kodeResi;
    string NamaPengirim;
    int beratBarang;
    string tujuan;
};


const int MAX = 5;

struct queueEkspedisi
{
    Paket dataPaket[MAX];
    int head;
    int tail;
};

void CreateQueue(queueEkspedisi &Q);
bool isEmpty(queueEkspedisi Q);
bool isFull(queueEkspedisi Q);
void enQueue(queueEkspedisi &Q);
void deQueue(queueEkspedisi &Q);
void viewQueue(queueEkspedisi Q);

#endif