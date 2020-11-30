//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
void input(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
}
int Search(int a[], int l, int r, int k)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] < k)
        return Search(a, mid + 1, r, k);
    else if (a[mid] > k)
        return Search(a, l, mid - 1, k);
    else
        return mid;
}
void SelectionSort(int *a, int n)
{
    int minIndex;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (a[minIndex] > a[j])
                minIndex = j;
        if (minIndex > i)
        {
            int t = a[minIndex];
            a[minIndex] = a[i];
            a[i] = t;
        }
    }
    printf("\nArray after sort: ");
    print(a, n);
}
void Range(int val[], int n)
{
    int i;
    int MinVal, MaxVal;
    printf("Min Value: ");
    scanf("%d", &MinVal);
    printf("Max Value: ");
    scanf("%d", &MaxVal);
    printf("\nValue: ");
    for (i = 0; i < n; i++)
    {
        if (val[i] > MinVal && val[i] < MaxVal)
            printf("%d  ", val[i]);
    }
}
int main()
{
    int a[MAXN];
    int n, option, search, again = 1;
    int val;
    do
    {
        printf("How many elements which will be used ..%d: ", MAXN);
        scanf("%d", &n);
    } while (n < 1 || n > MAXN);
    printf("Enter %d values of the arrays: \n", n);
    input(a, n);
    do
    {
        printf("\nOption 1: Add a value to array");
        printf("\nOption 2. Search a value");
        printf("\nOption 3. Print out the array");
        printf("\nOption 4. Print out the value in range");
        printf("\nOption 5. Print out the array in ascending order");
        printf("\nOption 6. EXIT");
        printf("\nEnter option = ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: // Add value
            printf("Value: ");
            scanf("%d", &a[n]);
            n++;
            break;
        case 2: // Search a value
            printf("Enter value to find\n");
            scanf("%d", &search);
            int position = Search(a, 0, n - 1, search);
            if (position == -1)
                printf("\nElement %d not found\n", search);
            else
                printf("\nElement %d found at position %d\n", search, position);
            break;
        case 3: // Print out the array
            printf("Array: ");
            print(a, n);
            break;
        case 4: // Print out the value in range
            Range(a, n);
            break;
        case 5: // Print out the array in ascending order
            SelectionSort(a, n);
            break;
        case 6: // Exit
            exit(0);
            break;
        }
        printf("\n1. Again ?\n2. Exit");
        printf("\nEnter your idea: ");
        scanf("%d", &again);
    } while (again == 1);
    getchar();
    return 0;
}
