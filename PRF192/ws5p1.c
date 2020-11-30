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
    } while (total < 2 || total > 12);
    count = 0;
    do
    {
        x = random(1, 6);
        y = random(1, 6);
        printf("Result of throw %d: %d + %d\n", ++count, x, y);
    } while ((x + y) != total);
    printf("You got your total in %d throws!", count);
    getch();
    return 0;
}