#include <iostream>
using namespace std;
/*Kadane's Algorithm for maximum subarray sum */
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    int m=0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if(sum < 0)
        {
            sum = 0;
        }
        m = max(sum, m);
    }
    cout<<m;
    return 0;
}
