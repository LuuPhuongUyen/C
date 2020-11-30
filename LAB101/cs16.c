//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float mortgage, rate, payment;
    int month = 1;
    printf("What is the value left on the mortgage?\n");
    scanf("%f", &mortgage);
    printf("What is the annual interest rate of the loan, in percent?\n");
    scanf("%f", &rate);
    printf("What is the monthly payment?\n");
    scanf("%f", &payment);
    printf("Month	Payment		Amount Owed\n");
    do
    {
        mortgage = (mortgage + mortgage * rate / 1200) - payment;
        printf("%2d%12.2f %16.2f\n", month++, payment, mortgage);
    } while (mortgage > payment);
    printf("%2d%12.2f\t\t0", month, mortgage = (mortgage + mortgage * rate / 1200));
    getch();
}