#include <stdio.h>

int main()
{
    double deposit, rate, amount;
    int i;
    do
    {
        printf("Input your deposit , monthly rate and amount after duration : ");
        fflush(stdin);
        scanf("%lf %lf %d", &deposit, &rate, &amount);
        if (deposit <= 0)
            printf("Deposit must be positive!\n");
        if (amount <= 0)
            printf("Amount must be positive!\n");
        if (rate <= 0 || rate > 1.0)
            printf("Monthly rate must be positive but less than or equal to 1.0!\n");
    } while (deposit <= 0 || amount <= 0 || rate <= 0 || rate > 1.0);
    for (i = 1; deposit <= amount; deposit = deposit *(1 + rate))
    {
        i++;
       }
     
    printf("The number of month: %d", i);
    getch();
    return 0;
}