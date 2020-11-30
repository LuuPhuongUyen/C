#include <stdio.h>

int hour(int n)
{
    int n, k, h = 0, m = 0, s = 0;
    h = n / 3600;
    k = n % 3600;
    s = k / 60;
    m = k % 60;
  
}
int SumMaxMin(int n, int *max, int *min)
{
    int digit = 0, sum = 0;
    min = max = digit;
    digit = n % 10;
    n = n / 10;
    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;
        if (min > digit)
            min = digit;
        if (max > digit)
            max = digit;
        sum += digit;
    }
    printf("Minimum digit: %d \nMaximum digit: %d\n", min, max);
    printf("Sum of digits = %d", sum);
    
}
int main()
{
    int n, opt, max, min;
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
            printf("%d h %d m %d s ", hour(n));
            break;
        case 2:
            SumMaxMin(n, max,min);
            break;
        default:
            break;
        }
    } while (n < 0);
    getch();
    return 0;
}