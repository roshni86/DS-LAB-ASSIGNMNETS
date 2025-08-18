#include <iostream>
using namespace std;

#define MAX 4   

int main() {
    int i, j, k = 0;
    int size = (MAX * (MAX + 1)) / 2;   
    int a[size];

    cout << "Enter elements of symmetric matrix (store lower triangular part row-wise):\n";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << "\nThe symmetric matrix is...\n";
    k = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i >= j) {
                cout << a[k++] << " ";
            } else {
                // Use symmetry: a[i][j] = a[j][i]
                int index = (j * (j + 1)) / 2 + i;  // formula to map
                cout << a[index] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}