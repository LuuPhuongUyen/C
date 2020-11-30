//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef int arr[100];
#define EVER \
    ;        \
    ;
#define MAXN 100
void sellChips(int *numChips, int *money);
int main()
{
    srand(100);
    int n, k, opt;
    int money = 1000, numChips = 0;
    int bet;
    menu();
    do
    {
        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            buyChips(&numChips, &money);
            break;
        case 2:
            sellChips(&numChips, &money);
            break;
        case 3:

            printf("How many chips would you like to bet? ");
            scanf("%d", &bet);
            if (bet > numChips)
                printf("Sorry, that is not allowed. No game played.");
            else if (playCraps())
            {
                printf("You win");
                numChips += bet;
            }
            else
                numChips -= bet;
            break;
        case 4:
            printf("How many chips would you like to bet? ");
            scanf("%d", &bet);
            if (bet > numChips)
                printf("Sorry, that is not allowed. No game played.");
            if (playArup())
                numChips += bet;
            else
                numChips -= bet;
            break;
        case 5:
            statusReport(numChips, money);
            break;
        case 6:
            exit(0);
            break;
        }
    } while (opt >= 1 && opt <= 6);
    getch();
    return 0;
}
int menu()
{
    printf("1. Buy chips\n");
    printf("2. Sell chips\n");
    printf("3. Play Craps\n");
    printf("4. Play Arup's Game of Dice\n");
    printf("5. Status Report\n");
    printf("6. Quit");
}

void buyChips(int *numChips, int *money)
{
    int n;
    printf("You have %d$\n", *money);
    printf("You can buy at most %d", (int)(*money / 11));
    printf("\nHow many chips do you want to buy? ");
    scanf("%d", &n);
    int cost = (*money - n * 11);
    if (cost < 0)
    {
        printf("Sorry, you do not have that much money. No chips bought.\n");
    }
    else
    {
        *money = cost;
        *numChips = (*numChips + n);
    }
}
void sellChips(int *numChips, int *money)
{
    int n;
    printf("You can buy at most %d", *numChips);

    printf("\nHow many chips do you want to sell? ");
    scanf("%d", &n);
    int cost = (*money + n * 10);
    if (n > *numChips)
        printf("Sorry, you do not have that many chips. No chips sold.");
    else
    {
        *money = cost;
        *numChips = (*numChips - n);
    }
}
int dice()
{
    int sum, random1, random2;
    random1 = rand() % 6 + 1;
    random2 = rand() % 6 + 1;
    sum = random1 + random2;
    return sum;
}
int playCraps()
{
    int sum = dice();
    printf("Press 'r' and hit enter for your first roll.");
    printf("You rolled %d\n", dice());
    if (dice() == 7 || dice() == 11)
        return 1;
    if (dice() == 2 || dice() == 3 || dice() == 12)
        return 0;
    for (EVER)
    {
        printf("Press 'r' and hit enter for your next roll.");
        printf("You rolled %d\n", dice());
        getchar();
        int newsum = dice();
        if (newsum == sum)
            return 1;
        else
            return 0;
    }
}
int playArup()
{
    int sum = dice();
    printf("Press 'r' and hit enter for your first roll.");
    printf("You rolled %d\n", dice());
    if (dice() == 11 || dice() == 12)
        return 0;
    if (dice() == 2)
        return 1;
    for (EVER)
    {
        printf("Press 'r' and hit enter for your next roll.");
        printf("You rolled %d\n", dice());
        getchar();
        int newsum = dice();
        if (newsum == 7)
            return 0;
        if (newsum == sum)
            return 1;
    }
}
int statusReport(int numChips, int money)
{
    printf("\nYou have %d$ and %d chips", money, numChips);
}