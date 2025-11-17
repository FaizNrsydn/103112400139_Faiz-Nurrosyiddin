#ifndef SLLInventory_H
#define SLLInventory_H
#define Nil NULL

#include<iostream>
using namespace std;

struct Product
{
    string nama;
    string SKU;
    int jumlah;
    float hargaSatuan;
    float diskonPersen;
};

typedef struct Node *address; 

struct Node
{
    Product info;
    address next;
};

struct List{
    address head;
};

// bagian A
bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address &addr);
void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L, Product &P);
void deletelast(List &L, Product &P);
void deleteAfter(List &L, address Q, address nodeHapus);
void updatePosition(List L, int posisi);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);
void viewList(List L);

// bagian B
void maxHargaAkhir(List L);

#endif