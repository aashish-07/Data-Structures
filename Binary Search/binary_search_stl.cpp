#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 25};
    int n = sizeof(arr) / sizeof(int);
    int key = 8;
    /*binary_search function returns boolean value*/ 
    int ans = binary_search(arr, arr + n, key);
    if (ans)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }
    /*lower_bound returns address of the element >= key*/ 
    auto lb = lower_bound(arr, arr + n, key);
    cout << "lower bound is " << (lb - arr) << endl;
    /*upper_bound returns address of the element strictly greater than key*/
    auto ub = upper_bound(arr, arr + n, key);
    cout << "upper bound is " << (ub - arr) << endl;
    /*difference of ub & lb returns frequency*/ 
    cout << "frequency of given key is " << (ub - lb);

    return 0;
}
