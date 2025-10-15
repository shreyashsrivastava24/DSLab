#include <stdio.h>

void toh(int n, char a, char b, char c)
{
    if (n == 1)
        return;
    toh(n - 1, a, c, b);
    printf("move %c to %c\n", a, c);
    toh(n - 1, b, a, c);
}

int main()
{
    toh(4, 'A', 'B', 'C');
}