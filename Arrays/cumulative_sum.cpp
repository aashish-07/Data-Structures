#include <iostream>
using namespace std;

int main()
{// maximum subarray sum using cumulative sum
    int n, sum = 0, max = 0;
    int l = 0;
    int r = 0;
    cin >> n;
    int a[n];
    int csum[n];
    cin >> a[0];
    csum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        csum[i] = csum[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
             sum = 0;
             sum = csum[j] - csum[i - 1];
            if (sum > max)
            {
                max = sum;
                l = i;
                r = j;
            }
        }
        // cout<<sum<<endl;
    }
    cout << max << endl;
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
