#include <stdio.h>

int GetRand(int a, int b)
{
    return a + rand() % (b - a + 1);
}
int Prime()
{
    int a, b;

    int i, n = a + rand() % (b - a + 1);
    if (n < 2)
        return 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int min, max, count = 0, sum = 0;
    printf("Print min,max:");
    scanf("%d%d", &min, &max);
    while (count < Prime())
    {
        if (Prime() == 1)

        {
            count++;
            sum += Prime();
        }
    }
    printf("%d primes\n", count);
    printf("Sum of primes = %d", sum);

    getch();
}
