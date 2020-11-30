//Luu Phuong Uyen
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef char string[100];
void readFile(int **a, int **b, int **c, int *m, int *n, int *p, char *data, char *data2)
{
    FILE *fp, *fp2;
    int i, j;
    int *temp;
    if ((fp = fopen(data, "r")) == NULL)
    {
        printf("Unable to open %s.\n", data);
        return;
    }
    if ((fp2 = fopen(data2, "r")) == NULL)
    {
        printf("Unable to open %s.\n", data2);
        return;
    }
    fscanf(fp, "%d ", m);
    fscanf(fp, "%d", n);
    fscanf(fp2, "%d ", n);
    fscanf(fp2, "%d", p);
    *a = (int *)malloc(*(m) * *(n) * sizeof(int));
    *b = (int *)malloc(*(n) * *(p) * sizeof(int));
    *c = (int *)malloc(*(m) * *(p) * sizeof(int));

    for (i = 0; i < *m; i++)
    {
        fscanf(fp, "\n");
        for (j = 0; j < *n; j++)
        {
            temp = (*a + (i * *(n)) + j);
            fscanf(fp, "%d ", temp);
        }
    }
    for (i = 0; i < *n; i++)
    {
        fscanf(fp2, "\n");
        for (j = 0; j < *p; j++)
        {
            temp = (*b + (i * *(p)) + j);
            fscanf(fp2, "%d ", temp);
        }
    }
}

void PrintMatrix(int *Matrix, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%3d", *(Matrix + i * cols + j));
        printf("\n");
    }
}
void mulMaxtrix(int *a, int *b, int *c, int m, int n, int p)
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            *(c + i * p + j) = 0;
            for (k = 0; k < n; k++)
                *(c + i * p + j) += *(a + i * n + k) * *(b + k * p + j);
        }
    }
}
int main()
{
    string fn = "D:\\C\\LAB\\a.txt";
    string fn2 = "D:\\C\\LAB\\b.txt";
    int *a, *b, *c;
    int m, n, p;
    readFile(&a, &b, &c, &m, &n, &p, fn, fn2);
    printf("Matrix a:\n");
    PrintMatrix(a, m, n);
    printf("\nMatrix b:\n");
    PrintMatrix(b, n, p);
    printf("\nMatrix c = a x b:\n");
    mulMaxtrix(a, b, c, m, n, p);
    PrintMatrix(c, m, p);
    FILE *fc;
    fc = fopen("D:\\C\\LAB\\c.txt", "w+");
    fprintf(fc, "%d ", m);
    fprintf(fc, "%d\n", p);
    fclose(fc);
    getch();
    return 0;
}