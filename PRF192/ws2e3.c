//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    int n, s = 0;
    do
    {
        printf("n = ");
        scanf("%d", &n);
        s += n;
    } while (n != 0);
    printf("Sum = %d",s);
    getch();
}