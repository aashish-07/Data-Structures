#include <iostream>
using namespace std;

char keypad[][10] = {"", " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRs", "TUV", "XYZ"};
void generate_names(char *input, char *out, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        out[j] == '\0';
        cout << out << endl;
        return;
    }

    // rec case
    int digit = input[i] - '0';
    if (digit == 0 || digit == 1)
    {
        generate_names(input, out, i + 1, j);
    }
    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        // fill the remaining part
        generate_names(input, out, i + 1, j + 1);
    }
}

int main()
{

    char input[100] = {0};
    cin >> input;
    char output[100];
    generate_names(input, output, 0, 0);

    return 0;
}
