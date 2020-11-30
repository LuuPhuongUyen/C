//Luu Phuong Uyen - SE1401
#include <stdio.h>
int prime(int n)
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
void MinMax_Digits(int n)
{
    int digit = 0;
    int min, max;
    digit = n % 10;
    n = n / 10;
    min = max = digit;
    while (n > 0)
    {
        digit = n % 10; // Get the next digit
        n = n / 10;
        if (min > digit)
            min = digit; // update results
        if (max < digit)
            max = digit;
    }
    printf("Minimum digit: %d \nMaximum digit: %d", min, max);
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
    } while (n <= 0 && opt <= 0 && opt >= 3);
    do
    {
        switch (opt)
        {
        case 1:
            if (prime(n) == 0)
                printf("%d is not a prime", n);
            else
                printf("%d is a prime", n);
            break;
        case 2:
            MinMax_Digits(n);
            break;
        default:
            break;
        }
    } while (n < 0);
    getch();
    return 0;
}