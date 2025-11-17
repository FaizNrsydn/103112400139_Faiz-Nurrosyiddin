#ifndef DLLPlaylist_H
#define DLLPlaylist_H
#define Nil NULL

#include<iostream>
using namespace std;

struct Song
{
    string tittle;
    string artist;
    int durationSec;
    int playCount;
    float rating;
};

typedef struct Node *address; 

struct Node
{
    Song info;
    address next, prev;
};

struct List{
    address head, tail;
};

// bagian A
bool isEmpty(List L);
void createList(List &L);
address allocate(Song P);
void deallocate(address &addr);
void insertFirst(List &L, Song P);
void insertLast(List &L, Song P);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &P);
void deletelast(List &L, Song &P);
void deleteAfter(List &L, address Q, Song S);
void deleteBefore(List &L, address Q, Song S);
void updateAtPosition(List L, int posisi);
void updateBefore(List L, address Q);
void searchByPopularityRange(List L, float minScore, float maxScore);
address findAddressByPosition(List L, int posisi);
void viewList(List L);

#endif