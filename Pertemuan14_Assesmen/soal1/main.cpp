#include "bst.h"
#include<iostream>
using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    // NOMOR 1
    insertNode(tree, alokasi(50, "Monitor LED", 10));
    insertNode(tree, alokasi(30, "Keyboard RGB", 20));
    insertNode(tree, alokasi(70, "Mouse Gaming", 15));
    insertNode(tree, alokasi(20, "Kabel HDMI", 50));
    insertNode(tree, alokasi(40, "Headset 7.1", 12));
    insertNode(tree, alokasi(60, "Webcam HD", 8));
    insertNode(tree, alokasi(80, "Speaket BT", 5));

    // NOMOR 2
    cout << " === InOrder === \n"; inOrder(tree); cout << endl;
    cout << " === PreOrder === \n"; preOrder(tree); cout << endl;
    cout << " === PostOrder ===\n"; postOrder(tree); cout << endl;

    // NOMOR 3
    cout << " === Search ID 40 === " << endl;
    searchById(tree, 40);
    cout << endl;

    // NOMOR 4
    cout << " === Search ID 99 === " << endl;
    searchById(tree, 99);
    cout << endl;

    // NOMOR 5
    bool found;
    cout << " === Search Product 'Webcam HD' === " << endl;
    found = false;
    searchByProduct(tree, "Webcam HD", found);
    if (!found) cout << "Produk tidak ditemukan" << endl;
    cout << endl;

    // NOMOR 6
    cout << " === Search Product 'Printer' === " << endl;
    found = false;
    searchByProduct(tree, "Printer", found);
    if (!found) cout << "Produk tidak ditemukan" << endl;
    cout << endl;

    // NOMOR 7
    node minNode = findMin(tree);
    node maxNode = findMax(tree);
    if (minNode) cout << "Min ID: " << minNode->idProduk << " (" << minNode->namaProduk << ")" << endl;
    if (maxNode) cout << "Max ID: " << maxNode->idProduk << " (" << maxNode->namaProduk << ")" << endl;
    cout << endl;

    // NOMOR 8 & 9
    deleteNode(tree, 20);
    cout << " === Delete 20 === \n"; inOrder(tree); cout << endl;

    // NOMOR 10 & 11
    deleteNode(tree, 30);
    cout << " === Delete 30 === \n"; inOrder(tree); cout << endl;

    // NOMOR 12 & 13
    deleteNode(tree, 50);
    cout << " === Delete 50 === \n"; inOrder(tree); cout << endl;

    // NOMOR 14 & 15
    deleteTree(tree);
    cout << " === Delete Tree ===" << endl;
    cout << " >>> InOrder: "; inOrder(tree); 
    if (isEmpty(tree))
    {
        cout << "Tree Kosong!!!";
    }
    
    return 0;
}