// Program to print nth fibonacci
#include <iostream>
using namespace std;

int fib(int n)
{
    // bottom up approach
    int dp[100] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        /* code */
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibSpacOpt(int n)
{
    // bottom up approach
    if (n == 0 or n == 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        /* code */
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    cout << fibSpacOpt(n);

    return 0;
}