#include <iostream>
using namespace std;

class Array
{
    int n, m;
    int **arr;

public:
    Array(int n, int m)
    {
        this->n = n;
        this->m = m;
        arr = new int *[n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[m];
    }

    void inputArr()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
    }
    void outputArr()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Array a(n, m);
    a.inputArr();
    a.outputArr();
    return 0;
}