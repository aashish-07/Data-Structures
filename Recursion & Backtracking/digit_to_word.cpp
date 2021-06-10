#include <iostream>
using namespace std;

/* spell number 
2048 -> two zero four eight*/

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void spellnumbers(int n)
{
    if (n == 0)
        return;

    spellnumbers(n / 10);
    int digit = n % 10;
    cout << words[digit] << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    spellnumbers(n);

    return 0;
}
