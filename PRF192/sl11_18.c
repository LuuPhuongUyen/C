#include <stdio.h>

int main()
{
    int n = 1000;
    int *p = &n;
    printf("p = %d\n", p);
    printf("p + 8 = %d\n", p + 2); //+2*4 bytes
    printf("p - 3 = %d\n", p - 3);
    printf("p++ = %d", ++p);
    getch();
    return 0;
}
lp