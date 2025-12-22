#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H

#include <iostream>
using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota {
    adrKota First;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string namaKota);
adrEdge alokasiEdge(adrKota kotaTujuan, int jarak);
void insertNode(GraphKota &G, string namaKota);
adrKota findNode(GraphKota G, string namaKota);
void connectNode(GraphKota &G, string info1, string info2, int jarak);
void disconnectNode(adrKota node1, adrKota node2);
void deleteNode(GraphKota &G, string X);
void printGraph(GraphKota G);

void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string StartInfo);
void printDFS(GraphKota G, string StartInfo);

#endif