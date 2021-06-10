#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    // base case
    if (n == 1)
    {
        return;
    }

    // recursive case
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }
   
    return bubble_sort(a, n - 1);
}

void bubble_sort_recursive(int a[], int j, int n)
{
    // base case
    if (n == 1)
    {
        return;
    }

    if (j == n - 1)
    {
        // single pass has been completed
        return bubble_sort_recursive(a, 0, n - 1);
    }
    // recursive case
    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }
    bubble_sort_recursive(a, j + 1, n);
    return;
}

using namespace std;
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    // bubble_sort(arr,n);
    bubble_sort_recursive(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
