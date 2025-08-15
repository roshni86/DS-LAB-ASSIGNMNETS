#include<iostream>
using namespace std;
int main() {
    int m, p, n;
    cout << "Enter rows and columns of first matrix: ";
    cin >> m >> p;
    cout << "Enter rows and columns of second matrix: ";
    int p2, n2;
    cin >> p2 >> n2;

    if (p != p2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int A[m][p], B[p][n2], C[m][n2];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < n2; j++)
            cin >> B[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
