//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <stdlib.h>
typedef int arr[200];
// GetDigit(int n, arr D)
// {
//     int re;
//     if (n == 0)
//         return;
//     else
//     {
//         re = n % 10;
//         GetDigit(n / 10, 10);
//         printf("%d ", re);
//     }
// }

int GetDigit(arr D, int n)
{
    int i = 0;
    while (n != 0)
    {
        D[i++] = n % 10;
        n /= 10;
    }
    return i;
}
void Reverse(arr D, int num)
{
    int i, j, t;
    for (i = 0, j = num - 1; i < j; i++, j--)
    {
        t = D[i];
        D[i] = D[j];
        D[j] = t;
    }
}
int main()
{
    arr D;
    int n, N;
    printf("Enter a number: ");
    scanf("%d", &N);
    n = GetDigit(D, N);
    Reverse(D, n);
    char ChuSo[10][10] = {" khong", " mot", " hai", " ba", " bon", " nam", " sau", " bay", " tam", " chin"};
    char Hang[6][10] = {" dong", " ngan", " trieu", " ty"};
    int i, p, re;
    for (i = 0; i < n; i++)
    {
        p = n - i;
        re = p % 3;
        if (re == 1)
        {
            if (D[i] > 0)
                printf("%s", ChuSo[D[i]]);
            printf("%s", Hang[p / 3]);
        }
        else if (re == 2)
        {
            if (D[i] == 1)

                printf(" muoi");
            else if (D[i] == 0)
                printf(" le");
            else
            {
                printf("%s", ChuSo[D[i]]);
                printf(" muoi");
            }
        }
        else
        {
            printf("%s", ChuSo[D[i]]);
            printf(" tram");
        }
    }
    int s = 0;
    n = abs(n);
    for (i = 0; i < n; i++)
        s += D[i];
    printf("\nSum of digits = %d", s);

    getch();
    return 0;
}