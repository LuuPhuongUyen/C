//Luu Phuong Uyen SE1401
#include <stdio.h>

double factorial(int n)
{
    double p = 1;
    int i;
    for (i = 2; i <= n; i++)
        p *= i;
    return p;
}
int main()
{
    int n;
    double result;
    do
    {
        printf("Enter n = ");
        scanf("%d", &n);
    } while (n < 0);
    printf("n! = %.0lf", factorial(n));
    getch();
    return 0;
}