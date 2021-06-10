#include <iostream>
using namespace std;
// compute a^n using recursion
// this program makes logN calls to compute power
int fast_power(int a, int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // recursive case
    int smaller_ans = fast_power(a, n / 2);
    smaller_ans *= smaller_ans;
    if (n & 1)
    {
        return a * smaller_ans;
    }

    return smaller_ans;
}
int main()
{
    int n, a;
    cin >> a >> n;
    cout << fast_power(a, n);

    return 0;
}