#include <iostream>
using namespace std;

#define MAX 4   
int main() {
    int i, j, k = 0;
    int size = (MAX * (MAX + 1)) / 2;   
    int a[size];

    cout << "Enter elements of upper triangular matrix (row-major into 1D array):\n";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << "\nThe upper triangular matrix is...\n";
    k = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i <= j) {
                cout << a[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}
