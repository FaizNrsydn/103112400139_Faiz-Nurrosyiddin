#include <iostream>
#include "listAngka.h"
using namespace std;

int main(){
    linkedlist L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT & DELETE AFTER ---" << endl;
    printList(L);

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(L);

    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    penjumlahElm(L);
    penguranganElm(L);
    perkalianElm(L);
    return 0;
}