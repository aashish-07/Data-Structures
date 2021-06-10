/*
i/p = 123
o/p = ABC
     AWC
    LCC
*/

#include <iostream>
using namespace std;

void generate_strings(char *input, char *out, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        out[j] == '\0';
        cout << out << endl;
        return;
    }

    // rec case
    // one digit at a time
    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generate_strings(input, out, i + 1, j + 1);

    // to digits at a time
    if (input[i + 1] != '\0')
    {
        int secondDigit = input[i + 1] - '0';
        int no = digit * 10 + secondDigit;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            generate_strings(input, out, i + 2, j + 1);
        }
    }
    return;
}

int main()
{

    char input[100];
    cin >> input;
    char output[100];
    generate_strings(input, output, 0, 0);

    return 0;
}
