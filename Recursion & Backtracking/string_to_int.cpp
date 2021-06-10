#include <iostream>
#include <cstring>
using namespace std;

int stringtToInt(char *a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int digit = a[n - 1] - '0';
    int smallerans = stringtToInt(a, n - 1);
    return smallerans * 10 + digit;
}
int main()
{
    char num[] = "1234";
    int len = strlen(num);
    cout << stringtToInt(num, len);

    return 0;
}
