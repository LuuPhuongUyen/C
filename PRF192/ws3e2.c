//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <conio.h>

int validDate(int d, int m, int y)
{
    int maxd = 31; //max day of months 1, 3, 5, 7, 8, 10, 12
    if (d < 1 || d > 31 || m < 1 || m > 12)
        return 0;
    // update maxd of a month
    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxd = 30;
    else if (m == 2)
    {
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
            maxd = 29; //leap year
        else
            maxd = 28;
    }
    return d <= maxd;
}
int main()
{
    int d, m, y, result;
    printf("Enter day, month, year: ");
    scanf(" %d  %d  %d", &d, &m, &y);
    result = validDate(d, m, y);
    if (result)
        printf("Valid date");
    else
        printf("Invalid date");
    getch();
    getch();
    return 0;
}