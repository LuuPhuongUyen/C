//Luu Phuong Uyen - SE1401
#include <stdio.h>
void print_n_fib(int n)
{
    int t1 = 0, t2 = 1, i;
    if (n < 3)
        return 1;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", t2);
        int f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
}
int validDate(int d, int m, int y)
{
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12)
        return 0;
    // update maxd of a month
    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxd = 30;
    else if (m == 2)
    {
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
            maxd = 29; //leap year
        else
            maxd = 28;
    }
    return d <= maxd;
}
int main()
{
    int n, opt, d, m, y;
    do
    {
        printf("Enter option : ");
        scanf("%d", &opt);
    } while (opt <= 0 && opt >= 3);
    do
    {
        switch (opt)
        {
        case 1:
            printf("n = ");
            scanf("%d", &n);
            print_n_fib(n);
            break;
        case 2:
            printf("Enter day, month, year: ");
            scanf(" %d  %d  %d", &d, &m, &y);
            if (validDate(d, m, y))
                printf("Valid date");
            else
                printf("Invalid date");
            break;
        default:
            break;
        }
    } while (n < 0);
    getch();
    return 0;
}