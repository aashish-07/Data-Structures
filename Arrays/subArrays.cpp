#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        for (int j = i; j < n; j++)
        {
            /* code */
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << ",";
            }
            cout << endl;
        }
    }
    return 0;
}
