//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <conio.h>

int main()
{
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    i = 1;
    while (i <= 10)
    {
        printf("%dx%d = %d \n", n, i, n * i);
        ++i;
    }
    getch();
}