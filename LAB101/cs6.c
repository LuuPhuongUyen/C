//Luu Phuong Uyen
#include <stdio.h>
#include <stdlib.h>
typedef int arr[100];
#define EVER \
    ;        \
    ;
#define MAXN 100

int main()
{
    int n, k, opt;
    int *a;
    a = (int *)calloc(n, sizeof(int));
    menu();
    do
    {
        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {

        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            a = (int *)calloc(n, sizeof(int));
            input(a, n);
            break;
        case 2:
            break;
        case 3:
            printf("\nInputted array: ");
            printAll(a, n);
            break;
        case 4:
            printf("\nEven values in array: ");
            printEven(a, n);
            break;
        case 5:
            printf("\nEven values in array: ");
            printOdd(a, n);
            break;
        case 6:
            printRange(a, n);
            break;
        case 7:
            printf("\nMax value found at position %d\n", MaxIndex(a, n));
            break;
        case 8:
            printf("Add value: ");
            scanf("%d", &a[n]);
            n++;
            break;
        case 9:
            printf("Enter value to find\n");
            scanf("%d", &k);
            int pos = Search(a, n - 1, k);
            if (pos == -1)
                printf("\nElement %d not found\n", k);
            else
                printf("\nElement %d found at position %d\n", k, pos);
            break;
        case 10:
            printf("Element for remove: ");
            scanf("%d", &k);
            pos = Search(a, n, k);
            if (pos >= 0)
                removeAt(a, &n, pos);

            break;
        case 11:
            for (EVER)
            {
                printf("Element for remove: ");
                scanf("%d", &k);
                pos = Search(a, n, k);
                if (pos >= 0)
                    removeAt(a, &n, pos);
                else
                    break;
            }
            break;
        case 12:
            AscValue(a, n);
            break;
        case 13:
            DesValue(a, n);
            break;
        case 14:
            int *ind = AscBase(a, n);
            break;
        case 15:
            break;
        case 16:
            exit(0);
        }
    }

    while (opt >= 0 && opt <= 15);
    getch();
    return 0;
}
int input(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void printAll(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void printEven(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            printf("%d  ", a[i]);
}
void printOdd(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            printf("%d  ", a[i]);
}
void printRange(int val[], int n)
{
    int i;
    int MinVal, MaxVal;
    printf("Min Value: ");
    scanf("%d", &MinVal);
    printf("Max Value: ");
    scanf("%d", &MaxVal);
    printf("Value: ");
    for (i = 0; i < n; i++)
    {
        if (val[i] > MinVal && val[i] < MaxVal)
            printf("%d  ", val[i]);
    }
}
int MaxIndex(int a[], int n)
{
    int MaxInd = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[MaxInd])
            MaxInd = i;
    return MaxInd;
}
int Search(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            return i;
    return -1;
}

void removeAt(int a[], int *n, int pos)
{
    for (int j = pos + 1; j < *n; j++)
        a[j - 1] = a[j];
    (*n)--;
}
void AscValue(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    printf("\nArray after ascending value-base sort: ");
    printAll(a, n);
}
void DescValue(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    printf("\nArray after descending value-base sort: ");
    printAll(a, n);
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int AscBase(int a[], int n)
{
    int *ind = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        ind[i] = i;
    for (int p = 0; p <= n - 2; p++)
        for (int j = 0; j <= n - 2 - p; j++)
            if (a[ind[j]], a[ind[j + 1]])
                swap(&ind[j], &ind[j + 1]);
    return *ind;
}
int menu()
{
    printf("1. Input with a given number.\n");
    printf("2. \n");
    printf("3. Output all.\n");
    printf("4. Output even.\n");
    printf("5. Output odd.\n");
    printf("6. Output in range.\n");
    printf("7. Index of minimum and maximum.\n");
    printf("8. Add a value.\n");
    printf("9. Search index.\n");
    printf("10. Remove first.\n");
    printf("11. Remove all.\n");
    printf("12. Sort ascending value-base.\n");
    printf("13. Sort descending value-base.\n");
    printf("14. Sort ascending index-base.\n");
    printf("15. Sort descending index-base.\n");
    printf("16. EXIT.\n");
}
