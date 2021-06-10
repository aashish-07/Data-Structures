// Program to find power of a number using recursion
#include <iostream>
using namespace std;

int power(int x, int n)
{   
    // Base Case
    if (n == 0)
    {
        return 1;
    }
    // Recursive Case
    return x * power(x, n - 1);
}

int main()
{
    int n, x;
    cin >> x >> n;
    cout << power(x,n);

    return 0;
}