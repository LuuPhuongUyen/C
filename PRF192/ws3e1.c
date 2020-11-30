//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <math.h>

int prime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0; //n is divisible by i
    return 1;         // n is a prime
}
int main()
{
    int n, i;
    do
    {
        printf("Enter n = ");
        scanf("%d", &n);
    } while (n < 2);
    for (i = 2; i <= n; i++)
    {
        if (prime(i) == 1)
            printf("%d\t", i);
    }
    getch();
    return 0;
}