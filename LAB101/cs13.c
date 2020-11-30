//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef float arr[100];

void input(arr A, int *n)
{
    *n = 0;
    float k;
    for (;;)
    {
        printf("Enter number: ");
        scanf("%f", &k);
        if (k < 0 || k > 100)
            break;
        A[(*n)] = k;
        (*n)++;
    }
}
void output(arr A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%2.f ", A[i]);
}
int MinIndex(arr A, int n)
{
    int MinInd = 0;
    for (int i = 1; i < n; i++)
        if (A[i] < A[MinInd])
            MinInd = i;
    return MinInd;
}
int MaxIndex(arr A, int n)
{
    int MaxInd = 0;
    for (int i = 1; i < n; i++)
        if (A[i] > A[MaxInd])
            MaxInd = i;
    return MaxInd;
}

void removeAt(arr A, int *n, int pos)
{
    for (int j = pos + 1; j < *n; j++)
        A[j - 1] = A[j];
    (*n)--;
}
float Avg(arr A, int n)
{
    int i;
    float avg = 0, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += A[i];
    }

    avg = (float)sum / i;
    return avg;
}
float Deviation(arr A, int n, int agv)
{
    float stDevi = 0; //Standard deviation
    int i;
    for (i = 0; i < n; ++i)
        stDevi += pow(A[i] - agv, 2);
    return sqrt(stDevi / n);
}
void Histogram(arr A, int n)
{
    int i, j;
    for (i = 0; i <= 100; i += 5)
    {
        if (i == 100)
            printf("%7d|", i);
        else
            printf("%3d-%3d| ", i, i + 4);
        for (j = 0; j < n; j++)
        {
            if (A[j] >= i && A[j] <= i + 4)
                printf("*");
        }
        printf("\n");
    }
}
int main()
{
    int n, k, opt, ind, ind2;
    float mean;
    arr a;
    menu();
    do
    {
        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            input(a, &n);
            break;
        case 2:
            printf("Inputted array:\n");
            output(a, n);
            break;
        case 3:
            ind = MinIndex(a, n);
            printf("\nMin value found at position %d\n", ind);
            removeAt(a, &n, ind);
            break;
        case 4:
            ind2 = MaxIndex(a, n);
            printf("\nMax value found at position %d\n", ind2);
            removeAt(a, &n, ind2);
            break;
        case 5:
            printf("\nAverage = %f", Avg(a, n));
            break;
        case 6:
            mean = Avg(a, n);
            printf("Deviation = %f", Deviation(a, n, mean));
            break;
        case 7:
            Histogram(a, n);
            break;
        }
    } while (opt > 0 && opt <= 10);
    getch();
    return 0;
}
int menu()
{
    printf("1. Input number between [0..100].\n");
    printf("2. Print all\n");
    printf("3. Min index.\n");
    printf("4. Max index.\n");
    printf("5. Average.\n");
    printf("6. Deviation.\n");
    printf("7. Histogram.\n");
}