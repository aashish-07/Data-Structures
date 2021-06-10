#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// min steps to one
// n -> n/3, n/2, n-1
// top down approach
int minSteps(int n, int dp[])
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    // recursive case
    // lookup if n is computed
    if (dp[n] != 0)
    {
        return dp[n];
    }
    // compute if dp is not known
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op1 = (minSteps(n / 3, dp)) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = (minSteps(n / 2, dp)) + 1;
    }
    op3 = minSteps(n - 1, dp) + 1;

    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

// Bottom up Approach
int minStepsBU(int n){
	int dp[100] = {0};
	dp[1] = 0;
	//Loop
	for(int i=2;i<=n;i++){
        int op1,op2,op3;
		int op2 = i%2==0?dp[i/2]:INT_MAX;
		int op3 = i%3==0?dp[i/3]:INT_MAX;
		int ans = min(op1,min(op2,op3)) + 1;
		dp[i] = ans;
	}
	return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << minSteps(n, dp);

    return 0;
}
