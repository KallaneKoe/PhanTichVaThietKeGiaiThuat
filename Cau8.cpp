#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

void balo(int W, int wt[], int val[], int n)
{

    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
    cout << "Gia tri lon nhat ta co the thu duoc la: " << res << endl;

    int k = W;
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][k])
            continue;
        else
        {
            cout << i << " ";
            res = res - val[i - 1];
            k = k - wt[i - 1];
        }
    }
}

int main()
{
    int flag, n, W, val[100], wt[100];
    cout << "Chon loai bai toan balo (nhap 1 de thuc hien balo 1, nhap 2 de thuc hien bai toan balo 2): ";
    cin >> flag;
    cout << "Nhap so luong cac vat pham: ";
    cin >> n;
    cout << "Nhap vao trong luong toi da cua balo: ";
    cin >> W;
    if (flag == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap vao trong luong cua mon hang thu " << i << " : ";
            cin >> val[i];
            wt[i] = val[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap vao gia tri cua mon hang thu " << i + 1 << " : ";
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap vao trong luong cua mon hang thu " << i + 1 << " : ";
            cin >> wt[i];
        }
    }
    balo(W, wt, val, n);
    cout << endl;
    system("pause");
    return 0;
}