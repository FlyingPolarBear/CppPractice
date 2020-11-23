#include <iostream>
using namespace std;

int main()
{
    int i, j, k, N, C, N_total = 0, M_total = 0;
    int M[100] = {0}, V[100] = {0}, S[100][100] = {0};
    cin >> N;
    cin >> C;
    for (i = 0; i < N; i++)
    {
        cin >> M[i];
        M_total += M[i];
    }
    M_total = C;
    for (i = 0; i < N; i++)
        cin >> V[i];
    N_total = i + 1;

    for (i = 1; i < N_total; i++)
        for (j = 1; j < M_total; j++)
        {
            S[i][j] = S[i - 1][j];
            if (M[i] <= j)
                if (S[i][j] < S[i - 1][j - M[i]] + V[i])
                    S[i][j] = S[i - 1][j - M[i]] + V[i];
        }
    for (i = 0; i < N_total; i++)
        for (j = 0; j < M_total; j++)
        {
            cout << S[i][j] << " ";
            if (j == M_total - 1)
                cout << endl;
        }
    cout << S[N_total - 1][M_total - 1];
}