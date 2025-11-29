#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct node *address;

struct node
{
    infotype info;
    address left, right;
};

//no 1
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInorder(address root);

// no 2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// no 3
void preOrder(address root);
void postOrder(address root);

#endif