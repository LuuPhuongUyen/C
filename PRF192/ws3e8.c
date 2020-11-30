//Luu Phuong Uyen SE1401
#include <stdio.h>

double makeDouble(int ipart, int fraction)
{
    double d_f = fraction;
    while (d_f >= 1)
        d_f = d_f / 10; /* create the fraction <1 */
    if (ipart < 0)
        return ipart - d_f; /* case  -51 – 0.139 */
    return ipart + d_f;     /* case 32 + 0.25 */
}
int main()
{
    int ipart, fraction;
    do
    {
        printf("Enter ipart: ");
        scanf("%d", &ipart);
        printf("Enter fraction: ");
        scanf("%d", &fraction);
        if (fraction < 0)
            printf("Its fraction must be positive!\n");
    } while (fraction < 0);
    double value = makeDouble(ipart, fraction);
    printf("%.4lf", value);
    getch();
    return 0;
}
