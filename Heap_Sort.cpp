#include <iostream>
#include <stdlib.h>
using namespace std;
int arr[10];

void heapify(int arr[10], int n, int i)
{
    int temp, l, p, r;
    int largest = i;
    if (i <= n)
    {
        p = i / 2;
        l = p * 2;
        r = p * 2 + 1;

        if (l <= n && arr[l] > arr[r])
        {
            largest = l;
        }
        if (r <= n && arr[r] > arr[l])
        {
            largest = r;
        }
        if (arr[p] < arr[largest])
        {
            temp = arr[p];
            arr[p] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest * 2);
        }
    }
}

void heapsort(int arr[10], int n)
{
    for (int i = n; i > 1; i--)
    {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    system("cls");
    int arr[10], n;
    cout << "Enter Total No.Of Elements : ";
    cin >> n;
    arr[0] = n;
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter Elements : ";
        cin >> arr[i];
    }
    heapsort(arr, n);
    cout << "\nSorted Array is : ";
    printArray(arr, n);
    return 0;
}