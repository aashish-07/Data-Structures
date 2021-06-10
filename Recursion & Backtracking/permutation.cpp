#include <iostream>
using namespace std;

void permute(char *input, int i)
{
    if (input[i] == '\0')
    {
        cout << input << " ";
        return;
    }

    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        permute(input, i + 1);
        // Backtarcking - To restore the original array
        swap(input[i], input[j]);
    }
}
int main()
{
    char input[100];
    cin >> input;
    permute(input, 0);
    return 0;
}
