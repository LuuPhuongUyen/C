#include <stdio.h>

int main()
{
    int n, t;
    printf("Enter number of kwhs n = ");
    scanf("%d", &n);
    if (n <= 100)
        t = n * 950;
    else if (n <= 150)
        t = n * 1250 + (n - 100) * 950;
    else if (n <= 200) 
        t = 100 * 1350 + 50 * 1250 + (n - 150) * 950;
    else t = 100 * 1550 + 50 * 1350 + 50 * 1250 + (n - 200) * 950;
    printf("Prices = %d", t);
    getch();
}