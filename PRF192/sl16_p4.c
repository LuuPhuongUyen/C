#include <stdio.h>
#include <conio.h>
#include <math.h>
int Quadratic_equation()
{
    float a, b, c, x, x1, x2, delta;
    printf("Quadratic equation: ax^2+bx+c=0\n", a, b, c);
    printf("Enter a,b,c:");
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
        printf("Two Roots are real and same x1=x2=%f", x1 = x2 = -b / (2 * a));
    else if (delta > 0)
        printf("Two Roots are real and different x1=%.2f, x2=%.2f", x1 = (-b + sqrt(delta)) / (2 * a), x2 = (-b - sqrt(delta)) / (2 * a));
}
void bank()
{
    double deposit, rate, amount;
    int month, check;
    do
    {
        printf("Input your deposit , monthly rate and the number of months : ");
        fflush(stdin);
        check = scanf("%lf%*c%lf%*c%d", &deposit, &rate, &month);
        if (check != 3)
            printf("Retype 3 value please!\n");
        else
        {
            if (deposit <= 0)
                printf("Deposit must be positive!\n");
            if (month <= 0)
                printf("The number of months must be positive!\n");
            if (rate <= 0 || rate > 0.1)
                printf("Monthly rate must be positive but less than or equal to 0.1!\n");
        }
    } while (deposit <= 0 || month <= 0 || rate <= 0 || rate > 0.1 ||
             check != 3);
    amount = (float)deposit * pow((1 + rate), month);
    printf("Your amount after duration : %f", amount);
    printf("\n");
    system("pause");
    system("cls");
}
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
        Quadratic_equation();
        break;
    case 2:
        bank();
        break;
    default:
        break;
    }
    getch();
    return 0;
}
