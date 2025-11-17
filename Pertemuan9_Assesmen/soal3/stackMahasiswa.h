#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

struct Mahasiswa
{
    string Nama;
    string NIM;
    float NilaiTugas, NilaiUTS, NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa StackMHS);
bool isFull(StackMahasiswa StackMHS);
void createStack(StackMahasiswa &StackMHS);
void Push(StackMahasiswa &StackMHS, Mahasiswa dataMHS);
void Pop(StackMahasiswa &StackMHS);
void Update(StackMahasiswa &StackMHS, int posisi, Mahasiswa dataMHS);
void View(StackMahasiswa StackMHS);
void SearchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);

#endif