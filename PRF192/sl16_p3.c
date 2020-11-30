#include <stdio.h>
#include <math.h>

int validDate()
{
    int d, m, y;
    printf("Enter day, month, year: ");
    scanf(" %d  %d  %d", &d, &m, &y);
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12)
        return 0;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxd = 30;
    else if (m == 2)
    {
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
            maxd = 29;
        else
            maxd = 28;
    }
    return d <= maxd;
}

void ASCIICode()
{
    char c1, c, c2;
    int code1, code2;
    fflush(stdin);
    printf("\n Enter a character 1: ");
    // Reads character input from the user
    scanf("%c", &c1);
    code1 = c1;
    fflush(stdin);
    printf("\n Enter a character 2: ");
    // Reads character input from the user
    scanf("%c", &c2);
    code2 = c2;
    if (c1 > c2)
    {
        {
            for (c1; c1 >= c2; c1--)
                printf("%c : %d, %o, %X\n", c, c, c, c);
        }
    }
    else
    {

        for (c2; c2 <= c1; c--)
            printf("%c : %d, %o, %X\n", c, c, c, c);
    }
}
/*      {
            printf("%c : %d, %o, %X\n", c1, c1, c1, c1);
            for (c = c1 + 1; c < c2; c++)
                printf("%c : %d, %o, %X\n", c, c, c, c);
            printf("%c : %d, %o, %X\n", c2, c2, c2, c2);
        }
    }
    else
    {
        printf("%c : %d, %o, %X\n", c2, c2, c2, c2);
        for (c = c2 + 1; c < c1; c++)
            printf("%c : %d, %o, %X\n", c, c, c, c);
        printf("%c : %d, %o, %X\n", c1, c1, c1, c1);
    }
*/
int main()
{
    int n, opt;
    do
    {
        printf("Enter option : ");
        scanf("%d", &opt);
    } while (opt <= 0 && opt >= 3);

    switch (opt)
    {
    case 1:
        if (validDate())
            printf("Valid date");
        else
            printf("Invalid date");
        break;
    case 2:
        ASCIICode();
        break;
    default:
        break;
    }
    getch();
    return 0;
}