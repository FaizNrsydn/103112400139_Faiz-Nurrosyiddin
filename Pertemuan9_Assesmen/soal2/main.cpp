#include "DLLPlaylist.h"
#include <iostream>
#include <string>

using namespace std;

Song createSong(string title, string artist, int duration, int playCount, float rating) {
    Song S;
    S.tittle = title;
    S.artist = artist;
    S.durationSec = duration;
    S.playCount = playCount;
    S.rating = rating;
    return S;
}

int main() {
    List L;
    Song S_dummy; 
    
    // 1.
    createList(L);
    cout << "--- 1. List Kosong Dibuat ---" << endl;

    // 2.
    insertLast(L, createSong("Senja di Kota", "Nona Band", 210, 150, 4.2));
    insertLast(L, createSong("Langkahmu", "Delta", 185, 320, 4.8));
    insertLast(L, createSong("Hujan Minggu", "Arka", 240, 90, 3.9));
    
    // 3.
    viewList(L);

    // 4.
    deletelast(L, S_dummy);
    
    // 5.
    updateAtPosition(L, 2); 
    
    // 6.
    viewList(L);

    // 7.
    address nodePosisi2 = findAddressByPosition(L, 2);

    // 7.a.
    if (nodePosisi2 != Nil) {
        Song S_baru = createSong("Senandung", "Mira", 175, 120, 4.0);
        insertBefore(L, nodePosisi2, S_baru);
    }
    viewList(L);
    
    // 7.b.
    address nodePosisi2_lagi = findAddressByPosition(L, 2);
    if (nodePosisi2_lagi != Nil) {
        updateBefore(L, nodePosisi2_lagi); 
    }
    viewList(L);
    
    // 7.c.
    address nodePosisi3 = findAddressByPosition(L, 3);
    if (nodePosisi3 != Nil) {
        string laguHapus = nodePosisi3->prev->info.tittle; 
        deleteBefore(L, nodePosisi3, S_dummy);
    }
    viewList(L);
    
    // 8.
    searchByPopularityRange(L, 150.0, 300.0);
    viewList(L);

    return 0;
}