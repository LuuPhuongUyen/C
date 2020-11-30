#include <stdio.h>

float f(int n)
{
    int i;
    float t = 1;
    for (i = 1; i <= n; i++)
        t *= i;
    return t;
}
int main()
{
    int n, k;
    float C = 1;
    printf("n, k: ");
    scanf("%d %d", &n, &k);
    if (0 <= k && k <= n)
    {
        C = f(n) / (f(k) * f(n - k));
        printf("C = %.2f", C);
    }
    else
        printf("Invalid");
    getch();
}