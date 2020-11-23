#include <iostream>
using namespace std;

int main()
{
    int i, j, n, K, K0 = 0;
    int A[100] = {0};
    cin >> n;
    cin >> K;
    for (i = 0; i < n; i++)
        cin >> A[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if ((i != j) && (A[i] + A[j] <= K) && (A[i] + A[j] != K0))
                K0 = A[i] + A[j];
    cout << K0 << endl;
    return 0;
}