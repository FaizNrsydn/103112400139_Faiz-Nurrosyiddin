#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main(){
    List L;
    // no 1
    createList(L);
    Product A,B,C;
    A = {"Pulpen", "A001", 20, 2500, 0};
    B = {"Buku Tulis", "A002", 15, 5000, 0};
    C = {"Penghapus", "A003", 30, 1500, 0};

    // no 2
    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);

    // no 3
    viewList(L);

    // no 4
    deleteFirst(L, A);
    
    // no 5
    viewList(L);

    // no 6
    updatePosition(L, 2);

    // no 7
    viewList(L);

    // no 8
    searchByFinalPriceRange(L, 2000, 7000);

    // bagian B
    maxHargaAkhir(L);
    return 0;
}