#include <stdio.h>

double S1(int n)
{
    int i;
    double s1 = 0;
    for (i = 1; i <= n; i++)
    {
        s1 += i * (i + 1);
    }
    return s1;
}
double S2(int n)
{
    int i;
    double s2 = 1;
    for (i = 2; i <= n; i++)
        s2 *= i;
    return s2;
}
double S3(int n)
{
    int i;
    double s3 = 0;
    for (i = 2; i <= n; i += 2)
        s3 += 1 / (n * (n + 2));
}
int main()
{
    int opt;
    int n;
    double s1, s2, s3;
    printf("Enter n = ");
    scanf("%d", &n);
    printf("Enter option : ");
    scanf("%d", &opt);
    do
    {
        switch (opt)
        {
        case 1:
            printf("S1=%lf", S1(n));
            break;
        case 2:
            printf("S2=%lf", S2(n));
            break;
        case 3:
            printf("S3=%lf", S3(n));
            break;
        }
    } while (n < 0);
    getch();
    return 0;
}