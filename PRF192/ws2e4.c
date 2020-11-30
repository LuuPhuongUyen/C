//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    int t, x, y;
    do
    {
        printf("Enter two integers: ");
        scanf("%d%d", &x, &y);
        t = x;
        x = y;
        y = t;
        printf("x = %d\n", x);
        printf("y = %d\n", y);
    } while (x != 0 && y != 0);
    getch();
    return 0;
}