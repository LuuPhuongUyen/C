#include <stdio.h>

int gcd(int v1, int v2)
{
    while (v1 != v2)
        if (v1 > v2)
            v1 -= v2;
        else
            v2 -= v1;
    return v1;
}
int lcm(int v1, int v2)
{
    return (v1 * v2) / gcd(v1, v2);
}
int main()
{
    int m, n, L, G;
    do
    {
        printf("Enter 2 positives integer: ");
        scanf("%d%d", &m, &n);
    } while (m <= 0 || n <= 0);
    G = gcd(m, n);
    L = lcm(m, n);
    printf("GCD: %d, LCM: %d\n", G, L);
    getch();
    return 0;
}