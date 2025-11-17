#include "DLLPlaylist.h"

// Bagian A

bool isEmpty(List L) {
    return L.head == Nil;
}

void createList(List &L) {
    L.head = Nil;
    L.tail = Nil;
}

address allocate(Song P) { 
    address newNode = new Node;
    newNode->info.tittle = P.tittle;
    newNode->info.artist = P.artist;
    newNode->info.durationSec = P.durationSec;
    newNode->info.playCount = P.playCount;
    newNode->info.rating = P.rating;
    newNode->next = Nil;
    newNode->prev = Nil;
    return newNode;
}

void deallocate(address &addr) {
    delete addr;
    addr = Nil;
}

void insertFirst(List &L, Song P) {
    address newNode = allocate(P);
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

void insertLast(List &L, Song P) {
    address newNode = allocate(P);
    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
    } else {
        newNode->prev = L.tail;
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q == Nil) return;

    address newNode = allocate(S);
    
    newNode->prev = Q;
    newNode->next = Q->next;

    if (Q->next != Nil) {
        Q->next->prev = newNode;
    } else {
        L.tail = newNode;
    }
    Q->next = newNode;
}

void insertBefore(List &L, address Q, Song S) {
    if (Q == Nil) return;

    if (Q == L.head) {
        insertFirst(L, S);
    } else {
        address newNode = allocate(S);
        newNode->next = Q;
        newNode->prev = Q->prev;
        Q->prev->next = newNode;
        Q->prev = newNode;
    }
}

void deleteFirst(List &L, Song &P) {
    if (isEmpty(L)) return;

    address delNode = L.head;
    P = delNode->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.head = delNode->next;
        L.head->prev = Nil;
    }
    deallocate(delNode);
}

void deletelast(List &L, Song &P) {
    if (isEmpty(L)) return;

    address delNode = L.tail;
    P = delNode->info;

    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.tail = delNode->prev;
        L.tail->next = Nil;
    }
    deallocate(delNode);
}

void deleteAfter(List &L, address Q, Song S) {
    if (Q == Nil || Q->next == Nil) return;
    
    address delNode = Q->next;
    S = delNode->info;
    
    Q->next = delNode->next;

    if (delNode == L.tail) {
        L.tail = Q;
    } else {
        delNode->next->prev = Q;
    }
    deallocate(delNode);
}

void deleteBefore(List &L, address Q, Song S) {
    if (Q == Nil || Q->prev == Nil) return;

    address delNode = Q->prev;
    S = delNode->info;

    if (delNode == L.head) {
        deleteFirst(L, S);
    } else {
        delNode->prev->next = Q;
        Q->prev = delNode->prev;
        deallocate(delNode);
    }
}

address findAddressByPosition(List L, int posisi) {
    if (posisi <= 0 || isEmpty(L)) return Nil;
    address temp = L.head;
    int count = 1;
    while (temp != Nil && count < posisi) {
        temp = temp->next;
        count++;
    }
    return temp;
}

void updateAtPosition(List L, int posisi) {
    address target = findAddressByPosition(L, posisi);

    if (target != Nil) {
        cout << "Masukkan update data pada posisi ke- " << posisi << ":" << endl;
        cout << "Title (Baru): ";
        cin.ignore();
        getline(cin, target->info.tittle);
        cout << "Artist (Baru): ";
        getline(cin, target->info.artist);
        cout << "DurationSec (Baru): ";
        cin >> target->info.durationSec;
        cout << "PlayCount (Baru): ";
        cin >> target->info.playCount;
        cout << "Rating (Baru): ";
        cin >> target->info.rating;
        cout << "Data pada posisi " << posisi << " berhasil diupdate." << endl;
    } else {
        cout << "Posisi ke-" << posisi << " tidak valid atau list kosong." << endl;
    }
}

void updateBefore(List L, address Q) {
    if (Q == Nil || Q->prev == Nil) {
        cout << "Node sebelumnya tidak valid untuk diupdate." << endl;
        return;
    }
    address target = Q->prev;
    
    cout << "Masukkan update data untuk node SEBELUM (" << Q->info.tittle << "):" << endl;
    cout << "Title (Baru): ";
    cin.ignore();
    getline(cin, target->info.tittle);
    cout << "Artist (Baru): ";
    getline(cin, target->info.artist);
    cout << "DurationSec (Baru): ";
    cin >> target->info.durationSec;
    cout << "PlayCount (Baru): ";
    cin >> target->info.playCount;
    cout << "Rating (Baru): ";
    cin >> target->info.rating;
    cout << "Data node SEBELUM (" << Q->info.tittle << ") berhasil diupdate." << endl;
}

float calculatePopularityScore(Song S) {
    return (float)S.playCount * S.rating;
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address temp = L.head;
    int position = 0;
    bool found = false;

    cout << "\n--- Hasil Pencarian Berdasarkan Popularity Score Range (" << minScore << " - " << maxScore << ") ---" << endl;

    while (temp != Nil) {
        position++;
        float score = calculatePopularityScore(temp->info);
        
        if (score >= minScore && score <= maxScore) {
            cout << "------------------------------------------" << endl;
            cout << "Ditemukan pada posisi ke-" << position << ":" << endl;
            cout << "Title: " << temp->info.tittle << endl;
            cout << "Artist: " << temp->info.artist << endl;
            cout << "Popularity Score: " << score << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Tidak ada lagu dalam rentang Popularity Score tersebut!" << endl;
    }
    cout << "------------------------------------------" << endl;
}


void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address temp = L.head;
        int idx = 0;
        cout << "\n--- Daftar Lagu ---" << endl;
        while (temp != Nil) {
            idx++;
            float score = calculatePopularityScore(temp->info);
            cout << "[" << idx << "]" << endl;
            cout << "  Title: " << temp->info.tittle << endl;
            cout << "  Artist: " << temp->info.artist << endl;
            cout << "  Duration: " << temp->info.durationSec << "s" << endl;
            cout << "  Play Count: " << temp->info.playCount << endl;
            cout << "  Rating: " << temp->info.rating << endl;
            cout << "  Popularity Score: " << score << endl;
            temp = temp->next;
        }
        cout << "-------------------" << endl;
    }
}