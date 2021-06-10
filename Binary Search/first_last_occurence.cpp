#include <iostream>
using namespace std;
/*first and last occurence of a key in sorted array*/ 
int first_occurence(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

int last_occurence(int a[], int n, int key)
{
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 25};
    int n = sizeof(arr) / sizeof(int);
    int key = 8;

    cout << first_occurence(arr, n, key) << endl;
    cout << last_occurence(arr, n, key);

    return 0;
}
