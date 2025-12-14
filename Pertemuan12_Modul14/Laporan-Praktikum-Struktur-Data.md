# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>

<p align="center">Faiz Nurrosyiddin - 103112400139</p>

## Dasar Teori
Pemrograman graf dalam C++ merupakan bidang penting dalam ilmu komputer yang memadukan teori graf dengan teknik pemrograman modern. Graf adalah struktur data yang terdiri dari simpul (vertex) dan sisi (edge), digunakan untuk merepresentasikan hubungan antar objek, seperti jaringan komputer, peta, atau struktur data kompleks.

Graf secara formal didefinisikan sebagai pasangan terurut G = (V, E), di mana V adalah himpunan simpul dan E adalah himpunan sisi yang menghubungkan pasangan simpul. Graf dapat berupa terarah (directed) atau tak terarah (undirected), berbobot (weighted) atau tidak berbobot (unweighted), serta memiliki berbagai bentuk representasi seperti adjacency list dan adjacency matrix.

C++ menyediakan fleksibilitas tinggi untuk mengimplementasikan graf melalui berbagai struktur data. Representasi graf yang umum meliputi adjacency list (menggunakan array atau vector of lists) dan adjacency matrix (menggunakan array dua dimensi). Penggunaan kelas (class) dalam C++ memungkinkan pembuatan objek graf yang modular, dengan operasi seperti menambah/menghapus simpul dan sisi, serta traversal graf. Operasi dasar yang sering diimplementasikan meliputi penambahan/ penghapusan simpul dan sisi, pencarian jalur, serta algoritma seperti pencarian lintasan terpendek dan spanning tree.

## Guided

### 1. MULTI LINKED LIST
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;         // Memyimpan data node (misal: char/int)
    int visited;            // Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi atau belum)
    adrEdge firstEdge;      // Pointer ke edge pertama yang terhubung.
    adrNode Next;           // Pointer ke node berikutnya dalam graph.
};

struct ElmEdge
{
    adrNode Node;           // Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge Next;           // Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph
{
    adrNode First;          // Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G);                 // Prosedur untuk mengeset first dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);        // Alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);    // Alokasi edge baru

void InsertNode(Graph &G, infoGraph data);                      // Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data);                      // function untuk mencari alamat berdasarkan node
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);   // prosedur untuk menghubungkan dua node
void DisconnectNode(adrNode node1, adrNode node2);              // prosedur untuk memutuskan hubungan dua node
void DeleteNode(Graph &G, infoGraph X);                         // prosedur untuk menghapus Node X beserta semua edgenya

void PrintInfoGraph(Graph G);                  // Menampilkan isi graph (Adjacency List)
void ResetVisited(Graph &G);                    // Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);    // traversal Breadth First Search / BFS (Menggunakan )
void PrintDFS(Graph G, infoGraph StartInfo);    // traversal Depth First Search / DFS

#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>    // Library queue untuk BFS
#include <stack>    // Library stack untuk DFS
using namespace std;

int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'F');
    InsertNode(G, 'E');

    // Hubungkan Antar Node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // MULAI TRAVERSAL DARI NODE A
    PrintBFS(G, 'A'); // BFS
    PrintDFS(G, 'A'); // DFS
    cout << endl;

    cout << "=== HAPUS NODE E" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G,'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    }else{
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // MULAI TRAVERSAL DARI NODE A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```

