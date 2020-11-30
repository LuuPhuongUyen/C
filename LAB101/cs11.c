#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, choice, base;

    while (1)
    {
        printf("1. Convert binary number to decimal number \n");
        printf("2. Convert octal number to decimal number \n");
        printf("3. Convert hexadeciaml number to decimal number. \n");
        printf("4. Exit. \n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
           BinToDec(num);
            
            break;
        case 2:
            base = 8;
            break;
        case 3:
            base = 16;
            break;
        case 4:
            printf("Exiting ...");
            exit(1);
        default:
            printf("Invalid choice.\n\n");
            continue;
        }

        printf("Enter a number: ");
        scanf("%d", &num);
    }

    return 0; // return 0 to operating system
}
int BinToDec(long long bin)
{
    int dec = 0, i = 0, remainder;
    // printf("Enter a binary number: ");
    // scanf("%lld", &bin);
    while (bin != 0)
    {
        remainder = bin % 10;
        bin /= 10;
        dec += remainder * pow(2, i);
        ++i;
    }
    
     printf("%lld in binary = %d in decimal", bin, dec);
     getch();
}
int OctToDec(int n)
{

    int oct, dec = 0, i = 0;
    printf("Enter an octal number: ");
    scanf("%d", &oct);
    while (oct != 0)
    {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    i = 1;
    return dec;
}
int main()
{
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    /* Input hexadecimal number from user */
    printf("Enter any hexadecimal number: ");
    gets(hex);

    /* Find the length of total number of hex digit */
    len = strlen(hex);
    len--;

    /*
     * Iterate over each hex digit
     */
    for(i=0; hex[i]!='\0'; i++)
    {
 
        /* Find the decimal representation of hex[i] */
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }

    printf("Hexadecimal number = %s\n", hex);
    printf("Decimal number = %lld", decimal);

    return 0;
}
int main()
{
    char hex[32]={0};
    int  dec,i;
    int  cnt;   /*for power index*/
    int  dig;   /*to store digit*/
 
    printf("Enter hex value: ");
    gets(hex);
 
    cnt=0;
    dec=0;
    for(i=(strlen(hex)-1);i>=0;i--)
    {
        switch(hex[i])
        {
            case 'A':
                dig=10; break;
            case 'B':
                dig=11; break;
            case 'C':
                dig=12; break;
            case 'D':
                dig=13; break;
            case 'E':
                dig=14; break;
            case 'F':
                dig=15; break;
            default:
                dig=hex[i]-0x30;
        }
        dec= dec+ (dig)*pow((double)16,(double)cnt);
        cnt++;
    }
 
    printf("DECIMAL value is: %d",dec);
    return 0;
}