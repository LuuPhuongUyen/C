//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int n, base;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Enter a base: ");
    scanf("%d", &base);
    Convert(n, base);
    getch();
    return 0;
}
void Convert(int num, int base)
{
    int re;
    // base condition
    if (num == 0)
        return;
    else
    {
        re = num % base;          // get the rightmost digit
        Convert(num / base, base); // recursive call
        if (base == 16 && re >= 10)
            printf("%c", re + 55);
        else
            printf("%d", re);
    }
}
