#include <stdio.h>

int main()
{
    int i, n;
    printf("n=");
    scanf("%d", &n);
    int sum1 = 0;
    for (i = 1; i <= n; i++)
        sum1 += i;
    printf("sum1=%d\n", sum1);
    int sum2;
    for (sum2 = 0, i = 1; i <= n; sum2 += i, i++);
        printf("sum2=%d\n", sum2);
    int sum3 = 0;
    i = 1;
    for (;i<=n;)
    {
        sum3+=i;
        i++;
    }
    printf("sum3=%d\n", sum3);
    getch();
    return 0;
}