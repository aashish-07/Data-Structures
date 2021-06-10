#include <iostream>
using namespace std;

int main()
{
    // spiral print
    int i, j, s, m, n, val = 1;
    cin >> m >> n;
    int a[m][n] = {0};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val += 1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << a[i][j] << " ";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << a[i][j] << " ";
            }
        }
    }

    return 0;
}
