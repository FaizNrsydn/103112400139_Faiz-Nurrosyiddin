#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Input: ";
    cin >> n;
    cout << "output: " << endl;

    for (int i = 0; i <= n; i++){
        for (int j = 0;j<i;j++){
            cout << " ";
        }

        for (int j = n-i;j>=1;j--){
            cout << j;
        }

        cout << "*";

        for (int j = 1; j <= n-i;j++){
            cout << j;
        }
        cout << endl;
    }

    return 0;
}