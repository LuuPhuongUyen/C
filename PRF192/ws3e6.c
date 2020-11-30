//Luu Phuong Uyen SE1401
#include <stdio.h>

int isFibo(int n)
{
    int t1 = 1, t2 = 1, f = 1;
    if (n == 1)
        return 1; /* n belongs to the Fibonacci sequence*/
    while (f < n) /* Find out the Fibo number f to n */
    {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return n == f; // n is Fibo element
}
int main()
{
    int n;
    do
    {
        printf("Enter n = ");
        scanf("%d", &n);
    } while (n < 1);
    if (isFibo(n) == 1)
        printf("It is a Fibonacci element.");
    else
        printf("It is not a Fibonacci element.");
    getch();
    return 0;
}