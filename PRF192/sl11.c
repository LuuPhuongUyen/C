#include <stdio.h>

int main()
{
    int n = 7, m = 8;
    int *p1 = &n;
    int *p2 = &m;
    *p1 += 12 - m + (*p2);   // = 7 + 12 - 8 + 8
    *p2 = m + n - 2 * (*p1); // = 8 + 19 - 2*19
    printf("%d", m + n);
    getch();
    return 0;
}