#include <stdio.h>

int Prime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void print_n_primes(int n)
{
    int count = 0, value = 2;
    while (count < n)
    {
        if (Prime(value) == 1)
        {
            printf("%d ", value);
            count++;
        }
        value++;
    }
}
int main()
{
    int n;
    printf("Enter number of primes: ");
    scanf("%d", &n);
    print_n_primes(n);
    getch();
    return 0;
}