//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <stdlib.h>
#define MAXN 20
char codes[][5], names[][10];
double prices;
int n = 0;
void printList(char codes[][9], char names[][21], double prices[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d.%9s%21s%10d \n", i, codes[i], names[i], prices[i]);
}
void addProduct(char codes[][5], char names[][10], double prices[], int *n)
{
    int ok;
    do
    { // *Note: press keySPACE for codes[i] to exit
        printf("%d-- Input a code: ", *n);
        fflush(stdin);
        scanf("%5[^\n]", codes[*n]);
        ok = (codes[*n][0] != 32); //ok=(codes[0]!=' ');
        if (ok)
        {
            printf("Name: ");
            fflush(stdin);
            scanf("%10[^\n]", names[*n]);
            printf("Price: ");
            fflush(stdin);
            scanf("%lf", &prices[*n]);
            (*n)++;
        }
    } while (ok);
    printf("After adding: \n");
    printList(codes, names, prices, *n);
}
int Search(char *s)
{
    for (int i = 1; i <= n; i++)
        if ((strcmp(names[i], s) == 0) || (strcmp(codes[i], s) == 0))
            return i;
    return 0;
}
void Find()
{
    char *s = (char *)calloc(50, sizeof(char));
    int possition = Search(s);
    if (possition != 0)
    {
        printf("Employee \"%s\" is at possition: %d\n", names[possition], possition);
        printf("Code of the employee: %s\n", codes[possition]);
        printf("Prices: %.0lf\n", prices);
    }
    else
        printf("Not found!\n");
    free(s);
}
void Range(double prices[], char *codes[][5], char *names[][10], int n)
{
    int i;
    double MinVal, MaxVal;
    printf("Min Value: ");
    scanf("%.2lf", &MinVal);
    printf("Max Value: ");
    scanf("%.2lf", &MaxVal);
    printf("\nValue: ");
    for (i = 0; i < n; i++)
    {
        if (prices[i] > MinVal && prices[i] < MaxVal)
        {
            printf("Name: \"%s\"\n", names[i]);
            printf("Code: %s\n", codes[i]);
            printf("Prices: %.2lf\n", prices[i]);
        }
    }
}
void Lowest(double prices[], char codes[][5], char names[][10], int n)
{
    int min = prices[0];
    for (int i = 1; i < n; i++)
        if (prices[i] > min)
            min = prices[i];
    return min;
    printf("Prices: %.2lf\n", prices[min]);
    printf("Name: \"%s\"\n", names[min]);
    printf("Code: %s\n", codes[min]);
}
int findCode(char cod[], char codes[][9], int n)
{ //Find the position of a known code
    for (int i = 0; i < n; i++)
        if (strcmp(codes[i], cod) == 0)
            return i;
    return -1;
}
void removeCode(char cod[], char codes[][5], char names[][10], double prices[], int *n)
{
    int pos = findCode(cod, codes, *n);
    if (pos >= 0)
    {
        printf("found on %d    value is: %s \n", pos, codes[pos]);
        for (int i = pos; i < (*n - 1); i++)
        {
            strcpy(codes[i], codes[i + 1]);
            strcpy(names[i], names[i + 1]);
            prices[i] = prices[i + 1];
        }
        (*n)--;
        printf("After deleting: \n");
        printList(codes, names, prices, *n);
    }
    else
        printf("Not found in the list...! \n");
}
void swapInt(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void swapString(char a[], char b[])
{
    char t[31];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void sortPrice(char codes[][5], char names[][10], double prices[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int j;
        for (j = i + 1; j < n; ++j)
        {
            if (prices[i] < prices[j])
            {
                int a = prices[i];
                prices[i] = prices[j];
                prices[j] = a;
            }
        }
        printf("After sorting: \n");
        printList(codes, names, prices, n);
    }
}
void sortName(char codes[][5], char names[][10], double prices[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
        {
            int dName = strcmp(names[j], names[j - 1]);
            if (dName < 0)
            {
                swapString(codes[j], codes[j - 1]);
                swapString(names[j], names[j - 1]);
                swapInt(&prices[j], &prices[j - 1]);
            }
        }
    printf("After sorting: \n");
    printList(codes, names, prices, n);
}
int main()
{
    char codes[MAXN][5], names[MAXN][10];
    double prices[MAXN];
    char cod[9];
    int option, n = 0;
    do
    {
        printf("\nOption 1: Add some new products");
        printf("\nOption 2: Search a product");
        printf("\nOption 3: Print out products in a range");
        printf("\nOption 4: Print out products with the lowest price");
        printf("\nOption 5. Remove a product based on a code inputted");
        printf("\nPrint out the list based on price in descending order then name in ascending order. ");
        printf("\nEnter option = ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Add some new products: \n");
            addProduct(codes, names, prices, &n);
            break;
        case 2:
            printf("Search a product: \n");
            printf("What product do you want to print? ");
            fflush(stdin);
            scanf("%10[^\n]", names);
            Find(codes, names, prices, n);
            break;
        case 3:
            printf("Print out products in a range:\n");
            Range(prices, codes, names, n);
            break;
        case 4:
            printf(" Print out products with the lowest price:\n");
            Lowest(prices, codes, names, n);
            break;
        case 5:
            printf("Remove a product based on a code inputted\n");
            printf("What code do you want to delete? ");
            fflush(stdin);
            scanf("%9[^\n]", cod);
            removeCode(cod, codes, names, prices, n);
            break;
        case 6:
            printf("Print out the list based on price in descending order\n");
            sortPrice(codes, names, prices, n);
            break;
            printf("Print out the list based on name in ascending order\n");
            sortName(codes, names, prices, n);
        default:
        }
    } while ((option >= 1) && (option <= 6));
}