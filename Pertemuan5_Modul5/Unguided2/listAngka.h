#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

typedef int dataAngka;
typedef struct node *address;

struct node{
    dataAngka angka;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void updateFirst (linkedlist &L);
void updateLast (linkedlist &L);
void updateAfter (linkedlist &L, address nodePrev);

void SearchByData(linkedlist list, int data);
void SearchByAddress(linkedlist list, address node);
void SearchByRange(linkedlist list, int nilaiMin);

void penjumlahElm(linkedlist List);
void penguranganElm(linkedlist List);
void perkalianElm(linkedlist List);
#endif
