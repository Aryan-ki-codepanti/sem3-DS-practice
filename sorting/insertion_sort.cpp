#include <iostream>
using namespace std;

void insertion_sort_1(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertion_sort_2(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = temp;
    }
}

void insertion_sort_3(int arr[], int n)
{
    int temp, j;
    bool flag;
    for (int i = 1; i < n; i++)
    {
        flag = false;
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
            {
                arr[j + 1] = temp;
                flag = true;
                break;
            }
        }
        if (!flag)
            arr[0] = temp;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    display(arr, n);
    insertion_sort_3(arr, n);
    display(arr, n);
    return 0;
}