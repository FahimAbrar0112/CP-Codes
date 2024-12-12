#include <bits/stdc++.h>
using namespace std;

/*
    binary odd->last bit 1
    binary even->last bit 0

*/

bool evenOrOdd(int n)
{
    return (n & 1);
    // o even
    // 1 odd
}

void printBinary(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

char upperTOlower(char c)
{
    // return (c|(1<<5));

    return (c | ' ');
    // c | space
}
char lowerTOupper(char c)
{

    // return (c & (~(1<<5)));

    return (c & '_');
    // c & _ underscore
}

int clear_some_bit(int n, int i)
{
    // i = you wanna clear/convert 0 to ith bit to 0
    int x = ~((1 << (i + 1)) - 1);
    return (n & x);
}

bool check_is_n_a_powerOf_2_or_not(int n)
{
    // is n divisible by 2
    return !(n & (n - 1));
}

int clear_ith_bit_to_msb_all_1(int n, int i)
{
    int x = (1 << (i)) - 1;
    return n & x;
}

int main(void)
{

    // printBinary(59);
    printBinary((int('A')));
    printBinary((int)'a');
    cout << upperTOlower('A') << " " << lowerTOupper('z') << endl;

    printBinary(clear_some_bit(59, 4));
    printBinary(clear_ith_bit_to_msb_all_1(59, 4));

    return 0;
}