#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x) // search in left half
            right = mid - 1;

        else
            left = mid + 1;
    }

    return -1;
}

int binary_search_recursive(int arr[], int n, int x, int left, int right)
{
    int mid = (left + right) / 2;

    if (left > right) // base 1 : element not present in array
        return -1;

    if (arr[mid] == x) // base 2 : element present in array at mid
        return mid;

    if (arr[mid] > x) // search in left half
        return binary_search_recursive(arr, n, x, left, mid - 1);
    // else
    return binary_search_recursive(arr, n, x, mid + 1, right);
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter x :";
    cin >> x;
    cout << binary_search(arr, n, x) << endl;
    cout << binary_search_recursive(arr, n, x, 0, n - 1) << endl;
    return 0;
}