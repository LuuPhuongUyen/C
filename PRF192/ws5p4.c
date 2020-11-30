//Luu Phuong Uyen - SE1401
#include <stdio.h>
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
        printf("Two roots are real and same x1=x2=%f", x1 = x2 = -b / (2 * a));
    else if (delta > 0)
        printf("Two roots are real and different x1=%.2f, x2=%.2f", x1 = (-b + sqrt(delta)) / (2 * a), x2 = (-b - sqrt(delta)) / (2 * a));
}
void bank()
{
    double deposit, rate, amount;
    int month;
    char c;
    do
    {
        printf("Input your deposit , monthly rate and the number of months : ");
        fflush(stdin);scanf("%lf %lf %d", &deposit, &rate, &month);
            if ((deposit <= 0) && (deposit== c))
                printf("Deposit must be positive!\n");
            if (month <= 0)
                printf("The number of months must be positive!\n");
            if (rate <= 0 || rate > 1.0)
                printf("Monthly rate must be positive but less than or equal to 1.0!\n"); 
    } while (deposit <= 0 || month <= 0 || rate <= 0 || rate > 1.0 );
    amount = (float)deposit * pow((1 + rate), month);
    printf("Your amount after duration : %f", amount);
    printf("\n");
}
int main()
{
    int n, opt;
    do
    {
        printf("Enter option: ");
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