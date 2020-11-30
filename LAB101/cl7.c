//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int i, r;
    int perfect = 0, imperfect = 0;
    clock_t start = clock();
    //srand((unsigned)time(0));
    srand(100);
    int a = rand() % 6;
    int b = rand() % 6;
    int c = rand() % 6;
    int d = rand() % 6;
    int aa, bb, cc, dd;
    for (i = 1; i <= 10; i++)
    {
        printf("\nInput the mind: \n");
        scanf("%d %d %d %d", &aa, &bb, &cc, &dd);
        if (a == aa)
            perfect++;
        if (b == bb)
            perfect++;
        if (c == cc)
            perfect++;
        if (d == dd)
            perfect++;
        if (perfect == 4)
        {
            int delta = (clock() - start) / CLOCKS_PER_SEC;
            printf("You win in %d seconds", delta);
            break;
        }
        if (a == bb || a == cc || a == dd)
            imperfect++;
        if (b == aa || b == cc || b == dd)
            imperfect++;
        if (c == aa || c == bb || c == dd)
            imperfect++;
        if (d == aa || d == bb || d == cc)
            imperfect++;
        printf("You have %d perfect matches and %d imperfect matches", perfect, imperfect);
    }
    if (i > 10)
        printf("\nHere is the winning board: %d %d %d %d", a, b, c, d);
    getch();
    return 0;
}