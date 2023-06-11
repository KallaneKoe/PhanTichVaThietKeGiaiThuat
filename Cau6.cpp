#include <bits/stdc++.h>
using namespace std;
int step = 0;
void thapHanoi(int n, char a, char b,
               char c)
{
    if (n == 0)
    {
        return;
    }
    thapHanoi(n - 1, a, c, b);
    cout << endl
         << "Di chuyen dia so " << n << " tu cot " << a
         << " toi cot " << b;
    step++;
    thapHanoi(n - 1, c, b, a);
}

int main()
{
    int N;
    cout << "Nhap so luong dia: ";
    cin >> N;
    thapHanoi(N, 'A', 'C', 'B');
    cout << endl
         << "So buoc can thuc hien la: ";
    cout << step;
    cout << endl;
    system("pause");
    return 0;
}