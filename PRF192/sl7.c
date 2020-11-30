#include <stdio.h>

int main()
{
    int i, n, s = 0;
    printf("Nhap n = ");
    scanf("%d", &n);
    i = (n % 2 == 1) ? 1 : 2;
    for (; i <= n; i += 2)
        s += i;
    printf("Tong = %d", s);
    getch();
    return 0;
}