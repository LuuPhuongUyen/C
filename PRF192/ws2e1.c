//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <conio.h>

int main()
{
    double a, b, kq;
    char c;
    int err;
    printf("Enter num1, operator, num2:");
    scanf("%lf %c %lf", &a, &c, &b);
    switch (c)
    {
    case '+':
        kq = a + b;
        break;
    case '-':
        kq = a - b;
        break;
    case '*':
        kq = a * b;
        break;
    case '/':
        kq = a / b;
        if (b == 0)
        {
            printf("Not valid");
            err = 1;
        }
        else
            kq = a / b;
        break;
    default:
        err = 1;
        printf("Op is not supported\n");
        break;
    }
    if (err == 0)
        printf("Result : %.2lf", kq);
    getch();
    return 0;
}