#include <iostream>
using namespace std;

/*PROBLEM : AGGRESSIVE COWS
LINK : https://www.spoj.com/problems/AGGRCOW */

bool canPlaceCows(int stalls[], int n, int c, int minSteps)
{
    // first place should be occupied
    int lastCow = stalls[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        // check if current stall can be occupied
        if (stalls[i] - lastCow >= minSteps)
        {
            lastCow = stalls[i];
            count++;
            if (count == c)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int cows = 3;
    // binary search in monotonic search space
    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool cowRakhPaye = canPlaceCows(stalls, n, cows, mid);
        if (cowRakhPaye)
        {
            ans = mid;
            // to maximize minimum distance between two stalls
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
