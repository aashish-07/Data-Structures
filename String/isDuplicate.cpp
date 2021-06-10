/*remove duplicate char from string*/
#include <iostream>
#include <cstring>
using namespace std;
void isDuplicate(char s[])
{
    int prev = 0;
    int l = strlen(s);
    if (l == 0 or l == 1)
    {
        return;
    }
    for (int current = 1; current < l; current++)
    {
        if (s[prev] != s[current])
        {
            prev++;
            s[prev] = s[current];
        }
    }
    s[prev + 1] = '\0';
    return;
}
int main()
{
    char s[100];
    cin.getline(s, 100);
    isDuplicate(s);
    cout << s;

    return 0;
}
