#include "graphKota.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string namaKota) {
    adrKota nodeBaru = new ElmKota;
    nodeBaru->namaKota = namaKota;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->next = NULL;
    return nodeBaru;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->kotaTujuan = kotaTujuan;
    edgeBaru->jarak = jarak;
    edgeBaru->next = NULL;
    return edgeBaru;
}

void insertNode(GraphKota &G, string namaKota) {
    adrKota nodeBaru = alokasiNode(namaKota);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        adrKota nodeBantu = G.First;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

adrKota findNode(GraphKota G, string namaKota) {
    adrKota nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->namaKota == namaKota) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string info1, string info2, int jarak) {
    adrKota node1 = findNode(G, info1);
    adrKota node2 = findNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = alokasiEdge(node2, jarak);
        edge1->next = node1->firstEdge;
        node1->firstEdge = edge1;

        adrEdge edge2 = alokasiEdge(node1, jarak);
        edge2->next = node2->firstEdge;
        node2->firstEdge = edge2;
    }
}

void disconnectNode(adrKota node1, adrKota node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge prevE = NULL;

        while (edgeBantu != NULL && edgeBantu->kotaTujuan != node2) {
            prevE = edgeBantu;
            edgeBantu = edgeBantu->next;
        }

        if (edgeBantu != NULL) {
            if (prevE == NULL) {
                node1->firstEdge = edgeBantu->next;
            } else {
                prevE->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
    }
}

void deleteNode(GraphKota &G, string X) {
    adrKota nodeHapus = findNode(G, X);
    if (nodeHapus == NULL) return;

    adrKota nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        disconnectNode(nodeLainnya, nodeHapus);
        nodeLainnya = nodeLainnya->next;
    }

    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->next;
        delete tempE;
    }

    if (G.First == nodeHapus) {
        G.First = nodeHapus->next;
    } else {
        adrKota nodeBantu = G.First;
        while (nodeBantu->next != nodeHapus) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeHapus->next;
    }
    delete nodeHapus;
}

void printGraph(GraphKota G) {
    adrKota nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->namaKota << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->kotaTujuan->namaKota << "(" << edgeBantu->jarak << " KM), ";
            edgeBantu = edgeBantu->next;
        }
        cout << endl;
        nodeBantu = nodeBantu->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->next;
    }
}

void printBFS(GraphKota G, string StartInfo) {
    resetVisited(G);
    adrKota startNode = findNode(G, StartInfo);
    if (startNode == NULL) return;

    queue<adrKota> q;
    q.push(startNode);
    startNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota nodeBantu = q.front();
        q.pop();
        cout << nodeBantu->namaKota << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->kotaTujuan->visited == 0) {
                edgeBantu->kotaTujuan->visited = 1;
                q.push(edgeBantu->kotaTujuan);
            }
            edgeBantu = edgeBantu->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, string StartInfo) {
    resetVisited(G);
    adrKota startNode = findNode(G, StartInfo);
    if (startNode == NULL) return;

    stack<adrKota> s;
    s.push(startNode);

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        adrKota nodeBantu = s.top();
        s.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->namaKota << " - ";

            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->kotaTujuan->visited == 0) {
                    s.push(edgeBantu->kotaTujuan);
                }
                edgeBantu = edgeBantu->next;
            }
        }
    }
    cout << endl;
}