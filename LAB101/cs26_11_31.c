//Luu Phuong Uyen SE1401 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EVER ;;
typedef char string[100];
typedef int arr[100];
int main()
{
    arr D;
    int n, base;
    //printf("Enter a decimal number: ");
    //scanf("%d", &n);
    printf("Enter a base: ");
    scanf("%d", &base);
     printf("Enter a number: ");
    string s;
    fflush(stdin);
    gets(s);
    int num = XuLy(s, D);
    int n2 = ToDecimal(base, D, num);
    printf("\nThe number is %d\n", n2);
    getch();
    //int num = DecimalTo(n, base, D);
    // printf("\nThe number is %d\n", num);
    //Display(D, num);
    //int n2 = ToDecimal(base, D, num);
    // srand(100);
    // for (;;)
    // {
    //     int n = rand() % 1000000; //n=0,1,2,...,1000000-1
    //     int num = DecimalTo(n, base, D);
    //     int n2 = ToDecimal(base, D, num);
    //     if (n2 == n)
    //         //printf("\nKha nang dung rat cao");
    //         printf(".");
    //     else
    //     {
    //         printf("\nChuyen doi tu %d sang he %d khong dung", n, base);
    //         getch();
    //     }
    //     //getch(); //tieng bip
    // }
}
int DecimalTo(int n, int base, arr D)
{
    int pos = 0;
    while (n != 0)
    {
        int du = n % base;
        n /= base;
        D[pos++] = du;
    }
    Reverse(D, pos);
    return pos;
}
void Display(arr D, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        char c;
        if (D[i] >= 10)
            c = (char)(D[i] - 10 + 'A');
        else
            c = (char)(D[i] + '0');
        printf("%c", c);
    }
}
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
void Reverse(arr D, int num)
{
    int j;
    for (int i = 0, j = num - 1; i < j; i++, j--)
        swap(&D[i], &D[j]);
}
int ToDecimal(int base, arr D, int num)
{
    int i, n = 0;
    for (i = 0; i < num; i++)
        n += D[i] * pow(base, num - 1 - i);
    return n;
}
int CharToInt(char c)
{
    if ('0' <= c && c <= '9')
        return (c - '0');
    return (c - 'A' + 10);
}
int XuLy(char s[], arr D)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        D[i] = CharToInt(s[i]);
    return i;
}
