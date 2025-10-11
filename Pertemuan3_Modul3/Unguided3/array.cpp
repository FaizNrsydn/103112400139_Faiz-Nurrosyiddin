#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int arr[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp; 
        }
    }
}

void tukar(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

