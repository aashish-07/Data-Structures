#include <iostream>
using namespace std;

void generate_brackets(char *output, int idx, int n, int open, int close)
{
    // base case
    if (idx == 2 * n)
    {
        output[idx] = '\0';
        cout << output << endl;
        return;
    }

    // rec case
    if (open < n)
    {
        output[idx] = '(';
        generate_brackets(output, idx + 1, n, open + 1, close);
    }
    if (close < open)
    {
        output[idx] = ')';
        generate_brackets(output, idx + 1, n, open, close + 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    char output[100];
    int idx = 0;
    generate_brackets(output, 0, n, 0, 0);
    return 0;
}
