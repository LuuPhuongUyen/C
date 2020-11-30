//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <math.h>

int ReverseNum(int n)
{
    printf("Enter a number: ");
    scanf("%d", &n);
    int rn = 0, d;
    while (n != 0)
    {
        d = (n % 10);
        rn = rn * 10 + d;
        n /= 10;
    }
    return rn;
}
int SumStop(int n)
{
    int s = 0;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &n);
        s += n;
    } while (n != 0);
    return s;
}
int SquareNum(int n)
{
    int a = sqrt(n);
    if (a * a == n)
        printf("%dx%d\n", a, a);
    else
        printf("False\n", n);
}
int main()
{
    int n, opt;
    do
    {
        printf("Enter option : ");
        scanf("%d", &opt);
    } while (opt > 4 && opt <= 0);
    switch (opt)
    {
    case 1:
        printf("Reverse number: %d", ReverseNum(n));
        break;
    case 2:
        printf("Sum = %d", SumStop(n));
        break;
    case 3:
        printf("Enter a number: "); scanf("%d", &n);
        SquareNum(n);
        break;
    default:
        break;
    }
    getch();
    return 0;
}