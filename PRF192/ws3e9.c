//Luu Phuong Uyen SE1401
#include <stdio.h>
int gcd(int a, int b)
{
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
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