#include <iostream>
using namespace std;

class ArrayFixed
{
    int arr[3][4];

public:
    void inputArr()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
                cin >> arr[i][j];
        }
    }
    void outputArr()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    ArrayFixed a;
    a.inputArr();
    a.outputArr();
    return 0;
}