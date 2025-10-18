#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infoType;
typedef struct ElmList *address; 

struct ElmList
{
    infoType info;
    address next;
};

struct List
{
    address first;
};

void CreateList(List &L);
address alokasi(infoType x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteAfter(List &L, address P, address Q);
void deleteLast(List &L);
int nbList(List L);
void deleteList(List &L);

#endif