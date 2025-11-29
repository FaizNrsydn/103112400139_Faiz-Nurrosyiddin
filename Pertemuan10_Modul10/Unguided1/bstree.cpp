#include "bstree.h"
#include<iostream>
using namespace std;

// no 1
address alokasi(infotype x){
    address nodeBaru = new node;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype x){
    if (root == Nil){
        root = alokasi(x);
    }else if (x < root->info)
    {
        insertNode(root->left,x);
    }else if (x > root->info)
    {
        insertNode(root->right,x);
    }
}

address findNode(address root, infotype x){
    address nodeBantu = root;
    bool ketemu = false;
    while(nodeBantu != Nil){
        if(x < nodeBantu->info){
            nodeBantu = nodeBantu->left;
        } else if(x > nodeBantu->info){
            nodeBantu = nodeBantu->right;
        } else if(x == nodeBantu->info){
            ketemu = true;
            break;
        }
    }
    if (ketemu){
        return nodeBantu;
    }else{
        return Nil;
    }
}

void printInorder(address root){
    if(root == Nil){
        return;
    }
    printInorder(root->left);
    cout << root->info << " - ";
    printInorder(root->right);
}

// no 2
int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
}

int hitungTotalInfo(address root, int start){
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return -1;
    } else {
        int hl = hitungKedalaman(root->left, start + 1);
        int hr = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

// no 3
void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}
