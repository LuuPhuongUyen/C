#include <stdio.h>
#define MAXN 100
void input(int *a, int *pn);
int max(int a[], int n);
void print(int *a, int n);
void printEven(int *a, int n);
int main()
{
    int a[MAXN];
    int n;
    int maxVal;
    maxVal = max(a, n);
    printf("Max value: %d\n", maxVal);
    printf("\nInputted array: ");
    print(a, n);
    printf("\nEven values in array: ");
    printEven(a, n);
    while (getchar() != '\n');
    getchar();
    return 0;
}
void input(int *a, int *pn)
{
    *pn = 0;
    printf("Enter maximum %d elements, 0 for termination\n", MAXN);
    int x;
    do
    {
        scanf("%d", &x);
        if (x != 0)
            a[(*pn)++] = x;
    } while (x != 0 && *pn < MAXN);
}
int max(int a[], int n)
{ int i;
    int max = a[0];
    int index = 0;
   
    for (i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            index = i;
            max = a[i];
        }
    }
    //return max;
}
void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}
void printEven(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            printf("%d  ", a[i]);
}