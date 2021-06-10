#include <iostream>
using namespace std;

/*Generate subsets of a string
    input = "abc"
    output = {" ","a","b","c","ab","ac","bc","cb"};
*/

void generate_subsets(char *input, char *output, int i, int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        ;
        return;
    }
    // rec case
    // include first character
    output[j] = input[i];
    generate_subsets(input, output, i + 1, j + 1);
    // exclude first character
    generate_subsets(input, output, i + 1, j);
}

int main()
{
    char input[] = "abc";
    char output[10];
    generate_subsets(input, output, 0, 0);
    return 0;
}
