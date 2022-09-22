#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int linear_search_recursive(int arr[], int n, int x, int pos)
{
    if (n == pos)
        return -1;
    if (arr[pos] == x)
        return pos;
    return linear_search_recursive(arr, n, x, pos + 1);
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
    cout << linear_search_recursive(arr, n, x, 0) << endl;
    return 0;
}