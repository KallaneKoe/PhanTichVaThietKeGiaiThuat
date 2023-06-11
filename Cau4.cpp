

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high, int flag)
{
    int pivot = arr[high];
    int i = (low - 1);
    if (flag != 0)
    {

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    else
    {
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] > pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int flag)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, flag);
        quickSort(arr, low, pi - 1, flag);
        quickSort(arr, pi + 1, high, flag);
    }
}

int main()
{
    int n, arr[100], flag;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    cout << "Nhap cac phan tu trong mang: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Lua chon chieu ma ban muon sap xep (0 neu giam dan, 1 neu tang dan): ";
    cin >> flag;
    quickSort(arr, 0, n - 1, flag);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}
