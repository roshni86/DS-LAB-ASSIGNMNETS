#include <iostream>
using namespace std;

#define MAX 4

int main() {
    int i, j, k = 0;
    int size = 3 * MAX - 2;
    int a[size];

    cout << "Enter elements (row major): " << endl;
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << "\nThe matrix is...\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i - j == -1 || i - j == 0 || i - j == 1) {
                cout << a[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
