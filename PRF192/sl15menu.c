#include <stdio.h>
#include <math.h>
int sum_pow(int a, int n)
{
    int i, sum = 0;
    do
    {
        for (i = 1; i <= n; i++)
        {
            sum += pow(a, i);
        }
    } while (n < 0);
    return sum;
}
float distance(float xA, float yA, float xB, float yB)
{
    return sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
}
int main()
{
    int opt;
    do
    {
        printf("Enter option : ");
        scanf("%d", &opt);
    } while (opt <= 0 && opt >= 3);
    switch (opt)
    {
    case 1:
        int a, n;
        printf("Enter a ,n: ");
        scanf("%d %d", &a, &n);
        printf("Sum = %f ", sum_pow(a, n));
        break;
    case 2:
        int xA, yA, xB, yB;
        printf("Enter coordinates A(xA;yA)\n");
        scanf(" %f %f ", &xA , &yA );
        printf("Enter coordinates B(xB;yB)\n");
        scanf(" %f %f ", &xB , &yB );
        printf("Distance = %f", distance(xA, yA, xB, yB));
        break;
    default:
        break;
    }
    getch();
}