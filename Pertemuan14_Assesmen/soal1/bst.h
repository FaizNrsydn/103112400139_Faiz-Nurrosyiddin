#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST
{
    int idProduk;
    string namaProduk;
    int stok;
    node left, right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int id, string nama, int stok);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchById(BinTree tree, int id);
void searchByProduct(BinTree tree, string nama, bool &found);
bool deleteNode(BinTree &tree, int id);
void inOrder(BinTree tree);
void preOrder(BinTree tree);
void postOrder(BinTree tree);
void deleteTree(BinTree &tree);

node findMin(BinTree tree);
node findMax(BinTree tree);

#endif