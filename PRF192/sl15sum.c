#include <stdio.h>
int main()
{
    int a = 5, b = 50, n = 5;
    int s = 0, count = 0;
    srand(time(NULL));
    while (count < n)
    {
        int i = a + rand() % (b - a);
        if (i % 2 == 0)
        {
            s += i;
            count++;
            printf("%d ", i);
        }
    }
    printf("Sum = %d", s);
    getch();
    return 0;
}