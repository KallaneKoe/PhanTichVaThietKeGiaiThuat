#include <iostream>
using namespace std;

int horner(int a[], int n, int x)
{
    int result = a[0];
    for (int i = 1; i < n; i++)
        result = result * x + a[i];
    return result;
}

int main()
{
    int n, a[100];
    cout << "Nhap vao so luong cac don thuc: ";
    cin >> n;
    cout << "Nhap vao cac don thuc: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cout << "Nhap vao gia tri cua phan tu x: ";
    cin >> x;
    cout << endl;
    cout << "Gia tri cua da thuc la: " << horner(a, n, x) << endl;
    system("pause");
    return 0;
}