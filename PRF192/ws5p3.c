//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <math.h>

void checkDate()
{
    int d, m, y;
    printf("Enter day, month, year: ");
    scanf(" %d  %d  %d", &d, &m, &y);
    {
        if (m >= 1 && m <= 12)
        {
            if ((d >= 1 && d <= 31) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                printf("Valid date\n");
            else if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                printf("Valid date\n");
            else if ((d >= 1 && d <= 28) && (m == 2))
                printf("Valid date\n");
            else if (d == 29 && m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
                printf("Valid date\n");
            else
                printf("Invalid date\n");
        }
        else
            printf("Month is not valid.\n");
    }
}
void ASCIICode()
{
    char c1, c2;
    int code1, code2;
    printf("\nEnter a character 1: ");
    scanf(" %c", &c1);
    code1 = c1;
    fflush(stdin);
    printf("\nEnter a character 2: ");
    scanf(" %c", &c2);
    code2 = c2;
    if (code1 > code2)
    {
        for (code1; code1 >= code2; code1--)
        {
            printf("%c: %d, %o, %X\n", code1, code1, code1, code1);
        }
    }
    else
    {
        for (code2; code1 <= code2; code2--)
            printf("%c: %d, %o, %X\n", code2, code2, code2, code2);
    }
}
int main()
{
    int num, i;
    unsigned long int fact;
    int opt;
    do
    {
        printf("\n 1. Check date");
        printf("\n 2. Character");
        printf("\n 3. Quit");
        printf("\n Enter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            checkDate();
            break;
        case 2:
            ASCIICode();
            break;
        default:
            break;
        }
    } while (opt <= 0 && opt >= 3);
    getch();
    return 0;
}
