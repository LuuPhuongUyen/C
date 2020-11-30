#include <stdio.h>
#include <math.h>
int fibonacci(int n)
{
    int t1 = 1, t2 = 1, f = 1, i;
    for (i = 3; i <= n; i++) // i la position
    {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return f;
}

int is_prime(int n) // return 1 if number is prime, 0 if not prime
{
    int m = sqrt(n);
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= m; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
//nth prime
int prime(int n)
{
    int dem = 0, i = 1;
    while (dem < n)
    {
        i++;
        if (is_prime(i) == 1)
            dem++;
    }
    return i;
}

int gcd(int n, int n1)
{
    n1 = n + 100;
    while (n != n1)
        if (n > n1)
            n -= n1;
        else
            n1 -= n;
    return n;
}
int main()
{
    int n, opt;
    do
    {
        printf("Enter number : ");
        scanf("%d", &n);
        printf("Enter option : ");
        scanf("%d", &opt);
    } while (n <= 0 && opt <= 0);
    do
    {
        switch (opt)
        {
        case 1:
            printf("Fibonacci %dth : %d ", n, fibonacci(n));
            break;
        case 2:
            printf("Prime %dth : %d", n, prime(n));
            break;
        case 3:
            printf("GCD: %d", gcd(n, (n + 100)));
            break;
        default:
            break;
        }
    } while (n < 0);
    getch();
}