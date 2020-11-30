//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef char string[100];
typedef struct it
{
    int id;
    string name;
    float cost;
    char cate;
} item;
typedef item ItemArr[50];
void Load(string fn, ItemArr A, int *n);
void Save(string fn, ItemArr A, int n);

void Display(ItemArr A, int n);
item Input();
int InputId_ReturnIndex(ItemArr A, int n);
int IndexOf(ItemArr A, int n, int id);
void swap(item *x, item *y);
int main()
{
    string fn = "D:\\C\\LAB\\food.txt";
    string fn2 = "D:\\C\\LAB\\food2.txt";
    ItemArr A;
    int n, opt;
    Load(fn, A, &n);
    do
    {
        printf("\n1.Add new item");
        printf("\n2.Delete item");
        printf("\n3.Change the cost");
        printf("\n4.Search for item");
        printf("\n5.Display the list");
        printf("\n6.Sort by name");
        printf("\n7.Quit");
        printf("\nEnter option: ");
        scanf("%d", &opt);
        item x;
        int ind;
        switch (opt)
        {
        case 1:
            A[n++] = Input();
            break;

        case 2:
            ind = InputId_ReturnIndex(A, n);
            if (ind > -1)
            {
                swap(&A[ind], &A[n - 1]);
                n--;
            }
            break;
        case 3:
            ind = InputId_ReturnIndex(A, n);
            if (ind > -1)
            {
                printf("\n Please input the new cost: ");
                scanf("%f", &A[ind].cost);
            }
            break;
        case 4:
            ind = InputId_ReturnIndex(A, n);
            if (ind > -1)
                printf("The item is %d %s %f %c", A[ind].id, A[ind].name, A[ind].cost, A[ind].cate);
            break;
        case 5:
            Display(A, n);
            break;
        case 6:
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (strcmp(A[i].name, A[j].name) > 0)
                        swap(&A[i], &A[j]);
            break;
        case 7:

            Save(fn2, A, n);
            break;
        }
    } while (opt >= 1 && opt <= 7);
    getch();
    return 0;
}
void swap(item *x, item *y)
{
    item t = *x;
    *x = *y;
    *y = t;
}
int InputId_ReturnIndex(ItemArr A, int n)
{
    printf("\n Input ID: ");
    int id;
    scanf("%d", &id);
    int ind = IndexOf(A, n, id);
    if (ind == -1)
        printf("The ID %d does not exist.", id);
    return ind;
}
int IndexOf(ItemArr A, int n, int id)
{
    for (int i = 0; i < n; i++)
        if (id == A[i].id)
            return i;
    return -1;
}
void Display(ItemArr A, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d %s %f %c\n", A[i].id, A[i].name, A[i].cost, A[i].cate);
}
item Input()
{
    item x;
    printf("ID: ");
    scanf("%d", &x.id);
    printf("Name: ");
    scanf("%s", x.name);
    printf("Cost: ");
    scanf("%f", &x.cost);
    printf("Category: ");
    fflush(stdin);
    scanf("%c", &x.cate);
    return x;
}
void Load(string fn, ItemArr A, int *n)
{
    FILE *f = fopen(fn, "r");
    if (!f)
    {
        printf("The file with name %s does not exist!", fn);
        return;
    }
    printf("Loading data from file %s...", fn);
    item x;
    *n = 0;
    do
    {
        fscanf(f, "%d %[^ ] %f %c\n", &x.id, x.name, &x.cost, &x.cate);
        A[(*n)++] = x;
    } while (!feof(f));
    printf("Succesful.\n");
    fclose(f);
}
void Save(string fn, ItemArr A, int n)
{
    FILE *f = fopen(fn, "w");
    if (!f)
    {
        printf("The file with name %s does not exist!", fn);
        return;
    }
    printf("Saving data to file %s...", fn);
    for (int i = 0; i < n; i++)
        fprintf(f, "%d %s %f %c\n", A[i].id, A[i].name, A[i].cost, A[i].cate);
    fclose(f);
}