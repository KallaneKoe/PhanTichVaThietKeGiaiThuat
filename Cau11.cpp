#include <bits/stdc++.h>
using namespace std;

struct Activitiy
{
    string name;
    int start, finish;
};

bool SoSanh(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

void activityList(Activitiy arr[], int n)
{

    sort(arr, arr + n, SoSanh);
    cout << "Danh sach cac hoat dong la: ";
    int i = 0;
    cout << endl
         << arr[i].name << " ";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << arr[j].name << " ";
            i = j;
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong cac hoat dong: ";
    cin >> n;
    Activitiy arr[100];
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Nhap ten hoat dong thu " << i + 1 << " : ";
        cin >> arr[i].name;
        cout << endl
             << "Nhap thoi gian bat dau cua hoat dong thu " << i + 1 << " : ";
        cin >> arr[i].start;
        cout << endl
             << "Nhap thoi gian ket thuc cua hoat dong thu " << i + 1 << " : ";
        cin >> arr[i].finish;
    }
    activityList(arr, n);
    cout << endl;
    system("pause");
    return 0;
}
