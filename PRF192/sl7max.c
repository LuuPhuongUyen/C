#include <stdio.h>
//while min
int main()
{
    int n, dem = 0, s = 0, max;
    do
    {
        printf("n = ");
        scanf("%d", &n);
        s += n;
        dem += 1;
        if (n > max)
            max = n;
    } while (n != 0);
    printf("Average = %d\n", s / dem);
    printf("Max = %d", max);
    getch();
    return 0;
}