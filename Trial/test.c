#include <stdio.h>

int swapA(int a, int b)
{
    return b;
}

int swapB(int a, int b)
{
    return a;
}
void main()
{
    int a = 10, b = 20;
    printf("%d %d\n", a, b);
    int tmp = swapA(a, b);
    b = swapB(a, b);
    a = tmp;
    printf("%d %d\n", a, b);
}