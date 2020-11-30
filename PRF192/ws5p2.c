//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <math.h>

int random(int a, int b)
{
    return (a + rand() % (b - a + 1));
}
int main()
{
    int total, x, y, count;
    do
    {
        srand(time(NULL));
        printf("Total = ");
        fflush(stdin);
        scanf("%d", &total);
    } while (total < 2 || total > 20);
    count = 0;
    do
    {
        x = random(1, 10);
        y = random(1, 10);
        printf("Result of picks %d and %d: %d + %d\n", count++, ++count, x, y);
    } while ((x + y) != total);
    printf("You got your total in %d picks!", count);
    getch();
    return 0;
}