#include <iostream>
using namespace std;

bool isSorted(int *a, int n)
{
    // Base Case
    if (n == 0 or n == 1)
    {
        return true;
    }
    // Recursive Case
    if (a[0] < a[1] and isSorted(a, n - 1))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    int arr[] = {1, 4, 5, 6, 9};
    n = sizeof(arr) / sizeof(int);
    cout << isSorted(arr, n);

    return 0;
}