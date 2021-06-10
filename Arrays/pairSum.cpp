#include <iostream>
#include <algorithm>
using namespace std;
/*pair sum using two pointer approach*/ 
int main()
{
    // your code goes here
    int sum, i, j, s;
    int a[] = {1, 3, 5, 7, 10, 11, 12, 13};
    cin >> sum;
    i = 0;
    j = sizeof(a) / sizeof(int) - 1;
    while (i < j)
    {
        s = a[i] + a[j];
        if (s < sum)
        {
            i++;
        }
        else if (s > sum)
            j--;
        else if (s == sum)
        {
            cout << a[i] << "," << a[j] << endl;
            i++;
            j--;
        }
    }

    return 0;
}
