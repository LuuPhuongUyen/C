//Luu Phuong Uyen SE1401
#include <stdio.h>

int sumDigits(int n)
{
    int sum = 0; /* initialize sum of digits */
    do
    {
        int remainder = n % 10; /* Get a digit at unit position */
        n = n / 10;
        sum += remainder;
    } while (n > 0);
    return sum;
}
int main()
{
    int n;
    do
    {
        printf("n = ");
        scanf("%d", &n);
        if (n >= 0)
        {
            int S = sumDigits(n);
            printf(" S = %d\n", S);
        }
    } while (n >= 0);
    getchar();
}