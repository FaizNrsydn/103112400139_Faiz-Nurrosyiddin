#include "bst.h"
#include<iostream>
using namespace std;

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

void createTree(BinTree &tree) {
    tree = Nil;
}

node alokasi(int id, string nama, int stok) {
    node nodeBaru = new BST;
    nodeBaru->idProduk = id;
    nodeBaru->namaProduk = nama;
    nodeBaru->stok = stok;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
    } else if (nodeBaru->idProduk < tree->idProduk) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->idProduk > tree->idProduk) {
        insertNode(tree->right, nodeBaru);
    }
}

void searchById(BinTree tree, int id) {
    if (isEmpty(tree)) {
        cout << "ID " << id << " tidak ditemukan!" << endl;
        return;
    }
    if (id == tree->idProduk) {
        cout << "Ditemukan -> ID: " << tree->idProduk << ", Nama: " << tree->namaProduk << ", Stok: " << tree->stok << endl;
    } else if (id < tree->idProduk) {
        searchById(tree->left, id);
    } else {
        searchById(tree->right, id);
    }
}

void searchByProduct(BinTree tree, string nama, bool &found) {
    if (tree != Nil) {
        if (tree->namaProduk == nama) {
            cout << "Ditemukan -> ID: " << tree->idProduk << ", Nama: " << tree->namaProduk << ", Stok: " << tree->stok << endl;
            found = true;
        }
        searchByProduct(tree->left, nama, found);
        searchByProduct(tree->right, nama, found);
    }
}

void preOrder(BinTree tree) {
    if (tree != Nil) {
        cout << "ID Produk   : " << tree->idProduk << endl;
        cout << "Nama Produk : " << tree->namaProduk << endl;
        cout << "Stok        : " << tree->stok << endl;
        cout << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << "ID Produk   : " << tree->idProduk << endl;
        cout << "Nama Produk : " << tree->namaProduk << endl;
        cout << "Stok        : " << tree->stok << endl;
        cout << endl;
        inOrder(tree->right);
    }
}

void postOrder(BinTree tree) {
    if (tree != Nil) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << "ID Produk   : " << tree->idProduk << endl;
        cout << "Nama Produk : " << tree->namaProduk << endl;
        cout << "Stok        : " << tree->stok << endl;
        cout << endl;
    }
}

node findMin(BinTree tree) {
    while (tree != Nil && tree->left != Nil) {
        tree = tree->left;
    }
    return tree;
}

node findMax(BinTree tree) {
    while (tree != Nil && tree->right != Nil) {
        tree = tree->right;
    }
    return tree;
}

bool deleteNode(BinTree &tree, int id) {
    if (tree == Nil) return false;

    if (id < tree->idProduk) {
        return deleteNode(tree->left, id);
    } else if (id > tree->idProduk) {
        return deleteNode(tree->right, id);
    } else {
        if (tree->left == Nil && tree->right == Nil) {
            dealokasi(tree);
            tree = Nil;
        } else if (tree->left == Nil) {
            node tmp = tree;
            tree = tree->right;
            dealokasi(tmp);
        } else if (tree->right == Nil) {
            node tmp = tree;
            tree = tree->left;
            dealokasi(tmp);
        } else {
            node successor = findMin(tree->right);
            tree->idProduk = successor->idProduk;
            tree->namaProduk = successor->namaProduk;
            tree->stok = successor->stok;
            return deleteNode(tree->right, successor->idProduk);
        }
        return true;
    }
}

void deleteTree(BinTree &tree) {
    if (tree != Nil) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}