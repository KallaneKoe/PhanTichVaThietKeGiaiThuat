#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int matrixChain(int *p, int i, int j)
{

    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], matrixChain(p, i, k) + matrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int main()
{
    int n, arr[100], a;
    int j = 0;
    int match = 0;
    cout << "Nhap vao so luong cac ma tran can nhan: ";
    cin >> n;
    cout << "Nhap vao chieu dai cac mang can nhan: " << endl;
    for (int i = 0; i < (2 * n); i++)
    {
        cin >> a;
        if (i % 2 != 0)
        {
            match = a;
        }
        if (i % 2 == 0 || i == (2 * n - 1))
        {
            if (a != match && match != 0)
            {
                cout << "Du lieu khong chinh xac, xin thu lai" << endl;
                system("pause");
                exit(0);
            }
            else
            {
                arr[j] = a;
                j++;
            }
        }
        else
        {
            continue;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << endl;
    cout << "So phep toan toi thieu la " << matrixChain(arr, 1, n);
    cout << endl;
    system("pause");
    return 0;
}