### Penjelasan singkat guided 1:
struct ElmNode yang berisi infoGraph info,int visited,adrEdge firstEdge,adrNode Next.
struct ElmEdge yang berisi adrNode Node,adrEdge Next.
struct Graph yang berisi adrNode First.
void CreateGraph(Graph &G) prosedur untuk cek graph pertama kosong
adrNode AlokasiNode(infoGraph data) fungsi membuat variabel baru untuk menampung elm node nya. mengisi info = data, visited dimulai dari 0 dan semua pointer (firstEdge, next) ke NULL.
adrEdge AlokasiEdge(adrNode nodeTujuan) fungsi membuat variabel baru untuk menampung elmedge nya. menunjuk ke nodeTujuan dan next nya ke NULL.
void InsertNode(Graph &G, infoGraph data) prosedur untuk menambahkan node baru kedalam list utama graph. menggunakan konsep insert last di single linked list.
adrNode FindNode(Graph G, infoGraph data) fungsi untuk mencari aalamat pointer sebuah node berdasarkan info dan inisialisasi dengan variabel baru yaitu nodeBantu. menggunakan while if.
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) prosedur untuk menghubungkan node 1 dan node 2. karena ini adalah undericted graph. buat adrnode nya 2, node1 dan node2. jika node1 dan node2 nya tdk kosong dihubungkan menggunakan insert first pada list edge. lalu hubungkan nde2-node1 (karena undericted (bolakbalik)).
void DisconnectNode(adrNode node1, adrNode node2) prosedur untuk memutuskan hubungan 2 node. jika node nya tdk kosong cari edge yg mengarah ke node2 di dalam list milik node1. jika edge ditemukan , hapus edge pertama lalu, hapus edge ditengah terakhir.
void DeleteNode(Graph &G, infoGraph X) prosedur tersebut mengahpus node x dari graph. cari node x nya, hapus semua yg menuju ke node x panggil disconnect node. hapus semua tetangga milik node x nya, happus node x dari list utama graph.
void PrintInfoGraph(Graph G) prosedur menampilkan graph dna mencetak setiap node yg terhubung melalui edge.
void ResetVisited(Graph &G) prosedur mengatur ulang status visited semua node digraph kembali ke 0, harus dipaggil sebelum setiap BFS/DFS.
void PrintBFS(Graph G, infoGraph StartInfo) prosedur melakukan traversal Breadth-First Search (BFS), yaitu menjelajahi simpul secara lapisan demi lapisan (level terdekat lebih dulu).
Menggunakan struktur data Queue (queue).
Memulai dari StartNode, memasukkannya ke Queue dan menandai visited = 1.
Selama Queue tidak kosong, keluarkan node, cetak infonya, dan masukkan semua tetangganya yang belum dikunjungi ke dalam Queue (setelah menandai mereka sebagai visited).
void PrintDFS(Graph G,infoGraph StartInfo) prosedur melakukan traversal Depth-First Search (DFS), yaitu menjelajahi simpul sejauh mungkin di sepanjang cabang sebelum kembali (backtracking).
Menggunakan struktur data Stack (stack).
Memulai dari StartNode, memasukkannya ke Stack.
Selama Stack tidak kosong, keluarkan node. Jika node belum dikunjungi, tandai visited = 1, cetak infonya, dan masukkan semua tetangganya yang belum dikunjungi ke dalam Stack.

## Unguided

### 1. Buatlah ADT Graph tidak berarah file “graph.h”: lalu Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.
### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. "prosedur PrintDFS (Graph G, adrNode N);"
### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. "prosedur PrintBFS (Graph G, adrNode N);"

#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph{
    adrNode First;
};

// no.1
void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph X); 
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);
adrNode FindNode(Graph G, infoGraph X);

//no.2 
void PrintDFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

//no.3
void PrintBFS(Graph G, adrNode N);
#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>


void CreateGraph(Graph &G){
    G.First = NULL;
} 

adrNode AlokasiNode(infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
} 

