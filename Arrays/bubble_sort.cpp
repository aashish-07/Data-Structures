/* bubble sort in an array*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
/*comparator function*/
bool compare(int a, int b)
{
    return a<b;
}

void bubble_sort(int a[], int n, bool (&cmp)(int a, int b))
/*passing function as a parameter in another function*/
{
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            /*if (a[j] > a[j+1])*/
            if (cmp(a[j], a[j + 1]))
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble_sort(a,n,compare);
    return 0;
}
