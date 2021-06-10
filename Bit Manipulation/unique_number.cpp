#include <iostream>
using namespace std;
/*Problem : Unique Number
  Give a list of numbers where every number occurs twice,except one find the number*/
int main()
{
    int n, num, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        //Using Bitwise XOR operator to find the number
        cin >> num;
        ans = ans ^ num;
    }
    cout << ans;
}
