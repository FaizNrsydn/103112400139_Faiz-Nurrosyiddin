#include "multiLL.h"
#include <iostream>

using namespace std;

int main() {
    listParent L;
    createListParent(L);

    // NO 1 
    NodeParent Kat1 = allocNodeParent("G001", "Aves");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(L, Kat2);

    NodeParent Kat3 = allocNodeParent("G003", "Pisces");
    insertLastParent(L, Kat3);

    NodeParent Kat4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(L, Kat4);

    NodeParent Kat5 = allocNodeParent("G005", "Reptil");
    insertLastParent(L, Kat5);

    // --> Isi Kategori AVES (G001)
    NodeChild avs1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(Kat1->L_Child, avs1);

    NodeChild avs2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(Kat1->L_Child, avs2);

    // --> Isi Kategori MAMALIA (G002)
    NodeChild mml1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(Kat2->L_Child, mml1);

    NodeChild mml2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(Kat2->L_Child, mml2);

    NodeChild mml3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(Kat2->L_Child, mml3);

    // --> Isi Kategori AMFIBI (G004)
    NodeChild amf1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(Kat4->L_Child, amf1);

    cout << "   ### NOMOR 1 ###" << endl;
    printMLLStructure(L);
    cout << endl;

    // NO 2
    // 4. Test Pencarian (SEARCH)
    cout << "   ### NOMOR 2 ###" << endl;
    searchHewanByEkor(L, false);
    cout << endl;

    // NO 3
    cout << "   ### NOMOR 3 ###" << endl;
    cout << "=== Menghapus G004 ===" << endl;
    deleteAfterParent(L, Kat3);

    cout << "\n=== TAMPILAN AKHIR SETELAH DELETE ===" << endl;
    printMLLStructure(L);

    return 0;
}