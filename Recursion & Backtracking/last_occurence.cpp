#include <iostream>
using namespace std;
int last_occurence(int *a, int n, int key)
{
    // base case
    if (n == 0)
    {
        // return -1 if element is not present
        return -1;
    }
    // recursive case
    int i = last_occurence(a + 1, n - 1, key);
    if (i == -1)
    {
        // if element not found at remaining part check at current part of the array
        if (a[0] == key)
        {
            return 0;
        }
        else
        {
            // if element not found at current part of the array
            return -1;
        }
    }

    return i + 1;
}
int main()
{
    int n, key;
    int arr[] = {12, 43, 35, 16, 38};
    key = 38;
    n = sizeof(arr) / sizeof(int);
    cout << last_occurence(arr, n, key);
    return 0;
}
