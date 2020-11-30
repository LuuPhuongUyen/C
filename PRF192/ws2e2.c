//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    float income, n, pa = 9000000, pd = 3600000, itax;
    printf("Enter your income: ");
    scanf("%f", &income);
    printf("Enter number of dependents: ");
    scanf("%f", &n);
    float tf = 12 * (pa + n * pd);
    float ti = income - tf;
    if (ti <= 0)
    {
        itax = 0;
        ti = 0;
    }
    else if (ti <= 5000000)
        itax = 0.05 * ti;
    else if (ti <= 10000000)
        itax = 0.05 * 5000000 + 0.1 * (ti - 5000000);
    else if (ti <= 18000000)
        itax = 0.05 * 5000000 + 0.1 * 5000000 + 0.15 * (ti - 10000000);
    else
        itax = 0.05 * 5000000 + 0.1 * 5000000 + 0.15 * 8000000 + 0.2 * (ti - 18000000);
    printf("Yearly tax-free income: %.2f\n", tf);
    printf("Taxable income: %.2f\n", ti);
    printf("Income tax: %.2f", itax);
    getch();
    return 0;
}