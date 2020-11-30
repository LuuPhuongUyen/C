//Luu Phuong Uyen SE1401
#include <stdio.h>

void MinMax_Digits(int n)
{
    int digit = 0;     /* Variable for extracting 1 digit */
    int min, max;      /* Result variables */
    digit = n % 10;    /* get the first rightmost digit: 3 */
    n = n / 10;        /* 1029, the remainder needs to proceed after*/
    min = max = digit; /* initialize results */
    while (n > 0)
    {
        digit = n % 10; /* Get the next digit */
        n = n / 10;
        if (min > digit)
            min = digit; /* update results */
        if (max < digit)
            max = digit;
    }
    printf("Minimum digit: %d \nMaximum digit: %d", min, max);
}
int main()
{
    int n;
    do
    {
        printf("n = ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Enter a positive number!\n");
        }
        else
            MinMax_Digits(n);
    } while (n < 0);
    getch();
    return 0;
}
