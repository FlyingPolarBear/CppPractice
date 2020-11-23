#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n, K, c = 1;
    int A[10][10];
    cin >> n;
    cin >> K;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> A[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                if (i != j && A[i][j] > A[i][k] + A[k][j])
                    A[i][j] = A[i][k] + A[k][j];
    for (i = 1; i < n; i++)
        if (A[0][i] < K)
            c = i + 1;
    cout << c;
    return 0;
}