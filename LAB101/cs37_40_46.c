//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SquareNumber()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    int a = sqrt(n);
    if (a * a == n)
        printf("%dx%d", a, a);
    else
        printf("False", n);
}
int Quadratic_equation()
{
    float a, b, c, x, x1, x2, delta;
    printf("Quadratic equation: ax^2+bx+c=0\n", a, b, c);
    printf("Enter a,b,c:\n");
    scanf("%f%f%f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (a == 0)
    {
        printf("Linear equation.");
        return;
    }
    if (delta < 0)
        printf("No root");
    else if (delta == 0)
        printf("Two roots are real and same x1=x2=%f", x1 = x2 = -b / (2 * a));
    else if (delta > 0)
        printf("Two roots are real and different x1=%.2f, x2=%.2f", x1 = (-b + sqrt(delta)) / (2 * a), x2 = (-b - sqrt(delta)) / (2 * a));
}
int Prime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void print_n_primes()
{
    int n;
    printf("Enter number of primes: ");
    scanf("%d", &n);
    int count = 0, value = 2;
    while (count < n)
    {
        if (Prime(value) == 1)
        {
            printf("%d ", value);
            count++;
        }
        value++;
    }
}
int isFibonacci()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    int t1 = 0, t2 = 1, f = 1;
    if (n == 1)
        return 1;
    while (f < n)
    {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    if (n == f)
        return 1;
}
int main()
{
    int n, opt;
    printf("1. Square number.\n");
    printf("2. Quadratic equation.\n");
    printf("3. Prime number.\n");
    printf("4. Fibonacci.\n");
    printf("5. Exit.");
    do
    {
        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            SquareNumber();
            break;
        case 2:
            Quadratic_equation();
            break;
        case 3:
            print_n_primes();
            break;
        case 4:
            if (isFibonacci() == 1)
                printf("Fibonacci element\n");
            else
                printf("Not a Fibonacci element\n");
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    } while (opt >= 1 && opt <= 5);
    getch();
    return 0;
}