#include <stdio.h>

int main()
{
    int a, b, s, p;
    printf("Nhap hai so a,b: ");
    scanf("%d%d", &a, &b);
    s = a * b;
    p = (a + b) * 2;
    printf("Dien tich = %d\n", s);
    printf("Chu vi = %d", p);
    getch();
    return 0;
}