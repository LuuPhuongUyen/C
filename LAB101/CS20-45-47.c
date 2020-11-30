// SLOT
#include <stdio.h>
typedef char string[100];
typedef struct it
{
    int ID;
    string name;
    float cost;
    char category;
} item;

typedef item ItemArr[50];

//=====================LOAD=========================
void LoadItem(string fn, ItemArr A, int *n)
{
    FILE *f = fopen(fn, "r");
    if (!f)
    {
        printf("The file with name %s does not exist !", fn);
        return;
    }
    printf("Loading data from file %s", fn);
    item x;
    *n = 0;
    do
    {
        fscanf(f, "%d %[^\n], %f %c \n", &x.ID, x.name, &x.cost, &x.category);
        A[(*n)++] = x;

    } while (!feof(f));
    fclose(f);
}
//===================SAVE=========================================
void Save(string fn, ItemArr A, int n)
{
    FILE *f = fopen(fn, "w");
    if (!f)
    {
        printf("The file with name %s does not exist !", fn);
        return;
    }
    printf("Saving data to file %s ", fn);
    int i;
    for (i = 0; i < n; i++)
        fprintf(f, "%d %s %f %c", A[i].ID, A[i].name, A[i].cost, A[i].category);
    fclose(f);
}
//=============================ADD==================================
item Input()
{
    item x;
    printf("ID : ");
    scanf("%d", &x.ID);
    printf("Name : ");
    scanf("%s", x.name);
    printf("Cost : ");
    scanf("%f", &x.cost);
    printf("Category : ");
    fflush(stdin);
    scanf("%c", &x.category);
    return x;
}

int InputId_ReturnIndex(ItemArr A, int n)
{
    printf("\n Input ID : ");
    int ID;
    scanf("%d", &ID);
    int ind = IndexOf(A, n, ID);
    if (ind == -1)
        printf("The ID %d does not exist : ", ID);
    return ind;
}
int IndexOf(ItemArr A, int n, int ID)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ID == A[i].ID)
            return i;
        return -1;
    }
}
//===========================DISPLAY=================================
void Display(ItemArr A, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d %s %f %c", A[i].ID, A[i].name, A[i].cost, A[i].category);
}
void menu()
{
    printf("\n1 - Add new item");
    printf("\n2 - Delete item");
    printf("\n3 - Change the cost of an item");
    printf("\n4 - Search for an item");
    printf("\n5 - Display iventory details ");
    printf("\n6 - Quit");
}
//==================MAIN===================================

int main()
{
    string fn = "D:\\C\\LAB\\food.txt";
    ItemArr A;
    int n, ind;
    LoadItem(fn, A, &n);
    menu();
    int c;
    printf("\nEnter choice : ");
    scanf("%d", &c);
    if (c >= 7)
    {
        string fn2 = "D:\\C\\LAB\\food2.txt";
        Save(fn2, A, n);
    }
    switch (c)
    {
    case 1:
        A[n++] = Input();
        break;
    case 2:
        ind = InputId_ReturnIndex(A, n);
        break;
    case 3:
        ind = InputId_ReturnIndex(A, n);
        break;
    case 4:
        ind = InputId_ReturnIndex(A, n);
        if (ind > -1)
            printf("The item is %d %s %f %c", A[ind].ID, A[ind].name, A[ind].cost, A[ind].category);
        break;
    case 5:
        Display(A, n);
        break;
    case 6:
        break;
    }
    getch();
    return 0;
}
