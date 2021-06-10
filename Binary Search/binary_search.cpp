/*binary search in an array*/
#include <iostream>
using namespace std;
int binary_search(int a[], int n, int k);
int main()
{
    int n, k, r;
    cin >> n;
    cin >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    r = binary_search(a, n, k);
    cout << r;
    return 0;
}

int binary_search(int a[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid;
    for (int i = s; i < e; i++)
    {
        mid = (s + e) / 2;
        if (a[mid] == k)
        {
            return mid;
        }
        else if (a[mid] > k)
        {

            e = mid - 1;
        }
        else
            s = mid + 1;
    }
}