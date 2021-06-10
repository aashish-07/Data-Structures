#include <iostream>
using namespace std;
/*maximum subarray sum*/ 
int main()
{
    // your code goes here
    int n, sum = 0, max = 0;
    int l = 0;
    int r = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                if (sum > max)
                {
                    max = sum;
                    l = i;
                    r = j;
                }
            }
            // cout<<sum<<endl;
        }
    }
    cout << max << endl;
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
