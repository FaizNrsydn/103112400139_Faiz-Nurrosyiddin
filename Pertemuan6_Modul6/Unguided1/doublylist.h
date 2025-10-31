#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include<iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);

void insertLast(List &L, address P);

address findElm(List L, infotype x);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address prec, address &P);
void deleteByNopol(List &L, infotype x);

#endif