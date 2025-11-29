#include <iostream>
#include "bstree.h"
using namespace std;

// int main() {
//     // no 1
//     cout << "Hello World" << endl;
//     address root = Nil;
//     insertNode(root,1);
//     insertNode(root,2);
//     insertNode(root,6);
//     insertNode(root,4);
//     insertNode(root,5);
//     insertNode(root,3);
//     insertNode(root,6);
//     insertNode(root,7);
//     cout << "In-Order: ";
//     printInorder(root);
//     cout << endl;

//     // no 2
//     cout<<"\n";
//     cout<<"kedalaman : "<< hitungKedalaman(root,0)<<endl;
//     cout<<"jumlah Node : "<< hitungJumlahNode(root)<<endl;
//     cout<<"total : "<< hitungTotalInfo(root,0)<<endl;
//     return 0;
// }

// no 3
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);

    // no 3
    cout << "Pre-Order: ";
    preOrder(root);
    cout << endl;
    cout << "Post-Order: ";
    postOrder(root);
    return 0;
}