/*selection sort in an array*/
#include <bits/stdc++.h>
using namespace std;
void selection_sort(int a[], int n);
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection_sort(a, n);
    return 0;
}

void selection_sort(int a[], int n)
{
    int min, j;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}