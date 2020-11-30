//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, **a, **b, **c;
    InputMatrix(&m, &n, &a);
    output(m, n, a);
    InputMatrix(&m, &n, &b);
    output(m, n, b);
    c = Sum2Maxtrix(m, n, a, b);
    printf("\nSum of two maxtrices:\n");
    output(m, n, c);
    getch();
    return 0;
}
void InputMatrix(int *pm, int *pn, int ***pa)
{
    printf("\nThe number of rows and columns: ");
    scanf("%d %d", pm, pn);
    *pa = malloc((*pm) * sizeof(int *));
    for (int i = 0; i < *pm; i++)
    {
        *((*pa) + i) = (int *)malloc((*pn) * sizeof(int)); //a[i]
        for (int j = 0; j < *pn; j++)
            scanf("%d", *((*pa) + i) + j); //dia chi cua a[i][j]
    }
}
void output(int m, int n, int **a)
{
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("%4d", *(*(a + i) + j)); //a[i][j];
    }
}
int **Alloc(int m, int n)
{
    int **c = (int **)malloc(m * sizeof(int **));
    for (int i = 0; i < m; i++)
        *(c + i) = (int *)malloc(n * sizeof(int));
    return c;
}
int Sum2Maxtrix(int m, int n, int **a, int **b)
{
    int i, j;
    int **c = Alloc(m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
    }
    return c;
}