#include <stdio.h>
#include <stdlib.h>
void input(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void output(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
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
    output(a, n);
}
int BinarySearch(int a[], int l, int r, int k)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] < k)
        return BinarySearch(a, mid + 1, r, k);
    else if (a[mid] > k)
        return BinarySearch(a, l, mid - 1, k);
    else
        return mid;
}
int main()
{
    int count, search, n, a[50];
    int i, opt;
    do
    {
        printf("Option 1: Selection Sort\nOption 2: Binary Search\n");
        printf("Enter option : ");
        scanf("%d", &opt);
        printf("Enter number of elements\n");
        scanf("%d", &n);
        printf("Enter %d values of the arrays: \n", n);
        input(a, n);
        printf("\nInputted array: ");
        output(a, n);
        switch (opt)
        {
        case 1:
            SelectionSort(a, n);
            break;
        case 2:
            SelectionSort(a, n);
            printf("\nEnter value to find\n");
            scanf("%d", &search);
            int position = BinarySearch(a, 0, n - 1, search);
            if (position == -1)
                printf("\nElement %d not found\n", search);
            else
                printf("\nElement %d found at position %d\n", search, position);
            break;
        default:
            break;
        }
    } while (opt <= 0 && opt >= 3);
    getch();
    return 0;
}