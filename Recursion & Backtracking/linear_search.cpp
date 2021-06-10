#include <iostream>
using namespace std;
int liner_search(int *a, int n, int key)
{
    // base case
    if (n == 0)
    {
        // return -1 if elemnt is not present
        return -1;
    }
    // recursive case
    if (a[0] == key)
    {
        return 0;
    }
    int i = liner_search(a + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    else
        return i + 1;
}
int main()
{
    int n, key;
    int arr[] = {12, 43, 35, 16, 38};
    key = 38;
    n = sizeof(arr) / sizeof(int);
    cout << liner_search(arr, n, key);
    return 0;
}