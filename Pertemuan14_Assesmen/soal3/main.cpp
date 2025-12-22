#include "graphKota.h"
#include <iostream>
using namespace std;

int main() {
    GraphKota G;
    createGraph(G);

    // BAGIAN A
    // NOMOR 1
    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bekasi");

    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Tangerang", 24);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Bogor", "Jakarta", 42);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Bekasi", "Tangerang", 45);
    connectNode(G, "Bekasi", "Depok", 25);

    // NOMOR 2
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    printGraph(G);
    cout << endl;

    // NOMOR 3
    deleteNode(G, "Depok");

    // NOMOR 4
    cout << "===     SETELAH DELETE NODE DEPOK     ===" << endl;
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    printGraph(G);
    cout << endl;

    // BAGIAN B
    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");

    return 0;
}