#include <stdio.h>

int gcd(int v1, int v2)
{
    int g;
    if (v2 > v1)
        g = gcd(v1, v2 - v1);
    else if (v1 > v2)
        g = gcd(v1 - v2, v2);
    else
        g = v1;
    return g;
}
int main()
{
    int m, n;
    do
    {
        printf("Enter 2 positives integer: ");
        scanf("%d%d", &m, &n);
    } while (m <= 0 || n <= 0);
    printf("GCD: %d", gcd(m, n));
    getch();
    return 0;
}
