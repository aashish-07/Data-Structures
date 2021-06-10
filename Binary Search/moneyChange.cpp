#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int n, am;
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    n = sizeof(a)/sizeof(int);
    am = 168;
    while (am > 0)
    {
        int lb = lower_bound(a, a + n, am, compare) - a - 1;
        cout << a[lb] << " ";
        am = am - a[lb];
    }
    return 0;
}