adrEdge AlokasiEdge(adrNode nodeTujuan){
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

void InsertNode(Graph &G, infoGraph X){
    adrNode nodeBaru = AlokasiNode(X);
    if (G.First == NULL){
        G.First = nodeBaru;
    }else{
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL){
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == X) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

void ConnectNode(adrNode &N1, adrNode &N2){
    if (N1 == NULL || N2 == NULL) {
        cout << "ERROR node bernilai NULL." << endl;
        return;
    }
    adrEdge newEdge1 = AlokasiEdge(N2);
    newEdge1->Next = N1->firstEdge;
    N1->firstEdge = newEdge1;

    adrEdge newEdge2 = AlokasiEdge(N1);
    newEdge2->Next = N2->firstEdge;
    N2->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph G){
    adrNode nodeBantu = G.First;
    while(nodeBantu != NULL){
        cout << "Node" << nodeBantu->info << " terhubung ke :";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while(edgeBantu != NULL){
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

// no.2
void ResetVisited(Graph &G){
    adrNode nodeReset = G.First;
    while(nodeReset != NULL){
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

void PrintDFS(Graph G, adrNode N){
    ResetVisited(G);
    if(N == NULL) return;
    stack <adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();
        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";
            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

// no.3
void PrintBFS(Graph G, adrNode N){
    ResetVisited(G);
    if(N == NULL ) return;
    queue<adrNode> Qyu;
    N->visited = 1;
    Qyu.push(N);
    cout <<"BFS Traversal: ";
    while (!Qyu.empty()){
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while(edgeBantu != NULL){
            if(edgeBantu->Node->visited == 0){
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}
```

##### main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main(){
    // no 1
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode nA, nB, nC, nD, nE, nF, nG, nH;
    nA = FindNode(G, 'A');
    nB = FindNode(G, 'B');
    nC = FindNode(G, 'C');
    nD = FindNode(G, 'D');
    nE = FindNode(G, 'E');
    nF = FindNode(G, 'F');
    nG = FindNode(G, 'G');
    nH = FindNode(G, 'H');

    ConnectNode(nA, nC);
    ConnectNode(nA, nB);
    ConnectNode(nB, nE);
    ConnectNode(nB, nD);
    ConnectNode(nC, nG);
    ConnectNode(nC, nF);
    ConnectNode(nG, nH);
    ConnectNode(nF, nH);
    ConnectNode(nE, nH);
    ConnectNode(nD, nH);

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    // no 2
    PrintDFS(G, nA);
    // no 3
    PrintBFS(G, nA);
    cout << endl;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/FaizNrsydn/103112400139_Faiz-Nurrosyiddin/blob/main/Pertemuan12_Modul14/Output-Unguided1.png)

### Penjelasan unguided 1:
#### Nomor 1
struct ElmNode yang berisi infoGraph info,int visited,adrEdge firstEdge,adrNode Next.
struct ElmEdge yang berisi adrNode Node,adrEdge Next.
struct Graph yang berisi adrNode First.
void CreateGraph(Graph &G) prosedur cek graph pertama kosong
adrNode AlokasiNode(infoGraph X) fungsi membuat variabel baru untuk menampung elm node nya. mengisi info = data, visited dimulai dari 0 dan semua pointer (firstEdge, next) ke NULL.
adrEdge AlokasiEdge(adrNode nodeTujuan) fungsi membuat variabel baru untuk menampung elmedge nya. menunjuk ke nodeTujuan dan next nya ke NULL.
void InsertNode(Graph &G, infoGraph X) prosedur untuk menambahkan node baru kedalam list utama graph. menggunakan konsep insert last di single linked list.
void ConnectNode(adrNode &N1, adrNode &N2) prosedur menghubungkan node 1 dan node 2. karena ini adalah undericted graph. buat adrnode nya 2, node1 dan node2. jika node1 dan node2 nya tdk kosong dihubungkan menggunakan insert first pada list edge. lalu hubungkan nde2-node1 (karena undericted (bolakbalik)).
void PrintInfoGraph(Graph G) prosedur menampilkan graph dna mencetak setiap node yg terhubung melalui edge.
adrNode FindNode(Graph G, infoGraph X) fungsi untuk mencari aalamat pointer sebuah node berdasarkan info dan inisialisasi dengan variabel baru yaitu nodeBantu. menggunakan while if.

#### Nomor 2
void PrintDFS(Graph G, adrNode N) prosedur tersebut melakukan traversal Depth-First Search (DFS), yaitu menjelajahi simpul sejauh mungkin di sepanjang cabang sebelum kembali (backtracking).
Menggunakan struktur data Stack (stack).
dimuali memanggil risetvisited(G). untuk memastikan semua simpul (visited = 0), lalu node awal (N) dimasukkan ke dalam Stack. Selama Stack belum kosong, node teratas diambil dan dikeluarkan (pop). Logika utamanya terletak pada pengecekan if (nodeBantu->visited == 0): jika node belum dikunjungi, ia ditandai sebagai visited = 1, dan dicetak. Kemudian, program akan mengiterasi semua tetangga dari node tersebut. Setiap tetangga yang belum dikunjungi segera dimasukkan ke dalam Stack
void ResetVisited(Graph &G) -> mengatur ulang status visited semua node digraph kembali ke 0, harus dipaggil sebelum setiap BFS/DFS.

### Nomor 3
void PrintBFS(Graph G, infoGraph StartInfo) Fungsi tersebut menelusuri graf secara Breadth First Search (BFS), yaitu menjelajahi simpul berdasarkan tingkat kedekatan dari node awal. Algoritma ini sangat mengandalkan struktur data Queue (queue), yang beroperasi berdasarkan prinsip FIFO (First-In, First-Out). Setelah memanggil ResetVisited(G) dan menandai node awal (N) sebagai visited = 1, node tersebut dimasukkan ke Queue. Selama Queue tidak kosong, node yang berada di depan dikeluarkan, dicetak, dan semua tetangganya yang belum dikunjungi segera ditandai visited = 1 dan dimasukkan ke belakang Queue. Karena node-node baru ditambahkan ke belakang, mereka hanya akan diproses setelah semua node yang berada pada tingkat (level) yang sama telah selesai dieksplorasi.

## Kesimpulan
Dasar teori program graf di C++ meliputi pemahaman struktur graf, representasi data, serta implementasi algoritma graf menggunakan paradigma pemrograman modern dan library pendukung. Pendekatan modular dan generic programming di C++ memungkinkan pengembangan program graf yang efisien, fleksibel, dan mudah dikembangkan lebih lanjut.

## Referensi
[1] Lumsdaine, A., D'Alessandro, L., Deweese, K., Firoz, J., McMillan, S., Ratzloff, J. P., & Zalewski, M. (2022). Nwgraph: A library of generic graph algorithms and data structures in c++ 20. Leibniz international proceedings in informatics, 222.
<br>[2] Yzelman, A. N., Di Nardo, D., Nash, J. M., & Suijlen, W. J. (2020). A C++ GraphBLAS: specification, implementation, parallelisation, and evaluation. Preprint, 58.
<br> [3] Siek, J. G., Lee, L. Q., & Lumsdaine, A. (2001). The Boost Graph Library: User Guide and Reference Manual, The. Pearson Education.